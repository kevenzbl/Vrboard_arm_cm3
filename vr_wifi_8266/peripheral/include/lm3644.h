#ifndef __LM3644_H__ 
#define __LM3644_H__ 


#include "../include/define.h"

void lm3644_en(void);
bool lm3644_read_reg(u8 reg, u8 *pVal);
bool lm3644_write_reg(u8 reg, u8 data);

#endif
