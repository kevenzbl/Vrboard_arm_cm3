#include "peripheral.h"
#include "uart.h"
#include "stdarg.h"
#include "delay.h"
#if 1

//?¨®¨¨?¨°???¡ä¨²??,?¡ì3?printfo¡¥¨ºy,??2?D¨¨¨°a????use MicroLIB	  
#pragma import(__use_no_semihosting)             
//¡À¨º¡Á??aD¨¨¨°a¦Ì??¡ì3?o¡¥¨ºy                 

/*
static char printf_buf[100];

void dbg_printf(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsprintf(printf_buf,fmt,args);
    va_end(args);
    uartPuts(printf_buf);
}
*/
#else
void dbg_printf(char *fmt, ...)
{
    uartPuts(fmt);
}
#endif

void uartPutc(u8 c)
{
    volatile UART_T * pUart = (UART_T *)uartGetBaseAddr();
    volatile UART_DATA_U dat;    //0x0
     
	while(pUart->stat.bit_info.tx_full & 1)
		dat.v = dat.v;

    pUart->dat.v = c;
	dat.v = 0;
    dat.bit_info.data = c;
}

/*
char uartGetc(void)
{
    volatile UART_T * pUart = (UART_T *)uartGetBaseAddr();
//	UART_DATA_U                dat;    //0x0

    char data = pUart->dat.bit_info.data;

    return data;
}

void uartPuts(const char *s)
{
    while (*s)
        uartPutc(*s++);
}
*/

int fputc(int ch, FILE *f)
{
  	uartPutc(ch);
	return ch;
}

unsigned int uartGetBaseAddr(void)
{
    return UART0_BASE_ADDR;
}

void uartInit(void)
{
    __IO UART_T * pUart = (UART_T *)uartGetBaseAddr();
    //UART_STATE_U               stat;    			//0x4
    UART_CTRL_U    ctrl;   				//0x8
    //UART_INTR_STAT_CLEAR_U     intr_stat_clear;    	//0xC
	UART_BAUDDIV_U             bauddiv;	   			//0x10

	int rate;

    rate = (UART_CLK / BAUD_RATE) + 1;	 //0x9c4;
	bauddiv.v = 0;
    bauddiv.bit_info.baud_div = rate;
    pUart->bauddiv.v = bauddiv.v;

	ctrl.v = 0;
    ctrl.bit_info.tx_en = 1;
	ctrl.bit_info.rx_en = 1;
	ctrl.bit_info.tx_overrun_intr_en = 1;
	ctrl.bit_info.rx_overrun_intr_en = 1;
	pUart->ctrl.v = ctrl.v;
}

void uartStop(void)
{
    volatile UART_T * pUart = (UART_T *)uartGetBaseAddr();

}
