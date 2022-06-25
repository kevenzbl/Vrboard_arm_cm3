/****************************************************************************/
/* Project: Glass                                                           */
/*                                                                          */
/* Copyright ? 2020, Visinse. All Rights Reserved.                          */
/*                                                                          */
/* File        : imu.c                                                      */
/* Author      : Hoki                                                       */
/*                                                                          */
/* Description : Driver for IMU sensor                                      */
/*                                                                          */
/****************************************************************************/

#include "peripheral.h"
#include "spi.h"
#include "ssp.h"

#include "imu.h"
#include <string.h>

//***************************************************************************
// Definition
typedef union IMU_CS_SEL   //0x24
{
	unsigned int v;
	struct IMU_CS_SEL_T
	{
		unsigned acc    :1;   // [0]:  
		unsigned gyr    :1;   // [1]:  
		unsigned mag    :1;   // [2]:  
	}bit_info;
} IMU_CS_SEL;

#define IMU_SEL_ACC     0x01
#define IMU_SEL_GYR     0x02
#define IMU_SEL_MAG     0x04

typedef struct  {
    unsigned short nMagic;
    unsigned short nType;
    unsigned short nPacketID;
    unsigned short nBufSize;
    unsigned int   nTimeStamp;
} IMU_HEADER;

typedef struct
{
    IMU_HEADER     sImu_Header;
    BMA2X2_DATAOUT accel_data;
    BMG160_DATAOUT gyro_data;
}IMU_PKG;

//***************************************************************************
// Global Variables
IMU_PKG    sImu_Pkg;

//***************************************************************************
// Sensor Select
void imu_sensor_sel(unsigned int imu_sel)
{
    IMU_CS_SEL* psImuSel = (IMU_CS_SEL*)IMU_SENSOR_ADDR;

    switch(imu_sel)
    {
        case IMU_SEL_ACC:
            // Sensor ACC
            psImuSel->bit_info.acc = 1;
            psImuSel->bit_info.gyr = 0;
            psImuSel->bit_info.mag = 0;
            break;
        case IMU_SEL_GYR:
            // Sensor GYR
            psImuSel->bit_info.acc = 0;
            psImuSel->bit_info.gyr = 1;
            psImuSel->bit_info.mag = 0;
            break;
        case IMU_SEL_MAG:
            // Sensor MAG
            psImuSel->bit_info.acc = 0;
            psImuSel->bit_info.gyr = 0;
            psImuSel->bit_info.mag = 1;
            break;
        default:
            psImuSel->bit_info.acc = 0;
            psImuSel->bit_info.gyr = 0;
            psImuSel->bit_info.mag = 0;
    }
}


//***************************************************************************
// IMU Init
void imu_init(void)
{
	volatile int dly = 0xffff;
	
	spi_init();
    imu_sensor_sel(IMU_SEL_ACC);
    bma2x2_enable();            while(dly--);
    imu_sensor_sel(IMU_SEL_GYR);    dly = 0xffff; while(dly--);
    bmg160_enable();
	
	sImu_Pkg.gyro_data.x = 0xff;	
//    imu_sensor_sel(IMU_SEL_MAG);
//    bmm150_enable();

    *(unsigned int*)IMU_PKGLEN_ADDR = 0x6; // package length
  
    sImu_Pkg.sImu_Header.nMagic = 0x8FAA;
    sImu_Pkg.sImu_Header.nType  = 0x8800;
    sImu_Pkg.sImu_Header.nPacketID = 0;
    sImu_Pkg.sImu_Header.nBufSize = 12;
}    


//***************************************************************************
// IMU Run
void imu_run(unsigned int timestamp)
{
	volatile int dly = 0xffffff;
    
    sImu_Pkg.sImu_Header.nPacketID++;
    sImu_Pkg.sImu_Header.nTimeStamp = timestamp;

    // Sensor ACC
    imu_sensor_sel(IMU_SEL_ACC);
    bma2x2_data_readout(&sImu_Pkg.accel_data);
        
    // Sensor GYR
    imu_sensor_sel(IMU_SEL_GYR);
    bmg160_data_readout(&sImu_Pkg.gyro_data);
        
        // Sensor MAG
//        psImuSel->bit_info.acc = 0;
//        psImuSel->bit_info.gyr = 0;
//        psImuSel->bit_info.mag = 1;
//        bmm150_data_readout_template();
 
    memcpy((unsigned int*)IMU_PKGFIFO_ADDR, (unsigned int*)&sImu_Pkg, sizeof(sImu_Pkg));
		
		//	 printf("%8d %8d %8d %8d %8d %8d\n", sImu_Pkg.gyro_data.x, sImu_Pkg.gyro_data.y, sImu_Pkg.gyro_data.z, sImu_Pkg.accel_data.x, sImu_Pkg.accel_data.y, sImu_Pkg.accel_data.z);
}
