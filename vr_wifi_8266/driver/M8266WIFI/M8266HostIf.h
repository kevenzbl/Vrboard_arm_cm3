/********************************************************************
 * M8266HostIf.h
 * .Description
 *     header file of M8266WIFI Host Interface 
 * .Copyright(c) Anylinkin Technology 2015.5-
 *     IoT@anylinkin.com
 *     http://www.anylinkin.com
 *     http://anylinkin.taobao.com
 *  Author
 *     wzuo
 *  Date
 *  Version
 ********************************************************************/
#ifndef _M8266_HOST_IF_H_
#define _M8266_HOST_IF_H_
#include "define.h"
#include "system.h"

/** 
  * @brief Serial Peripheral Interface
  */

#define SPI_Direction_2Lines_FullDuplex ((uint16_t)0x0000)
#define SPI_Direction_2Lines_RxOnly     ((uint16_t)0x0400)
#define SPI_Direction_1Line_Rx          ((uint16_t)0x8000)
#define SPI_Direction_1Line_Tx          ((uint16_t)0xC000)
#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_2Lines_FullDuplex) || \
                                     ((MODE) == SPI_Direction_2Lines_RxOnly) || \
                                     ((MODE) == SPI_Direction_1Line_Rx) || \
                                     ((MODE) == SPI_Direction_1Line_Tx))

#define SPI_Mode_Master                 ((uint16_t)0x0104)
#define SPI_Mode_Slave                  ((uint16_t)0x0000)
#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
                           ((MODE) == SPI_Mode_Slave))

#define SPI_DataSize_16b                ((uint16_t)0x0800)
#define SPI_DataSize_8b                 ((uint16_t)0x0000)
#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DataSize_16b) || \
                                   ((DATASIZE) == SPI_DataSize_8b))

/** @defgroup SPI_Clock_Polarity 
  * @{
  */

#define SPI_CPOL_Low                    ((uint16_t)0x0000)
#define SPI_CPOL_High                   ((uint16_t)0x0002)
#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
                           ((CPOL) == SPI_CPOL_High))

/** @defgroup SPI_Clock_Phase 
  * @{
  */

#define SPI_CPHA_1Edge                  ((uint16_t)0x0000)
#define SPI_CPHA_2Edge                  ((uint16_t)0x0001)
#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
                           ((CPHA) == SPI_CPHA_2Edge))

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */


void M8266HostIf_Init(void);
void M8266HostIf_SPI_SetSpeed(u32 SPI_BaudRatePrescaler);

#endif

