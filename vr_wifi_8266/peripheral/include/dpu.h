#ifndef __DPU_H__ 
#define __DPU_H__ 

#define IRCMIF_DY_RAM0                 ((volatile unsigned int *)(DPU_RAM_BASE_ADDR + 0x10000))
#define IRCMIF_DY_RAM1                 ((volatile unsigned int *)(DPU_RAM_BASE_ADDR + 0x20000))
#define IR_MIRROR_ENABLE_BIT           (1 << 8)

typedef union BINCALC_C_U_ 
{
	 unsigned long v;
	 struct BINCALC_C_T_ 
	 {
		 unsigned bincalc_c                           : 16;
		 unsigned reserved0                           : 16;
	 }bit_info; 
}BINCALC_C_U; 

typedef union BINCALC_VL_U_ 
{
	 unsigned long v;
	 struct BINCALC_VL_T_ 
	 {
		 unsigned bincalc_vl                          : 20;
		 unsigned reserved0                           : 12;
	 }bit_info; 
}BINCALC_VL_U; 

typedef union BINCALC_VH_U_ 
{
	 unsigned long v;
	 struct BINCALC_VH_T_ 
	 {
		 unsigned bincalc_vh                          : 20;
		 unsigned reserved0                           : 12;
	 }bit_info; 
}BINCALC_VH_U; 

typedef union BINCALC_T_U_ 
{
	 unsigned long v;
	 struct BINCALC_T_T_ 
	 {
		 unsigned bincalc_t                           : 8;
		 unsigned reserved0                           : 24;
	 }bit_info; 
}BINCALC_T_U; 

typedef union SAD_BAD_U_ 
{
	 unsigned long v;
	 struct SAD_BAD_T_ 
	 {
		 unsigned sad_bad                             : 9;
		 unsigned reserved0                           : 23;
	 }bit_info; 
}SAD_BAD_U; 

typedef union SAD_GOOD_U_ 
{
	 unsigned long v;
	 struct SAD_GOOD_T_ 
	 {
		 unsigned sad_good                            : 9;
		 unsigned reserved0                           : 23;
	 }bit_info; 
}SAD_GOOD_U; 

typedef union CONST_SHIFT_U_ 
{
	 unsigned long v;
	 struct CONST_SHIFT_T_ 
	 {
		 unsigned const_shift                         : 8;
		 unsigned reserved0                           : 24;
	 }bit_info; 
}CONST_SHIFT_U; 

typedef union SATURATED_AREA_U_ 
{
	 unsigned long v;
	 struct SATURATED_AREA_T_ 
	 {
		 unsigned saturated_area                      : 32;
	 }bit_info; 
}SATURATED_AREA_U; 

typedef union IRCMIF_INT_STATUS_U_ 
{
	 unsigned long v;
	 struct IRCMIF_INT_STATUS_T_ 
	 {
		 unsigned ircmif_bincalc_done                 : 1;
		 unsigned ircmif_corr_done                    : 1;
		 unsigned ircmif_corr_refready                : 1;
		 unsigned corre_objfifo_overflow              : 1;
		 unsigned bincalc_fifo_overflow               : 1;
		 unsigned vblank_short_detected               : 1;
		 unsigned bad_row_detected                    : 1;
		 unsigned bad_frame_detected                  : 1;
		 unsigned bad_hblank_detected                 : 1;
		 unsigned reserved0                           : 23;
	 }bit_info; 
}IRCMIF_INT_STATUS_U; 

typedef union IRCMIF_INT_ENABLE_U_ 
{
	 unsigned long v;
	 struct IRCMIF_INT_ENABLE_T_ 
	 {
		 unsigned ircmif_bincalc_done_int_ena         : 1;
		 unsigned ircmif_corr_done_int_ena            : 1;
		 unsigned ircmif_corr_refready_int_ena        : 1;
		 unsigned corre_objfifo_overflow_int_ena      : 1;
		 unsigned bincalc_fifo_overflow_int_ena       : 1;
		 unsigned vblank_short_detected_int_ena       : 1;
		 unsigned bad_row_detected_int_ena            : 1;
		 unsigned bad_frame_detected_int_ena          : 1;
		 unsigned bad_hblank_detected_int_ena         : 1;
		 unsigned reserved0                           : 23;
	 }bit_info; 
}IRCMIF_INT_ENABLE_U; 

