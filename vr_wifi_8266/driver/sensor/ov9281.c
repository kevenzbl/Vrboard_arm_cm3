#include <stdio.h>
#include "i2c.h"
#include "gpio.h"
#include "config.h"
#include "define.h"
#include "serial.h"
#include "camera_sensor.h"

#define OV9281_ADDR		    0xc0	    

extern u8 i2c_scl;
extern u8 i2c_sda;

void ov9281_l_reset()
{
    gpio_out_data(CMR0_RST, 0);
    delay_ms(10);
    gpio_out_data(CMR0_RST, 1);
    delay_ms(10);
}

bool ov9281_l_read_reg(u16 reg, u8 *pVal)
{
	u32 temp = 2;

    i2c_scl = SCL_I2C0;
    i2c_sda = SDA_I2C0;

	  i2cRead(OV9281_ADDR, 2, reg, 1, &temp);

	*pVal = (u16)temp;

   // printf("read: 0x%04x: 0x%04x\n", reg, *pVal);
	return true;
}

bool ov9281_l_write_reg(u16 reg, u8 data)
{
    i2c_scl = SCL_I2C0;
    i2c_sda = SDA_I2C0;

	//dbg_printf("write: 0x%04x: 0x%04x\n", reg, data);
	i2cWrite(OV9281_ADDR, 2, reg, 1, data);
	
	return true;
}

bool ov9281_r_read_reg(u16 reg, u8 *pVal)
{
	u32 temp;

    i2c_scl = SCL_I2C1;
    i2c_sda = SDA_I2C1;

	i2cRead(OV9281_ADDR, 2, reg, 1, &temp);
	*pVal = (u16)temp;

	return true;
}

bool ov9281_r_write_reg(u16 reg, u8 data)
{
    i2c_scl = SCL_I2C1;
    i2c_sda = SDA_I2C1;

	//dbg_printf("write: 0x%04x: 0x%04x\n", reg, data);
	i2cWrite(OV9281_ADDR, 2, reg, 1, data);
	
	return true;
}

u16 ov9281_l_get_id(void)
{
	u8 id_l, id_h;
	ov9281_l_read_reg(0x300a, &id_h);
	ov9281_l_read_reg(0x300b, &id_l);
	
	printf("9281_l_id 0x%x%x\n", id_h, id_l);
	
	return (id_h << 8 | id_l);
}

u16 ov9281_r_get_id(void)
{
	u8 id_l, id_h;
	ov9281_r_read_reg(0x300a, &id_h);
	ov9281_r_read_reg(0x300b, &id_l);
	
	printf("9281_r_id 0x%x%x\n", id_h, id_l);
	
	return (id_h << 8 | id_l);
}

