#include "../include/i2c.h"
#include "../include/gpio.h"
#include "../include/config.h"
#include "../include/define.h"
#include "../include/serial.h"

#define OV9282_ADDR		    0xc0	    //addr is low

extern u8 i2c_scl;
extern u8 i2c_sda;

bool ov9282_read_reg(u16 reg, u8 *pVal)
{
	u32 temp;

    i2c_scl = SCL_I2C2;
    i2c_sda = SDA_I2C2;

	i2cRead(OV9282_ADDR, 2, reg, 1, &temp);
	*pVal = (u16)temp;
    //dbg_printf("read: 0x%04x: 0x%04x\n", reg, *pVal);
		
	return true;
}

bool ov9282_write_reg(u16 reg, u8 data)
{
    i2c_scl = SCL_I2C2;
    i2c_sda = SDA_I2C2;

	//dbg_printf("write: 0x%04x: 0x%04x\n", reg, data);
	i2cWrite(OV9282_ADDR, 2, reg, 1, data);
	
	return true;
}


u16 ov9282_get_id(void)
{
	u8 id_l, id_h;
	ov9282_read_reg(0x300a, &id_h);
	ov9282_read_reg(0x300b, &id_l);
	
	printf("9282_id 0x%x%x\n", id_h, id_l);
	
	return (id_h << 8 | id_l);
}

/*
void ov9282_init()
{
    ov9282_write_reg(0x103, 0x01);
    ov9282_write_reg(0x302, 0x32);
	  ov9282_write_reg(0x303, 0x01);
    ov9282_write_reg(0x30d, 0x50);
    ov9282_write_reg(0x30e, 0x06);
	
    ov9282_write_reg(0x3001, 0x00);
    ov9282_write_reg(0x3004, 0x00);
    ov9282_write_reg(0x3005, 0x00);
    ov9282_write_reg(0x3006, 0x04);
    ov9282_write_reg(0x3011, 0x0a);
    ov9282_write_reg(0x3013, 0x18);
    ov9282_write_reg(0x3022, 0x01);
    ov9282_write_reg(0x3030, 0x10);
    ov9282_write_reg(0x3039, 0x32);
    ov9282_write_reg(0x303a, 0x00);
    ov9282_write_reg(0x3500, 0x00);
    ov9282_write_reg(0x3501, 0x03);
    ov9282_write_reg(0x3502, 0x00);
    ov9282_write_reg(0x3503, 0x7b);
    ov9282_write_reg(0x3505, 0x8c);
    ov9282_write_reg(0x3507, 0x03);
    ov9282_write_reg(0x3508, 0x00);
    ov9282_write_reg(0x3509, 0x10);
    ov9282_write_reg(0x3610, 0x80);
    ov9282_write_reg(0x3611, 0xa0);
    ov9282_write_reg(0x3620, 0x6e);
    ov9282_write_reg(0x3632, 0x56);
    ov9282_write_reg(0x3633, 0x78);
    ov9282_write_reg(0x3662, 0x05);	   //8bit  0x5: 10bit
    ov9282_write_reg(0x3666, 0x00);
    ov9282_write_reg(0x366f, 0x5a);
    ov9282_write_reg(0x3680, 0x84);
    ov9282_write_reg(0x3712, 0x80);
    ov9282_write_reg(0x372d, 0x22);
    ov9282_write_reg(0x3731, 0x80);
    ov9282_write_reg(0x3732, 0x30);
    ov9282_write_reg(0x3778, 0x00);
    ov9282_write_reg(0x377d, 0x22);
    ov9282_write_reg(0x3788, 0x02);
    ov9282_write_reg(0x3789, 0xa4);
    ov9282_write_reg(0x378a, 0x00);
    ov9282_write_reg(0x378b, 0x4a);
    ov9282_write_reg(0x3799, 0x20);
    ov9282_write_reg(0x3800, 0x00);
    ov9282_write_reg(0x3801, 0x00);
    ov9282_write_reg(0x3802, 0x00);
    ov9282_write_reg(0x3803, 0x00);
    ov9282_write_reg(0x3804, 0x05);
    ov9282_write_reg(0x3805, 0x0f);
    ov9282_write_reg(0x3806, 0x03);
    ov9282_write_reg(0x3807, 0x2f);
    ov9282_write_reg(0x3808, 0x05);
    ov9282_write_reg(0x3809, 0x00);
    ov9282_write_reg(0x380a, 0x03);
    ov9282_write_reg(0x380b, 0x20);
    ov9282_write_reg(0x380c, 0x05);	 //0x05b0
    ov9282_write_reg(0x380d, 0x64);		
    ov9282_write_reg(0x380e, 0x03);    // 0x38e
    ov9282_write_reg(0x380f, 0xc0);
    ov9282_write_reg(0x3810, 0x00);
    ov9282_write_reg(0x3811, 0x08);
    ov9282_write_reg(0x3812, 0x00);
    ov9282_write_reg(0x3813, 0x08);
    ov9282_write_reg(0x3814, 0x11);
    ov9282_write_reg(0x3815, 0x11);
    ov9282_write_reg(0x3820, 0x40);
    ov9282_write_reg(0x3821, 0x00);
		ov9282_write_reg(0x382c, 0x05);
		ov9282_write_reg(0x382d, 0xb0);
		ov9282_write_reg(0x389d, 0x00);
		
		
    ov9282_write_reg(0x3881, 0x42);
		ov9282_write_reg(0x3882, 0x01);
		ov9282_write_reg(0x3883, 0x00);
		ov9282_write_reg(0x3885, 0x02);
		ov9282_write_reg(0x38a8, 0x02);
		ov9282_write_reg(0x38a9, 0x80);
				
		
    ov9282_write_reg(0x38b1, 0x00);
		ov9282_write_reg(0x38b3, 0x02);
		
		ov9282_write_reg(0x38c4, 0x00);
		ov9282_write_reg(0x38c5, 0xc0);
		ov9282_write_reg(0x38c6, 0x04);
		ov9282_write_reg(0x38c7, 0x80);

		
    ov9282_write_reg(0x3920, 0xff);
    ov9282_write_reg(0x4003, 0x40);
    ov9282_write_reg(0x4008, 0x04);
    ov9282_write_reg(0x4009, 0x0b);
    ov9282_write_reg(0x400c, 0x00);
    ov9282_write_reg(0x400d, 0x07);
    ov9282_write_reg(0x4010, 0x40);
    ov9282_write_reg(0x4043, 0x40);
    ov9282_write_reg(0x4307, 0x30);
    ov9282_write_reg(0x4317, 0x00);
    ov9282_write_reg(0x4501, 0x00);
    ov9282_write_reg(0x4507, 0x00);
    ov9282_write_reg(0x4509, 0x00);
    ov9282_write_reg(0x450a, 0x08);
    ov9282_write_reg(0x4601, 0x04);
    ov9282_write_reg(0x470f, 0x00);
		
    ov9282_write_reg(0x481c, 0x00);
    ov9282_write_reg(0x481d, 0x6c);
		ov9282_write_reg(0x4821, 0x66);
    ov9282_write_reg(0x4826, 0x1b);
		
		ov9282_write_reg(0x4f07, 0x00);
    ov9282_write_reg(0x4800, 0x20);
		
    ov9282_write_reg(0x5000, 0x9f);
    ov9282_write_reg(0x5001, 0x00);
    ov9282_write_reg(0x5e00, 0x00);
    ov9282_write_reg(0x5d00, 0x07);
    ov9282_write_reg(0x5d01, 0x00);
		
		ov9282_write_reg(0x4f00, 0x04);
    ov9282_write_reg(0x4f10, 0x00);
		ov9282_write_reg(0x4f11, 0x98);
    ov9282_write_reg(0x4f12, 0x0f);
		ov9282_write_reg(0x4f13, 0xc4);
    ov9282_write_reg(0x5a00, 0x00);
		ov9282_write_reg(0x5a01, 0x08);
		ov9282_write_reg(0x5a02, 0x00);
		ov9282_write_reg(0x5a03, 0x00);
		
    ov9282_write_reg(0x100, 0x01);	
}
*/


