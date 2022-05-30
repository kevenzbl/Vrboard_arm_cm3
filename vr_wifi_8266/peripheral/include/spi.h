#ifndef __SPI_H__
#define __SPI_H__
#include "ssp.h"
#define CMD_WRITE                  0x00
#define CMD_READ                   0x80
#define CMD_IDLE                   0xFF


void spi_init(void);
void spi_single_read(unsigned char ubAddr, unsigned char *hpubdata);
void spi_single_write(unsigned char ubAddr, unsigned char ubdata);
void spi_multi_read(unsigned char ubAddr, unsigned char ubLen, unsigned char *hpubdata);

void spi_send_byte(SPI_TypeDef* SPIx, uint16_t Data);
u16 spi_ReadWrite_byte(u16 TxData);
#endif