void ov9281_init_1()
{
    ov9281_l_write_reg(0x103, 0x01);
    ov9281_l_write_reg(0x302, 0x32);
    ov9281_l_write_reg(0x30d, 0x60);
    ov9281_l_write_reg(0x30e, 0x02);
    ov9281_l_write_reg(0x3001, 0x00);
    ov9281_l_write_reg(0x3004, 0x00);
    ov9281_l_write_reg(0x3005, 0x00);
    ov9281_l_write_reg(0x3006, 0x04);
    ov9281_l_write_reg(0x3011, 0x0a);
    ov9281_l_write_reg(0x3013, 0x18);
    ov9281_l_write_reg(0x3022, 0x01);  //ov9281_l_write_reg(0x3022, 0x01); 0x41
	
	ov9281_l_write_reg(0x4F00, 0x01);	  
	ov9281_l_write_reg(0x3030, 0x04); // bit2: trigger mode;  ov9281_l_write_reg(0x3030, 0x10);
	ov9281_l_write_reg(0x303F, 0x01);
	//ov9281_l_write_reg(0x3023, 0x00);
	
	
    ov9281_l_write_reg(0x3039, 0x32);
    ov9281_l_write_reg(0x303a, 0x00);
    ov9281_l_write_reg(0x3500, 0x00);
    //ov9281_l_write_reg(0x3501, 0x1f);  // expo time
	ov9281_l_write_reg(0x3501, 0x2f);  // expo time
    ov9281_l_write_reg(0x3502, 0x00);
    ov9281_l_write_reg(0x3503, 0x08);
    ov9281_l_write_reg(0x3505, 0x8c);
    ov9281_l_write_reg(0x3507, 0x03);
    ov9281_l_write_reg(0x3508, 0x00);
    ov9281_l_write_reg(0x3509, 0x10); // gain
    ov9281_l_write_reg(0x3610, 0x80);
    ov9281_l_write_reg(0x3611, 0xa0);
    ov9281_l_write_reg(0x3620, 0x6f);
    ov9281_l_write_reg(0x3632, 0x56);
    ov9281_l_write_reg(0x3633, 0x78);
    ov9281_l_write_reg(0x3662, 0x07);	   //07:8bit  0x5: 10bit
    ov9281_l_write_reg(0x3666, 0x00);
    ov9281_l_write_reg(0x366f, 0x5a);
    ov9281_l_write_reg(0x3680, 0x84);
    ov9281_l_write_reg(0x3712, 0x80);
    ov9281_l_write_reg(0x372d, 0x22);
    ov9281_l_write_reg(0x3731, 0x80);
    ov9281_l_write_reg(0x3732, 0x30);
    ov9281_l_write_reg(0x3778, 0x00);
    ov9281_l_write_reg(0x377d, 0x22);
    ov9281_l_write_reg(0x3788, 0x02);
    ov9281_l_write_reg(0x3789, 0xa4);
    ov9281_l_write_reg(0x378a, 0x00);
    ov9281_l_write_reg(0x378b, 0x4a);
    ov9281_l_write_reg(0x3799, 0x20);
    ov9281_l_write_reg(0x3800, 0x00);
    ov9281_l_write_reg(0x3801, 0x00);
    ov9281_l_write_reg(0x3802, 0x00);
    ov9281_l_write_reg(0x3803, 0x00);
    ov9281_l_write_reg(0x3804, 0x05);
    ov9281_l_write_reg(0x3805, 0x0f);
    ov9281_l_write_reg(0x3806, 0x03);
    ov9281_l_write_reg(0x3807, 0x2f);
    ov9281_l_write_reg(0x3808, 0x05);
    ov9281_l_write_reg(0x3809, 0x00);
    ov9281_l_write_reg(0x380a, 0x03);
    ov9281_l_write_reg(0x380b, 0x20);
    ov9281_l_write_reg(0x380c, 0x02);	 //0x05b0
    ov9281_l_write_reg(0x380d, 0xd8);
    ov9281_l_write_reg(0x380e, 0x03);  // 0x38e
    ov9281_l_write_reg(0x380f, 0x8e);
    ov9281_l_write_reg(0x3810, 0x00);
    ov9281_l_write_reg(0x3811, 0x08);
    ov9281_l_write_reg(0x3812, 0x00);
    ov9281_l_write_reg(0x3813, 0x08);
    ov9281_l_write_reg(0x3814, 0x11);
    ov9281_l_write_reg(0x3815, 0x11);
    ov9281_l_write_reg(0x3820, 0x40);
    ov9281_l_write_reg(0x3821, 0x00);
    ov9281_l_write_reg(0x3881, 0x42);
    ov9281_l_write_reg(0x38b1, 0x00);
    ov9281_l_write_reg(0x3920, 0xff);
    ov9281_l_write_reg(0x4003, 0x40);
    ov9281_l_write_reg(0x4008, 0x04);
    ov9281_l_write_reg(0x4009, 0x0b);
    ov9281_l_write_reg(0x400c, 0x00);
    ov9281_l_write_reg(0x400d, 0x07);
    ov9281_l_write_reg(0x4010, 0x40);
    ov9281_l_write_reg(0x4043, 0x40);
    ov9281_l_write_reg(0x4307, 0x30);
    ov9281_l_write_reg(0x4317, 0x00);
    ov9281_l_write_reg(0x4501, 0x00);
    ov9281_l_write_reg(0x4507, 0x00);
    ov9281_l_write_reg(0x4509, 0x00);
    ov9281_l_write_reg(0x450a, 0x08);
    ov9281_l_write_reg(0x4601, 0x04);
    ov9281_l_write_reg(0x470f, 0x00);
    ov9281_l_write_reg(0x4f07, 0x00);
    ov9281_l_write_reg(0x4800, 0x00);
    ov9281_l_write_reg(0x5000, 0x9f);
    ov9281_l_write_reg(0x5001, 0x00);
    ov9281_l_write_reg(0x5e00, 0x00);
    ov9281_l_write_reg(0x5d00, 0x07);
    ov9281_l_write_reg(0x5d01, 0x00);
		
	//*  colorbar enable
	/*
	ov9281_l_write_reg(0x5e00, 0x80);
	ov9281_l_write_reg(0x4320, 0x80);
	ov9281_l_write_reg(0x4322, 0x03);
	ov9281_l_write_reg(0x4323, 0x9a);
	ov9281_l_write_reg(0x4324, 0x03);
	ov9281_l_write_reg(0x4325, 0x9a);
	ov9281_l_write_reg(0x4326, 0x03);
	ov9281_l_write_reg(0x4327, 0x9a);
	ov9281_l_write_reg(0x4328, 0x03);
	ov9281_l_write_reg(0x4329, 0x9a);
	*/
		
		
    //ov9281_l_write_reg(0x100, 0x01);
}

