
#include "config.h"
#include "cpu_core.h"

/*
 ��Cortex-M�ں�������һ�������DWT(Data Watchpoint and Trace)����������һ��32λ�ļĴ�����CYCCNT��
 ����һ�����ϵ� ����������¼�����ں�ʱ�����еĸ�������CYCCNT���֮�󣬻���0���¿�ʼ���ϼ�����
 ʹ��CYCCNT�����Ĳ������裺
 1����ʹ��DWT���裬����������ں˵��ԼĴ���DEMCR��λ24���ƣ�д1ʹ��
 2��ʹ��CYCCNT�Ĵ���֮ǰ������0
 3��ʹ��CYCCNT�Ĵ����������DWT_CTRL(�����Ϻ궨��ΪDWT_CR)��λ0���ƣ�д1ʹ��
 */
#define  BSP_REG_DEM_CR                       (*(vu32 *)0xE000EDFC)
#define  BSP_REG_DWT_CR                       (*(vu32 *)0xE0001000)
#define  BSP_REG_DWT_CYCCNT                   (*(vu32 *)0xE0001004)
#define  BSP_REG_DBGMCU_CR                    (*(vu32 *)0xE0042004)

/*
*********************************************************************************************************
*                                            �Ĵ���λ����
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

	/* Ŀǰ�����������ʹ��25M��ϵͳʱ�� */
	CPU_HCLK = 60000000;

	return CPU_HCLK;
#endif
}

/* ʱ�����ʱ����ʼ�� */
#if (CPU_CFG_TS_TMR_EN == true)
void  cpu_ts_tmr_init (void)
{
    u32 fclk_freq;

    fclk_freq = BSP_CPU_ClkFreq();

    /* ʹ��DWT���� */
	BSP_REG_DEM_CR     |= (u32)BSP_BIT_DEM_CR_TRCENA;
	/* DWT CYCCNT�Ĵ���������0 */
    BSP_REG_DWT_CYCCNT  = (u32)0u;
/* ע�⣺��ʹ���������ȫ�����е�ʱ�򣬻���ͣ�����
         �ͺ���������������һ���ϵ�һ������Ҫ�ֶ����в��������� 
         ��ʹ��Ӳ�������ʱ��ȴ���� */
	/* ʹ��Cortex-M3 DWT CYCCNT�Ĵ��� */
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
