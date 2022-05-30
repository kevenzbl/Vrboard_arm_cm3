#ifndef __GPIO_H__
#define __GPIO_H__
#include "../include/define.h"
#pragma anon_unions

#define GROUP_PIN_NUM 32

typedef enum {
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
	GPIO_PIN16,
} GPIO_PIN;

#define		WIFI_CS 	GPIO_PIN13
#define 	WIFI_RST 	GPIO_PIN14
#define 	WIFI_OE 	GPIO_PIN15
#define 	LED_HL2 	GPIO_PIN3
#define		SCL_I2C0	GPIO_PIN4
#define    	SDA_I2C0	GPIO_PIN5
#define    	SCL_I2C1	GPIO_PIN6
#define    	SDA_I2C1	GPIO_PIN7
#define    	SDA_I2C2	GPIO_PIN8
#define    	SCL_I2C2	GPIO_PIN9
#define    	SCL_I2C3	GPIO_PIN10  //gpio 6
#define    	SDA_I2C3	GPIO_PIN11
#define		CMR0_RST	GPIO_PIN12
#define		CMR1_RST	GPIO_PIN13
#define		CY_RST		GPIO_PIN14
#define		IR_RST		GPIO_PIN15
#define		LM_HW_EN	GPIO_PIN16

typedef struct GPIO_T_ 
{ 
   int data;	       //0x00
   int data_out;	   //0x04
   int rsvd[2];        //0x08
   int out_set;        //0x10
   int out_clr;		   //0x14
   int func_set;	   //0x18
   int func_clr;       //0x1c
   int intr_set;       //0x20
   int intr_clr;       //0x24
   int intr_type_set;  //0x28
   int intr_type_clr;  //0x2c
   int intr_pol_set;   //0x30
   int intr_pol_clr;   //0x34
   int intr_stat;      //0x3
}GPIO_Type;

enum GPIO_GRP {
    GPIO_A = 0,
    GPIO_B = 1,
};

typedef enum
{
    GPIO_DIR_INPUT = 0, ///< Input.
    GPIO_DIR_OUTPUT = 1 ///< Output.
} gpio_dir_t;

void gpio_init(u8 pin_num, gpio_dir_t pin_dir);
void gpio_set_dir_out(unsigned char num);
void gpio_out_data(u8 pin_num, u8 data);
void gpio_set_dir_In(unsigned char num);
char gpio_in_data(unsigned char num);

#endif