void ov9281_init_r()
{
    ov9281_r_write_reg(0x103, 0x01);
    ov9281_r_write_reg(0x302, 0x32);
    ov9281_r_write_reg(0x30d, 0x60);
    ov9281_r_write_reg(0x30e, 0x02);
    ov9281_r_write_reg(0x3001, 0x00);
    ov9281_r_write_reg(0x3004, 0x00);
    ov9281_r_write_reg(0x3005, 0x00);
    ov9281_r_write_reg(0x3006, 0x04);
    ov9281_r_write_reg(0x3011, 0x0a);
    ov9281_r_write_reg(0x3013, 0x18);
    ov9281_r_write_reg(0x3022, 0x01);  //ov9281_r_write_reg(0x3022, 0x01); 0x41
	
	ov9281_r_write_reg(0x4F00, 0x01);
	ov9281_r_write_reg(0x3030, 0x04);  // ov9281_r_write_reg(0x3030, 0x10);
	ov9281_r_write_reg(0x303F, 0x01);
	
    ov9281_r_write_reg(0x3039, 0x32);
    ov9281_r_write_reg(0x303a, 0x00);
    ov9281_r_write_reg(0x3500, 0x00);
	//ov9281_r_write_reg(0x3501, 0x1f); // expo time
	ov9281_r_write_reg(0x3501, 0x2f); // expo time
    ov9281_r_write_reg(0x3502, 0x00);
    ov9281_r_write_reg(0x3503, 0x08);
    ov9281_r_write_reg(0x3505, 0x8c);
    ov9281_r_write_reg(0x3507, 0x03);
    ov9281_r_write_reg(0x3508, 0x00);
    ov9281_r_write_reg(0x3509, 0x10); // gain
    ov9281_r_write_reg(0x3610, 0x80);
    ov9281_r_write_reg(0x3611, 0xa0);
    ov9281_r_write_reg(0x3620, 0x6f);
    ov9281_r_write_reg(0x3632, 0x56);
    ov9281_r_write_reg(0x3633, 0x78);
    ov9281_r_write_reg(0x3662, 0x07);	   //8bit  0x5: 10bit
    ov9281_r_write_reg(0x3666, 0x00);
    ov9281_r_write_reg(0x366f, 0x5a);
    ov9281_r_write_reg(0x3680, 0x84);
    ov9281_r_write_reg(0x3712, 0x80);
    ov9281_r_write_reg(0x372d, 0x22);
    ov9281_r_write_reg(0x3731, 0x80);
    ov9281_r_write_reg(0x3732, 0x30);
    ov9281_r_write_reg(0x3778, 0x00);
    ov9281_r_write_reg(0x377d, 0x22);
    ov9281_r_write_reg(0x3788, 0x02);
    ov9281_r_write_reg(0x3789, 0xa4);
    ov9281_r_write_reg(0x378a, 0x00);
    ov9281_r_write_reg(0x378b, 0x4a);
    ov9281_r_write_reg(0x3799, 0x20);
    ov9281_r_write_reg(0x3800, 0x00);
    ov9281_r_write_reg(0x3801, 0x00);
    ov9281_r_write_reg(0x3802, 0x00);
    ov9281_r_write_reg(0x3803, 0x00);
    ov9281_r_write_reg(0x3804, 0x05);
    ov9281_r_write_reg(0x3805, 0x0f);
    ov9281_r_write_reg(0x3806, 0x03);
    ov9281_r_write_reg(0x3807, 0x2f);
    ov9281_r_write_reg(0x3808, 0x05);
    ov9281_r_write_reg(0x3809, 0x00);
    ov9281_r_write_reg(0x380a, 0x03);
    ov9281_r_write_reg(0x380b, 0x20);
    ov9281_r_write_reg(0x380c, 0x02);	 //0x05b0
    ov9281_r_write_reg(0x380d, 0xd8);
    ov9281_r_write_reg(0x380e, 0x03);  // 0x38e
    ov9281_r_write_reg(0x380f, 0x8e);
    ov9281_r_write_reg(0x3810, 0x00);
    ov9281_r_write_reg(0x3811, 0x08);
    ov9281_r_write_reg(0x3812, 0x00);
    ov9281_r_write_reg(0x3813, 0x08);
    ov9281_r_write_reg(0x3814, 0x11);
    ov9281_r_write_reg(0x3815, 0x11);
    ov9281_r_write_reg(0x3820, 0x40);
    ov9281_r_write_reg(0x3821, 0x00);
    ov9281_r_write_reg(0x3881, 0x42);
    ov9281_r_write_reg(0x38b1, 0x00);
    ov9281_r_write_reg(0x3920, 0xff);
    ov9281_r_write_reg(0x4003, 0x40);
    ov9281_r_write_reg(0x4008, 0x04);
    ov9281_r_write_reg(0x4009, 0x0b);
    ov9281_r_write_reg(0x400c, 0x00);
    ov9281_r_write_reg(0x400d, 0x07);
    ov9281_r_write_reg(0x4010, 0x40);
    ov9281_r_write_reg(0x4043, 0x40);
    ov9281_r_write_reg(0x4307, 0x30);
    ov9281_r_write_reg(0x4317, 0x00);
    ov9281_r_write_reg(0x4501, 0x00);
    ov9281_r_write_reg(0x4507, 0x00);
    ov9281_r_write_reg(0x4509, 0x00);
    ov9281_r_write_reg(0x450a, 0x08);
    ov9281_r_write_reg(0x4601, 0x04);
    ov9281_r_write_reg(0x470f, 0x00);
    ov9281_r_write_reg(0x4f07, 0x00);
    ov9281_r_write_reg(0x4800, 0x00);
    ov9281_r_write_reg(0x5000, 0x9f);
    ov9281_r_write_reg(0x5001, 0x00);
    ov9281_r_write_reg(0x5e00, 0x00);
    ov9281_r_write_reg(0x5d00, 0x07);
    ov9281_r_write_reg(0x5d01, 0x00);
		
	//*  colorbar enable
	/*
	ov9281_r_write_reg(0x5e00, 0x80);
	ov9281_r_write_reg(0x4320, 0x80);
	ov9281_r_write_reg(0x4322, 0x03);
	ov9281_r_write_reg(0x4323, 0x9a);
	ov9281_r_write_reg(0x4324, 0x03);
	ov9281_r_write_reg(0x4325, 0x9a);
	ov9281_r_write_reg(0x4326, 0x03);
	ov9281_r_write_reg(0x4327, 0x9a);
	ov9281_r_write_reg(0x4328, 0x03);
	ov9281_r_write_reg(0x4329, 0x9a);
	*/
		
		
    //ov9281_r_write_reg(0x100, 0x01);
}

