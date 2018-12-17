/********************************************************************************
 *            Copyright(c) 2015 Actions (Zhuhai) Technology Co., Limited,
 *                            All Rights Reserved.
 *
 * 描述：RAM地址定义
 * 作者：liminxian
 ********************************************************************************/

#ifndef __ADDR_MAP_H__
#define __ADDR_MAP_H__

#define SRAM_BANK_A_ADDR    0x09000
#define SRAM_BANK_A_SIZE    0x400
#define SRAM_BANK_B_ADDR    0x09400
#define SRAM_BANK_B_SIZE    0x800
#define SRAM_BANK_C_ADDR    0x1f400
#define SRAM_BANK_C_SIZE    0x400

#define SRAM_SIZE_MASK      0x3ffff
#define RDATA_ADDR_BASE     0x9fc00000
#define RCODE_ADDR_BASE     0xbfc00000

#define KERNEL_TLB_MAX      22

//SDFW INFO
#define SDFW_SEC_BIT                     8
#define SDFW_SEC_SIZE                   (1<<SDFW_SEC_BIT)//256
#define SDFW_AP_HEAD_INFO_SZIE          (SDFW_SEC_SIZE)
#define SDFW_MMM_HEAD_INFO_SZIE         (SDFW_SEC_SIZE)
#define SDFW_DRV_HEAD_INFO_SZIE         (SDFW_SEC_SIZE*2)
#define SDFW_BANK_CNT_MAX               (64)
#define SDFW_BANK_INDEX_SZIE            (SDFW_SEC_SIZE*3)
#define SDFW_KERNEL_BANK_INFO_OFFSET    (128)

#define KERNEL_BANK_A       0x1
#define KERNEL_BANK_B       0x2
#define KERNEL_BANK_C       0x3

#define AP_BANK_FRONT_CONTROL_1 0x40
#define AP_BANK_FRONT_CONTROL_1_PAGE_INDEX  4
#define AP_BANK_FRONT_CONTROL_1_BASE_OFFSET         (SDFW_SEC_SIZE)

#define AP_BANK_AUTOTEST 0x41
#define AP_BANK_AUTOTEST_PAGE_INDEX 3   //复用bankC代码        
#define AP_BANK_AUTOTEST_BASE_OFFSET (SDFW_SEC_SIZE)

#define AP_BANK_FRONT_UI_1      0x48
#define AP_BANK_FRONT_UI_1_PAGE_INDEX       5
#define AP_BANK_FRONT_UI_1_BASE_OFFSET              (SDFW_SEC_SIZE*4)

#define AP_BANK_FRONT_BASAL     0x50
//#define AP_BANK_FRONT_BASAL_PAGE_INDEX      6
#define AP_BANK_FRONT_BASAL_PAGE_INDEX      20
#define AP_BANK_FRONT_BASAL_BASE_OFFSET             (SDFW_SEC_SIZE)

#define AP_BANK_FRONT_CODEC     0x58
#define AP_BANK_FRONT_CODEC_PAGE_INDEX      7
#define AP_BANK_FRONT_CODEC_BASE_OFFSET             (SDFW_SEC_SIZE)

#define AP_BANK_BACK_CONTROL_1  0x60
//#define AP_BANK_BACK_CONTROL_1_PAGE_INDEX   8
#define AP_BANK_BACK_CONTROL_1_PAGE_INDEX   16
#define AP_BANK_BACK_CONTROL_1_BASE_OFFSET          (SDFW_SEC_SIZE)

#define AP_BANK_BACK_BASAL      0x68
//#define AP_BANK_BACK_BASAL_PAGE_INDEX       9
#define AP_BANK_BACK_BASAL_PAGE_INDEX       7
#define AP_BANK_BACK_BASAL_BASE_OFFSET              (SDFW_SEC_SIZE)

#define AP_BANK_BACK_CODEC      0x70
#define AP_BANK_BACK_CODEC_PAGE_INDEX       10
#define AP_BANK_BACK_CODEC_BASE_OFFSET              (SDFW_SEC_SIZE)

#define AP_BANK_FRONT_ENHANCED_1      0x78
#define AP_BANK_FRONT_ENHANCED_1_PAGE_INDEX      11
#define AP_BANK_FRONT_ENHANCED_1_BASE_OFFSET        (SDFW_SEC_SIZE*7)

