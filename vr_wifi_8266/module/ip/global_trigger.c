#include "../include/config.h"
#include "../include/define.h"
#include "../include/global_trigger.h"

unsigned int global_trigger_get_base_addr(void)
{
    return GLOBAL_TRIGGER_BASE_ADDR;
}

void global_trigger_init()
{
    volatile GLOBAL_TRIGGER_T *p_glb_trig = (GLOBAL_TRIGGER_T *)global_trigger_get_base_addr();
    volatile TRIG0_U       trig0;    //0x0
    volatile TRIG1_U       trig1;    //0x0
    volatile TRIG2_U       trig2;    //0x0
    volatile TRIG3_U       trig3;    //0x0
    volatile TRIG4_U       trig4;    //0x0
    volatile VS_CFG_U      vs_cfg;   //0x14
    volatile TRIG_EN_U     trig_en;  //0x18

    trig0.v = 0;
    trig0.bit_info.glb_cnt = 0x196E69;
    trig0.bit_info.vs_cnt = 0;
    p_glb_trig->trig0.v = trig0.v;  
    
    trig1.v = 0;
    trig1.bit_info.glb_cnt = 0x196E69;
    trig1.bit_info.vs_cnt = 0;
    p_glb_trig->trig1.v = trig1.v;

    trig2.v = 0;
    trig2.bit_info.glb_cnt = 0x196E69;
    trig2.bit_info.vs_cnt = 0;
    p_glb_trig->trig2.v = trig2.v;

    trig3.v = 0;
    trig3.bit_info.glb_cnt = 0x196E69;
    trig3.bit_info.vs_cnt = 0;
    p_glb_trig->trig3.v = trig3.v;
    
    trig4.v = 0;
    trig4.bit_info.glb_cnt = 0x196E69;
    trig4.bit_info.vs_cnt = 0;
    p_glb_trig->trig4.v = trig4.v;
}

void trig_cfg(bool ext_trig)
{
	volatile GLOBAL_TRIGGER_T *p_glb_trig = (GLOBAL_TRIGGER_T *)global_trigger_get_base_addr();
    volatile VS_CFG_U      vs_cfg;   //0x14
    
    vs_cfg.v = p_glb_trig->vs_cfg.v;
    vs_cfg.bit_info.global_trig = ext_trig;
    
    p_glb_trig->vs_cfg.v = vs_cfg.v;
}

void trig_enable()
{
	volatile GLOBAL_TRIGGER_T *p_glb_trig = (GLOBAL_TRIGGER_T *)global_trigger_get_base_addr();
    volatile TRIG_EN_U     trig_en;  //0x18
    
    trig_en.v = 0;
    trig_en.bit_info.trig_en = 1;
    p_glb_trig->trig_en.v = trig_en.v;
}