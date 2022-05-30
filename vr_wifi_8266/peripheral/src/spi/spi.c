#include "ssp.h"
#include "spi.h"
#include "config.h"

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


#if 1
//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u16 spi_ReadWrite_byte(u16 TxData)
{						 	
	while((SPI0->SR & 1<<1)==0);	//等待发送区空	
	  
	spi_send_byte(SPI0, TxData&0xFF); //通过外设SPIx发送一个数据
	//spi_send_byte(SPI0, TxData>>8); //通过外设SPIx发送一个数据

	while((SPI0->SR&1<<0)==0); 		//等待接收完一个byte  
 						    
	return spi_receive_data(SPI0); //返回通过SPIx最近接收的数据
}
#endif

//spi_write_byte

