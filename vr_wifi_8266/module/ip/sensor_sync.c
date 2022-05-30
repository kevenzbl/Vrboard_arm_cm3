 #include "../include/config.h"
#include "../include/sensor_sync.h"
#include "../include/define.h"	

unsigned int sensor_sync0_get_base_addr(void)
{
    return SENSOR_SYNC0_BASE_ADDR;
}

unsigned int sensor_sync1_get_base_addr(void)
{
    return SENSOR_SYNC1_BASE_ADDR;
}

unsigned int sensor_sync2_get_base_addr(void)
{
    return SENSOR_SYNC2_BASE_ADDR;
}

void sensor_sync_init()
{
    volatile SENSOR_SYNC_T *p_sensor_sync0 = (SENSOR_SYNC_T *)sensor_sync0_get_base_addr();
    volatile SENSOR_SYNC_T *p_sensor_sync1 = (SENSOR_SYNC_T *)sensor_sync1_get_base_addr();
    volatile SENSOR_SYNC_T *p_sensor_sync2 = (SENSOR_SYNC_T *)sensor_sync2_get_base_addr();
    
    volatile SYNC_CFG_U      sync_cfg;    //0x0
    volatile DLY_CNT_U       dly;         //0x4
    volatile SYNC_EN_U       sync_en;     //0x8

    sync_cfg.v = 0;
    sync_cfg.bit_info.pclk_div = 1;
    sync_cfg.bit_info.pulse_y  = 0x2000;
    
    p_sensor_sync0->sync_cfg.v = sync_cfg.v;
    p_sensor_sync1->sync_cfg.v = sync_cfg.v;
    p_sensor_sync2->sync_cfg.v = sync_cfg.v;
    
    dly.bit_info.dly = 0xB2660;
    p_sensor_sync0->dly.v = dly.v;
    p_sensor_sync1->dly.v = dly.v;
    p_sensor_sync2->dly.v = dly.v;
}


void sensor_sync_en(bool intr_en)
{
    volatile SENSOR_SYNC_T *p_sensor_sync0 = (SENSOR_SYNC_T *)sensor_sync0_get_base_addr();
    volatile SENSOR_SYNC_T *p_sensor_sync1 = (SENSOR_SYNC_T *)sensor_sync1_get_base_addr();
    volatile SENSOR_SYNC_T *p_sensor_sync2 = (SENSOR_SYNC_T *)sensor_sync2_get_base_addr();
    
    volatile SYNC_EN_U       sync_en;     //0x8
    
    sync_en.v = p_sensor_sync0->sync_en.v;
    sync_en.bit_info.vs_intr_en = intr_en; 
    sync_en.bit_info.sync_en = 1;
    
    p_sensor_sync0->sync_en.v = sync_en.v;
    p_sensor_sync1->sync_en.v = sync_en.v;
    p_sensor_sync2->sync_en.v = sync_en.v;
}