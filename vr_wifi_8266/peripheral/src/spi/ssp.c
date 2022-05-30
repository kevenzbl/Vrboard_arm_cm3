#include "ssp.h"
//#include "../include/gpio.h"
#include "config.h"

//SSPMS clk 100MHz

static unsigned int ssp_get_base_addr()
{
	return SPI0_BASE_ADDR;
}

void ssp_cs_enable()
{
//	write32(IO_SPI_CSN, 1);	
}

void ssp_cs_disable()
{
//	write32(IO_SPI_CSN, 3);	
}

void ssp_init(SPI_InitPara_t* spi_init_para)
{
    __IO SSPMS_T *pSspms = (SSPMS_T *)ssp_get_base_addr();
//    __IO SSPCR0_U          sspcr0;                // 0x00
//    __IO SSPCR1_U          sspcr1;                // 0x04
//  __IO SSPDR_U           sspdr;                 // 0x08
//  __IO SSPSR_U           sspsr;                 // 0x0C
    __IO SSPCPSR_U         sspcpsr;               // 0x10
//  __IO SSPII_ICR_U       sspii_icr;             // 0x14

	__IO SPI_TypeDef* SPI = (SPI_TypeDef*)SPI_32F1_BASE_ADDR;
	__IO SPI_CR1_T spi_cr1;										//0x00
	__IO SPI_CR2_T spi_cr2;										//0x04
	
    sspcpsr.v = 0;
    sspcpsr.bit_info.cpsdvsr = 0xFF;
    pSspms->sspcpsr.v = sspcpsr.v;

	spi_cr1.bit_info.mstr = spi_init_para->spi_mode&0x01;
	spi_cr1.bit_info.dff = spi_init_para->spi_datasize&0x01;
	spi_cr1.bit_info.cpha = spi_init_para->spi_cpha&0x01;
	spi_cr1.bit_info.cpol = spi_init_para->spi_cpol&0x01;
	SPI->CR1.cr1_reg = spi_cr1.cr1_reg;
}

void ssp_disable(void)
{
	__IO SPI_TypeDef* SPI = (SPI_TypeDef*)SPI_32F1_BASE_ADDR;
	__IO SPI_CR1_T spi_cr1;										//0x00
	
	spi_cr1.cr1_reg = SPI->CR1.cr1_reg;
	spi_cr1.bit_info.spe = 0;
	SPI->CR1.cr1_reg = spi_cr1.cr1_reg;
}

void ssp_enable(void)
{
	__IO SPI_TypeDef* SPI = (SPI_TypeDef*)SPI_32F1_BASE_ADDR;
	__IO SPI_CR1_T spi_cr1;										//0x00
	
	spi_cr1.cr1_reg = SPI->CR1.cr1_reg;
	spi_cr1.bit_info.spe = 1;
	SPI->CR1.cr1_reg = spi_cr1.cr1_reg;      	
}

void ssp_wait_for_idle(void)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    
	while (pSspms->sspsr.bit_info.bsy);
}

unsigned int ssp_tx_is_full(void)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    volatile SSPSR_U           sspsr;                 // 0x0C
    
    sspsr.v = pSspms->sspsr.v;
    
    if (sspsr.bit_info.tnf == 0)
        return 1;   //full
    else 
        return 0;
}

unsigned int ssp_rx_is_empty(void)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    volatile SSPSR_U           sspsr;                 // 0x0C
 
    sspsr.v = pSspms->sspsr.v;
    
    if (sspsr.bit_info.rne == 0)
        return 1;  //empty
    else 
        return 0;  	
}

void ssp_xfer(unsigned char w, unsigned char *r)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    volatile SSPDR_U           sspdr;                 // 0x08	
    
//    while(ssp_tx_is_full());
    
    pSspms->sspdr.v = w;
    
//    ssp_wait_for_idle();

//    while(!ssp_rx_is_empty())
        *r =pSspms->sspdr.bit_info.data;
}

void ssp_tx_fifo(unsigned char w)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    
    while(ssp_tx_is_full());
    
    pSspms->sspdr.v = w;
}

unsigned char ssp_rx_fifo(unsigned char *r)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    
    if(!ssp_rx_is_empty())
    {
        *r =pSspms->sspdr.bit_info.data;
        return 1;
    }
    else
        return 0; // if rx fifo empty, return false
}

void ssp_empty_fifo(void)
{
    volatile SSPMS_T * pSspms = (SSPMS_T *)ssp_get_base_addr();
    
	/* Empty RX FIFO */
	while (pSspms->sspsr.bit_info.rne)
		pSspms->sspdr.v;
}
