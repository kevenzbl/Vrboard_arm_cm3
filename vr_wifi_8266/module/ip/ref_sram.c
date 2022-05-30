#include "../include/config.h"
#include "../include/ref_sram.h"

static unsigned int ref_sram_get_base_addr()
{
    return REF_SRAM_BASE_ADDR;
}

void ref_sram_init(void)
{
    REF_SRAM_T *pRef_sram = (REF_SRAM_T *)ref_sram_get_base_addr();
	REF_ADDR_U ref_addr;
	REF_LEN_U  ref_len;
	  
    ref_addr.v = 0;
	ref_addr.bit_info.addr = REF_ADDR_OFFSET;
	pRef_sram->addr.v = ref_addr.v;

    ref_len.v = 0;
	ref_len.bit_info.len = REF_SIZE;
	pRef_sram->len.v = ref_len.v;	  
}

void ref_sram_en(void)
{
    REF_SRAM_T *pRef_sram = (REF_SRAM_T *)ref_sram_get_base_addr();

	pRef_sram->en.bit_info.en = 1;
}																	   