#include "ssp.h"
#include "spi.h"
#include "peripheral.h"
#include "brd_cfg.h"

void spi_init()
{
	SPI_InitPara_t init_para;
	
	init_para.spi_cpha = SPI_Sample_1Edge;
	init_para.spi_cpol = SPI_Sck_Low;
	init_para.spi_datasize = SPI_BIT_8;
	init_para.spi_mode = SPI_Master;
    ssp_init(&init_para);
	
	ssp_enable();
}

void spi_single_read(unsigned char ubAddr, unsigned char *hpubdata)
{
	unsigned char r;
    unsigned char w;
    
    ssp_cs_enable();
    
    // check tx fifo
    while(ssp_tx_is_full());
    
    // check rx fifo
    if(!ssp_rx_is_empty())
        ssp_empty_fifo();
    
    // start trans
    w = ubAddr | CMD_READ;
    ssp_tx_fifo(w);
    w = CMD_IDLE;
    ssp_tx_fifo(w);
    
    ssp_wait_for_idle();
    
    while(ssp_rx_fifo(&r));
    
    ssp_cs_disable();
    
    *hpubdata = (unsigned char)r;
}

void spi_multi_read(unsigned char ubAddr, unsigned char ubLen, unsigned char *hpubdata)
{
	unsigned char r;
    unsigned char w;
    unsigned char i;
    
    ssp_cs_enable();
    
    // check rx fifo
    if(!ssp_rx_is_empty())
        ssp_empty_fifo();
    
    // start trans
    w = ubAddr | CMD_READ;
    ssp_tx_fifo(w);
    w = CMD_IDLE;
    for(i=0;i<ubLen;i++)
        ssp_tx_fifo(w);

    ssp_wait_for_idle();
    
    i=0;
    while(ssp_rx_fifo(&r))
    {
        if(i>0)
            *(hpubdata+i-1) = r;
        i++;
    }
}

void spi_single_write(unsigned char ubAddr, unsigned char ubdata)
{
    unsigned char w;
    
    ssp_cs_enable();
    
    // check tx fifo
    while(ssp_tx_is_full());
    
    // start trans
    w = ubAddr | CMD_WRITE;
    ssp_tx_fifo(w);
    w = ubdata;
    ssp_tx_fifo(w);

    ssp_wait_for_idle();

    // flush rx fifp
    if(!ssp_rx_is_empty())
        ssp_empty_fifo();

    ssp_cs_disable();
}


void spi_send_byte(SPI_TypeDef* SPIx, uint16_t Data)
{
	/* Write in the DR register the data to be sent */
	SPIx->DR = Data;
}

uint16_t spi_receive_data(SPI_TypeDef* SPIx)
{ 
  /* Return the data in the DR register */
  return SPIx->DR;
}

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI1) || \
                                   ((PERIPH) == SPI2) || \
                                   ((PERIPH) == SPI3))
#define SPI_I2S_FLAG_RXNE               ((uint16_t)0x0001)
#define SPI_I2S_FLAG_TXE                ((uint16_t)0x0002)

void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
{
  /* Check the parameters */
  //assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  /* Write in the DR register the data to be sent */
  SPIx->DR = Data;
}

uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
{
  /* Check the parameters */
  //assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  /* Return the data in the DR register */
  return SPIx->DR;
}

FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
//  assert_param(IS_SPI_ALL_PERIPH(SPIx));
//  assert_param(IS_SPI_I2S_GET_FLAG(SPI_I2S_FLAG));
  /* Check the status of the specified SPI/I2S flag */
  if ((SPIx->SR & SPI_I2S_FLAG) != (uint16_t)RESET)
  {
    /* SPI_I2S_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* SPI_I2S_FLAG is reset */
    bitstatus = RESET;
  }
  /* Return the SPI_I2S_FLAG status */
  return  bitstatus;
}


#if 1
//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u16 spi_ReadWrite_byte(u16 TxData)
{						 	
	while((SPI0->SR & 1<<1)==0);	//等待发送区空	
	  
	spi_send_byte(SPI0, TxData&0xFF); //通过外设SPIx发送一个数据

	while((SPI0->SR&1<<0)==0); 		//等待接收完一个byte  
 						    
	return spi_receive_data(SPI0); //返回通过SPIx最近接收的数据
}
#endif

//spi_write_byte


u8 M8266HostIf_SPI_ReadWriteByte(u8 TxdByte)
{
#if 1
	while(SPI_I2S_GetFlagStatus(M8266WIFI_INTERFACE_SPI, SPI_I2S_FLAG_TXE) == RESET){} 	//wait SPI TXD Buffer Empty
	SPI_I2S_SendData(M8266WIFI_INTERFACE_SPI, TxdByte); 			//Write the byte to the TXD buffer and then shift out via MOSI
	while(SPI_I2S_GetFlagStatus(M8266WIFI_INTERFACE_SPI, SPI_I2S_FLAG_RXNE) == RESET){} 	//wait the SPI RXD buffer has received the data from MISO
	return SPI_I2S_ReceiveData(M8266WIFI_INTERFACE_SPI);  		//return the data received from MISO
#endif	
}


