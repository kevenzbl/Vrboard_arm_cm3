#include <stdio.h>
#include "define.h"
#include "gpio.h"
#include "i2c.h"
#include "lm3644.h"
#include "imu.h"
#include "spi.h"
#include "uart.h"
#include "delay.h"
#include "peripheral.h"
#include "cpu_core.h"
#include "M8266HostIf.h"
#include "M8266WIFIDrv.h"
#include "M8266WIFI_ops.h"

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
void M8266WIFI_Test(void);
#define TIMESTAMP_DIF_1MS       10


// LM_HW_EN  GPIO13 3644 en
// scl gpio6; sda gpio7

/*
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


void HardFault_Handler(void)
{
  // Go to infinite loop when Hard Fault exception occurs
  while (1)
  {
  }
}
*/
u8 buf[128];

int main()
{
	static int imu_cnt = 0;
	u8 success = 0;
	
	cpu_ts_tmr_init();
	uartInit();
	delay_init();
	spi_init();

	M8266HostIf_Init();
	success = M8266WIFI_Module_Init_Via_SPI();
	M8266WIFI_Test();

#if 1
	while(1) {
		imu_cnt++;
		//printf("zzz imu_cnt:%d!\n",imu_cnt);
		delay_ms(10);
	}
#endif
}

void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