typedef union IRCMIF_INT_CLEAR_U_ 
{
	 unsigned long v;
	 struct IRCMIF_INT_CLEAR_T_ 
	 {
		 unsigned ircmif_bincalc_done_int_clr         : 1;
		 unsigned ircmif_corr_done_int_clr            : 1;
		 unsigned ircmif_corr_refready_int_clr        : 1;
		 unsigned corre_objfifo_overflow_int_clr      : 1;
		 unsigned bincalc_fifo_overflow_int_clr       : 1;
		 unsigned vblank_short_detected_int_clr       : 1;
		 unsigned bad_row_detected_int_clr            : 1;
		 unsigned bad_frame_detected_int_clr          : 1;
		 unsigned bad_hblank_detected_int_clr         : 1;
		 unsigned reserved0                           : 23;
	 }bit_info; 
}IRCMIF_INT_CLEAR_U; 

typedef union GMC_POINT_VALID_MAP_U_ 
{
	 unsigned long v;
	 struct GMC_POINT_VALID_MAP_T_ 
	 {
		 unsigned gmc_point_valid_map                 : 31;
		 unsigned valid_gmc_ram1                      : 1;
	 }bit_info; 
}GMC_POINT_VALID_MAP_U; 

typedef union IRCMIF_DBG_STATUS0_U_ 
{
	 unsigned long v;
	 struct IRCMIF_DBG_STATUS0_T_ 
	 {
		 unsigned ircmif_dbg_status0                  : 32;
	 }bit_info; 
}IRCMIF_DBG_STATUS0_U; 

typedef union IRCMIF_DBG_STATUS1_U_ 
{
	 unsigned long v;
	 struct IRCMIF_DBG_STATUS1_T_ 
	 {
		 unsigned ircmif_dbg_status1                  : 32;
	 }bit_info; 
}IRCMIF_DBG_STATUS1_U; 

typedef union IRCMIF_CTRL_U_ 
{
	 unsigned long v;
	 struct IRCMIF_CTRL_T_ 
	 {
		 unsigned ircmif_enable                       : 1;
		 unsigned bypass_scale                        : 1;
		 unsigned bypass_gradient                     : 1;
		 unsigned ircmif_test_enable                  : 1;
		 unsigned gmc_comp_coef_switch                : 1;
		 unsigned dy_in_ram_update                    : 1;
		 unsigned gradient_4v                         : 1;
		 unsigned input_downscale_enable              : 1;
		 unsigned mirror_enable                       : 1;
		 unsigned bypass_scale_2                      : 1;
		 unsigned corre_640_enable                    : 1;
		 unsigned filter_last_8row                    : 1;
		 unsigned bypass_outcontrol                   : 1;
		 unsigned outcontrol_clr                      : 1;
		 unsigned gmcpt_mask_sel                      : 1;
		 unsigned filter_last_4row                    : 1;
		 unsigned filter_fast_frame_en                : 1;
		 unsigned corre_sadsum_sel                    : 1;
		 unsigned through_path_mirror_en              : 1;
		 unsigned bypass_midfilter                    : 1;
		 unsigned bypass_compense                     : 1;
		 unsigned obj_13                              : 1;
		 unsigned bypass_noise_filter                 : 1;
		 unsigned inbit_width_12                      : 1;
		 unsigned bypass_blob                         : 1;
		 unsigned corre_freeze                        : 1;
		 unsigned bypass_holefilling                  : 1;
		 unsigned dy_slection                         : 3;
		 unsigned filter_control                      : 2;
	 }bit_info; 
}IRCMIF_CTRL_U; 

typedef union IRCMIF_AHB_RAM_STATUS_U_ 
{
	 unsigned long v;
	 struct IRCMIF_AHB_RAM_STATUS_T_ 
	 {
		 unsigned ircmif_ahb_ram_status1              : 32;
	 }bit_info; 
}IRCMIF_AHB_RAM_STATUS_U; 

typedef union IRCMIF_FRAME_RESOLUTION_U_ 
{
	 unsigned long v;
	 struct IRCMIF_FRAME_RESOLUTION_T_ 
	 {
		 unsigned img_width                           : 16;
		 unsigned img_height                          : 16;
		 //unsigned reserved0                           : 6;
	 }bit_info; 
}IRCMIF_FRAME_RESOLUTION_U; 

