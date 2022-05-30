#ifndef __BMG160_SUPPORT_H__
#define __BMG160_SUPPORT_H__

#include "..\include\define.h"

/* This function is an example for reading sensor data
 *  \param: None
 *  \return: communication result
 */

#define BMG160_API

/*---------------------------------------------------------------------------*
*  The following functions are used for reading and writing of
*   sensor data using I2C or SPI communication
*---------------------------------------------------------------------------*/
#ifdef BMG160_API

/*  \Brief: The function is used as I2C bus read
 *  \Return : Status of the I2C read
 *  \param dev_addr : The device address of the sensor
 *  \param reg_addr : Address of the first register, will data is going to be read
 *  \param reg_data : This data read from the sensor, which is hold in an array
 *  \param cnt : The no of byte of data to be read
 */
s8 BMG160_I2C_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);

/*  \Brief: The function is used as I2C bus write
 *  \Return : Status of the I2C write
 *  \param dev_addr : The device address of the sensor
 *  \param reg_addr : Address of the first register, will data is going to be written
 *  \param reg_data : It is a value hold in the array,
 *      will be used for write the value into the register
 *  \param cnt : The no of byte of data to be write
 */
s8 BMG160_I2C_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);

/*  \Brief: The function is used as SPI bus write
 *  \Return : Status of the SPI write
 *  \param dev_addr : The device address of the sensor
 *  \param reg_addr : Address of the first register, will data is going to be written
 *  \param reg_data : It is a value hold in the array,
 *      will be used for write the value into the register
 *  \param cnt : The no of byte of data to be write
 */
s8 BMG160_SPI_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);

/*  \Brief: The function is used as SPI bus read
 *  \Return : Status of the SPI read
 *  \param dev_addr : The device address of the sensor
 *  \param reg_addr : Address of the first register, will data is going to be read
 *  \param reg_data : This data read from the sensor, which is hold in an array
 *  \param cnt : The no of byte of data to be read
 */
s8 BMG160_SPI_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);

/*
 * \Brief: SPI/I2C init routine
 */
s8 BMG160_I2C_routine(void);
s8 BMG160_SPI_routine(void);

#endif

/********************End of I2C/SPI function declarations***********************/

typedef struct
{
    short x;
    short y;
    short z;
} BMG160_DATAOUT;
 
int bmg160_data_readout_template(void);
int bmg160_enable(void);
int bmg160_data_readout(BMG160_DATAOUT *gyro_data);

#endif
