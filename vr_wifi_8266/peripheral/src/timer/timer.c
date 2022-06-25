#include "timer.h"
#include "peripheral.h"

unsigned int timerGetBaseAddr(void)
{
    return TIMER0_BASE_ADDR;
}

void timerInit(unsigned char timer, float freq, int single)
{
    volatile TIMER_T * pTimer = (TIMER_T *)timerGetBaseAddr();
    volatile TIMER_CTRL_U         ctrl;          //0x4
    volatile TIMER_LOAD_VALUE_U   load;          //0x8
    volatile TIMER_ENABLE_U       enable;        //0x10
    volatile TIMER_INTR_CLR_U     intr_clr;      //0x20
    volatile TIMER_INTR_MASK_U    mask;          //0x24

    ctrl.v = 0;
    ctrl.bit_info.single = single ? 1 : 0;
    pTimer->timer[timer].ctrl.v = ctrl.v;
    
    load.v = 0;
    load.bit_info.val = (int)((float)TIMER_CLK / freq); 
    pTimer->timer[timer].load.v = load.v;
    
    while (pTimer->timer[timer].intr_clr.bit_info.clr_busy);
    intr_clr.v = 0;
    intr_clr.bit_info.clr = 1;
    pTimer->timer[timer].intr_clr.v = intr_clr.v;
    
    mask.v = 0;
    pTimer->timer[timer].mask.v = mask.v;

    enable.v = 0;
    enable.bit_info.en = 1;
    pTimer->timer[timer].enable.v = enable.v;

}

void timerDisable(unsigned char timer)
{
    volatile TIMER_T * pTimer = (TIMER_T *)timerGetBaseAddr();
    pTimer->timer[timer].enable.v = 0;
}

void timerIsr(unsigned char timer, int single)
{
    volatile TIMER_T * pTimer = (TIMER_T *)timerGetBaseAddr();
    volatile TIMER_ENABLE_U       enable;        //0x10
    volatile TIMER_RELOAD_U       reload;       //0x14
    volatile TIMER_INTR_CLR_U     intr_clr;    //0x20

    while (pTimer->timer[timer].intr_clr.bit_info.clr_busy);
    intr_clr.v = 0;
    intr_clr.bit_info.clr = 1;
    pTimer->timer[timer].intr_clr.v = intr_clr.v;

    reload.v = 0;
    reload.bit_info.reload = 1;
    pTimer->timer[timer].reload.v = reload.v;
    
    enable.v = 0;
    enable.bit_info.en = single?1:0;
    pTimer->timer[timer].enable.v = enable.v;
}

unsigned int timerGetValue(unsigned char timer)
{
    volatile TIMER_T * pTimer = (TIMER_T *)timerGetBaseAddr();
    unsigned int val = pTimer->timer[timer].val.bit_info.val;
    
    return val;
}