typedef union GMCPT_SEARCH_1STFRAME_LOW_U_ 
{
	 unsigned long v;
	 struct GMCPT_SEARCH_1STFRAME_LOW_T_ 
	 {
		 unsigned gmcpt_search_1stframe_low           : 32;
	 }bit_info; 
}GMCPT_SEARCH_1STFRAME_LOW_U; 

typedef union GMCPT_SEARCH_HIGH_U_ 
{
	 unsigned long v;
	 struct GMCPT_SEARCH_HIGH_T_ 
	 {
		 unsigned gmcpt_search_1stframe_high          : 8;
		 unsigned gmcpt_search_2ndframe_high          : 8;
		 unsigned reserved0                           : 16;
	 }bit_info; 
}GMCPT_SEARCH_HIGH_U; 

typedef union GMCPT_SEARCH_2NDFRAME_LOW_U_ 
{
	 unsigned long v;
	 struct GMCPT_SEARCH_2NDFRAME_LOW_T_ 
	 {
		 unsigned gmcpt_search_2ndframe_low           : 32;
	 }bit_info; 
}GMCPT_SEARCH_2NDFRAME_LOW_U; 

typedef union HBLANK_THRESHOLD_U_ 
{
	 unsigned long v;
	 struct HBLANK_THRESHOLD_T_ 
	 {
		 unsigned hblank_min                          : 16;
		 unsigned hblank_max                          : 16;
	 }bit_info; 
}HBLANK_THRESHOLD_U; 

typedef union VBLANK_MIN_U_ 
{
	 unsigned long v;
	 struct VBLANK_MIN_T_ 
	 {
		 unsigned vblank_min                          : 32;
	 }bit_info; 
}VBLANK_MIN_U; 

typedef union FRAME_MONITOR_CNT_U_ 
{
	 unsigned long v;
	 struct FRAME_MONITOR_CNT_T_ 
	 {
		 unsigned monitor_col_cnt                     : 11;
		 unsigned monitor_row_cnt                     : 11;
		 unsigned monitor_hblank_cnt                  : 10;
	 }bit_info; 
}FRAME_MONITOR_CNT_U; 

typedef union VBLANK_MONITOR_CNT_U_ 
{
	 unsigned long v;
	 struct VBLANK_MONITOR_CNT_T_ 
	 {
		 unsigned vblank_monitor_cnt                  : 20;
		 unsigned reserved0                           : 12;
	 }bit_info; 
}VBLANK_MONITOR_CNT_U; 

typedef union GMC_COEF1_FRAME1_U_ 
{
	 unsigned long v;
	 struct GMC_COEF1_FRAME1_T_ 
	 {
		 unsigned gmc_coef1_frame1                    : 32;
	 }bit_info; 
}GMC_COEF1_FRAME1_U; 

typedef union GMC_COEF2_FRAME1_U_ 
{
	 unsigned long v;
	 struct GMC_COEF2_FRAME1_T_ 
	 {
		 unsigned gmc_coef2_frame1                    : 32;
	 }bit_info; 
}GMC_COEF2_FRAME1_U; 

typedef union GMC_COEF3_FRAME1_U_ 
{
	 unsigned long v;
	 struct GMC_COEF3_FRAME1_T_ 
	 {
		 unsigned gmc_coef3_frame1                    : 32;
	 }bit_info; 
}GMC_COEF3_FRAME1_U; 

typedef union GMC_COEF4_FRAME1_U_ 
{
	 unsigned long v;
	 struct GMC_COEF4_FRAME1_T_ 
	 {
		 unsigned gmc_coef4_frame1                    : 32;
	 }bit_info; 
}GMC_COEF4_FRAME1_U; 

typedef union GMC_COEF5_FRAME1_U_ 
{
	 unsigned long v;
	 struct GMC_COEF5_FRAME1_T_ 
	 {
		 unsigned gmc_coef5_frame1                    : 32;
	 }bit_info; 
}GMC_COEF5_FRAME1_U; 

typedef union GMC_COEF1_FRAME2_U_ 
{
	 unsigned long v;
	 struct GMC_COEF1_FRAME2_T_ 
	 {
		 unsigned gmc_coef1_frame2                    : 32;
	 }bit_info; 
}GMC_COEF1_FRAME2_U; 

typedef union GMC_COEF2_FRAME2_U_ 
{
	 unsigned long v;
	 struct GMC_COEF2_FRAME2_T_ 
	 {
		 unsigned gmc_coef2_frame2                    : 32;
	 }bit_info; 
}GMC_COEF2_FRAME2_U; 

