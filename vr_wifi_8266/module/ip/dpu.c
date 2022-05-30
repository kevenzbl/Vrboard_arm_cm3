#include "../include/dpu.h"
#include "../include/config.h"
#include "../include/define.h"

static unsigned int ircmifGetBaseAddr(void)
{
    return DPU_BASE_ADDR;
}

void ircmifSetCtrl(u32 ctrlVal)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    volatile IRCMIF_CTRL_U ircmif_ctrl;
    ircmif_ctrl.v = ctrlVal;
    pIrcmif->ircmif_ctrl.v = ircmif_ctrl.v;
}

u32 ircmifGetCtrl(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    u32 ctrlVal = pIrcmif->ircmif_ctrl.v;
    return ctrlVal;
}

bool ircmifIsRefReady(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    
    return (pIrcmif->ircmif_int_status.bit_info.ircmif_corr_refready ? true : false);
}

void ircmifClrRefReady(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    volatile IRCMIF_INT_CLEAR_U ircmif_int_clear;                    //0x0028 
    
    ircmif_int_clear.v = 0;
    ircmif_int_clear.bit_info.ircmif_corr_refready_int_clr = 1;
    pIrcmif->ircmif_int_clear.v = ircmif_int_clear.v;
    pIrcmif->ircmif_int_clear.v = 0;
}

bool ircmifIsCorrDone(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    return (pIrcmif->ircmif_int_status.bit_info.ircmif_corr_done?true:false);
}

void ircmifClrCorrDone(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    volatile IRCMIF_INT_CLEAR_U ircmif_int_clear;                    //0x0028 
   
    ircmif_int_clear.v = 0;
    ircmif_int_clear.bit_info.ircmif_corr_done_int_clr = 1;
    pIrcmif->ircmif_int_clear.v = ircmif_int_clear.v;
    pIrcmif->ircmif_int_clear.v = 0;
}

void disableCorrRefInt(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();            //0x0040 
    volatile IRCMIF_INT_ENABLE_U                 ircmif_int_enable; 
    
    ircmif_int_enable.v = pIrcmif->ircmif_int_enable.v;
    ircmif_int_enable.bit_info.ircmif_corr_refready_int_ena = 0;
    pIrcmif->ircmif_int_enable.v = ircmif_int_enable.v; 
}

 /*
void ircmifEnable(IpParam *param)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    
    u32 ircmifCtrlCfg;
    ircmifCtrlCfg = param->ircmifCtrlCfg;
    pIrcmif->ircmif_ctrl.v = ircmifCtrlCfg;

}
*/

void ircmifDisable(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    pIrcmif->ircmif_ctrl.v = 0;
}

void enableIrCorrDoneInt()
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    volatile IRCMIF_INT_ENABLE_U                 ircmif_int_enable;

    ircmif_int_enable.v = pIrcmif->ircmif_int_enable.v;
    ircmif_int_enable.bit_info.ircmif_corr_done_int_ena = 1;
    pIrcmif->ircmif_int_enable.v = ircmif_int_enable.v;    
}

void waitRefReady(void)
{
	static bool ready = false;
	if(ready)
		return;
	while(!ircmifIsRefReady());
	ircmifClrRefReady();
	//DBG_Printf("sromcRefReady()\n");
	ready = true;
}

void ircmifInit(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    volatile IRCMIF_COMMON_USE_0_U               ircmif_common_use_0;                 //0x00a0 
    volatile IRCMIF_COMMON_USE_1_U               ircmif_common_use_1;                 //0x00a4 
    volatile IRCMIF_FRAME_RESOLUTION_U           ircmif_frame_resolution;             //0x0040 
    volatile IRCMIF_INT_ENABLE_U                 ircmif_int_enable;                   //0x0024 
    volatile CONST_SHIFT_U                       const_shift;                         //0x0018 
    volatile SAD_BAD_U                           sad_bad;                             //0x0010 
    volatile SAD_GOOD_U                          sad_good;                            //0x0014 
//    volatile BINCALC_C_U                         bincalc_c;                           //0x0000 
//    volatile BINCALC_VL_U                        bincalc_vl;                          //0x0004 
/*    
    WORD irImgHeight;
    WORD irImgWitdh;
    
    irImgWitdh = param->irImgWidth;
    irImgHeight = param->irImgHeigth;
    
    ircmif_frame_resolution.v = 0;
    ircmif_frame_resolution.bit_info.img_width = irImgWitdh;
    ircmif_frame_resolution.bit_info.img_height = irImgHeight;
    pIrcmif->ircmif_frame_resolution.v = ircmif_frame_resolution.v;
 */
				  /*
WRITE_DWORD(DPU_APB_BASE_ADDR+0x94, blobThreshold);
WRITE_DWORD(DPU_APB_BASE_ADDR+0x90, 0x7ff | (5300<<16));
WRITE_DWORD(DPU_APB_BASE_ADDR+0xA0, commonUse0);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xA4, commonUse1);

WRITE_DWORD(DPU_APB_BASE_ADDR+0xB4, 1500);
//WRITE_DWORD(DPU_APB_BASE_ADDR+0x08, 2047);


WRITE_DWORD(DPU_APB_BASE_ADDR+0xb8, 0xfffffff3);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xbc, 0x4);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xc0, 0x1);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xc4, 0xffffffff);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xc8, 0x8);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xcc, 0xfffffff7);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xd0, 0x1953d35);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xd4, 0xfffec8b0);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xd8, 0xffffd0b5);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xdc, 0x010616ca);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xe0, 0x2f4e);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xe4, 0xfffea0d1);
WRITE_DWORD(DPU_APB_BASE_ADDR+0xe8, 0x4fdf3);

WRITE_DWORD(DPU_APB_BASE_ADDR + 0x9c, 0x30a00);
WRITE_DWORD(DPU_APB_BASE_ADDR + 0x90, 0xa000700);
WRITE_DWORD(DPU_APB_BASE_ADDR + 0xa0, 0x3240a00);
WRITE_DWORD(DPU_APB_BASE_ADDR + 0xec, 0x2d0a00);
*/
    ircmif_int_enable.v = 0;
    ircmif_int_enable.bit_info.ircmif_corr_done_int_ena = 0;
    ircmif_int_enable.bit_info.ircmif_corr_refready_int_ena = 1;
    pIrcmif->ircmif_int_enable.v = ircmif_int_enable.v;
}

u32 ircmifGetGmcPointValidMap(void)
{
    volatile IRCMIF_T  *pIrcmif = (IRCMIF_T  *)ircmifGetBaseAddr();
    unsigned int val = pIrcmif->gmc_point_valid_map.v;
    return val;
}

/*
void initDYRam(void)
{
    int i;
    
    for(i = 0; i < 1240; i++) {
        IRCMIF_DY_RAM0[i] = 0x1f;
        IRCMIF_DY_RAM1[i] = 0x1f;
    }
}*/
