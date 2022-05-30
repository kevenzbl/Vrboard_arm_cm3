#ifndef __SSP_H__
#define __SSP_H__
#include "define.h"
#include "system.h"

typedef union SSPCR0_U_    //0
{
	unsigned int v;
	struct SSPCR0_U_T_
	{
		unsigned dss  :4;          
		unsigned frf  :2;  
		unsigned spo  :1; 
		unsigned sph  :1;   
		unsigned scr  :8;  
	}bit_info;
} SSPCR0_U;

typedef union SSPCR1_U_    //0x04
{
	unsigned int v;
	struct SSPCR1_T_
	{
		unsigned lbm    :1;   // [0]:  
		unsigned sse    :1;   // [1]:  
		unsigned ms     :1;   // [2]:  
		unsigned sod    :1;   // [3]:  
		unsigned rsvd   :12;  // [4-15]:  
	}bit_info;
} SSPCR1_U;

typedef union SSPDR_U_    //0x08
{
	unsigned int v;
	struct SSPDR_T_
	{
		unsigned data  :16;  // [0]:  
	}bit_info;
} SSPDR_U;

typedef union SSPSR_U_   //0x0C
{
	unsigned int v;
	struct SSPSR_T_ 
	{
		unsigned tfe   :1;  // [0]:  
		unsigned tnf   :1;  // [1]:  
		unsigned rne   :1;  // [1]: 
		unsigned rff   :1;  // [1]: 
		unsigned bsy   :1;  // [1]: 
		unsigned rsvd  :11;  // [2]:
	}bit_info;
} SSPSR_U;


typedef union SSPCPSR_U_   //0x10
{
	unsigned int v;
	struct SSPCPSR_T_
	{
		unsigned cpsdvsr  :8;  // [0]:  
		unsigned rsvd     :8;  // [1]:  
	}bit_info;
} SSPCPSR_U;

typedef union SSP_IMSC_U_   //0x14
{
	unsigned int v;
	struct SSP_IMSC_T_
	{
		unsigned rorim    :1;   // [0]:  
		unsigned rtim     :1;   // [1]:  
		unsigned rxim     :1;   // [2]:  
	  unsigned txim     :1;   // [3]:
		unsigned rsvd     :12;  // [4]:  
	}bit_info;
} SSP_IMSC_U;

typedef union SSP_RIS_U_   //0x18
{
	unsigned int v;
	struct SSP_RIS_T_
	{
		unsigned rorris    :1;   // [0]:  
		unsigned rtris     :1;   // [1]:  
		unsigned rxris     :1;   // [2]:  
	    unsigned txris     :1;   // [3]:
		unsigned rsvd      :12;  // [4]:  
	} bit_info;
} SSP_RIS_U;

typedef union SSP_MIS_U_   //0x1c
{
	unsigned int v;
	struct SSP_MIS_T_
	{
		unsigned rormis    :1;   // [0]:  
		unsigned rtmis     :1;   // [1]:  
		unsigned rxmis     :1;   // [2]:  
	    unsigned txmis     :1;   // [3]:
		unsigned rsvd      :12;  // [4]:  
	}bit_info;
} SSP_MIS_U;

typedef union SSP_ICR_U_   //0x20
{
	unsigned int v;
	struct SSP_ICR_T_
	{
		unsigned roric    :1;   // [0]:  
		unsigned rtic     :1;   // [1]:  
		unsigned rsvd     :14;  // [2]:  
	}bit_info;
} SSP_ICR_U;

typedef union SSP_DMACR_U_   //0x24
{
	unsigned int v;
	struct SSP_DMACR_T_
	{
		unsigned rxdmae    :1;   // [0]:  
		unsigned txdmae    :1;   // [1]:  
		unsigned rsvd      :13;  // [2]:  
	}bit_info;
} SSP_DMACR_U;

typedef struct SSPMS_T_
{
   SSPCR0_U          sspcr0;                // 0x00
   SSPCR1_U          sspcr1;                // 0x04
   SSPDR_U           sspdr;                 // 0x08
   SSPSR_U           sspsr;                 // 0x0C
   SSPCPSR_U         sspcpsr;               // 0x10
   SSP_IMSC_U        sspimsc;               // 0x14
   SSP_RIS_U         sspirs;                // 0x18
   SSP_MIS_U         sspmis;                // 0x1c
   SSP_ICR_U         sspicr;                // 0x20
   SSP_DMACR_U       sspdmacr;              // 0x24
}SSPMS_T;


typedef enum
{
	SPI_Slave = 0,
	SPI_Master,
}SPI_Mode_Type;

typedef enum
{
	SPI_BIT_8 = 0,
	SPI_BIT_16,
}SPI_DataSize_Type;

typedef enum
{
	SPI_Sck_Low = 0,
	SPI_Sck_High,
}SPI_Cpol_Type;

typedef enum
{
	SPI_Sample_1Edge = 0,
	SPI_Sample_2Edge,
}SPI_Cpha_Type;

typedef enum
{
	SPI_FirstBit_MSB = 0,
	SPI_FirstBit_LSB,
}SPI_FirstBit_Type;

typedef struct
{
  u16 spi_dir;           				/*!< Specifies the SPI unidirectional or bidirectional data mode.*/
  SPI_Mode_Type spi_mode;             	/*!< Specifies the SPI operating mode.*/
  SPI_DataSize_Type spi_datasize;     	/*!< Specifies the SPI data size.*/
  SPI_Cpol_Type spi_cpol;            				/*!< Specifies the serial clock steady state.*/
  SPI_Cpha_Type spi_cpha;             			/*!< Specifies the clock active edge for the bit capture.*/
  SPI_FirstBit_Type spi_firstbit;         			/*!< Specifies whether data transfers start from MSB or LSB bit.*/
}SPI_InitPara_t;

void ssp_init(SPI_InitPara_t* spi_init_para);
void ssp_cs_enable(void);
void ssp_cs_disable(void);
void ssp_disable(void);
void ssp_enable(void);
void ssp_empty_fifo(void);
void ssp_wait_for_idle(void);
void ssp_xfer(unsigned char, unsigned char *);
unsigned int ssp_tx_is_full(void);
unsigned int ssp_rx_is_empty(void);
void ssp_tx_fifo(unsigned char w);
unsigned char ssp_rx_fifo(unsigned char *r);

#endif