typedef union GMC_COEF3_FRAME2_U_ 
{
	 unsigned long v;
	 struct GMC_COEF3_FRAME2_T_ 
	 {
		 unsigned gmc_coef3_frame2                    : 32;
	 }bit_info; 
}GMC_COEF3_FRAME2_U; 

typedef union GMC_COEF4_FRAME2_U_ 
{
	 unsigned long v;
	 struct GMC_COEF4_FRAME2_T_ 
	 {
		 unsigned gmc_coef4_frame2                    : 32;
	 }bit_info; 
}GMC_COEF4_FRAME2_U; 

typedef union GMC_COEF5_FRAME2_U_ 
{
	 unsigned long v;
	 struct GMC_COEF5_FRAME2_T_ 
	 {
		 unsigned gmc_coef5_frame2                    : 32;
	 }bit_info; 
}GMC_COEF5_FRAME2_U; 

typedef union IRCMIF_DEBUGSEL_U_ 
{
	 unsigned long v;
	 struct IRCMIF_DEBUGSEL_T_ 
	 {
		 unsigned front_to_usb                        : 1;
		 unsigned gradient_to_usb                     : 1;
		 unsigned corre_to_usb                        : 1;
		 unsigned shift_to_usb                        : 1;
		 unsigned downscale_to_usb                    : 1;
		 unsigned gradient_joint                      : 1;
		 unsigned gmc_to_usb                          : 1;
		 unsigned ref_to_usb                          : 1;
		 unsigned front_to_debug                      : 1;
		 unsigned gradient_to_debug                   : 1;
		 unsigned corre_to_debug                      : 1;
		 unsigned shift_to_debug                      : 1;
		 unsigned downscale_to_debug                  : 1;
		 unsigned gmc_to_debug                        : 1;
		 unsigned ref_to_debug                        : 1;
		 unsigned blob_to_debug                       : 1;
		 unsigned irout_to_debug                      : 1;
		 unsigned input_stagefifo_error_clr           : 1;
		 unsigned holefilling_to_usb                  : 1;
		 unsigned holefilling_to_debug                : 1;
		 unsigned blob_to_usb                         : 1;
		 unsigned pre_siggen_en                       : 1;
		 unsigned usb_siggen_en                       : 1;
		 unsigned ircmif_debugsel                     : 9;
	 }bit_info; 
}IRCMIF_DEBUGSEL_U; 

typedef union IRCMIF_NOISE_FILTER_U_ 
{
	 unsigned long v;
	 struct IRCMIF_NOISE_FILTER_T_ 
	 {
		 unsigned snr_threshold                       : 8;
		 unsigned noise_default                       : 8;
		 unsigned reserved0                           : 16;
	 }bit_info; 
}IRCMIF_NOISE_FILTER_U; 

typedef union IRCMIF_HBLANK_U_ 
{
	 unsigned long v;
	 struct IRCMIF_HBLANK_T_ 
	 {
		 unsigned correlation_out_hblank              : 16;
		 unsigned blob_out_hblank                     : 16;
	 }bit_info; 
}IRCMIF_HBLANK_U; 

typedef union IRCMIF_BLOB_U_ 
{
	 unsigned long v;
	 struct IRCMIF_BLOB_T_ 
	 {
		 unsigned blob_area_threshold                 : 16;
		 unsigned blob_similar_threshold              : 8;
		 unsigned reserved0                           : 8;
	 }bit_info; 
}IRCMIF_BLOB_U; 

typedef union IRCMIF_CLKGATING_EN_U_ 
{
	 unsigned long v;
	 struct IRCMIF_CLKGATING_EN_T_ 
	 {
		 unsigned clk_gating_en                       : 13;
		 unsigned reserved0                           : 1;
		 unsigned corre_shadow_en                     : 1;
		 unsigned hw_ctr_clkgating                    : 1;
		 unsigned blob_clkgating_en                   : 1;
		 unsigned shift_clkgating_en                  : 1;
		 unsigned darkcheck_clkgating_en              : 1;
		 unsigned first_ds_clkgating_en               : 1;
		 unsigned second_ds_clkgating_en              : 1;
		 unsigned gmc_compense_clkgating_en           : 1;
		 unsigned gmc_collection_clkgating_en         : 1;
		 unsigned corre_clkgating_en                  : 1;
		 unsigned holefilling_clkgating_en            : 1;
		 unsigned reserved1                           : 7;
	 }bit_info; 
}IRCMIF_CLKGATING_EN_U; 

