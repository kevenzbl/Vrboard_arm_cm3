#include "../include/config.h"
#include "../include/pwm.h"
#include "../include/define.h"

static unsigned int pwm_get_base_addr()
{
	return PWM_BASE_ADDR;
}

void pwm0_set(u8 duty_cycle, u8 clk_div)
{
    volatile PWM_T * pPwm = (PWM_T *)pwm_get_base_addr();
    volatile PWM0_U       pwm0;   

	pwm0.v = 0;
	pwm0.bit_info.duty_cycle = duty_cycle;
	pwm0.bit_info.clk_div	 = clk_div;
	pwm0.bit_info.polarity	 = 0;		  //pwm0 	正输出

	pPwm->pwm0.v = pwm0.v;
}

void pwm1_set(u8 duty_cycle, u8 clk_div)
{
    volatile PWM_T * pPwm = (PWM_T *)pwm_get_base_addr();
    volatile PWM1_U       pwm1;   

	pwm1.v = 0;
	pwm1.bit_info.duty_cycle = duty_cycle;
	pwm1.bit_info.clk_div	 = clk_div;
	pwm1.bit_info.polarity	 = 1;		  //pwm1 	正输出

	pPwm->pwm1.v = pwm1.v;
}

void pwm0_disable()
{
    volatile PWM_T * pPwm = (PWM_T *)pwm_get_base_addr();

	pPwm->pwm0.bit_info.clk_div = 0;
}

void pwm1_disable()
{
    volatile PWM_T * pPwm = (PWM_T *)pwm_get_base_addr();

	pPwm->pwm1.bit_info.clk_div = 0;
}