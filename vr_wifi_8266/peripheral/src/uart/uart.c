#include "../include/config.h"
#include "../include/uart.h"
#include "../include/define.h"

unsigned int uartGetBaseAddr(void)
{
    return UART0_BASE_ADDR;
}

void uartPutc(char c)
{
    volatile UART_T * pUart = (UART_T *)uartGetBaseAddr();
    UART_DATA_U                dat;    //0x0
	UART_STATE_U               stat; 
     
	while(read32(0x40004004) & 1);
    dat.v = 0;
    dat.bit_info.data = c;
    pUart->dat.v = dat.v;
}

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

void uartInit(void)
{
    volatile UART_T * pUart = (UART_T *)uartGetBaseAddr();
    UART_DATA_U                dat;    //0x0
    UART_STATE_U               stat;    //0x4
    UART_CTRL_U                ctrl;   //0x8
    UART_INTR_STAT_CLEAR_U     intr_stat_clear;    //0xC
    UART_BAUDDIV_U             bauddiv;	   //0x10

	int rate;

    rate = UART_CLK / BAUD_RATE;	 //0x9c4; 
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