typedef union IRCMIF_OUTCONTROL_U_ 
{
	 unsigned long v;
	 struct IRCMIF_OUTCONTROL_T_ 
	 {
		 unsigned out_hblank                          : 16;
		 unsigned out_pix_cycle                       : 8;
		 unsigned reserved0                           : 8;
	 }bit_info; 
}IRCMIF_OUTCONTROL_U; 

typedef union IRCMIF_COMMON_USE_0_U_ 
{
	 unsigned long v;
	 struct IRCMIF_COMMON_USE_0_T_ 
	 {
		 unsigned holefilling_outhblank               : 16;
		 unsigned length_threshold                    : 5;
		 unsigned col_gradients_threshold             : 11;
	 }bit_info; 
}IRCMIF_COMMON_USE_0_U; 

typedef union IRCMIF_COMMON_USE_1_U_ 
{
	 unsigned long v;
	 struct IRCMIF_COMMON_USE_1_T_ 
	 {
		 unsigned line_gradients_threshold            : 11;
		 unsigned col_threshold                       : 3;
		 unsigned reserved0                           : 2;
		 unsigned blob_gradients_threshold            : 11;
		 unsigned reserved1                           : 5;
	 }bit_info; 
}IRCMIF_COMMON_USE_1_U; 

typedef union IRCMIF_COMMON_USE_2_U_ 
{
	 unsigned long v;
	 struct IRCMIF_COMMON_USE_2_T_ 
	 {
		 unsigned sig_gen_hblank                      : 16;
		 unsigned sig_gen_vblank                      : 8;
		 unsigned reserved0                           : 8;
	 }bit_info; 
}IRCMIF_COMMON_USE_2_U; 

typedef union IRCMIF_COMMON_USE_3_U_ 
{
	 unsigned long v;
	 struct IRCMIF_COMMON_USE_3_T_ 
	 {
		 unsigned data_value_1                        : 12;
		 unsigned data_value_2                        : 12;
		 unsigned common_use_3                        : 8;
	 }bit_info; 
}IRCMIF_COMMON_USE_3_U; 

typedef union IRCMIF_VERSION_U_ 
{
	 unsigned long v;
	 struct IRCMIF_VERSION_T_ 
	 {
		 unsigned ircmif_debug_version                : 16;
		 unsigned ircmif_version                      : 16;
	 }bit_info; 
}IRCMIF_VERSION_U; 

typedef union IRCMIF_DUMMY_U_ 
{
	 unsigned long v;
	 struct IRCMIF_DUMMY_T_ 
	 {
		 unsigned ircmif_dummy                        : 32;
	 }bit_info; 
}IRCMIF_DUMMY_U; 

