				#ifndef __SENSOR_SYNC_H__
#define __SENSOR_SYNC_H__

typedef union SYNC_CFG_U_ 
{
	 unsigned long v;
	 struct SYNC_CFG_T_ 
	 {
		 unsigned pclk_div                 : 16;
		 unsigned pulse_y                  : 14;
		 unsigned sync_mode                : 1;
		 unsigned polarity                 : 1;
	 }bit_info; 
} SYNC_CFG_U;                                  //0x0

typedef union DLY_CNT_U_ 
{
	 unsigned long v;
	 struct DLY_CNT_T_ 
	 {
		 unsigned dly                      : 32;
	 }bit_info; 
} DLY_CNT_U;                                  //0x4

typedef union SYNC_EN_U_ 
{
	 unsigned long v;
	 struct SYNC_EN_T_ 
	 {
		 unsigned sync_en                  : 1;
		 unsigned vs_intr_en               : 1;
		 unsigned single                   : 1;
	 }bit_info; 
} SYNC_EN_U;                                  //0x8


typedef struct SENSOR_SYNC_T_ 
{ 
    SYNC_CFG_U      sync_cfg;    //0x0
    DLY_CNT_U       dly;         //0x4
    SYNC_EN_U       sync_en;     //0x8
} SENSOR_SYNC_T;

#endif