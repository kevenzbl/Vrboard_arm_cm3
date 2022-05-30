 /****************************************************************************
   Copyright (c) 2015 Huajie IMI Technology Co., Ltd. 
   All rights reserved.
         
   @file   uart.h
   @brief  header file of uart.c
           define the uart base address, clock, baund rate, registers

   @date    2015-04-13
   @author  Guo Yushi  
   @version 0.1.0
  
   History: 1. 2015-04-13 the initial version 
  **************************************************************************/

#ifndef __UART_H__
#define __UART_H__


#define UART_CLK	60000000
#define BAUD_RATE	115200

typedef union UART_DATA_U_ 
{
	 unsigned long v;
	 struct UART_DATA_T_ 
	 {
		 unsigned data         : 8;
	 }bit_info; 
}UART_DATA_U;    //0x0


typedef union UART_STATE_U_ 
{
	 unsigned long v;
	 struct UART_STATE_T_ 
	 {
		 unsigned tx_full          : 1;
         unsigned rx_full          : 1;
         unsigned tx_overrun       : 1;
         unsigned rx_overrun       : 1;
	 }bit_info; 
}UART_STATE_U;    //0x4

typedef union UART_CTRL_U_ 
{
	 unsigned long v;
	 struct UART_CTRL_T_ 
	 {
		 unsigned tx_en               : 1;
         unsigned rx_en               : 1;
         unsigned tx_intr_en          : 1;
         unsigned rx_intr_en          : 1;
         unsigned tx_overrun_intr_en  : 1;
         unsigned rx_overrun_intr_en  : 1;
         unsigned tx_test_mode        : 1;
	 }bit_info; 
}UART_CTRL_U;    //0x08

typedef union UART_INTR_STAT_CLEAR_U_ 
{
	 unsigned long v;
	 struct UART_INTR_STAT_CLEAR_T_ 
	 {
		 unsigned tx_intr             : 1;
		 unsigned rx_intr             : 1;
		 unsigned tx_overrun_intr     : 1;
		 unsigned rx_overrun_intr     : 1;
	 }bit_info; 
}UART_INTR_STAT_CLEAR_U;    //0x0c

typedef union UART_BAUDDIV_U_ 
{
	 unsigned long v;
	 struct UART_BAUDDIV_T_ 
	 {
		 unsigned baud_div            : 20;
	 }bit_info; 
}UART_BAUDDIV_U;    //0x10


typedef struct UART_T_ 
{ 
    UART_DATA_U                dat;    //0x0
    UART_STATE_U               stat;    //0x4
    UART_CTRL_U                ctrl;   //0x8
    UART_INTR_STAT_CLEAR_U     intr_stat_clear;    //0xC
    UART_BAUDDIV_U             bauddiv;	   //0x10
}UART_T;

unsigned int uartGetBaseAddr(void);
void uartInit(void);
void uartStop(void);
void uartPutc(char c);
char uartGetc(void);
void uartPuts(const char *s);




#endif /* __UART_H__ */