#define AP_BANK_FRONT_ENHANCED_2      0x71
#define AP_BANK_FRONT_ENHANCED_2_PAGE_INDEX      12
#define AP_BANK_FRONT_ENHANCED_2_BASE_OFFSET        (SDFW_SEC_SIZE*10)

#define AP_BANK_BACK_ENHANCED_1       0x7a
//#define AP_BANK_BACK_ENHANCED_1_PAGE_INDEX       13
#define AP_BANK_BACK_ENHANCED_1_PAGE_INDEX       7
#define AP_BANK_BACK_ENHANCED_1_BASE_OFFSET         (SDFW_SEC_SIZE*4)

#define AP_BANK_BACK_ENHANCED_2       0x7b
#define AP_BANK_BACK_ENHANCED_2_PAGE_INDEX       14
#define AP_BANK_BACK_ENHANCED_2_BASE_OFFSET         (SDFW_SEC_SIZE*7)

#define AP_BANK_MANAGER               0x7f
//#define AP_BANK_MANAGER_PAGE_INDEX               15
#define AP_BANK_MANAGER_PAGE_INDEX              20
#define AP_BANK_MANAGER_BASE_OFFSET                 (SDFW_SEC_SIZE)

#define AP_BANK_BTENGINE_CONTROL_1    0x72
#define AP_BANK_BTENGINE_CONTROL_1_PAGE_INDEX    16
#define AP_BANK_BTENGINE_CONTROL_1_BASE_OFFSET      (SDFW_SEC_SIZE)

#define AP_BANK_BTENGINE_LIB_1        0x73
#define AP_BANK_BTENGINE_LIB_1_PAGE_INDEX        17
#define AP_BANK_BTENGINE_LIB_1_BASE_OFFSET          (SDFW_SEC_SIZE * 4)

#define AP_BANK_BTENGINE_LIB_2        0x74
#define AP_BANK_BTENGINE_LIB_2_PAGE_INDEX        18
#define AP_BANK_BTENGINE_LIB_2_BASE_OFFSET          (SDFW_SEC_SIZE * 7)

#define AP_BANK_BTENGINE_EXTEND_1     0x75
#define AP_BANK_BTENGINE_EXTEND_1_PAGE_INDEX     19
#define AP_BANK_BTENGINE_EXTEND_1_BASE_OFFSET       (SDFW_SEC_SIZE * 10)

#define AP_BANK_BTENGINE_EXTEND_2     0x76
#define AP_BANK_BTENGINE_EXTEND_2_PAGE_INDEX     20
#define AP_BANK_BTENGINE_EXTEND_2_BASE_OFFSET       (SDFW_SEC_SIZE * 13)

#define AP_BANK_BTENGINE_EXTEND_3    0x77
//#define AP_BANK_BTENGINE_EXTEND_3_PAGE_INDEX     21
#define AP_BANK_BTENGINE_EXTEND_3_BASE_OFFSET (SDFW_SEC_SIZE * 16)

#define AP_BANK_BTENGINE_EXTEND_4        0x7c
#define AP_BANK_BTENGINE_EXTEND_4_PAGE_INDEX         7
#define AP_BANK_BTENGINE_EXTEND_4_BASE_OFFSET (SDFW_SEC_SIZE * 19)

#define AP_BANK_BTENGINE_EXTEND_5        0x79
#define AP_BANK_BTENGINE_EXTEND_5_PAGE_INDEX          0
#define AP_BANK_BTENGINE_EXTEND_5_BASE_OFFSET (SDFW_SEC_SIZE * 22)



#define DSP_CODEC_BANK1_PAGE_INDEX   22
#define DSP_CODEC_BANK2_PAGE_INDEX   23
#define DSP_CODEC_BANK3_PAGE_INDEX   24
#define DSP_CODEC_BANK4_PAGE_INDEX   25
#define DSP_CODEC_BANK_PAGE_MAX      26

#define DSP_CODEC_BANK1_BASE_OFFSET  (256)
#define DSP_CODEC_BANK2_BASE_OFFSET  (256+1*192)
#define DSP_CODEC_BANK3_BASE_OFFSET  (256+2*192)
#define DSP_CODEC_BANK4_BASE_OFFSET  (256+3*192)





#endif
