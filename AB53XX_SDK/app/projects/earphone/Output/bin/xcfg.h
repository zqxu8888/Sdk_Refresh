//该头文件由软件自动生成，请勿随意修改！
#ifndef _XCFG_H
#define _XCFG_H

#define XCFG_EN             1

typedef struct __attribute__((packed)) _xcfg_cb_t {
    u8 lang_id;                                 //提示音语言选择: 0:英文, 1:中文, 2:中英文(出厂默认英文), 3:中英文(出厂默认中文)
    u32 buck_mode_en                     : 1;   //BUCK MODE
    u32 pwron_frist_bat_en               : 1;   //第一次上电直接开机
    u32 soft_power_on_off_en             : 1;   //软开关机功能
    u32 powkey_10s_reset                 : 1;   //POWKEY 10s复位系统
    u32 spk_mute_en                      : 1;   //功放MUTE功能
    u8 spk_mute_io_sel;                         //功放MUTE控制IO选择: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2, 25:PF3, 26:PF4
    u32 high_mute                        : 1;   //高MUTE
    u8 loudspeaker_unmute_delay;                //功放MUTE延时(单位5ms)
    u16 sys_sleep_time;                         //自动休眠时间: 不休眠: 0, 10秒钟后: 10, 20秒钟后: 20, 30秒钟后: 30, 45秒钟后: 45, 1分钟后: 60, 2分钟后: 120, 3分钟后: 180, 4分钟后: 240, 5分钟后: 300, 6分钟后: 360, 7分钟后: 420, 8分钟后: 480, 9分钟后: 540, 10分钟后: 600, 15分钟后: 900, 20分钟后: 1200, 25分钟后: 1500, 30分钟后: 1800, 45分钟后: 2700, 1小时后: 3600
    u16 sys_off_time;                           //自动关机时间: 不关机: 0, 30秒钟后: 30, 1分钟后: 60, 2分钟后: 120, 3分钟后: 180, 4分钟后: 240, 5分钟后: 300, 6分钟后: 360, 7分钟后: 420, 8分钟后: 480, 9分钟后: 540, 10分钟后: 600, 15分钟后: 900, 20分钟后: 1200, 25分钟后: 1500, 30分钟后: 1800, 45分钟后: 2700, 1小时后: 3600
    u32 lowpower_warning_en              : 1;   //低电提示
    u8 lpwr_warning_vbat;                       //低电语音提示电压: 0:2.8V, 1:2.9V, 2:3.0V, 3:3.1V, 4:3.2V, 5:3.3V, 6:3.4V, 7:3.5V, 8:3.6V, 9:3.7V
    u8 lpwr_off_vbat;                           //低电关机电压: 0:不关机, 1:2.8V, 2:2.9V, 3:3.0V, 4:3.1V, 5:3.2V, 6:3.3V, 7:3.4V, 8:3.5V, 9:3.6V, 10:3.7V
    u8 lpwr_warning_period;                     //低电语音播报周期(秒)
    u8 vol_max;                                 //音量级数: 0:16级音量, 1:30级音量, 2:32级音量
    u32 sys_vol_fixed_2_init_vol         : 1;   //开机音量固定为默认音量
    u8 sys_init_vol;                            //开机默认音量
    u8 sys_limit_volume;                        //恢复默认音量的阈值
    u8 warning_volume;                          //提示音播放音量
    u8 osc_both_cap;                            //OSC基础电容: 0:0PF, 1:6PF
    u8 osci_cap;                                //OSCI电容(0.25PF)
    u8 osco_cap;                                //OSCO电容(0.25PF)
    u32 eq_dgb_spp_en                    : 1;   //EQ调试（蓝牙串口）
    u32 eq_dgb_uart_en                   : 1;   //EQ调试（UART）
    u8 eq_uart_sel;                             //EQ调试串口选择: 0:PA7, 1:PB2, 2:PB3
    u32 linein_2_pwrdown_en              : 1;   //插入LINEIN关机
    u8 linein_2_pwrdown_tone_en;                //插入LINEIN关机提示音: 0:None, 1:关机提示音, 2:LINEIN提示音
    u8 linein_det_io;                           //选择LINEIN检测IO: 0:复用MICL检测, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2
    u8 dac_sel;                                 //DAC声道选择: 0:单声道, 1:双声道, 2:差分单声道, 3:差分双声道, 4:VCMBUF单声道, 5:VCMBUF双声道, 6:MIX_VCM单声道, 7:MIX_VCM差分
    u8 dac_ldoh_sel;                            //VDDDAC电压: 0:2.4V, 1:2.5V, 2:2.7V, 3:2.9V, 4:3.1V, 5:3.2V
    u8 dac_pull_down_delay;                     //DAC隔直电容放电时间
    u32 dac_vcm_less_en                  : 1;   //省VCM方案
    u8 dac_max_gain;                            //DAC最大音量: 0:-9DB, 1:-8DB, 2:-7DB, 3:-6DB, 4:-5DB, 5:-4DB, 6:-3DB, 7:-2DB, 8:-1DB, 9:0DB, 10:+1DB, 11:+2DB, 12:+3DB, 13:+4DB, 14:+5DB
    u8 bt_call_max_gain;                        //通话最大音量: 0:-9DB, 1:-8DB, 2:-7DB, 3:-6DB, 4:-5DB, 5:-4DB, 6:-3DB, 7:-2DB, 8:-1DB, 9:0DB, 10:+1DB, 11:+2DB, 12:+3DB, 13:+4DB, 14:+5DB
    u32 dac_max_digvol;                         //系统最大数字音量
    u32 maxvol_tone_is_mp3               : 1;   //最大音量提示音MP3格式
    u32 dac_off_for_conn                 : 1;   //蓝牙连接时关闭DAC
    u32 charge_en                        : 1;   //充电使能
    u32 support_ext_charge_ic            : 1;   //支持外接充电IC
    u32 charge_trick_en                  : 1;   //涓流充电使能
    u32 charge_dc_reset                  : 1;   //插入DC复位系统
    u32 charge_dc_not_pwron              : 1;   //插入DC禁止软开机
    u32 charge_warehouse_set             : 3;   //充电仓充电操作选项: 不进行任何操作: 0, 耳机充电完成自动关机: 1, 耳机从充电仓拿起自动开机: 2
    u8 charge_stop_curr;                        //充电截止电流: 0:2.5mA, 1:5mA, 2:10mA, 3:15mA, 4:20mA, 5:25mA, 6:30mA, 7:35mA
    u8 charge_constant_curr;                    //恒流充电电流: 0:30mA, 1:40mA, 2:50mA, 3:60mA, 4:70mA, 5:80mA, 6:90mA, 7:100mA, 8:110mA, 9:120mA, 10:140mA, 11:160mA, 12:180mA, 13:200mA
    u8 charge_trickle_curr;                     //涓流充电电流: 0:30mA, 1:40mA, 2:50mA
    char bt_name[32];                           //蓝牙名称
    u8 bt_addr[6];                              //蓝牙地址
    u8 bt_txpwr;                                //#1 预置RF发射功率: 0:+4DBM, 1:+3DBM, 2:+2DBM, 3:+1DBM, 4:0DBM
    u32 bt_rf_param                      : 8;   //#1 预置RF参数选择: LQFP48: 0, QFN32: 1, SOP28: 2, TSSOP24: 3, TSSOP20: 4, SOP16: 5, QFN32小耳机板: 129, SOP16小耳机板: 133, AUTO: 255
    u8 bt_rf_user_param;                        //#2 main.c定义RF参数: 0:不使用, 1:参数0, 2:参数1, 3:参数2, 4:参数3, 5:参数4, 6:参数5, 7:参数6, 8:参数7, 9:参数8, 10:参数9, 11:参数10, 12:参数11, 13:参数12, 14:参数13, 15:参数14, 16:参数15
    u32 bt_user_param_en                 : 1;   //#3 是否自定义RF参数
    u8 rf_tag0;                                 //#3 TAG0
    u8 rf_tag1;                                 //#3 TAG1
    u8 rf_captune;                              //#3 CAPTUNE
    u8 rf_pa_gain;                              //#3 PA_GAIN
    u8 rf_mix_gain;                             //#3 MIX_GAIN
    u8 rf_dig_gain;                             //#3 DIG_GAIN
    u8 rf_pa_bias;                              //#3 PA_BIAS
    u8 rf_vbko_add;                             //#3 VBKO_ADD
    u8 rf_txdbm;                                //#3 DBM
    u8 rf_udf;                                  //#3 UDF
    u32 rf_param_sco_en                  : 1;   //#3 通话RF参数
    u8 rf_mix_gain_sco;                         //#3 通话MIX_GAIN0
    u8 rf_dig_gain_sco;                         //#3 通话DIG_GAIN0
    u32 bt_rf_ltx_recon                  : 1;   //降低回连TXPWR
    u8 bt_pwrkey_nsec_discover;                 //长按几秒开机进配对: 0:不支持, 1:1秒, 2:2秒, 3:3秒, 4:4秒, 5:5秒, 6:6秒, 7:7秒, 8:8秒
    u8 bt_power_up_reconnect_times;             //上电回连次数(每次5秒)
    u8 bt_time_out_reconnect_times;             //掉线回连次数(每次5秒)
    u32 warning_bt_pair                  : 1;   //配对提示音
    u32 bt_pair_sleep_en                 : 1;   //未配对是否进入休眠模式
    u32 bt_2acl_en                       : 1;   //连接两部手机功能
    u32 bt_a2dp_en                       : 1;   //音乐播放功能
    u32 bt_a2dp_vol_ctrl_en              : 1;   //音乐音量同步
    u32 bt_sco_en                        : 1;   //通话功能
    u32 bt_hfp_private_en                : 1;   //私密接听功能
    u32 bt_hfp_ring_number_en            : 1;   //来电报号功能
    u32 bt_spp_en                        : 1;   //串口功能
    u32 bt_hid_en                        : 1;   //拍照功能
    u32 bt_hid_menu_en                   : 1;   //按键HID连接/断开功能
    u32 bt_hid_discon_default_en         : 1;   //HID默认不连接
    u32 func_bthid_en                    : 1;   //HID独立自拍器模式
    char bthid_name[32];                        //HID蓝牙名称
    u32 bt_siri_ctrl_en                  : 3;   //复用Siri键设置: 不支持: 0, 长按P/P键2S: 1, 双击P/P键: 2
    u32 bt_siri_key_sel                  : 2;   //独立Siri键设置: 单击SIRI键: 0, 双击SIRI键: 1, 长按SIRI键: 2
    u32 bt_tws_en                        : 1;   //TWS功能
    u32 bt_tws_pair_mode                 : 3;   //TWS配对方式选择: 自动配对: 0, 双击PLAY/POWER键配对: 1, 长按MODE键配对: 2, 自定义配对<调用api>: 3
    u32 bt_tws_lr_mode                   : 4;   //TWS声道分配选择: 不分配，主副均双声道输出: 0, 自动分配，主右声道副左声道: 1, PWRKEY,有820K接地为左: 2, GPIOx有接地为左: 3, 自动分配，主左声道副右声道: 4
    u32 tws_sel_left_gpio_sel            : 6;   //TWS GPIOx有接地为左: None: 0, PA0: 1, PA1: 2, PA2: 3, PA3: 4, PA4: 5, PA5: 6, PA6: 7, PA7: 8, PB0: 9, PB1: 10, PB2: 11, PB3: 12, PB4: 13, PE0: 14, PE1: 15, PE2: 16, PE3: 17, PE4: 18, PE5: 19, PE6: 20, PE7: 21, PF0: 22, PF1: 23, PF2: 24, PF3: 25, PF4: 26, PF5: 27
    u32 ble_en                           : 1;   //BLE控制功能
    char le_name[32];                           //BLE名称
    u32 bt_test_redial_en                : 1;   //测试模式双击回拨
    u8 bt_ch_mic;                               //MIC通路选择: 0:MICL0(MICL2ADCL), 1:MICL1(MICR2ADCL), 2:MICR0(MICR2ADCR), 3:MICR1(MICL2ADCR)
    u8 bt_anl_gain;                             //MIC模拟增益
    u8 bt_dig_gain;                             //MIC数字增益(0~3DB)
    u32 bt_noise_threshoid;                     //环境噪声阈值
    u32 bt_aec_en                        : 1;   //AEC功能
    u8 bt_echo_level;                           //AEC回声消除级别
    u8 bt_far_offset;                           //AEC远端补偿值
    u32 bt_alc_en                        : 1;   //ALC功能
    u8 bt_alc_in_delay;                         //ALC淡入延时: 0:16ms, 1:64ms, 2:112ms, 3:160ms, 4:224ms, 5:288ms
    u8 bt_alc_in_step;                          //ALC淡入速度: 0:4ms, 1:8ms, 2:16ms, 3:32ms, 4:64ms, 5:128ms
    u8 bt_alc_out_delay;                        //ALC淡出延时: 0:16ms, 1:64ms, 2:112ms, 3:160ms, 4:224ms, 5:288ms
    u8 bt_alc_out_step;                         //ALC淡出速度: 0:4ms, 1:8ms, 2:16ms, 3:32ms, 4:64ms, 5:128ms
    u32 user_pwrkey_en                   : 1;   //PWRKEY功能
    u32 user_adkey_en                    : 1;   //ADKEY1功能
    u32 user_adkey2_en                   : 1;   //ADKEY2功能
    u32 user_iokey_en                    : 1;   //IOKEY功能
    u32 user_key_double_en               : 1;   //按键双击功能
    u32 double_key_time                  : 3;   //双击响应时间选择: 200ms: 0, 300ms: 1, 400ms: 2, 500ms: 3, 600ms: 4, 700ms: 5, 800ms: 6, 900ms: 7
    u32 adc_detect_linein                : 1;   //复用ADKEY检测LINEIN
    u8 adkey_ch;                                //ADKEY1通路选择: 0:ADCCH_PA5, 1:ADCCH_PA6, 2:ADCCH_PA7, 3:ADCCH_PB1, 4:ADCCH_PB2, 5:ADCCH_PB3, 6:ADCCH_PB4, 7:ADCCH_PE5, 8:ADCCH_PE6, 9:ADCCH_PE7, 10:ADCCH_PF2
    u8 adkey2_ch;                               //ADKEY2通路选择: 0:ADCCH_PA5, 1:ADCCH_PA6, 2:ADCCH_PA7, 3:ADCCH_PB1, 4:ADCCH_PB2, 5:ADCCH_PB3, 6:ADCCH_PB4, 7:ADCCH_PE5, 8:ADCCH_PE6, 9:ADCCH_PE7, 10:ADCCH_PF2
    u8 pwron_press_time;                        //软开机长按时间选择: 0:1.5秒, 1:2秒, 2:2.5秒, 3:3秒, 4:3.5秒, 5:4秒, 6:4.5秒, 7:5秒
    u8 pwroff_press_time;                       //软关机长按时间选择: 0:1.5秒, 1:2秒, 2:2.5秒, 3:3秒, 4:3.5秒, 5:4秒, 6:4.5秒, 7:5秒
    u32 key_double_config_en             : 1;   //支持双击的按键定制
    u8 dblkey_num0;                             //双击按键1选择: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 dblkey_num1;                             //双击按键2选择: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 dblkey_num2;                             //双击按键3选择: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 dblkey_num3;                             //双击按键4选择: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 dblkey_num4;                             //双击按键5选择: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u32 pwrkey_config_en                 : 1;   //PWRKEY按键定制
    u8 pwrkey_num0;                             //PWRKEY按键1功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 pwrkey_num1;                             //PWRKEY按键2功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 pwrkey_num2;                             //PWRKEY按键3功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 pwrkey_num3;                             //PWRKEY按键4功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 pwrkey_num4;                             //PWRKEY按键5功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u32 adkey_config_en                  : 1;   //ADKEY1按键定制
    u8 adkey1_num0;                             //ADKEY1按键1功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num1;                             //ADKEY1按键2功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num2;                             //ADKEY1按键3功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num3;                             //ADKEY1按键4功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num4;                             //ADKEY1按键5功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num5;                             //ADKEY1按键6功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num6;                             //ADKEY1按键7功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num7;                             //ADKEY1按键8功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num8;                             //ADKEY1按键9功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num9;                             //ADKEY1按键10功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num10;                            //ADKEY1按键11功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey1_num11;                            //ADKEY1按键12功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u32 adkey2_config_en                 : 1;   //ADKEY2按键定制
    u8 adkey2_num0;                             //ADKEY2按键1功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num1;                             //ADKEY2按键2功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num2;                             //ADKEY2按键3功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num3;                             //ADKEY2按键4功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num4;                             //ADKEY2按键5功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num5;                             //ADKEY2按键6功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num6;                             //ADKEY2按键7功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num7;                             //ADKEY2按键8功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num8;                             //ADKEY2按键9功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num9;                             //ADKEY2按键10功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num10;                            //ADKEY2按键11功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 adkey2_num11;                            //ADKEY2按键12功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u32 iokey_config_en                  : 1;   //IOKEY按键定制
    u8 iokey_io0;                               //IOKEY按键1的IO: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2
    u8 iokey_io1;                               //IOKEY按键2的IO: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2
    u8 iokey_io2;                               //IOKEY按键3的IO: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2
    u8 iokey_io3;                               //IOKEY按键4的IO: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2
    u8 iokey_num0;                              //IOKEY按键1功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 iokey_num1;                              //IOKEY按键2功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 iokey_num2;                              //IOKEY按键3功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 iokey_num3;                              //IOKEY按键4功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u8 iokey_num4;                              //两IO中间的按键功能: 0:None, 1:PP/POWER, 2:P/P, 3:POWER, 4:NEXT/VOL+, 5:VOL+/NEXT, 6:PREV/VOL-, 7:VOL-/PREV, 8:VOL+, 9:VOL-, 10:NEXT, 11:PREV, 12:MODE, 13:PP/MODE, 14:HSF, 15:EQ, 16:REPEAT, 17:MUTE, 18:VOL/NEXT/PREV, 19:SIRI
    u32 led_disp_en                      : 1;   //系统指示灯(蓝灯)
    u32 led_pwr_en                       : 1;   //电源状态灯(红灯)
    u32 led_btpair_5s_en                 : 1;   //配对状态LED独立状态
    u32 bt_recon_led_en                  : 1;   //回连状态LED独立状态
    u32 charge_full_bled                 : 1;   //充满电蓝灯亮
    u32 charge_full_bled_on_time;               //充满电蓝灯亮的时间(秒)
    u32 bled_low2on_en                   : 1;   //蓝灯低电平亮
    u32 bled_fft_en                      : 1;   //蓝灯频谱闪烁
    u32 rled_lowbat_en                   : 1;   //电池低电闪灯
    u32 rled_lowbat_follow_en            : 1;   //红灯跟随语音闪烁
    u8 bled_io_sel;                             //蓝灯IO选择: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2, 25:PF3, 26:PF4
    u8 rled_io_sel;                             //红灯IO选择: 0:None, 1:PA0, 2:PA1, 3:PA2, 4:PA3, 5:PA4, 6:PA5, 7:PA6, 8:PA7, 9:PB0, 10:PB1, 11:PB2, 12:PB3, 13:PB4, 14:PE0, 15:PE1, 16:PE2, 17:PE3, 18:PE4, 19:PE5, 20:PE6, 21:PE7, 22:PF0, 23:PF1, 24:PF2, 25:PF3, 26:PF4
    u32 led_pwron_config_en              : 1;   //开机状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_poweron;                              //开机闪灯控制
    u32 led_pwroff_config_en             : 1;   //关机状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_poweroff;                             //关机闪灯控制
    u32 led_btinit_config_en             : 1;   //蓝牙初始化状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_btinit;                               //初始化闪灯控制
    u32 led_reconnect_config_en          : 1;   //蓝牙回连状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_reconnect;                            //回连闪灯控制
    u32 led_btpair_config_en             : 1;   //蓝牙配对状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_pairing;                              //配对闪灯控制
    u32 led_btconn_config_en             : 1;   //蓝牙已连接状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_connected;                            //已连接闪灯控制
    u32 led_btmusic_config_en            : 1;   //蓝牙音乐状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_playing;                              //播放闪灯控制
    u32 led_btring_config_en             : 1;   //蓝牙来电状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_ring;                                 //来电闪灯控制
    u32 led_btcall_config_en             : 1;   //蓝牙通话状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_calling;                              //通话闪灯控制
    u32 led_lowbat_config_en             : 1;   //低电状态配置LED
    struct __attribute__((packed)) {
        u8 redpat;
        u8 bluepat;
        u8 unit;
        u8 cycle;
    } led_lowbat;                               //低电闪灯控制
} xcfg_cb_t;

extern xcfg_cb_t xcfg_cb;
#endif
