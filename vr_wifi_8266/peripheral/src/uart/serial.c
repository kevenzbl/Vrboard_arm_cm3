#include "../include/uart.h"
#include "../include/serial.h"
#include <stdio.h>
#define PRINTF_STANDARD 1

#if 1
#include "stdarg.h"

static char printf_buf[100];

void dbg_printf(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsprintf(printf_buf,fmt,args);
    va_end(args);
    uartPuts(printf_buf);
}
#else
void dbg_printf(char *fmt, ...)
{
    uartPuts(fmt);
}
#endif


int fputc(int ch, FILE *f)
{
  	uartPutc(ch);
}
