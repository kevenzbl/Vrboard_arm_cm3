#ifndef __FRAME_PRE_PROC_H__
#define __FRAME_PRE_PROC_H__

typedef union FPF_INT_STATUS_U_ 
{
	 unsigned long v;
	 struct FPF_INT_STATUS_T 
	 {
		 unsigned rsvd0                : 9;
		 unsigned vblank_mismatch      : 1;
		 unsigned hblank_mismatch      : 1;
		 unsigned frame_mismatch       : 1;
		 unsigned row_mismatch         : 1;
         unsigned rsvd1                : 19;
	 }bit_info; 
}FPF_INT_STATUS_U;    			    // 0x08
		
typedef union FPF_INT_MASK_U_ 
{
	 unsigned long v;
	 struct FPF_INT_MASK_T 
	 {
		 unsigned rsvd0                : 9;
		 unsigned vblank_mismatch      : 1;
		 unsigned hblank_mismatch      : 1;
		 unsigned frame_mismatch       : 1;
		 unsigned row_mismatch         : 1;
         unsigned rsvd1                : 19;
	 }bit_info; 
}FPF_INT_MASK_U;    			    // 0x0c		
				
typedef union FPF_IRCM_CTRL_FF_U_ 
{
	 unsigned long v;
	 struct FPF_IRCM_CTRL_FF_T 
	 {
		 unsigned ir_input_en          : 1;
		 unsigned ircm_vs_polarity     : 1;
		 unsigned ir_output_en         : 1;
		 unsigned ir_freeze_en         : 1;
		 unsigned ir_frame_chk_en      : 1;
         unsigned rsvd1                : 27;
	 }bit_info; 
}FPF_IRCM_CTRL_FF_U;    			    // 0x0c					
				
typedef union FPF_IMG_RESOLUTION_CHK_CNT_U_ 
{
	 unsigned long v;
	 struct FPF_IMG_RESOLUTION_CHK_CNT_T 
	 {
		 unsigned monitor_col_cnt      : 11;
		 unsigned rsvd0                : 5;
		 unsigned monitor_row_cnt      : 11;
		 unsigned rsvd1                : 5;
	 }bit_info; 
}FPF_IMG_RESOLUTION_CHK_CNT_U;    			    // 0x80		
				
typedef union FPF_IMG_HBLANK_CHK_CNT_U_ 
{
	 unsigned long v;
	 struct FPF_IMG_HBLANK_CHK_CNT_T 
	 {
		 unsigned monitor_hblank_cnt   : 10;
		 unsigned rsvd                 : 22;
	 }bit_info; 
}FPF_IMG_HBLANK_CHK_CNT_U;    			    // 0x84	
				
typedef union FPF_IMG_VBLANK_CHK_CNT_U_ 
{
	 unsigned long v;
	 struct FPF_IMG_VBLANK_CHK_CNT_T 
	 {
		 unsigned monitor_vblank_cnt   : 20;
		 unsigned rsvd                 : 12;
	 }bit_info; 
}FPF_IMG_VBLANK_CHK_CNT_U;    			    // 0x88	

typedef union FPF_IRCM_IMG_FF_U_ 
{
	 unsigned long v;
	 struct FPF_IRCM_IMG_FF_T 
	 {
		 unsigned img_width            : 11;
		 unsigned rsvd0      		   : 5 ;
		 unsigned img_height           : 11;
		 unsigned rsvd1      		   : 5 ;
	 }bit_info; 
}FPF_IRCM_IMG_FF_U;    			       // 0x90	

typedef union FPF_IRCM_HBLANK_FF_U_ 
{
	 unsigned long v;
	 struct FPF_IRCM_HBLANK_FF_T 
	 {
		 unsigned img_hblank_min       : 16;
		 unsigned img_hblank_max       : 16;
	 }bit_info; 
}FPF_IRCM_HBLANK_FF_U;    			   // 0x94	

typedef union FPF_IRCM_VBLANK_FF_U_ 
{
	 unsigned long v;
	 struct FPF_IRCM_VBLANK_FF_T 
	 {
		 unsigned img_vblank_min       : 32;
	 }bit_info; 
}FPF_IRCM_VBLANK_FF_U;                 // 0x98	
																	  
typedef struct FRM_PRE_PROC_T_ 
{ 
    int                                rsvd0;
	int                                rsvd1;
    FPF_INT_STATUS_U                   int_status;	        //0x08
    FPF_INT_MASK_U			           int_mask;	        //0x0c
	FPF_IRCM_CTRL_FF_U                 ircm_ctrl_ff;	    //0x10
	int						           rsvd2[27];
	FPF_IMG_RESOLUTION_CHK_CNT_U       img_rsl_chk_cnt;     //0x80
	FPF_IMG_HBLANK_CHK_CNT_U		   img_hblank_chk_cnt;  //0x84
	FPF_IMG_VBLANK_CHK_CNT_U		   img_vblank_chk_cnt;  //0x88
	FPF_IRCM_IMG_FF_U                  ircm_img_ff;         //0x90
	FPF_IRCM_HBLANK_FF_U               ircm_hblank_ff;      //0x94
	FPF_IRCM_VBLANK_FF_U               ircm_vblank_ff;      //0x98
}FRM_PRE_PROC_T;


#endif
