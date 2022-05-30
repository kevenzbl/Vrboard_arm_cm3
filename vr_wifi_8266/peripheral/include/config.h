#ifndef __CONFIG_H__
#define __CONFIG_H__

//APB
#define TIMER0_BASE_ADDR				0x40000000
#define TIMER1_BASE_ADDR				0x40001000
#define TIMER2_BASE_ADDR                0x40002000
#define UART0_BASE_ADDR                 0xA0004000
#define I2C0_BASE_ADDR                  0x40004000
#define I2C1_BASE_ADDR                  0x40005000
#define WATCHDOS_BASE_ADDR              0x40008000
#define SPI_32F1_BASE_ADDR				0xA0007000
#define SPI0_BASE_ADDR                  0xA0009000

#define SROM_CONTROL_BASE_ADDR          0x4000B000
#define DPU_BASE_ADDR                   0x4000C000
#define ORB0_BASE_ADDR                  0x4000D000
#define ORB1_BASE_ADDR                  0x4000E000
#define TIMESTAMP_BASE_ADDR             0x4000F000
#define GPIO0_BASE_ADDR                 0x40010000

#define SYSCTRL_BASE_ADDR               0x4001F000
#define SYSROM_BASE_ADDR                0xF0000000

//AHB
#define BOOT_ADDR_BASE                  0x00000000
#define FLASH_ADDR_BASE                 0x10100000
#define SRAM_ADDR_BASE                  0x20000000
#define DPU_RAM_BASE_ADDR               0x30000000
#define LE_RAM_BASE_ADDR                0x30000000
#define DY_RAM_BASE_ADDR                0x30010000
#define SHIF2DEPTH_RAM_BASE_ADDR 		0x30020000
#define MIPI_ORB_LEFT_BASE_ADDR 	    0xa0100000  //0K			  
#define MIPI_ORB_RIGHT_BASE_ADDR 	    0x50010000
#define MIPI_DPU_BASE_ADDR				0x50020000
#define REF_SRAM_BASE_ADDR          	0x60000000    

#define IMU_SENSOR_ADDR                 0xa0000050
#define IMU_PKGLEN_ADDR                 0xa0000054
#define IMU_PKGFIFO_ADDR                0xa0001000

#define TIMESTAMP_VALUE_ADDR            0xa00000f4
#define TIMESTAMP_SET_ADDR              0xa0000003
#define TIMESTAMP_PERIOD_ADDR           0xa000000C

/*
#define GLOBAL_TRIGGER_BASE_ADDR           0x51000000  // 0x51000000 ~ 0x51000FFF
#define SENSOR_SYNC0_BASE_ADDR             0x51001000  // 0x51001000 ~ 0x51001FFF
#define SENSOR_SYNC1_BASE_ADDR             0x51002000  // 0x51002000 ~ 0x51002FFF
#define SENSOR_SYNC2_BASE_ADDR             0x51003000  // 0x51003000 ~ 0x51003FFF
#define PWM_BASE_ADDR                      0x51004000  // 0x51004000 ~ 0x51004FFF
#define GPIO_BASE_ADDR                     0x51004008
#define FRAME_PRE_PROC_BASE_ADDR           0x51005000  // 0x51005000 ~ 0x51005FFF
#define REF_SRAM_BASE_ADDR                 0x51006000  // 0x51006000 ~ 0x51006FFF
#define DPU_BASE_ADDR                      0x51007000  // 0x51007000 ~ 0x51007FFF
#define UVCPKT_BASE_ADDR                   0x51008000  // 0x51008000 ~ 0x51008FFF
#define TIMER_BASE_ADDR                    0x51009000  // 0x51009000 ~ 0x51009FFF
#define SPI_BASE_ADDR                      0x5100a000  // 0x5100a000 ~ 0x5100aFFF
#define SEL_DATA_BASE_ADDR                 0x5100b000  // 0x5100b000 ~ 0x5100bFFF
#define UART_BASE_ADDR                     0x5100c000  // 0x5100c000 ~ 0x5100cFFF	  25Mhz

#define AHB_SRAM0_BASE_ADDR                0x50000000  // 0x50000000 ~ 0x500FFFFF
#define AHB_SRAM1_BASE_ADDR                0x50100000  // 0x50100000 ~ 0x501FFFFF
#define DPU_RAM_BASE_ADDR                  0x20A00000  // 0x20A00000 ~ 0x20AFFFFF
#define	REF_RAM_BASE_ADDR                  0x50300000  // 0x50300000 ~ 0x504FFFFF
#define DDR_BASE_ADDR                      0x80000000
*/

#define SHIFT_Y_RANGE              13     
#define SHIFT_X_RANGE              256
#define SHITF_Y_BASE               6    //0x18
#define IR_IMG_HEIGHT			   800
#define IR_IMG_WIDTH               1280
#define REF_ADDR_OFFSET	           (((SHITF_Y_BASE - (SHIFT_Y_RANGE >> 1)) * (IR_IMG_WIDTH + SHIFT_X_RANGE) / 8) * 2)
#define REF_SIZE  		           ((IR_IMG_HEIGHT + SHIFT_Y_RANGE - 1) * (IR_IMG_WIDTH + SHIFT_X_RANGE) / 16 - 1)

  
#endif
