#ifndef __DELAY_H
#define __DELAY_H 			   
#include "system.h"
#include "define.h"

#define SYSTEM_CLOCK 60000000

void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif





























