#include "../include/i2c.h"
#include "../include/gpio.h"
#include "../include/config.h"
#include "../include/define.h"
#include "../include/serial.h"

#define LM3644_ADDR		    0xc6	    

extern u8 i2c_scl;
extern u8 i2c_sda;
/*
void delay_ms(u32 ms)
{
	volatile int i;

	while(ms--){
		i = 2500;
		while(i--);
	}
}
*/
void lm3644_en()
{
    gpio_out_data(LM_HW_EN, 1);
    delay_ms(10);
}

bool lm3644_read_reg(u8 reg, u8 *pVal)
{
	  u32 temp = 2;

    i2c_scl = SCL_I2C3;
    i2c_sda = SDA_I2C3;

	  i2cRead(LM3644_ADDR, 1, reg, 1, &temp);

	  *pVal = (u16)temp;

   // printf("read: 0x%04x: 0x%04x\n", reg, *pVal);
	  return true;
}

bool lm3644_write_reg(u8 reg, u8 data)
{
    i2c_scl = SCL_I2C3;
    i2c_sda = SDA_I2C3;

	//dbg_printf("write: 0x%04x: 0x%04x\n", reg, data);
	i2cWrite(LM3644_ADDR, 1, reg, 1, data);
	
	return true;
}

void lm3644_init()
{
	lm3644_write_reg(0x08, 0);
	lm3644_write_reg(0x03, 0x36);
	lm3644_write_reg(0x04, 0x36);
	lm3644_write_reg(0x01, 0xa7);    
}
