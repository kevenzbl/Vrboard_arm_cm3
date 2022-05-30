#include "../include/i2c.h"
#include "../include/define.h"
#include "../include/gpio.h"

u32 slaveAddr; 
u8 i2c_scl;
u8 i2c_sda;
//u8 i2c_scl = IO_AR0330_0_SCL;
//u8 i2c_sda = IO_AR0330_0_SDA;

static void _nop_()
{
    volatile unsigned int n = 0x1ff;

    while (n--);
}
/**************************************/
/* ��ͬ�Ĺ�������,��Ҫ�����˺�����ע��ʱ�ӹ���ʱ��Ҫ�޸� */
/**************************************/
void delay()
{
    _nop_();
}

/**************************************
��ʼ�ź�												 
**************************************/
void i2cStart()
{
    I2C_SDA(1);                    //����������
    I2C_SCL(1);                    //����ʱ����
    delay();                       //��ʱ
    I2C_SDA(0);                    //�����½���
    delay();                        //��ʱ
    I2C_SCL(0);                    //����ʱ����
}

/**************************************
ֹͣ�ź�
**************************************/
void i2cStop()
{
    I2C_SDA(0);                    //����������
    I2C_SCL(1);                    //����ʱ����
    delay();                       //��ʱ
    I2C_SDA(1);                    //����������
    delay();                       //��ʱ
}

/**************************************
����Ӧ���ź�
��ڲ���:ack (0:ACK 1:NAK)
**************************************/
void i2cSendACK(u8 ack)
{
    I2C_SDA(ack);                  //дӦ���ź�
    I2C_SCL(1);                    //����ʱ����
    delay();                 //��ʱ
    I2C_SCL(0);                    //����ʱ����
    delay();                 //��ʱ
}

/**************************************
����Ӧ���ź�
**************************************/
u8 i2cRecvACK()
{
    u8 ack;
 
    I2C_SET_GPIO_DIRECTION_IN();

    I2C_SCL(0); 
    delay();
    delay();

    I2C_SCL(1);                    //����ʱ����
    delay();                 //��ʱ
    
    ack = I2C_GET_GPIO_VALUE() & 1; //��Ӧ���ź�              
 
    I2C_SCL(0);              //����ʱ���� 
    delay();                 //��ʱ

    return ((u8)ack);
}

/**************************************
��IIC���߷���һ���ֽ�����
**************************************/
u8 i2cSendByte(u8 dat)
{    
    u8 ret;
    int i;
	 
    for(i = 0; i < 8; i++)
    {
        I2C_SCL(0);
    
        if((dat << i) & 0x80)
            I2C_SDA(1); //����1
        else 
            I2C_SDA(0);  //����0
        
        delay();
        I2C_SCL(1);//ʱ�Ӹߵ�ƽ
    
        delay();
        I2C_SCL(0);//ʱ�ӵ͵�ƽ
    }
			
    ret = i2cRecvACK();
/*
   Delay5us();//��9������
   SDA(1); //������8bit���ͷ�����׼������Ӧ��λ

   Delay5us();
   SCL(1);
   
   Delay5us(); //sda�����ݼ��Ǵ�Ӧ��λ
   SCL(0); //�����Ǵ�Ӧ��λ����Ҫ���ƺ�ʱ��
*/
   return ret;
}

/**************************************
��IIC���߽���һ���ֽ�����
**************************************/
u8 i2cRecvByte()
{
    u8  i;
    u8 dat = 0;

	//I2C_SDA(1);                   //ʹ���ڲ�����,׼����ȡ����,
  //  I2C_SET_GPIO_DIRECTION_IN();
    
    for (i = 0; i < 8; i++)         //8λ������
    {
        dat <<= 1;
        I2C_SCL(1);                 //����ʱ����
        delay();             //��ʱ
        dat |= (I2C_GET_GPIO_VALUE() & 1);             //������               
        I2C_SCL(0);                 //����ʱ����
        delay();             //��ʱ
    }
    
    return dat;
}


void i2cWrite(u8 slave_Addr, u32 regLen, u32 reg, u32 dataLen, u32 data)
{
	if((regLen > 4) ||(dataLen > 4))
		return;
    //slaveAddr = slave_Addr;
    i2cStart();                  //��ʼ�ź�
    i2cSendByte(slave_Addr);   //�����豸��ַ+д�ź�

	while(regLen) {
		i2cSendByte((u8)(reg >> (8 * (regLen - 1)))); 
		regLen--;
	}

	while(dataLen) {
		i2cSendByte((u8)(data >> (8 * (dataLen - 1)))); 
		dataLen--;
	}    
    delay();    
    i2cStop();                   //����ֹͣ�ź�
}

void i2cRead(u8 slave_Addr, u32 regLen, u32 reg, u32 dataLen, u32 *pData)
{
	u8 *pBuf = (u8 *)pData;
	if((regLen > 4) ||(dataLen > 4))
		return;
	
    //slaveAddr = slave_Addr;
    	
    i2cStart();                  //��ʼ�ź�
	
    i2cSendByte(slave_Addr);   //�����豸��ַ+д�ź�
			 
	while(regLen) {
		i2cSendByte((u8)(reg >> (8 * (regLen - 1)))); 
		regLen--;
	}

	i2cStart();  
	                        //��ʼ�ź�
    i2cSendByte(slave_Addr + 1);       //�����豸��ַ+���ź�
    
    delay();
	while(dataLen) {
		pBuf[dataLen - 1] = i2cRecvByte();
		delay();
		dataLen--;
		if (dataLen) {
            i2cSendACK(0);               //��ӦACK
        } else {
            i2cSendACK(1);               //���һ��������Ҫ��NOACK
        }
	}     
	
    i2cStop();                   //����ֹͣ�ź�
}
