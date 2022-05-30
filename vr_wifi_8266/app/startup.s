init_xxx  EQU     0




Stack_Size      EQU     0x00000080

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp

Heap_Size       EQU     0x00000000 

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB

                IMPORT   int0_isr           [WEAK]

; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     int0_isr 		  




                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler                [WEAK]
                
				        IF      init_xxx == 1
; init pll ddr 
			 
				        LDR R0,= 0xBBBBBBBB ;data
				        LDR R1,= 0x40011404 ;addr
				        STR R0,[R1]		
					  		ENDIF                
               
                IMPORT  main
                LDR     R0, =main
                BX      R0


;               IMPORT  main
;				LDR     R0,=main
;               BLX     R0
;				LDR     R0,=0x20000000		;bit0==0 ARM ,bit0==1 THUMB
;				BX 		R0	
                ENDP

; Dummy Exception Handlers (infinite loops which can be modified)                

NMI_Handler     PROC
                EXPORT  NMI_Handler                  [WEAK]       
                B       .
                ENDP
HardFault_Handler PROC
                EXPORT  HardFault_Handler            [WEAK]
                B       .
                ENDP
MemManage_Handler PROC
                EXPORT  MemManage_Handler            [WEAK]
                B       .
                ENDP
BusFault_Handler  PROC
                EXPORT  BusFault_Handler             [WEAK]
                B       .
                ENDP
UsageFault_Handler PROC
                EXPORT  UsageFault_Handler           [WEAK]
                B       .							 
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                  [WEAK]
                B       .
                ENDP
DebugMon_Handler  PROC
                EXPORT  DebugMon_Handler             [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler               [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler              [WEAK]
                B       .
                ENDP
;Default_Handler PROC
;			    EXPORT  int0_isr                     [WEAK]
;int0_isr
;				B       .
;				ENDP	

                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