void ov9281_l_enable(bool bEn)
{

}

void ov9281_r_enable(bool bEn)
{

}

#if 0
void ov9281_init_1M_1280x800_8bit_linear30(VI_PIPE ViPipe)
{
    ov9281_write_register(ViPipe,0x0103, 0x01);
	ov9281_write_register(ViPipe,0x0302, 0x28);//0x32  20190117
	ov9281_write_register(ViPipe,0x0305, 0x02);//
	ov9281_write_register(ViPipe,0x030b, 0x04);//
	ov9281_write_register(ViPipe,0x030d, 0x50);
	ov9281_write_register(ViPipe,0x030e, 0x02);//
	ov9281_write_register(ViPipe,0x030f, 0x04);//0x03 20190117
	ov9281_write_register(ViPipe,0x3001, 0x00);
	ov9281_write_register(ViPipe,0x3004, 0x00);
	ov9281_write_register(ViPipe,0x3005, 0x00);
	ov9281_write_register(ViPipe,0x3006, 0x04);//
	ov9281_write_register(ViPipe,0x3011, 0x0a);
	ov9281_write_register(ViPipe,0x3013, 0x18);
	ov9281_write_register(ViPipe,0x3022, 0x01);
	ov9281_write_register(ViPipe,0x3030, 0x10);
	ov9281_write_register(ViPipe,0x3039, 0x32);
	ov9281_write_register(ViPipe,0x303a, 0x00);
	ov9281_write_register(ViPipe,0x3500, 0x00); 
	ov9281_write_register(ViPipe,0x3501, 0x2a);
	ov9281_write_register(ViPipe,0x3502, 0x90);
	ov9281_write_register(ViPipe,0x3503, 0x08);
	ov9281_write_register(ViPipe,0x3505, 0x8c);
	ov9281_write_register(ViPipe,0x3507, 0x03);
	ov9281_write_register(ViPipe,0x3508, 0x00);
	ov9281_write_register(ViPipe,0x3509, 0x10);
	ov9281_write_register(ViPipe,0x3610, 0x80);
	ov9281_write_register(ViPipe,0x3611, 0xa0);
	ov9281_write_register(ViPipe,0x3620, 0x6f);
	ov9281_write_register(ViPipe,0x3632, 0x56);
	ov9281_write_register(ViPipe,0x3633, 0x78);
	ov9281_write_register(ViPipe,0x3662, 0x05);
	ov9281_write_register(ViPipe,0x3666, 0x00);
	ov9281_write_register(ViPipe,0x366f, 0x5a);
	ov9281_write_register(ViPipe,0x3680, 0x84);
	ov9281_write_register(ViPipe,0x3712, 0x80);
	ov9281_write_register(ViPipe,0x372d, 0x22);
	ov9281_write_register(ViPipe,0x3731, 0x80);
	ov9281_write_register(ViPipe,0x3732, 0x30);
	ov9281_write_register(ViPipe,0x3778, 0x00);
	ov9281_write_register(ViPipe,0x377d, 0x22);
	ov9281_write_register(ViPipe,0x3788, 0x02);
	ov9281_write_register(ViPipe,0x3789, 0xa4);
	ov9281_write_register(ViPipe,0x378a, 0x00);
	ov9281_write_register(ViPipe,0x378b, 0x4a);
	ov9281_write_register(ViPipe,0x3799, 0x20);

	ov9281_write_register(ViPipe,0x3800, 0x00);
	ov9281_write_register(ViPipe,0x3801, 0x00);
	ov9281_write_register(ViPipe,0x3802, 0x00);
	ov9281_write_register(ViPipe,0x3803, 0x00);
	ov9281_write_register(ViPipe,0x3804, 0x05);
	ov9281_write_register(ViPipe,0x3805, 0x0f);
	ov9281_write_register(ViPipe,0x3806, 0x03);
	ov9281_write_register(ViPipe,0x3807, 0x2f);

	ov9281_write_register(ViPipe,0x3808, 0x05);
	ov9281_write_register(ViPipe,0x3809, 0x00);
	ov9281_write_register(ViPipe,0x380a, 0x03);
	ov9281_write_register(ViPipe,0x380b, 0x20);
	ov9281_write_register(ViPipe,0x380c, 0x05);
	ov9281_write_register(ViPipe,0x380d, 0xB0);
	ov9281_write_register(ViPipe,0x380e, 0x04); //05 20190117
	ov9281_write_register(ViPipe,0x380f, 0x44); //5d 20190117
	ov9281_write_register(ViPipe,0x3810, 0x00);
	ov9281_write_register(ViPipe,0x3811, 0x08);
	ov9281_write_register(ViPipe,0x3812, 0x00);
	ov9281_write_register(ViPipe,0x3813, 0x08);
	ov9281_write_register(ViPipe,0x3814, 0x11);
	ov9281_write_register(ViPipe,0x3815, 0x11);

	ov9281_write_register(ViPipe,0x3820, 0x40);
	ov9281_write_register(ViPipe,0x3821, 0x00);

	ov9281_write_register(ViPipe,0x3881, 0x42);
	ov9281_write_register(ViPipe,0x38b1, 0x00);

	ov9281_write_register(ViPipe,0x3920, 0xff);
	ov9281_write_register(ViPipe,0x3921, 0x00);
	ov9281_write_register(ViPipe,0x3922, 0x00);
	ov9281_write_register(ViPipe,0x3923, 0x00);
	ov9281_write_register(ViPipe,0x3924, 0x00);

	ov9281_write_register(ViPipe,0x3929, 0x00);
	ov9281_write_register(ViPipe,0x392a, 0x00);
	ov9281_write_register(ViPipe,0x392c, 0x00);

	ov9281_write_register(ViPipe,0x4003, 0x40);
	ov9281_write_register(ViPipe,0x4008, 0x04);
	ov9281_write_register(ViPipe,0x4009, 0x0b);
	ov9281_write_register(ViPipe,0x400c, 0x00);
	ov9281_write_register(ViPipe,0x400d, 0x07);
	ov9281_write_register(ViPipe,0x4010, 0x40);
	ov9281_write_register(ViPipe,0x4043, 0x40);
	ov9281_write_register(ViPipe,0x4307, 0x30);



	ov9281_write_register(ViPipe,0x3006, 0x08);
	ov9281_write_register(ViPipe,0x3b81, 0xff);
	ov9281_write_register(ViPipe,0x392f, 0xC0);


	ov9281_write_register(ViPipe,0x3927, 0x00);
	ov9281_write_register(ViPipe,0x3928, 0x80);

	ov9281_write_register(ViPipe,0x4317, 0x00);
	ov9281_write_register(ViPipe,0x4501, 0x00);
	ov9281_write_register(ViPipe,0x4507, 0x00);
	ov9281_write_register(ViPipe,0x4509, 0x00);
	ov9281_write_register(ViPipe,0x450a, 0x08);
	ov9281_write_register(ViPipe,0x4601, 0x04);
	ov9281_write_register(ViPipe,0x4708, 0x0B);
	ov9281_write_register(ViPipe,0x470f, 0x00);
	ov9281_write_register(ViPipe,0x4f07, 0x00);


	ov9281_write_register(ViPipe,0x4800, 0x00);
	ov9281_write_register(ViPipe,0x5000, 0x9f);
	ov9281_write_register(ViPipe,0x5001, 0x00);
	ov9281_write_register(ViPipe,0x5e00, 0x00);
	ov9281_write_register(ViPipe,0x5d00, 0x07);
	ov9281_write_register(ViPipe,0x5d01, 0x00);


	

    //ov9281_default_reg_init(ViPipe);
    ov9281_write_register(ViPipe, 0x0100, 0x01);

    ov9281_write_register(ViPipe, 0x0100, 0x00);

    ov9281_write_register(ViPipe, 0x0100, 0x01);
	
    printf("-------OV 9281_init_1M_1280x800_10bit_nonewdr30 Initial OK!-------\n");
}
#endif
