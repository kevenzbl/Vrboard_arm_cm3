#ifndef _TIMER_H_
#define _TIMER_H_

#define TIMER_CLK                  24000000
#define TIMER0_FREQ                (1.0)    //Hz            


void timerInit(unsigned char timer, float freq, int single);
void timerIsr(unsigned char, int single);
void timerDisable(unsigned char timer);
unsigned int timerGetValue(unsigned char timer);


typedef __packed union TIMER_INTR_STATE_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_INTR_STATE_T_ 
	 {
		 unsigned timer0                            : 1;
         unsigned timer1                            : 1;
         unsigned timer2                            : 1;
         unsigned timer3                            : 1;
         unsigned watchdog                          : 1;
         unsigned timer4                            : 1;
         unsigned timer5                            : 1;
         unsigned timer6                            : 1;
	 }bit_info; 
}TIMER_INTR_STATE_U; //0x0


typedef __packed union TIMER_CTRL_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_CTRL_T_ 
	 {
		 unsigned single                            : 1;
	 }bit_info; 
}TIMER_CTRL_U; //0x4

typedef __packed union TIMER_LOAD_VALUE_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_LOAD_VALUE_T_ 
	 {
		 unsigned val                            : 32;
	 }bit_info; 
}TIMER_LOAD_VALUE_U; //0x8

typedef __packed union TIMER_ENABLE_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_ENABLE_T_ 
	 {
		 unsigned en                            : 1;
	 }bit_info; 
}TIMER_ENABLE_U; //0x10

typedef __packed union TIMER_RELOAD_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_RELOAD_T_ 
	 {
		 unsigned reload                            : 1;
	 }bit_info; 
}TIMER_RELOAD_U; //0x14

typedef __packed union TIMER_VALUE_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_VALUE_T_ 
	 {
		 unsigned val                            : 32;
	 }bit_info; 
}TIMER_VALUE_U; //0x18

typedef __packed union TIMER_INTR_CLR_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_INTR_CLR_T_ 
	 {
		 unsigned clr                            : 1;
         unsigned clr_busy                       : 1;
	 }bit_info; 
}TIMER_INTR_CLR_U; //0x20

typedef __packed union TIMER_INTR_MASK_U_ 
{
	 unsigned int v;
	  __packed struct TIMER_INTR_MASK_T_ 
	 {
		 unsigned mask                            : 1;
	 }bit_info; 
}TIMER_INTR_MASK_U; //0x24


typedef __packed union WATCH_DOG_CTRL_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_CTRL_T_ 
	 {
		 unsigned reset                            : 1;
	 }bit_info; 
}WATCH_DOG_CTRL_U; //0x104

typedef __packed union WATCH_DOG_LOAD_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_LOAD_T_ 
	 {
		 unsigned val                            : 32;
	 }bit_info; 
}WATCH_DOG_LOAD_U; //0x108

typedef __packed union WATCH_DOG_ENABLE_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_ENABLE_T_ 
	 {
		 unsigned en                            : 1;
	 }bit_info; 
}WATCH_DOG_ENABLE_U; //0x110

typedef __packed union WATCH_DOG_RELOAD_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_RELOAD_T_ 
	 {
		 unsigned reload                            : 1;
	 }bit_info; 
}WATCH_DOG_RELOAD_U; //0x114

typedef __packed union WATCH_DOG_COUNTER_VALUE_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_COUNTER_VALUE_T_ 
	 {
		 unsigned val                            : 32;
	 }bit_info; 
}WATCH_DOG_COUNTER_VALUE_U; //0x118

typedef __packed union WATCH_DOG_INTR_CLR_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_INTR_CLR_T_ 
	 {
		 unsigned clr                            : 1;
         unsigned clr_busy                       : 1;
	 }bit_info; 
}WATCH_DOG_INTR_CLR_U; //0x120

typedef __packed union WATCH_DOG_INTR_MASK_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_INTR_MASK_T_ 
	 {
		 unsigned mask                            : 1;
	 }bit_info; 
}WATCH_DOG_INTR_MASK_U; //0x124

typedef __packed union WATCH_DOG_LOCK_U_ 
{
	 unsigned int v;
	  __packed struct WATCH_DOG_LOCK_T_ 
	 {
		 unsigned lock                            : 1;
	 }bit_info; 
}WATCH_DOG_LOCK_U; //0x13c


typedef struct TIMERx_T_
{     
    TIMER_CTRL_U         ctrl;      //0x4
    TIMER_LOAD_VALUE_U   load;          //0x8
    int                  reserved0;     //0xc
    TIMER_ENABLE_U       enable;        //0x10
    TIMER_RELOAD_U       reload;       //0x14
    TIMER_VALUE_U        val;         //0x18
    int                  reserved1;    //0x1c
    TIMER_INTR_CLR_U     intr_clr;    //0x20
    TIMER_INTR_MASK_U    mask;        //0x24
    char                 reserved2[0x1c];
}TIMERx_T;

typedef struct WATCH_DOG_T_
{     
    WATCH_DOG_CTRL_U            ctrl;           //104
    WATCH_DOG_LOAD_U            load;       //0x108
    int                         reserved0;  //0x10c
    WATCH_DOG_ENABLE_U          enable;         //0x110
    WATCH_DOG_RELOAD_U          reload; //0x114
    WATCH_DOG_COUNTER_VALUE_U   value; //0x118
    int                         reserved1;  //0x11c
    WATCH_DOG_INTR_CLR_U        intr_clr; //0x120
    WATCH_DOG_INTR_MASK_U       intr_mask; //0x124
    char                        reserved2[0x14];
    WATCH_DOG_LOCK_U            lock; //0x13c
}WATCH_DOG_T;

typedef struct TIMER_T_
{     
    TIMER_INTR_STATE_U          intr_state;      //0x0
    TIMERx_T                    timer[8];          //(0x4~0x23) * 8 = 0x104
    WATCH_DOG_T                 wd;
}TIMER_T;

#endif
