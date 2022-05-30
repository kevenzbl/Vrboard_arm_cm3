#ifndef __GLOBAL_TRIGGER_H__
#define __GLOBAL_TRIGGER_H__

typedef union TRIG0_U_ 
{
	 unsigned long v;
	 struct TRIG0_T_ 
	 {
		 unsigned glb_cnt                 : 24;
         unsigned vs_cnt                  : 8;
	 }bit_info; 
} TRIG0_U;                                  //0x0

typedef union TRIG1_U_ 
{
	 unsigned long v;
	 struct TRIG1_T_ 
	 {
		 unsigned glb_cnt                 : 24;
         unsigned vs_cnt                  : 8;
	 }bit_info; 
} TRIG1_U;                                  //0x4

typedef union TRIG2_U_ 
{
	 unsigned long v;
	 struct TRIG2_T_ 
	 {
		 unsigned glb_cnt                 : 24;
         unsigned vs_cnt                  : 8;
	 }bit_info; 
} TRIG2_U;                                  //0x8

typedef union TRIG3_U_ 
{
	 unsigned long v;
	 struct TRIG3_T_ 
	 {
		 unsigned glb_cnt                 : 24;
         unsigned vs_cnt                  : 8;
	 }bit_info; 
} TRIG3_U;                                  //0xC

typedef union TRIG4_U_ 
{
	 unsigned long v;
	 struct TRIG4_T_ 
	 {
		 unsigned glb_cnt                 : 24;
         unsigned vs_cnt                  : 8;
	 }bit_info; 
} TRIG4_U;                                  //0x10

typedef union VS_CFG_U_ 
{
	 unsigned long v;
	 struct VS_CFG_T_ 
	 {
		 unsigned vs_cfg                 : 1;
         unsigned global_trig            : 1;
	 }bit_info; 
} VS_CFG_U;                                  //0x14

typedef union TRIG_EN_U_ 
{
	 unsigned long v;
	 struct TRIG_EN_T_ 
	 {
		 unsigned trig_en                 : 1;
	 }bit_info; 
} TRIG_EN_U;                                 //0x18

typedef struct GLOBAL_TRIGGER_T_ 
{ 
    TRIG0_U       trig0;    //0x0
    TRIG1_U       trig1;    //0x4
    TRIG2_U       trig2;    //0x8
    TRIG3_U       trig3;    //0xc
    TRIG4_U       trig4;    //0x10
    VS_CFG_U      vs_cfg;   //0x14
    TRIG_EN_U     trig_en;  //0x18
} GLOBAL_TRIGGER_T;

#endif