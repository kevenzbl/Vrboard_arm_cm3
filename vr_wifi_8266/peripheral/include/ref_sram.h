#ifndef __REF_SRAM_H__
#define __REF_SRAM_H__

typedef union REF_ADDR_U_ 
{
	 unsigned long v;
	 struct REF_ADDR_T 
	 {
		 unsigned addr             : 18;
		 unsigned rsvd             : 14;
	 }bit_info; 
}REF_ADDR_U;    
																	  
typedef union REF_LEN_U_ 
{
	 unsigned long v;
	 struct REF_LEN_T 
	 {
		 unsigned len               : 18;
		 unsigned rsvd              : 14;
	 }bit_info; 
}REF_LEN_U;  

typedef union REF_EN_U_ 
{
	 unsigned long v;
	 struct REF_EN_T 
	 {
		 unsigned en                : 1;
		 unsigned rsvd              : 31;
	 }bit_info; 
}REF_EN_U; 
																	  
typedef struct REF_SRAM_T_ 
{ 
    REF_ADDR_U	 addr;
    REF_LEN_U	 len;
    REF_EN_U     en;
}REF_SRAM_T;

void ref_sram_init(void);
void ref_sram_en(void);

#endif
