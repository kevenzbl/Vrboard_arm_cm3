#ifndef _I2C_H_
#define _I2C_H_

#include "../include/gpio.h"
#include "../include/define.h"

#define    I2C_SCL(val)                    gpio_out_data(i2c_scl, val)      //IIC时钟引脚定义
#define    I2C_SDA(val)                    gpio_out_data(i2c_sda, val)      //IIC数据引脚定义
#define    I2C_SET_GPIO_DIRECTION_IN()     gpio_set_dir_in(i2c_sda)
#define    I2C_GET_GPIO_VALUE()            gpio_in_data(i2c_sda)


void i2cStart(void);
u8 i2cSendByte(u8 dat);
void i2cStop(void);
u8 i2cSendByte(u8 dat);

u8    singleRead(u8 reg);                   //单个读取内部寄存器数据
void  singleWrite(u8 reg, u8 data);        //单个写入数据
void  multipleRead(u8 reg, u8 *buf, u8 nBytes);                         //连续的读取内部寄存器数据
void  multipleWrite(u8 regH, u8 regL, u8 dataH, u8 dataL);
void i2cWrite(u8 slave_Addr, u32 regLen, u32 reg, u32 dataLen, u32 data);
void i2cRead(u8 slave_Addr, u32 regLen, u32 reg, u32 dataLen, u32 *pData);

#endif
