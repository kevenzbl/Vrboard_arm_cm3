#ifndef __PWM_H__
#define __PWM_H__

typedef union PWM0_U_ 
{
	 unsigned long v;
	 struct PWM0_T_ 
	 {
		 unsigned duty_cycle            : 8;
         unsigned clk_div               : 8;
         unsigned polarity              : 1;
		 unsigned rsvd                  : 15;
	 }bit_info; 
}PWM0_U;    
																	  
typedef union PWM1_U_ 
{
	 unsigned long v;
	 struct PWM1_T_ 
	 {
		 unsigned duty_cycle            : 8;
         unsigned clk_div               : 8;
         unsigned polarity              : 1;
		 unsigned rsvd                  : 15;
	 }bit_info; 
}PWM1_U;  

																	  
typedef struct PWM_T_ 
{ 
   PWM0_U          pwm0;
   PWM1_U          pwm1;
}PWM_T;

#endif
