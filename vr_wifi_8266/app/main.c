#include <stdio.h>
#include "define.h"
#include "gpio.h"
#include "i2c.h"
#include "config.h"
#include "lm3644.h"
#include "imu.h"
#include "spi.h"
#include "uart.h"
#include "delay.h"

/*
UARTINTR£¬
SSPINTR,
trigger_vcsel1_int,
trigger_vcsel0_int,
trigger_ir_int,
uvcpkt_all_int,
frame_pre_process_int,
dpu_irq,
TIMINT7,
TIMINT6,
TIMINT5,
wdog_irq,
TIMINT3,
TIMINT2,
TIMINT1,
TIMINT0
*/

void int0_isr(void);


volatile u32 *ptr;

extern u8 i2c_scl;
extern u8 i2c_sda;

#define TIMESTAMP_DIF_1MS       10


// LM_HW_EN  GPIO13 3644 en
// scl gpio6; sda gpio7


void sensor_reset()
{
	gpio_out_data(CMR0_RST, 0);
	delay();
	gpio_out_data(CMR0_RST, 1);

	gpio_out_data(CMR1_RST, 0);
	delay();
	gpio_out_data(CMR1_RST, 1);

	gpio_out_data(CY_RST, 0);
	delay();
	gpio_out_data(CY_RST, 1);

	gpio_out_data(IR_RST, 0);
	delay();
	gpio_out_data(IR_RST, 1);

	gpio_out_data(GPIO_PIN16, 0);
	delay();
	gpio_out_data(GPIO_PIN16, 1);	    
}


int main()
{
	volatile int dly = 0x1fff;
	static int imu_cnt = 0;
	u8 data;

    unsigned int timestamp,timedif;
	//gpio_init();
	//uartInit();
	delay_init();
	spi_init();
	gpio_out_data(WIFI_OE, 1);
#if 0
	//    sensor_reset();
	gpio_out_data(CMR0_RST, 0);
	dly = 0x1fff;  	  while(dly--);
	gpio_out_data(CMR0_RST, 1);

	gpio_out_data(CMR1_RST, 0);
	dly = 0x1fff;  	  while(dly--);
	gpio_out_data(CMR1_RST, 1);

	gpio_out_data(CY_RST, 0);
	dly = 0x1fff;  	  while(dly--);
	gpio_out_data(CY_RST, 1);

	gpio_out_data(IR_RST, 0);
	dly = 0x1fff;  	  while(dly--);
	gpio_out_data(IR_RST, 1);

	gpio_out_data(GPIO_16, 0);
	dly = 0x1fff;  	  while(dly--);
	gpio_out_data(GPIO_16, 1);	

	ov9281_l_get_id();
	ov9281_init_1();

	ov9281_r_get_id();
	ov9281_init_r();

#endif

#if 1
    //imu_init();
	
	while(1) {
		imu_cnt++;
		delay_us(1000);
		gpio_out_data(WIFI_CS, 0);
		spi_ReadWrite_byte(0x66);
		gpio_out_data(WIFI_CS, 1);
		//spi_send_byte(SPI0,0xAA);
		//imu_run(timestamp);
	}
#endif
}


void int0_isr()
{  
}

