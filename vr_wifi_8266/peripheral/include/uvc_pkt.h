#ifndef __UVC_PKT_H__
#define __UVC_PKT_H__

typedef union UVCPKT_INT_STATUS_U_ 
{
	 unsigned long v;
	 struct UVCPKT_INT_STATUS_T 
	 {
		 unsigned buff0_frame_done_int          : 1;
		 unsigned buff1_frame_done_int          : 1;
		 unsigned buff2_frame_done_int          : 1;
		 unsigned buff0_pkt_done_int            : 1;
		 unsigned buff1_pkt_done_int            : 1;
		 unsigned buff2_pkt_done_int            : 1;
		 unsigned burst_wr_err                  : 1;
		 unsigned rsvd                          : 25;
	 }bit_info; 
}UVCPKT_INT_STATUS_U;    				       //0x08
																	  
typedef union UVCPKT_INT_MSK_U_ 
{
	 unsigned long v;
	 struct UVCPKT_INT_MSK_T 
	 {
		 unsigned buff0_frame_done_msk          : 1;
		 unsigned buff1_frame_done_msk          : 1;
		 unsigned buff2_frame_done_msk          : 1;
		 unsigned buff0_pkt_done_msk            : 1;
		 unsigned buff1_pkt_done_msk            : 1;
		 unsigned buff2_pkt_done_msk            : 1;
		 unsigned burst_wr_err_msk              : 1;
		 unsigned rsvd                          : 25;
	 }bit_info; 								
}UVCPKT_INT_MSK_U;  							//0x0c

typedef union UVCPKT_CTRL_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_CTRL_FF_T 
	 {
		 unsigned cfg_input_en                  : 1;
		 unsigned cfg_ir_input_10b_en           : 1;
		 unsigned cfg_bypass_en                 : 1;
		 unsigned cfg_uvc_hdr_mod               : 1;
		 unsigned cfg_uvc_hdr_bypass            : 1;
		 unsigned cfg_ts_switch_en              : 1;
		 unsigned rsvd0                         : 2;
		 unsigned ircm_hblank_thd               : 8;
		 unsigned rsvd                          : 16;
	 }bit_info; 								
}UVCPKT_CTRL_FF_U;  							//0x10

typedef union UVCPKT_IRCM_IMG_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_IRCM_IMG_FF_T 
	 {
		 unsigned ircm_img_width                : 11;
		 unsigned rsvd0                         : 5;
		 unsigned ircm_img_height               : 11;
		 unsigned rsvd1                         : 5;
	 }bit_info; 								
}UVCPKT_IRCM_IMG_FF_U;  						//0x14

typedef union UVCPKT_LEN_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_LEN_FF_T 
	 {
		 unsigned uvc_pkt_length                : 16;
		 unsigned rsvd1                         : 16;
	 }bit_info; 								
}UVCPKT_LEN_FF_U;  					         	//0x18

typedef union UVCPKT_DMA_MODE_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_DMA_MODE_FF_T 
	 {
		 unsigned burst_length                  : 4;
		 unsigned dram_buff0_en                 : 1;
		 unsigned dram_buff1_en                 : 1;
		 unsigned dram_buff2_en                 : 1;
		 unsigned rsvd                          : 25;
	 }bit_info; 								
}UVCPKT_DMA_MODE_FF_U;  					    //0x1c
			
typedef union UVCPKT_BUFF0_ADDR_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_BUFF0_ADDR_FF_T 
	 {
		 unsigned buff0_addr_ff                 : 32;
	 }bit_info; 								
}UVCPKT_BUFF0_ADDR_FF_U;  					    //0x20			

typedef union UVCPKT_BUFF1_ADDR_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_BUFF1_ADDR_FF_T 
	 {
		 unsigned buff1_addr_ff                 : 32;
	 }bit_info; 								
}UVCPKT_BUFF1_ADDR_FF_U;  					    //0x24	

typedef union UVCPKT_BUFF2_ADDR_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_BUFF2_ADDR_FF_T 
	 {
		 unsigned buff2_addr_ff                 : 32;
	 }bit_info; 								
}UVCPKT_BUFF2_ADDR_FF_U;  					    //0x28

typedef union UVCPKT_HDR0_ADDR_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_HDR0_ADDR_FF_T 
	 {
		 unsigned hdr0_addr_ff                 : 32;
	 }bit_info; 								
}UVCPKT_HDR0_ADDR_FF_U;  					    //0x2c

typedef union UVCPKT_HDR1_ADDR_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_HDR1_ADDR_FF_T 
	 {
		 unsigned hdr1_addr_ff                 : 32;
	 }bit_info; 								
}UVCPKT_HDR1_ADDR_FF_U;  					    //0x30

typedef union UVCPKT_HDR2_ADDR_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_HDR2_ADDR_FF_T 
	 {
		 unsigned hdr2_addr_ff                 : 32;
	 }bit_info; 								
}UVCPKT_HDR2_ADDR_FF_U;  					    //0x34

typedef union UVCPKT_FRAME_CNT_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_FRAME_CNT_FF_T
	 {
		 unsigned frame_cnter_ff                : 32;
	 }bit_info; 								
}UVCPKT_FRAME_CNT_FF_U;  					    //0x40

typedef union UVCPKT_UVC_PKT_CNT_FF_U_ 
{
	 unsigned long v;
	 struct UVCPKT_UVC_PKT_CNT_FF_T 
	 {
		 unsigned uvc_pkt_cnt_ff                : 32;
	 }bit_info; 								
}UVCPKT_UVC_PKT_CNT_FF_U;  					    //0x44
																	  
typedef struct UVCPKT_DEPTH_T_ 
{ 
    int                        rsvd0;
	int                        rsvd1;
    UVCPKT_INT_STATUS_U        int_stat;
    UVCPKT_INT_MSK_U	       int_msk;
    UVCPKT_CTRL_FF_U           ctrl;
	UVCPKT_IRCM_IMG_FF_U       ircm_img;		   //0x14
	UVCPKT_LEN_FF_U		       len;
	UVCPKT_DMA_MODE_FF_U       dma_mode;  //1c
	UVCPKT_BUFF0_ADDR_FF_U     buf0_addr;
	UVCPKT_BUFF1_ADDR_FF_U     buf1_addr;
	UVCPKT_BUFF1_ADDR_FF_U     buf2_addr;	   //0x28
	UVCPKT_HDR0_ADDR_FF_U      hdr0_addr;
	UVCPKT_HDR1_ADDR_FF_U      hdr1_addr;
	UVCPKT_HDR1_ADDR_FF_U      hdr2_addr;	   //0x34
    int                        rsvd2;          //0x38
	int                        rsvd3;          //0x3c
	UVCPKT_FRAME_CNT_FF_U      frame_cnt;
	UVCPKT_UVC_PKT_CNT_FF_U    uvc_pkt_cnt;
}UVCPKT_DEPTH_T;












#endif