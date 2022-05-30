#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "define.h"

typedef struct
{
  __IO uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IO uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IO uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IO uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;


#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

#define SysTick_BASE		(0xA0005000)     	 				/*!< SysTick Base Address */
#define SysTick             ((SysTick_Type *)SysTick_BASE  )   	/*!< SysTick configuration struct */

typedef union SPI_CR1_U    //0
{
	uint16_t cr1_reg;
	struct SPI_CR1_T_
	{
		uint16_t cpha 		:1;		//Clock phase
		uint16_t cpol 		:1;		//Clock polarity)
		uint16_t mstr 		:1;     //Master selection 
		uint16_t br   		:3;  	//reserve
		uint16_t spe  		:1; 	//SPI enable
		uint16_t lsbfirst  	:1;     //Frame format
		uint16_t reserve  	:3;		//reserve
		uint16_t dff  		:1;		//Data frame format
	}bit_info;
} SPI_CR1_T;

typedef union SPI_CR2_U    //0
{
	uint16_t cr2_reg;
	struct SPI_CR2_T_
	{
		uint16_t reserve0 	:1;		//reserve0
		uint16_t reserve1 	:1;		//
		uint16_t reserve2 	:1;     //
		uint16_t reserve3   :2;  	//reserve
		uint16_t reserve4  	:1; 	//
		uint16_t reserve5  	:1;     //
		uint16_t reserve6  	:1;		//reserve
	}bit_info;
} SPI_CR2_T;

/** 
  * @brief Serial Peripheral Interface
  */
typedef struct
{
  __IO SPI_CR1_T CR1;
  uint16_t  RESERVED0;
  __IO SPI_CR2_T CR2;
  uint16_t  RESERVED1;
  __IO uint16_t SR;
  uint16_t  RESERVED2;
  __IO uint16_t DR;
  uint16_t  RESERVED3;
  __IO uint16_t CRCPR;
  uint16_t  RESERVED4;
  __IO uint16_t RXCRCR;
  uint16_t  RESERVED5;
  __IO uint16_t TXCRCR;
  uint16_t  RESERVED6;
  __IO uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  __IO uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;

#define SPI0 	((SPI_TypeDef* )SPI_32F1_BASE_ADDR)


#endif
