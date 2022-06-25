
#include "config.h"
#include "cpu_core.h"

/*
 在Cortex-M内核里面有一个外设叫DWT(Data Watchpoint and Trace)，该外设有一个32位的寄存器叫CYCCNT，
 它是一个向上的 计数器，记录的是内核时钟运行的个数，当CYCCNT溢出之后，会清0重新开始向上计数。
 使能CYCCNT计数的操作步骤：
 1、先使能DWT外设，这个由另外内核调试寄存器DEMCR的位24控制，写1使能
 2、使能CYCCNT寄存器之前，先清0
 3、使能CYCCNT寄存器，这个由DWT_CTRL(代码上宏定义为DWT_CR)的位0控制，写1使能
 */
#define  BSP_REG_DEM_CR                       (*(vu32 *)0xE000EDFC)
#define  BSP_REG_DWT_CR                       (*(vu32 *)0xE0001000)
#define  BSP_REG_DWT_CYCCNT                   (*(vu32 *)0xE0001004)
#define  BSP_REG_DBGMCU_CR                    (*(vu32 *)0xE0042004)

/*
*********************************************************************************************************
*                                            寄存器位定义
*********************************************************************************************************
*/

#define  BSP_DBGMCU_CR_TRACE_IOEN_MASK                   0x10
#define  BSP_DBGMCU_CR_TRACE_MODE_ASYNC                  0x00
#define  BSP_DBGMCU_CR_TRACE_MODE_SYNC_01                0x40
#define  BSP_DBGMCU_CR_TRACE_MODE_SYNC_02                0x80
#define  BSP_DBGMCU_CR_TRACE_MODE_SYNC_04                0xC0
#define  BSP_DBGMCU_CR_TRACE_MODE_MASK                   0xC0

#define  BSP_BIT_DEM_CR_TRCENA                          (1<<24)
#define  BSP_BIT_DWT_CR_CYCCNTENA                       (1<<0)

u32  BSP_CPU_ClkFreq (void)
{
#if 0
	RCC_ClocksTypeDef  rcc_clocks;


    RCC_GetClocksFreq(&rcc_clocks);
    return ((CPU_INT32U)rcc_clocks.HCLK_Frequency);
#else
	u32    CPU_HCLK;

	/* 目前软件仿真我们使用25M的系统时钟 */
	CPU_HCLK = 60000000;

	return CPU_HCLK;
#endif
}

/* 时间戳定时器初始化 */
#if (CPU_CFG_TS_TMR_EN == true)
void  cpu_ts_tmr_init (void)
{
    u32 fclk_freq;

    fclk_freq = BSP_CPU_ClkFreq();

    /* 使能DWT外设 */
	BSP_REG_DEM_CR     |= (u32)BSP_BIT_DEM_CR_TRCENA;
	/* DWT CYCCNT寄存器计数清0 */
    BSP_REG_DWT_CYCCNT  = (u32)0u;
/* 注意：当使用软件仿真全速运行的时候，会先停在这里，
         就好像在这里设置了一个断点一样，需要手动运行才能跳过， 
         当使用硬件仿真的时候却不会 */
	/* 使能Cortex-M3 DWT CYCCNT寄存器 */
    BSP_REG_DWT_CR     |= (u32)BSP_BIT_DWT_CR_CYCCNTENA;

    //CPU_TS_TmrFreqSet((CPU_TS_TMR_FREQ)fclk_freq);
}
#endif

#if (CPU_CFG_TS_TMR_EN == true)
u32  cpu_ts_tmr_rd (void)
{
    u32  ts_tmr_cnts;

    ts_tmr_cnts = (u32)BSP_REG_DWT_CYCCNT;

    return (ts_tmr_cnts);
}
#endif
