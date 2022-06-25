#include "peripheral.h"
#include "gpio.h"

//GPIO_PIN_T gpio_grp_pin[GPIO_PIN15];

static u32 gpio_get_base_addr(u8 pin_num)
{
    u32 addr;
    u8 group = pin_num/GROUP_PIN_NUM;
	
    switch (group) {
        case 0:
            addr = GPIO0_BASE_ADDR;
            break;
        case 1:
            break;
        default:
            addr = GPIO0_BASE_ADDR;
            break;
    }

    return addr;
}

void gpio_out_data(u8 pin_num, u8 data)
{
    volatile GPIO_Type *pGpio = (GPIO_Type *)gpio_get_base_addr(pin_num);
	volatile int out_set;

	pin_num &= 0x1F;
    out_set	= pGpio->out_set | (1 << pin_num);  
    pGpio->out_set = out_set;
	
	if (data)
	{
		pGpio->data = pGpio->data_out | (1 << pin_num);  
	}
    else 
	{
	    pGpio->data = pGpio->data_out & (0xffff ^ (1 << pin_num));  
	}	    
}

void gpio_set_dir_in(u8 pin_num)
{
    volatile GPIO_Type *pGpio = (GPIO_Type *)gpio_get_base_addr(pin_num);
	volatile int out_clr;
	
	pin_num &= 0x1F;
	out_clr	= (1 << pin_num);  
	pGpio->out_clr = out_clr;	 	
}


char gpio_in_data(u8 pin_num)
{
    volatile GPIO_Type *pGpio = (GPIO_Type *)gpio_get_base_addr(pin_num);
	volatile int out_clr;
    char ret;

	pin_num &= 0x1F;
	out_clr	= (1 << pin_num);
	pGpio->out_clr = out_clr;	 		   

    ret = (pGpio->data >> pin_num) & 1;

    return ret;
}

void gpio_init(u8 pin_num, gpio_dir_t pin_dir)
{
	volatile GPIO_Type *pGpio = (GPIO_Type *)gpio_get_base_addr(pin_num);
	volatile int out_clr;
	volatile int out_set;
	
	pin_num &= 0x1F;
	switch (pin_dir) {
		case GPIO_DIR_INPUT:
			out_clr	= (1 << pin_num);
			pGpio->out_clr = out_clr;
			break;
		
		case GPIO_DIR_OUTPUT:
			out_set	= pGpio->out_set | (1 << pin_num);  
			pGpio->out_set = out_set;
			break;
		
		default:
			break;
	}
}