#if 1
void ov9282_init()
{
	  ov9282_write_reg(0x0103,0x01);
    ov9282_write_reg(0x0302,0x28);
    ov9282_write_reg(0x0303,0x01);
    ov9282_write_reg(0x030d,0x50);
    ov9282_write_reg(0x030e,0x06);
	
    ov9282_write_reg(0x3001,0x00);
    ov9282_write_reg(0x3004,0x00); 
    ov9282_write_reg(0x3005,0x00);
    ov9282_write_reg(0x3006,0x0a);
	  ov9282_write_reg(0x3009,0x0a);
    ov9282_write_reg(0x3011,0x0a);
    ov9282_write_reg(0x3013,0x18);
    ov9282_write_reg(0x3022,0x01);
    ov9282_write_reg(0x3030,0x10);
    ov9282_write_reg(0x3039,0x32);
    ov9282_write_reg(0x303a,0x00);
    ov9282_write_reg(0x3500,0x08); // 0x00
	  ov9282_write_reg(0x3927,0x07);   
	  ov9282_write_reg(0x3928,0x20);  
    ov9282_write_reg(0x3501,0x08); // 0x1
    ov9282_write_reg(0x3502,0xb0); // 0xb0 
    ov9282_write_reg(0x3503,0x08); //0x8
    ov9282_write_reg(0x3505,0x8c);
    ov9282_write_reg(0x3507,0x03);
    ov9282_write_reg(0x3508,0x00);
    ov9282_write_reg(0x3509,0x10);
    ov9282_write_reg(0x3610,0x80);
    ov9282_write_reg(0x3611,0xa0);
    ov9282_write_reg(0x3620,0x6f);
    ov9282_write_reg(0x3632,0x56);
    ov9282_write_reg(0x3633,0x78);
    ov9282_write_reg(0x3662,0x05);
    ov9282_write_reg(0x3666,0x00);
    ov9282_write_reg(0x366f,0x5a);
    ov9282_write_reg(0x3680,0x84);
    ov9282_write_reg(0x3712,0x80);
    ov9282_write_reg(0x372d,0x22);
    ov9282_write_reg(0x3731,0x80);
    ov9282_write_reg(0x3732,0x30);
    ov9282_write_reg(0x3778,0x00);
    ov9282_write_reg(0x377d,0x22);
    ov9282_write_reg(0x3788,0x02);
    ov9282_write_reg(0x3789,0xa4);
    ov9282_write_reg(0x378a,0x00);
    ov9282_write_reg(0x378b,0x4a);
    ov9282_write_reg(0x3799,0x20);
    ov9282_write_reg(0x3800,0x00);
    ov9282_write_reg(0x3801,0x00);
    ov9282_write_reg(0x3802,0x00);
    ov9282_write_reg(0x3803,0x00);
    ov9282_write_reg(0x3804,0x05);
    ov9282_write_reg(0x3805,0x0f);
    ov9282_write_reg(0x3806,0x03);
    ov9282_write_reg(0x3807,0x2f);
    ov9282_write_reg(0x3808,0x05);
    ov9282_write_reg(0x3809,0x00);
    ov9282_write_reg(0x380a,0x03);
    ov9282_write_reg(0x380b,0x20);

		ov9282_write_reg(0x380c, 0x05);	 //0x05b0
    ov9282_write_reg(0x380d, 0x64);
    ov9282_write_reg(0x380e, 0x03);    // 0x38e
    ov9282_write_reg(0x380f, 0xc0);
		
    ov9282_write_reg(0x3810,0x00);
    ov9282_write_reg(0x3811,0x08);
    ov9282_write_reg(0x3812,0x00);
    ov9282_write_reg(0x3813,0x08);
    ov9282_write_reg(0x3814,0x11);
    ov9282_write_reg(0x3815,0x11);
    ov9282_write_reg(0x3820,0x40);
    ov9282_write_reg(0x3821,0x00);
    ov9282_write_reg(0x3881,0x42);
    ov9282_write_reg(0x38b1,0x00);
    ov9282_write_reg(0x3920,0xff);
    ov9282_write_reg(0x4003,0x40);
    ov9282_write_reg(0x4008,0x04);
    ov9282_write_reg(0x4009,0x0b);
    ov9282_write_reg(0x400c,0x00);
    ov9282_write_reg(0x400d,0x07);
    ov9282_write_reg(0x4010,0x40);
    ov9282_write_reg(0x4043,0x40);
    ov9282_write_reg(0x4307,0x30);
    ov9282_write_reg(0x4317,0x00);
    ov9282_write_reg(0x4501,0x00);
    ov9282_write_reg(0x4507,0x00);
    ov9282_write_reg(0x4509,0x00);
    ov9282_write_reg(0x450a,0x08);
    ov9282_write_reg(0x4601,0x04);
    ov9282_write_reg(0x470f,0x00);
    ov9282_write_reg(0x4f07,0x00);
    ov9282_write_reg(0x4800,0x00);
    ov9282_write_reg(0x4837,0x19);
    ov9282_write_reg(0x5000,0x9f);
    ov9282_write_reg(0x5001,0x00);
    ov9282_write_reg(0x5e00,0x00);
    ov9282_write_reg(0x5d00,0x07);
    ov9282_write_reg(0x5d01,0x00);
		
//    ov9282_write_reg(0x0100,0x01);
		
		
#if 0 //trigger mode 
	ov9282_write_reg(0x3666, 0x10); // trigger mode:0x10  normal mode:0x0a
	ov9282_write_reg(0x4f00, 0x01); // trigger mode:0x01  normal mode:0x00 
	ov9282_write_reg(0x3030, 0x84); // trigger mode:0x84  normal mode:0x10
		
	ov9282_write_reg(0x303f, 0x01); // frame number by one trigger action
	ov9282_write_reg(0x3023, 0x07);
#else
	ov9282_write_reg(0x3666, 0x0a);
	ov9282_write_reg(0x4f00, 0x00); 
	ov9282_write_reg(0x3030, 0x10);

	ov9282_write_reg(0x0100, 0x01); // stream on
#endif
}
#endif

void ov9282_enable(bool bEn)
{
//   gpioOutData(IO_CMOS_COLOR_PDN, bEn ? 0 : 1);
}
