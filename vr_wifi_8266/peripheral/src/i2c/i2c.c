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
/* 不同的工作环境,需要调整此函数，注意时钟过快时需要修改 */
/**************************************/
void delay()
{
    _nop_();
}

/**************************************
起始信号												 
**************************************/
void i2cStart()
{
    I2C_SDA(1);                    //拉高数据线
    I2C_SCL(1);                    //拉高时钟线
    delay();                       //延时
    I2C_SDA(0);                    //产生下降沿
    delay();                        //延时
    I2C_SCL(0);                    //拉低时钟线
}

/**************************************
停止信号
**************************************/
void i2cStop()
{
    I2C_SDA(0);                    //拉低数据线
    I2C_SCL(1);                    //拉高时钟线
    delay();                       //延时
    I2C_SDA(1);                    //产生上升沿
    delay();                       //延时
}

/**************************************
发送应答信号
入口参数:ack (0:ACK 1:NAK)
**************************************/
void i2cSendACK(u8 ack)
{
    I2C_SDA(ack);                  //写应答信号
    I2C_SCL(1);                    //拉高时钟线
    delay();                 //延时
    I2C_SCL(0);                    //拉低时钟线
    delay();                 //延时
}

/**************************************
接收应答信号
**************************************/
u8 i2cRecvACK()
{
    u8 ack;
 
    I2C_SET_GPIO_DIRECTION_IN();

    I2C_SCL(0); 
    delay();
    delay();

    I2C_SCL(1);                    //拉高时钟线
    delay();                 //延时
    
    ack = I2C_GET_GPIO_VALUE() & 1; //读应答信号              
 
    I2C_SCL(0);              //拉低时钟线 
    delay();                 //延时

    return ((u8)ack);
}

/**************************************
向IIC总线发送一个字节数据
**************************************/
u8 i2cSendByte(u8 dat)
{    
    u8 ret;
    int i;
	 
    for(i = 0; i < 8; i++)
    {
        I2C_SCL(0);
    
        if((dat << i) & 0x80)
            I2C_SDA(1); //发送1
        else 
            I2C_SDA(0);  //发送0
        
        delay();
        I2C_SCL(1);//时钟高电平
    
        delay();
        I2C_SCL(0);//时钟低电平
    }
			
    ret = i2cRecvACK();
/*
   Delay5us();//第9个脉冲
   SDA(1); //发送完8bit，释放总线准备接收应答位

   Delay5us();
   SCL(1);
   
   Delay5us(); //sda上数据即是从应答位
   SCL(0); //不考虑从应答位，但要控制好时序
*/
   return ret;
}

/**************************************
从IIC总线接收一个字节数据
**************************************/
u8 i2cRecvByte()
{
    u8  i;
    u8 dat = 0;

	//I2C_SDA(1);                   //使能内部上拉,准备读取数据,
  //  I2C_SET_GPIO_DIRECTION_IN();
    
    for (i = 0; i < 8; i++)         //8位计数器
    {
        dat <<= 1;
        I2C_SCL(1);                 //拉高时钟线
        delay();             //延时
        dat |= (I2C_GET_GPIO_VALUE() & 1);             //读数据               
        I2C_SCL(0);                 //拉低时钟线
        delay();             //延时
    }
    
    return dat;
}


void i2cWrite(u8 slave_Addr, u32 regLen, u32 reg, u32 dataLen, u32 data)
{
	if((regLen > 4) ||(dataLen > 4))
		return;
    //slaveAddr = slave_Addr;
    i2cStart();                  //起始信号
    i2cSendByte(slave_Addr);   //发送设备地址+写信号

	while(regLen) {
		i2cSendByte((u8)(reg >> (8 * (regLen - 1)))); 
		regLen--;
	}

	while(dataLen) {
		i2cSendByte((u8)(data >> (8 * (dataLen - 1)))); 
		dataLen--;
	}    
    delay();    
    i2cStop();                   //发送停止信号
}

void i2cRead(u8 slave_Addr, u32 regLen, u32 reg, u32 dataLen, u32 *pData)
{
	u8 *pBuf = (u8 *)pData;
	if((regLen > 4) ||(dataLen > 4))
		return;
	
    //slaveAddr = slave_Addr;
    	
    i2cStart();                  //起始信号
	
    i2cSendByte(slave_Addr);   //发送设备地址+写信号
			 
	while(regLen) {
		i2cSendByte((u8)(reg >> (8 * (regLen - 1)))); 
		regLen--;
	}

	i2cStart();  
	                        //起始信号
    i2cSendByte(slave_Addr + 1);       //发送设备地址+读信号
    
    delay();
	while(dataLen) {
		pBuf[dataLen - 1] = i2cRecvByte();
		delay();
		dataLen--;
		if (dataLen) {
            i2cSendACK(0);               //回应ACK
        } else {
            i2cSendACK(1);               //最后一个数据需要回NOACK
        }
	}     
	
    i2cStop();                   //发送停止信号
}
