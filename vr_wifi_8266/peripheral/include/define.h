#ifndef __DEFINE_H__
#define __DEFINE_H__
#include <stdint.h>

typedef signed long  s32;
typedef signed short s16;
typedef signed char  s8;

typedef signed long  const sc32;  /* Read Only */
typedef signed short const sc16;  /* Read Only */
typedef signed char  const sc8;   /* Read Only */

typedef volatile signed long  vs32;
typedef volatile signed short vs16;
typedef volatile signed char  vs8;

typedef volatile signed long  const vsc32;  /* Read Only */
typedef volatile signed short const vsc16;  /* Read Only */
typedef volatile signed char  const vsc8;   /* Read Only */

typedef unsigned int  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef unsigned long  const uc32;  /* Read Only */
typedef unsigned short const uc16;  /* Read Only */
typedef unsigned char  const uc8;   /* Read Only */

typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;

typedef volatile unsigned long  const vuc32;  /* Read Only */
typedef volatile unsigned short const vuc16;  /* Read Only */
typedef volatile unsigned char  const vuc8;   /* Read Only */

#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */
	
#define read8(addr)         (*((volatile u8 *)(addr)))
#define read16(addr)        (*((volatile u16 *)(addr)))
#define read32(addr)        (*((volatile unsigned int *)(addr)))
#define write8(addr,data)   (*((volatile u8 *)(addr)) = (data))
#define write16(addr,data)  (*((volatile u16 *)(addr)) = (data))
#define write32(addr,data)  (*((volatile unsigned int *)(addr)) = (data))

/* Define standard constants */
#define TRUE  1
#define FALSE 0
#ifndef NULL
#define NULL  0
#endif

#ifndef bool
typedef unsigned char bool;
#endif

#ifndef true
#define true (1)
#endif

#ifndef false
#define false (0)
#endif

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

#endif