typedef struct IRCMIF_T_ 
{ 
   BINCALC_C_U                         bincalc_c;                           //0x0000 
   BINCALC_VL_U                        bincalc_vl;                          //0x0004 
   BINCALC_VH_U                        bincalc_vh;                          //0x0008 
   BINCALC_T_U                         bincalc_t;                           //0x000c 
   SAD_BAD_U                           sad_bad;                             //0x0010 
   SAD_GOOD_U                          sad_good;                            //0x0014 
   CONST_SHIFT_U                       const_shift;                         //0x0018 
   SATURATED_AREA_U                    saturated_area;                      //0x001c 
   IRCMIF_INT_STATUS_U                 ircmif_int_status;                   //0x0020 
   IRCMIF_INT_ENABLE_U                 ircmif_int_enable;                   //0x0024 
   IRCMIF_INT_CLEAR_U                  ircmif_int_clear;                    //0x0028 
   GMC_POINT_VALID_MAP_U               gmc_point_valid_map;                 //0x002c 
   IRCMIF_DBG_STATUS0_U                ircmif_dbg_status0;                  //0x0030 
   IRCMIF_DBG_STATUS1_U                ircmif_dbg_status1;                  //0x0034 
   IRCMIF_CTRL_U                       ircmif_ctrl;                         //0x0038 
   IRCMIF_AHB_RAM_STATUS_U             ircmif_ahb_ram_status;               //0x003c 
   IRCMIF_FRAME_RESOLUTION_U           ircmif_frame_resolution;             //0x0040 
   GMCPT_SEARCH_1STFRAME_LOW_U         gmcpt_search_1stframe_low;           //0x0044 
   GMCPT_SEARCH_HIGH_U                 gmcpt_search_high;                   //0x0048 
   GMCPT_SEARCH_2NDFRAME_LOW_U         gmcpt_search_2ndframe_low;           //0x004c 
   HBLANK_THRESHOLD_U                  hblank_threshold;                    //0x0050 
   VBLANK_MIN_U                        vblank_min;                          //0x0054 
   FRAME_MONITOR_CNT_U                 frame_monitor_cnt;                   //0x0058 
   VBLANK_MONITOR_CNT_U                vblank_monitor_cnt;                  //0x005c 
   GMC_COEF1_FRAME1_U                  gmc_coef1_frame1;                    //0x0060 
   GMC_COEF2_FRAME1_U                  gmc_coef2_frame1;                    //0x0064 
   GMC_COEF3_FRAME1_U                  gmc_coef3_frame1;                    //0x0068 
   GMC_COEF4_FRAME1_U                  gmc_coef4_frame1;                    //0x006c 
   GMC_COEF5_FRAME1_U                  gmc_coef5_frame1;                    //0x0070 
   GMC_COEF1_FRAME2_U                  gmc_coef1_frame2;                    //0x0074 
   GMC_COEF2_FRAME2_U                  gmc_coef2_frame2;                    //0x0078 
   GMC_COEF3_FRAME2_U                  gmc_coef3_frame2;                    //0x007c 
   GMC_COEF4_FRAME2_U                  gmc_coef4_frame2;                    //0x0080 
   GMC_COEF5_FRAME2_U                  gmc_coef5_frame2;                    //0x0084 
   IRCMIF_DEBUGSEL_U                   ircmif_debugsel;                     //0x0088 
   IRCMIF_NOISE_FILTER_U               ircmif_noise_filter;                 //0x008c 
   IRCMIF_HBLANK_U                     ircmif_hblank;                       //0x0090 
   IRCMIF_BLOB_U                       ircmif_blob;                         //0x0094 
   IRCMIF_CLKGATING_EN_U               ircmif_clkgating_en;                 //0x0098 
   IRCMIF_OUTCONTROL_U                 ircmif_outcontrol;                   //0x009c 
   IRCMIF_COMMON_USE_0_U               ircmif_common_use_0;                 //0x00a0 
   IRCMIF_COMMON_USE_1_U               ircmif_common_use_1;                 //0x00a4 
   IRCMIF_COMMON_USE_2_U               ircmif_common_use_2;                 //0x00a8 
   IRCMIF_COMMON_USE_3_U               ircmif_common_use_3;                 //0x00ac 
   IRCMIF_DUMMY_U                      ircmif_dummy0;                       //0x00b0 
   IRCMIF_DUMMY_U                      ircmif_dummy1;                       //0x00b4 
   IRCMIF_DUMMY_U                      ircmif_dummy2;                       //0x00b8 
   IRCMIF_DUMMY_U                      ircmif_dummy3;                       //0x00bc 
   IRCMIF_DUMMY_U                      ircmif_dummy4;                       //0x00c0 
   IRCMIF_DUMMY_U                      ircmif_dummy5;                       //0x00c4 
   IRCMIF_DUMMY_U                      ircmif_dummy6;                       //0x00c8 
   IRCMIF_DUMMY_U                      ircmif_dummy7;                       //0x00cc 
   IRCMIF_DUMMY_U                      ircmif_dummy8;                       //0x00d0 
   IRCMIF_DUMMY_U                      ircmif_dummy9;                       //0x00d4 
   IRCMIF_DUMMY_U                      ircmif_dummy10;                      //0x00d8 
   IRCMIF_DUMMY_U                      ircmif_dummy11;                      //0x00dc 
   IRCMIF_DUMMY_U                      ircmif_dummy12;                      //0x00e0 
   IRCMIF_DUMMY_U                      ircmif_dummy13;                      //0x00e4 
   IRCMIF_DUMMY_U                      ircmif_dummy14;                      //0x00e8 
   IRCMIF_DUMMY_U                      ircmif_dummy15;                      //0x00ec 
   IRCMIF_DUMMY_U                      ircmif_dummy16;                      //0x00f0 
   IRCMIF_DUMMY_U                      ircmif_dummy17;                      //0x00f4 
   IRCMIF_DUMMY_U                      ircmif_dummy18;                      //0x00f8 
   IRCMIF_VERSION_U                    ircmif_version;                      //0x00fc 
}IRCMIF_T;



#endif 
