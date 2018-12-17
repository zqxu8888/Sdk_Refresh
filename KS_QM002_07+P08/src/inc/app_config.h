///////////////////////////////////////////////////////////////////////////////
//               Mountain View Silicon Tech. Inc.
//  Copyright 2012, Mountain View Silicon Tech. Inc., Shanghai, China
//                       All rights reserved.
//  Filename: app_config.h
//  maintainer: Halley
///////////////////////////////////////////////////////////////////////////////
#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include "type.h"
#include "app_msg.h"
#include "timer_api.h"
#include "drc.h"
#include "three_d.h"	
#include "virtual_bass.h"
#include "rtc.h"
#include "bt_device_type.h"
#include "timeout.h"
#include "delay.h"
#include "chip_info.h"
#include "os.h"
#include "eq.h"
#include "eq_params.h"
#include "gpio.h"

//****************************************************************************************
//WAV提示音存放在CODE和CONST区播放宏控制
//此功能用于音乐播放中MIX提示音。
//****************************************************************************************
//#define CFG_WAV_REMINDSOUND_MIX_EN

#ifdef CFG_WAV_REMINDSOUND_MIX_EN
	#include "audio_file.h"
	#define CFG_WAV_REMIND_IN_CODE_AREA			(0)				//存放CODE区
	#define CFG_WAV_REMIND_IN_CONST_AREA		(1)				//存放常数区		
	//#define CFG_WAV_REMIND_DET_ADC_EN							//ADC检测提示音播放
	#define CFG_WAV_REMIND_DET_GPIO_EN							//GPIO检测提示音播放

	#ifdef CFG_WAV_REMIND_DET_ADC_EN
		#define ADC_REMIND_DET_PORT		ADC_CHANNEL_B6			//ADC检测通道
	#endif

	#ifdef CFG_WAV_REMIND_DET_GPIO_EN
	//GPIO KEY1
		#define GPIO_KEY1_DETECT_PORT_IN			GPIO_B_IN	
		#define GPIO_KEY1_DETECT_PORT_OE			GPIO_B_OE	
		#define GPIO_KEY1_DETECT_PORT_PU			GPIO_B_PU	
		#define GPIO_KEY1_DETECT_PORT_PD			GPIO_B_PD	
		#define GPIO_KEY1_DETECT_PORT_IE  			GPIO_B_IE
		#define GPIO_KEY1_DETECT_PORT_INT  			GPIO_B_INT
		#define GPIO_KEY1_DETECT_BIT_MASK			GPIOB6

	//GPIO KEY2
		#define GPIO_KEY2_DETECT_PORT_IN			GPIO_B_IN	
		#define GPIO_KEY2_DETECT_PORT_OE			GPIO_B_OE	
		#define GPIO_KEY2_DETECT_PORT_PU			GPIO_B_PU	
		#define GPIO_KEY2_DETECT_PORT_PD			GPIO_B_PD	
		#define GPIO_KEY2_DETECT_PORT_IE  			GPIO_B_IE
		#define GPIO_KEY2_DETECT_PORT_INT  			GPIO_B_INT
		#define GPIO_KEY2_DETECT_BIT_MASK			GPIOB24

	//GPIO KEY3
		#define GPIO_KEY3_DETECT_PORT_IN			GPIO_B_IN	
		#define GPIO_KEY3_DETECT_PORT_OE			GPIO_B_OE	
		#define GPIO_KEY3_DETECT_PORT_PU			GPIO_B_PU	
		#define GPIO_KEY3_DETECT_PORT_PD			GPIO_B_PD	
		#define GPIO_KEY3_DETECT_PORT_IE  			GPIO_B_IE
		#define GPIO_KEY3_DETECT_PORT_INT  			GPIO_B_INT
		#define GPIO_KEY3_DETECT_BIT_MASK			GPIOB25

	//GPIO KEY4
		#define GPIO_KEY4_DETECT_PORT_IN			GPIO_B_IN	
		#define GPIO_KEY4_DETECT_PORT_OE			GPIO_B_OE	
		#define GPIO_KEY4_DETECT_PORT_PU			GPIO_B_PU	
		#define GPIO_KEY4_DETECT_PORT_PD			GPIO_B_PD	
		#define GPIO_KEY4_DETECT_PORT_IE  			GPIO_B_IE
		#define GPIO_KEY4_DETECT_PORT_INT  			GPIO_B_INT
		#define GPIO_KEY4_DETECT_BIT_MASK			GPIOB26

	//GPIO KEY5
		#define GPIO_KEY5_DETECT_PORT_IN			GPIO_B_IN	
		#define GPIO_KEY5_DETECT_PORT_OE			GPIO_B_OE	
		#define GPIO_KEY5_DETECT_PORT_PU			GPIO_B_PU	
		#define GPIO_KEY5_DETECT_PORT_PD			GPIO_B_PD	
		#define GPIO_KEY5_DETECT_PORT_IE  			GPIO_B_IE
		#define GPIO_KEY5_DETECT_PORT_INT  			GPIO_B_INT
		#define GPIO_KEY5_DETECT_BIT_MASK			GPIOB27

	#endif
	
	#if (CFG_WAV_REMIND_IN_CODE_AREA) && (CFG_WAV_REMIND_IN_CONST_AREA)
		#error	"Cannot define CFG_WAV_REMIND_IN_CODE_AREA and CFG_WAV_REMIND_IN_CONST_AREA at the same time"
	#endif
#endif

//****************************************************************************************
//获取一个随机数，原是在player_control.c中定义的，为了方便使用，改为定义在app_config.h中
//****************************************************************************************

    #define GetRandNum(MaxValue) ((OSSysTickGet()%MaxValue) + 3)
	
//****************************************************************************************
//                  系统默认音量配置         
//****************************************************************************************
	#define MAX_VOLUME  32
	#define DEFAULT_VOLUME  24
	#define DEC_FADEIN_TIME					1000	//fadein时间	

	#define ADC_DIGITAL_VOL				VOLUME_ADC_DIGITAL
	#define DAC_DIGITAL_VOL				VOLUME_DAC_DIGITAL
	
//****************************************************************************************
//                  输出通道选择       
//****************************************************************************************
    //同一时刻只能使能其中的一种
    #define OUTPUT_CHANNEL_DAC                      //DAC输出
//    #define OUTPUT_CHANNEL_I2S                    //标准I2S输出
//    #define OUTPUT_CHANNEL_DAC_I2S                //标准I2S以及DAC同时输出
//    #define OUTPUT_CHANNEL_CLASSD                 //以外接ST系列CLASSD的I2S输出
//    #define OUTPUT_CHANNEL_DAC_CLASSD             //以外接ST系列CLASSD的I2S以及DAC输出:该输出不能播放采样率低于32KHZ,如果需要全部支持，可以开启转采样功能
                                                   
    
//****************************************************************************************
//					升级功能
//****************************************************************************************
	#define FUNC_SPI_UPDATE_EN
	
	#ifdef 	FUNC_SPI_UPDATE_EN
		//#define FUNC_UPDATE_CONTROL   			//升级交互过程控制
		#define FUNC_UPDATE_DONE_DELETE_FILE		//升级完成删除升级包
	#endif

//****************************************************************************************
//                  频谱采集配置        
//****************************************************************************************
	#define FUNC_SPEC_TRUM_EN                      	//假频谱功能开关
	
//****************************************************************************************
//                 语音提示音功能配置        
//****************************************************************************************
	#define FUNC_SOUND_REMIND		//语音提示

//****************************************************************************************
//                  系统采样率配置            
//****************************************************************************************
//使能该宏表示MIXER模块自动将各种采样率统一转换为44.1KHZ
//当做卡拉OK类的应用时，强烈建议使能该宏
//使能该宏后，MIXER模块对非44.1KHZ采样率的数据做采样率转换，高频信号会略有衰减
//	#define FUNC_MIXER_SRC_EN   					
													
//****************************************************************************************
//                  软件微调配置       
//****************************************************************************************
//使能该宏，则会在Normal模式输出时，进行软件微调
//	#define FUNC_SOFT_ADJUST_EN

//****************************************************************************************
//                  文件系统配置
//****************************************************************************************
	#define FS_EXFAT_EN

//****************************************************************************************
//                  Decoder 相应超时设置
//****************************************************************************************
	#define DECODER_TASK_WAIT_TIMEOUT		10*1000	// 10S

	#define FUNC_DECODER_ENCRYPT_FILE               //播放用户自定义加密文件

//****************************************************************************************
//                  各音频源使用的MIXER模块的输入通道号配置             
//****************************************************************************************
	#define MIXER_SOURCE_DEC				0		//U盘/SD卡播放
	#define MIXER_SOURCE_BT					0		//蓝牙播放
	#define MIXER_SOURCE_USB				0		//USB声卡播放
	#define MIXER_SOURCE_MIC				1		//MIC
	#define MIXER_SOURCE_ANA_MONO			2		//单声道模拟输入，单声道GUITAR、单声道GUITAR+LINEIN
	#define MIXER_SOURCE_ANA_STERO			3		//双声道模拟输入，双声道LINEIN、双声道FM，此时MIC不可用


//****************************************************************************************
//                  BASS/TREB功能配置                        
//****************************************************************************************
//	#define FUNC_TREB_BASS_EN					//高低音调节功能
	#ifdef FUNC_TREB_BASS_EN
		#define MAX_TREB_VAL 			10		//高音调节的级数：0--10
		#define MAX_BASS_VAL 			10		//低音调节的级数：0--10
		#define DEFAULT_TREB_VAL		5		//高音调节的默认级数
		#define DEFAULT_BASS_VAL		5 		//高音调节的默认级数
	#endif
//****************************************************************************************
//                 EQ功能配置        
//****************************************************************************************
	#define EQ_STYLE_MODE				EQ_MODE
	
//****************************************************************************************
//                 DC Blocker功能配置        
//****************************************************************************************
	#define FUNC_DC_BLOCKER

//****************************************************************************************
//                 Silence detector 功能配置        
//****************************************************************************************
	#ifdef FUNC_DC_BLOCKER
//		#define FUNC_SILENCE_DETECTOR

		#define SILENCE_THRSHOLD				100
		#define SILENCE_COUNT					200
	#endif

//****************************************************************************************
//                  MIC功能配置  
//****************************************************************************************
//	#define FUNC_MIC_EN								//MIC功能
	#ifdef FUNC_MIC_EN
		#define FUNC_MIC_ALC_EN							//MIC ALC功能开关
		//#define FUNC_MIC_NOISE_GATE_EN					//MIC Noise Gate功能开关
		#define MAX_MICIN_VOLUME				16		//MIC音量可调的级数：0--16
		#define DEFAULT_MICIN_VOLUME			12		//MIC音量默认值
		#define MICIN_ANA_GAIN_VAL				VOLUME_ADC_ANA_MIC		//MIC输入通路模拟增益(22.9dB),GIAN 对应关系见 sys_vol.h
//		#define FUNC_MIC_DET_EN  						//MIC插拔检测定义
		#ifdef FUNC_MIC_DET_EN
			#define	MICIN_DETECT_PORT_IN		GPIO_A_IN
			#define	MICIN_DETECT_PORT_IE		GPIO_A_IE
			#define	MICIN_DETECT_PORT_OE		GPIO_A_OE
			#define	MICIN_DETECT_PORT_PU		GPIO_A_PU
			#define	MICIN_DETECT_PORT_PD		GPIO_A_PD
			#define MICIN_DETECT_BIT			(1 << 0)
		#endif

//		#define FUNC_MIC_ECHO_EN						//MIC ECHO功能
		#ifdef FUNC_MIC_ECHO_EN
			#define MAX_ECHO_DELAY_STEP			30		//MIC回声延时可调的级数：0--30
			#define DEFAULT_DELAY_STEP			22		//MIC回声延时默认值
			#define DELAY_ONE_STEP				400		//MIC回声延时每调一级对应的采样点数差异
			#define MAX_ECHO_DEPTH_STEP			16		//MIC回声强度可调的级数：0--16
			#define DEFAULT_DEPTH_STEP			12		//MIC回声强度默认值
			#define DEPTH_ONE_STEP				1024	//MIC回声强度每调一级对应的强度差异	
			
			#define MIC_ECHO_MIX_BYPASS_EN				//MIC回声是否叠加原始数据
			#define MIC_BYPASS_VOL				4095	//MIC回声音量增益
			#define MIC_ECHO_EFFECT_VOL			4095	//MIC原始音量增益
		#endif
		
		#define CFG_ECHO_DELAY                         (17640)  //400 ms
		#define CFG_ECHO_ATTENUATION                   (11626)  //-9 dB
		#define CFG_ECHO_DIRECT_SND_EN                 (    1)
		#define CFG_ECHO_CUTOFF_FREQ                   (    0)  //Disabled

	#endif

//****************************************************************************************
//					String format convert
//****************************************************************************************
	#define FUNC_STRING_CONVERT_EN 			// 字符串编码转换

//****************************************************************************************
//                  播放模式配置                        
//****************************************************************************************
//	#define FUNC_USB_EN						// U盘播放功能
	#ifdef FUNC_USB_EN
		#define UDISK_PORT_NUM		        2		// USB端口定义
	#endif
	#define FUNC_CARD_EN						// SD卡播放功能	
	#ifdef FUNC_CARD_EN
		#define	SD_PORT_NUM                 1		// SD卡端口定义
	#endif

	#if (SD_PORT_NUM == 1)
		//SD_CLK复用为硬件检测脚：A20
		#define CARD_DETECT_PORT_IN			GPIO_A_IN	
		#define CARD_DETECT_PORT_OE			GPIO_A_OE	
		#define CARD_DETECT_PORT_PU			GPIO_A_PU	
		#define CARD_DETECT_PORT_PD			GPIO_A_PD	
		#define CARD_DETECT_PORT_IE  		GPIO_A_IE
		#define CARD_DETECT_BIT_MASK		(1 << 20)
	#else
		#define CARD_DETECT_PORT_IN			GPIO_B_IN	
		#define CARD_DETECT_PORT_OE			GPIO_B_OE	
		#define CARD_DETECT_PORT_PU			GPIO_B_PU	
		#define CARD_DETECT_PORT_PD			GPIO_B_PD	
		#define CARD_DETECT_PORT_IE  		GPIO_B_IE
		#define CARD_DETECT_BIT_MASK		(GPIOB4)
	#endif

	#if (defined(FUNC_USB_EN) || defined(FUNC_CARD_EN))
		#define FUNC_LRC_EN							// LRC歌词文件解析
		//#define FUNC_FFFB_WITHOUT_SOUND     		//可选项，快进快退是否播放声音，默认出声音
		//#define FUNC_FFFB_END_WITHOUT_AUTO_SWITCH	//可选项，快进曲尾或者快退到曲首是否停止seek，默认保持快进快退
	#endif

//****************************************************************************************
//                 文件浏览模式配置        
//****************************************************************************************
	#define FUNC_BROWSER_EN  				//文件浏览功能

//****************************************************************************************
//                 FM收音机模式配置 
//****************************************************************************************
//	#define FUNC_RADIO_EN						//Fm Radio
	#ifdef FUNC_RADIO_EN
		#define FMIN_ANA_GAIN_VAL			VOLUME_ADC_ANA_LIN23	//FM输入通道的模拟增益(10.8dB)，如果作为LineIn使用需要设置为18(-3.65dB)，否则失真
												//GIAN 对应关系见 sys_vol.h
		#define FUNC_RADIO_DIV_CLK_EN			//FM降频工作

		#define FUNC_RADIO_RDA5807_EN
//		#define FUNC_RADIO_QN8035_EN

		#define MAX_RADIO_CHANNEL_NUM    50
		#define RADIO_SEEK_PREVIEW_SUPPORT		//支持搜台时，每搜到一个电台都自动播放几秒钟
		#define RADIO_DELAY_SWITCH_CHANNEL		//延迟处理电台切换，合并连续按键切换电台的特殊情况
		#define FM_CHL_SEARCH_TIME_UNIT 100		//搜台时频率扫描间隔ms
		#define FM_PERVIEW_TIMEOUT 1000			//FM搜台预览时间，该值不能小于MIN_TIMER_PERIOD，否则精确度会有问题(unit ms)
	#endif


//****************************************************************************************
//                 LINEIN模式配置 
//****************************************************************************************
//	#define FUNC_LINEIN_EN   					// Linein
	#ifdef FUNC_LINEIN_EN
		#define LINEIN_ANA_GAIN_VAL			VOLUME_ADC_ANA_LIN1	//LINEIN输入通道的模拟增益(-3.83),GIAN 对应关系见 sys_vol.h
		#define LINEIN_DETECT_PORT_IN		GPIO_A_IN
		#define LINEIN_DETECT_PORT_OE		GPIO_A_OE
		#define LINEIN_DETECT_PORT_IE		GPIO_A_IE
		#define LINEIN_DETECT_PORT_PU		GPIO_A_PU
		#define LINEIN_DETECT_PORT_PD		GPIO_A_PD
		#define LINEIN_DETECT_BIT_MASK		GPIOA24
	#endif
        
//****************************************************************************************
//                 I2S模式配置        
//****************************************************************************************
//  #define FUNC_I2SIN_EN

	#define FUNC_I2S_MASTER_EN				//enbale:master mode, disable: slave mode
        #define I2SIN_MCLK_IO_PORT      1   //mclk port: 0--B2, 1--C8, 0XFF--NO USE
        #define I2SIN_I2S_IO_PORT       1   //i2s port: 0-- lrck: B3, bclk: B4, din: B6, do: B5;
                                            //          1-- lrck: B24, bclk: B25, din: B27, do: B26
                                            //          2-- lrck: C9, bclk: C10, din: C12, do: C11  
                                            //          0xff--NO USE

//****************************************************************************************
//                 USB一线通模式配置        
//****************************************************************************************
//	#define FUNC_USB_AUDIO_EN				//单独的USB声卡模式
	#define FUNC_USB_READER_EN				//单独的USB读卡器模式
//	#define FUNC_USB_AUDIO_READER_EN		//一线通模式
		#define PC_PORT_NUM			        2

//****************************************************************************************
//                 录音模式配置        
//****************************************************************************************
	#if (defined(FUNC_USB_EN) || defined(FUNC_CARD_EN))
//		#define FUNC_PLAY_RECORD_FOLDER_EN		//播放模式播放record文件夹
//		#define FUNC_RECORD_EN   				//录音功能
		#ifdef FUNC_RECORD_EN
			#define FUNC_RECORD_FILE_DELETE_EN 		//支持录音删除功能
			#define FUNC_REC_FILE_REFRESH_EN 		//定时保存文件（避免掉电后录音数据不能保存的问题）
			#define FUNC_REC_PLAYBACK_EN 			//录音回放功能

			#define RECORD_FORMAT		MP3_FORMAT	// MP3_FORMAT , WAV_FORMAT
			#define RECORD_BITRATE		96			// 双声道最高支持320kbps，单声道最高支持192kbps
			#define RECORD_CHANNEL		1			// 必须是 1 或者 2，等于2时可能MEM不够，需要去除一些功能
		#endif
	#endif

//****************************************************************************************
//                 RTC功能配置        
//****************************************************************************************
//	#define FUNC_RTC_EN						//rtc功能
	#ifdef FUNC_RTC_EN
		#define FUNC_RTC_ALARM 				//alarm功能
		#define FUNC_RTC_LUNAR
	#endif


//****************************************************************************************
//                 蓝牙模式配置        
//****************************************************************************************
	#define FUNC_BT_EN											//蓝牙功能
		#define BT_DEVICE_TYPE		BTUartDeviceRTL8761//BTUartDeviceMTK662X//BTUartDeviceRTL8761 		// bt chip type

		#define BLE_STACK										// 使能BLE

		#define BT_LDOEN_RST_GPIO_PORT				GPIO_PORT_B
		#define BT_LDOEN_RST_GPIO_PIN				(22)

		#define BT_UART_RTS_PORT					(1)			// 0 --- A12; 1 --- B31; 2 --- C1

		#define AP80_DEV_BOARD									// AP80_DEV_BOARD : 为MV的AP80开发板，不定义则适用于MVs的大邮票版

		#ifdef AP80_DEV_BOARD
			#define MTK_BT_PWR_EN					GPIOB22
			#define MTK_BT_RESET					GPIOB31
		#else
			#define MTK_BT_PWR_EN					GPIOC1
			#define MTK_BT_RESET					GPIOB31
		#endif

	#ifdef FUNC_BT_EN
//		#define FUNC_BT_HF_EN									//bt hf call module
		#ifdef FUNC_BT_HF_EN

//			#define FUNC_BT_HF_UART								// 蓝牙电话语音通过UART传输(仅RTK8761支持此功能)

			#define MAX_BTHF_VOLUME					(15)		//蓝牙最大音量等级
			#ifdef FUNC_RECORD_EN
				#define BT_HF_RECORD_FUNC						// 蓝牙通话录音功能
			#endif

			#ifdef FUNC_SOUND_REMIND
//				#define BT_HF_NUMBER_REMIND						// 蓝牙语音报号功能
			#endif

			#define NON_LINEAR_PROCESS				(1)			// "非线性处理"(AEC之后的后处理模块，起到进一步压制回声，以及底噪抑制等)打开或者关闭；0:关闭，1:打开
			#define NOISE_SUPPRESSION_LEVEL			(0)			// 噪声抑制等级。取值范围(1 ~ 5)，0为关闭此功能
		#endif

		#define BT_RECONNECTION_FUNC							// 蓝牙自动重连功能
		#ifdef BT_RECONNECTION_FUNC
			#define BT_POWERON_RECONNECTION						// 开机自动重连
			#ifdef BT_POWERON_RECONNECTION
				#define BT_POR_TRY_COUNTS			(7)			// 开机重连尝试次数
				#define BT_POR_INTERNAL_TIME		(3)			// 开机重连每两次间隔时间(in seconds)
			#endif

			#define BT_BB_LOST_RECONNECTION						// BB Lost之后自动重连
			#ifdef BT_BB_LOST_RECONNECTION
				#define BT_BLR_TRY_COUNTS			(90)		// BB Lost 尝试重连次数
				#define BT_BLR_INTERNAL_TIME		(5)			// BB Lost 重连每两次间隔时间(in seconds)
			#endif

		#endif

		#define BT_ADVANCED_AVRCP_SUPPORT						// 高级AVRCP支持
		#ifdef BT_ADVANCED_AVRCP_SUPPORT
			#define BT_VOLUME_SYNC								// 音量同步
			#define BT_SONG_TRACK_INFOR							// 歌曲ID3信息反馈
			#define BT_SONG_PLAY_STATUS							// 歌曲播放状态
		#endif

		//#define FUNC_BT_DISABLE_SIMPLE_PARING					//取消simple pairing功能，自定义PIN CODE

		//#define CONFIG_INQUIRY_SCAN_FUNC						// 配置INQUIRY_SCAN相关参数

		//#define FUNC_BT_PBAP_EN									//PBAP功能

		#define TEST_CLEAR_BT_PAIRED_INFO						//强制断开蓝牙连接
		
//		#define MASS_PRODUCTION_TEST_FUNC						// 量产测试功能

//		#define FAST_POWER_ON_OFF_BT							// 快速打开/关闭蓝牙功能

//		#define BT_RF_POWER_ON_OFF								// BT RF 硬件开关

//		#define AUTO_MV_BT_TEST_FUNC							// auto scan and test bt device, 
																// one must be initialized with 
																// [MvBtAutoTestFlag = 1] in this case,
																// please refer to the related files.
		#if defined(FAST_POWER_ON_OFF_BT) && defined(BT_RF_POWER_ON_OFF)
			#error	"Cannot define FAST_POWER_ON_OFF_BT and BT_RF_POWER_ON_OFF at the same time"
		#endif
	#endif
//****************************************************************************************
//                 UART DEBUG功能配置        
//****************************************************************************************
	#define FUNC_DEBUG_EN
	#ifdef FUNC_DEBUG_EN
		#define FUART_RX_PORT  0xFF	//rx port  0--A1，1--B6，2--C4，0xFF--NO USE
		#define FUART_TX_PORT  1	//tx port  0--A0，1--B7，2--C3，0xFF--NO USE
	#endif

//****************************************************************************************
//                 WATCH DOG功能配置        
//****************************************************************************************
	#define FUNC_WATCHDOG_EN			//WATCHDOG功能


//****************************************************************************************		
//                 音效功能开关(3D, VB, DRC)
//****************************************************************************************
	#define FUNC_AUDIO_EFFECT_EN
	#ifdef FUNC_AUDIO_EFFECT_EN
		#include "audio_effect_codec.h"
		#define FUNC_AUDIO_EQ_EN						//EQ功能开关
		#define DIGITAL_PER_GAIN_EN						//数字音量预增益
		#define DIGITAL_PER_GAIN_VAL       1850         //数字音量预增益值
	#endif

//****************************************************************************************		
//				音效功能切换时淡入淡出操作，用于消除pop音(3D, VB, DRC，EQ)
//				目前标准只做了软件EQ切换时做了pop音消除，其他的需要做一定的改动
//****************************************************************************************
	//#define AUDIO_EFFECT_SWITCH_FADEOUT_FADEIN
	
//****************************************************************************************
//                 断点记忆功能配置        
//****************************************************************************************
	#define FUNC_BREAKPOINT_EN			// 系统断点信息管理
	#ifdef FUNC_BREAKPOINT_EN
		#define BP_SAVE_TO_NVM				//将断点信息保存到NVM 中
		#define BP_SAVE_TO_FLASH			// 掉电记忆功能（支持将断点信息保存到FLASH中，防止掉电丢失）
		//#define BP_SAVE_TO_EEPROM			// 掉电记忆功能（支持将断点信息保存到EEPROM中，防止掉电丢失）		
		#define FUNC_MATCH_PLAYER_BP		// 获取FS扫描后与播放模式断点信息相匹配的文件、文件夹ID号
	#endif


//****************************************************************************************
//                 VIN输入5V再次Trim LDO3V3功能配置        
//****************************************************************************************
//	#define FUNC_5VIN_TRIM_LDO3V3			//LDO3V3_TRIM 5VIN功能	


//****************************************************************************************
//                 POWER MONITOR功能配置        
//****************************************************************************************
// 定义电能监视(适用于带电池系统)的功能宏和选项宏
// 电能监视包括，电池电压检测及低电压后的系统行为以及充电指示等
// 电池电压检测，是指LDOIN输入端的电压检测功能(电池系统一般都是电池直接给LDOIN管脚供电)
// 该功能宏打开后，默认包含电池电压检测功能，有关电池电压检测的其它可定义参数，请详见power_monitor.c文件

//USE_POWERKEY_SLIDE_SWITCH 和USE_POWERKEY_SOFT_PUSH_BUTTON 两个宏不要同时定义
//	#define USE_POWERKEY_SLIDE_SWITCH     		//for slide switch case ONLY
	#define USE_POWERKEY_SOFT_PUSH_BUTTON		//for soft push button case ONLY

//	#define POWERON_DETECT_VOLTAGE        		//开机检测电池电压，低于关机电压则直接进入关机流程
	#define FUNC_POWER_MONITOR_EN
//	#define	OPTION_CHARGER_DETECT				//打开该宏定义，支持GPIO检测充电设备插入功能
			//充电检测端口设置
	#ifdef OPTION_CHARGER_DETECT
		#define CHARGE_DETECT_PORT_PU			GPIO_A_PU
		#define CHARGE_DETECT_PORT_PD			GPIO_A_PD
		#define CHARGE_DETECT_PORT_IN			GPIO_A_IN
		#define CHARGE_DETECT_PORT_IE			GPIO_A_IE
		#define CHARGE_DETECT_PORT_OE			GPIO_A_OE
		#define CHARGE_DETECT_BIT				(1 << 3)
	#endif

//	#define FUNC_POWERKEY_SOFT_POWERON_EN 		//软开关用BYBASS模式实现
	#define FUNC_GPIO_POWER_ON_EN         		//GPIO控制系统上电

	#ifdef FUNC_GPIO_POWER_ON_EN          		//GPIO控制系统上电
		#define POWERON_GPIO_PORT_OUT			GPIO_A_OUT
		#define POWERON_GPIO_PORT_BIT			GPIOA24

		#define POWERON_GPIO_PORT_IE			(POWERON_GPIO_PORT_OUT + 1)
		#define POWERON_GPIO_PORT_OE			(POWERON_GPIO_PORT_OUT + 2)
		#define POWERON_GPIO_PORT_PU			(POWERON_GPIO_PORT_OUT + 5)
		#define POWERON_GPIO_PORT_PD			(POWERON_GPIO_PORT_OUT + 6)

		#define SysPowerOnControlEnable()		do{\
												GpioSetRegOneBit(POWERON_GPIO_PORT_PU, POWERON_GPIO_PORT_BIT);\
												GpioClrRegOneBit(POWERON_GPIO_PORT_PD, POWERON_GPIO_PORT_BIT);\
												GpioClrRegOneBit(POWERON_GPIO_PORT_IE, POWERON_GPIO_PORT_BIT);\
												GpioSetRegOneBit(POWERON_GPIO_PORT_OE, POWERON_GPIO_PORT_BIT);\
												GpioSetRegOneBit(POWERON_GPIO_PORT_OUT, POWERON_GPIO_PORT_BIT);\
												DBG("GpioControlSysPowerOn.........................\n");\
												}while(0)
								
		#define SysPowerOnControlDisable()		do{\
												GpioSetRegOneBit(POWERON_GPIO_PORT_PU, POWERON_GPIO_PORT_BIT);\
												GpioClrRegOneBit(POWERON_GPIO_PORT_PD, POWERON_GPIO_PORT_BIT);\
												GpioClrRegOneBit(POWERON_GPIO_PORT_IE, POWERON_GPIO_PORT_BIT);\
												GpioSetRegOneBit(POWERON_GPIO_PORT_OE, POWERON_GPIO_PORT_BIT);\
												GpioClrRegOneBit(POWERON_GPIO_PORT_OUT, POWERON_GPIO_PORT_BIT);\
												DBG("GpioControlSysPowerOff.........................\n");\
												}while(0)
		
	#endif

//****************************************************************************************
//                 按键功能配置        
//****************************************************************************************
//	#define FUNC_KEY_BEEP_SOUND_EN    						//按键beep声功能

	//ADC KEY定义
	#define FUNC_ADC_KEY_EN								//ADC KEY宏开关  									
		#define ADC_KEY_PORT_CH1	ADC_CHANNEL_B5			//如果只使用1路ADC按键，则保留本行
		//#define	ADC_KEY_PORT_CH2	ADC_CHANNEL_B5			//如果只使用2路ADC按键，则保留本行

	//IR KEY定义
//	#define FUNC_IR_KEY_EN   							//IR KEY宏开关
		#define IR_KEY_PORT			IR_USE_GPIOC2			//IR使用的端口：IR_USE_GPIOA10, IR_USE_GPIOB7 or IR_USE_GPIOC2

	//CODING KEY定义
//	#define FUNC_CODING_KEY_EN							//CODING KEY宏开关			
		#define 	CODING_KEY_A_PORT_IN	GPIO_B_IN	
		#define		CODING_KEY_A_PORT_OE	GPIO_B_OE 			
		#define		CODING_KEY_A_PORT_PU	GPIO_B_PU 
		#define		CODING_KEY_A_PORT_PD	GPIO_B_PD 					
		#define		CODING_KEY_A_PORT_INT	GPIO_B_INT 				
		#define		CODING_KEY_A_BIT		(1 << 21)	//GPIO_B[21] for signal A 
	
		#define		CODING_KEY_B_PORT_IN	GPIO_B_IN 				
		#define		CODING_KEY_B_PORT_OE	GPIO_B_OE 			
		#define		CODING_KEY_B_PORT_PU	GPIO_B_PU 
		#define		CODING_KEY_B_PORT_PD	GPIO_B_PD 					
		#define		CODING_KEY_B_BIT		(1 << 20)	//GPIO_B[20] for signal B
	
	#define FUNC_POWER_KEY_EN							//POWER KEY宏开关，软开关复用功能
														//需要同时开启宏USE_POWERKEY_SOFT_PUSH_BUTTON 该功能才真正有效

	#define FUNC_KEY_HOLD_EN							//按键长按保持。

//****************************************************************************************
//                 功放配置        
//****************************************************************************************
#define FUNC_AMP_MUTE_EN         //功放Mute功能配置		
#define FUNC_AMP_POWER_EN									
								
#ifdef FUNC_AMP_MUTE_EN
															
	#define AMP_SILENCE_MUTE_EN     //打开该宏，支持在DAC输出无音时MUTE功放
	#define AMP_GPIO_MUTE_EN        //打开该宏，支持GPIO控制功放MUTE
	#ifdef  AMP_SILENCE_MUTE_EN
		#define SILENCE_MUTE_TIMER        500     //无信号MUTE检测时间
		#define SILENCE_UNMUTE_TIMER      30      //解MUTE检测时间
		#define DEC_SILENCE_MUTE_VALUE    1       //DEC解码MUTE阀值
		#define ANA_SILENCE_MUTE_VALUE    16      //模拟输入MUTE阀值
		#define SILENCE_MUTE_DET_CNT      85      //百分比，在200ms内低于检测阀值的百分比达到该值，启动功放MUTE
	#endif
	
	#ifdef AMP_GPIO_MUTE_EN		
		#define AMP_MUTE_PORT_OUT				GPIO_A_OUT
		#define AMP_MUTE_PORT_BIT				  GPIOA25

		#define AMP_MUTE_PORT_IE				(AMP_MUTE_PORT_OUT + 1)
		#define AMP_MUTE_PORT_OE				(AMP_MUTE_PORT_OUT + 2)
		#define AMP_MUTE_PORT_PU				(AMP_MUTE_PORT_OUT + 5)
		#define AMP_MUTE_PORT_PD				(AMP_MUTE_PORT_OUT + 6)

		#define GpioAmpMuteEnable()				do{\
												GpioSetRegOneBit(AMP_MUTE_PORT_PU, AMP_MUTE_PORT_BIT);\
												GpioClrRegOneBit(AMP_MUTE_PORT_PD, AMP_MUTE_PORT_BIT);\
												GpioClrRegOneBit(AMP_MUTE_PORT_IE, AMP_MUTE_PORT_BIT);\
												GpioSetRegOneBit(AMP_MUTE_PORT_OE, AMP_MUTE_PORT_BIT);\
												GpioClrRegOneBit(AMP_MUTE_PORT_OUT, AMP_MUTE_PORT_BIT);\
												}while(0)
							
		#define GpioAmpMuteDisable()			do{\
												GpioSetRegOneBit(AMP_MUTE_PORT_PU, AMP_MUTE_PORT_BIT);\
												GpioClrRegOneBit(AMP_MUTE_PORT_PD, AMP_MUTE_PORT_BIT);\
												GpioClrRegOneBit(AMP_MUTE_PORT_IE, AMP_MUTE_PORT_BIT);\
												GpioSetRegOneBit(AMP_MUTE_PORT_OE, AMP_MUTE_PORT_BIT);\
												GpioSetRegOneBit(AMP_MUTE_PORT_OUT, AMP_MUTE_PORT_BIT);\
												}while(0)
	#endif
#endif
								
#ifdef FUNC_AMP_POWER_EN
																					
	#define AMP_POWER_PORT_OUT				GPIO_B_OUT
	#define AMP_POWER_PORT_BIT				GPIOB8

	#define AMP_POWER_PORT_IE				(AMP_POWER_PORT_OUT + 1)
	#define AMP_POWER_PORT_OE				(AMP_POWER_PORT_OUT + 2)
	#define AMP_POWER_PORT_PU				(AMP_POWER_PORT_OUT + 5)
	#define AMP_POWER_PORT_PD				(AMP_POWER_PORT_OUT + 6)

	#define AmpPowerEnable()				do{\
											GpioSetRegOneBit(AMP_POWER_PORT_PU, AMP_POWER_PORT_BIT);\
											GpioClrRegOneBit(AMP_POWER_PORT_PD, AMP_POWER_PORT_BIT);\
											GpioClrRegOneBit(AMP_POWER_PORT_IE, AMP_POWER_PORT_BIT);\
											GpioSetRegOneBit(AMP_POWER_PORT_OE, AMP_POWER_PORT_BIT);\
											GpioSetRegOneBit(AMP_POWER_PORT_OUT, AMP_POWER_PORT_BIT);\
											}while(0)
								
	#define AmpPowerDisable()				do{\
											GpioSetRegOneBit(AMP_POWER_PORT_PU, AMP_POWER_PORT_BIT);\
											GpioClrRegOneBit(AMP_POWER_PORT_PD, AMP_POWER_PORT_BIT);\
											GpioClrRegOneBit(AMP_POWER_PORT_IE, AMP_POWER_PORT_BIT);\
											GpioSetRegOneBit(AMP_POWER_PORT_OE, AMP_POWER_PORT_BIT);\
											GpioClrRegOneBit(AMP_POWER_PORT_OUT, AMP_POWER_PORT_BIT);\
											}while(0)

#endif				
					
/**********************************************************************************************************
 *               LED DISPLAY DEFINE                          *
 *********************************************************************************************************/
 
// 显示模块定义，根据实际选择可支持LED,LCD,单颗LED灯
// FUNC_DISP_EN：是否开启显示功能
// FUNC_SEG_LCD_EN, FUNC_SEG_LED_EN,	FUNC_SINGLE_LED_EN根据需要选择一个或多个，其他更详细的信息见segPanel.h
// 另外还需要配置gDisplayMode变量为需要的模式,显示模式列在下面.
// DISP_DEV_SLED	-> 单颗LED灯
// DISP_DEV_LED1888	-> 三位半段码LED屏
// DISP_DEV_LED8888	-> 四位段码LED屏
// DISP_DEV_LED57	-> 5*7段码LED屏
// DISP_DEV_LCD58	-> 5*8段码LCD屏
//注意显示控制宏与gDisplayMode变量的对应关系，例如要选择LED57显示设备，必须要开启FUNC_SEG_LED_EN宏并将gDisplayMode赋值为DISP_DEV_LED57。

#define FUNC_DISP_EN					//显示功能

#ifdef FUNC_DISP_EN						              
	//#define FUNC_SEG_LED_EN				    //段码LED屏
	//#define FUNC_SEG_LCD_EN				    //段码LCD屏
	#define FUNC_SINGLE_LED_EN			    //单颗LED灯
	//#define FUNC_ALEXA_PWM_LED_EN			  //PWM LED灯
#endif

//特殊段码LED 屏选择
#ifdef	FUNC_SEG_LED_EN
	//#define FUNC_7PIN_SEG_LED_EN		//7只脚的段码LED 屏
	//#define FUNC_6PIN_SEG_LED_EN		  //6只脚的段码LED 屏
	//#define FUNC_AIP1629A_LED_EN            //AIP1629LED段码驱动IC
#endif

#ifdef FUNC_SINGLE_LED_EN
//蓝灯
	#define LED_BLUE_PORT_OUT				GPIO_A_OUT
	#define LED_BLUE_PORT_BIT				  GPIOA0

	#define LED_BLUE_PORT_IE				(LED_BLUE_PORT_OUT + 1)
	#define LED_BLUE_PORT_OE				(LED_BLUE_PORT_OUT + 2)
	#define LED_BLUE_PORT_PU				(LED_BLUE_PORT_OUT + 5)
	#define LED_BLUE_PORT_PD				(LED_BLUE_PORT_OUT + 6)

	#define BlueLedOn()						do{\
											GpioSetRegOneBit(LED_BLUE_PORT_PU, LED_BLUE_PORT_BIT);\
											GpioClrRegOneBit(LED_BLUE_PORT_PD, LED_BLUE_PORT_BIT);\
											GpioClrRegOneBit(LED_BLUE_PORT_IE, LED_BLUE_PORT_BIT);\
											GpioSetRegOneBit(LED_BLUE_PORT_OE, LED_BLUE_PORT_BIT);\
											GpioSetRegOneBit(LED_BLUE_PORT_OUT, LED_BLUE_PORT_BIT);\
										}while(0)
									
	#define BlueLedOff()					do{\
											GpioSetRegOneBit(LED_BLUE_PORT_PU, LED_BLUE_PORT_BIT);\
											GpioClrRegOneBit(LED_BLUE_PORT_PD, LED_BLUE_PORT_BIT);\
											GpioClrRegOneBit(LED_BLUE_PORT_IE, LED_BLUE_PORT_BIT);\
											GpioSetRegOneBit(LED_BLUE_PORT_OE, LED_BLUE_PORT_BIT);\
											GpioClrRegOneBit(LED_BLUE_PORT_OUT, LED_BLUE_PORT_BIT);\
										}while(0)

//红灯
	#define LED_RED_PORT_OUT				GPIO_B_OUT
	#define LED_RED_PORT_BIT				  GPIOB8

	#define LED_RED_PORT_IE				(LED_RED_PORT_OUT + 1)
	#define LED_RED_PORT_OE				(LED_RED_PORT_OUT + 2)
	#define LED_RED_PORT_PU				(LED_RED_PORT_OUT + 5)
	#define LED_RED_PORT_PD				(LED_RED_PORT_OUT + 6)

	#define RedLedOn()						do{\
											GpioSetRegOneBit(LED_RED_PORT_PU, LED_RED_PORT_BIT);\
											GpioClrRegOneBit(LED_RED_PORT_PD, LED_RED_PORT_BIT);\
											GpioClrRegOneBit(LED_RED_PORT_IE, LED_RED_PORT_BIT);\
											GpioSetRegOneBit(LED_RED_PORT_OE, LED_RED_PORT_BIT);\
											GpioClrRegOneBit(LED_RED_PORT_OUT, LED_RED_PORT_BIT);\
										}while(0)
									
	#define RedLedOff()						do{\
											GpioSetRegOneBit(LED_RED_PORT_PU, LED_RED_PORT_BIT);\
											GpioClrRegOneBit(LED_RED_PORT_PD, LED_RED_PORT_BIT);\
											GpioClrRegOneBit(LED_RED_PORT_IE, LED_RED_PORT_BIT);\
											GpioSetRegOneBit(LED_RED_PORT_OE, LED_RED_PORT_BIT);\
											GpioSetRegOneBit(LED_RED_PORT_OUT, LED_RED_PORT_BIT);\
										}while(0)
#endif

//****************************************************************************************
//                 音频菜单配置        
//****************************************************************************************
	#define FUNC_AUDIO_MENU_EN						//音量键功能复用选择：MIC音量、回声延时、回声强度、BASS调节、TREB调节
		#define		MENU_TIMEOUT		5000		//进入菜单调节后，如果5秒没有按MENU、VOL_UP、VOL_DW，则自动退出菜单模式


//****************************************************************************************
//                 定时关机功能配置        
//****************************************************************************************
//	#define FUNC_SLEEP_EN
	#define FUNC_SLEEP_LEDOFF_EN
															
	#ifdef FUNC_SLEEP_EN
		#define SLEEP_POWEROFF_TMR   30   //单位：分钟
	#endif
	#ifdef FUNC_SLEEP_LEDOFF_EN
		#define SLEEP_LED_OFF_TMR    1
	#endif

//****************************************************************************************
//                 系统模式值配置        
//****************************************************************************************
enum EnumModuleID
{
    MODULE_ID_UNKNOWN     = 0,	// idle

    MODULE_ID_PLAYER_SD,		// player
    MODULE_ID_PLAYER_USB,		// player
    MODULE_ID_BLUETOOTH,		// module bt
    MODULE_ID_RECORDER,			// recorder
    MODULE_ID_RADIO,			// FM/AM radio
    MODULE_ID_LINEIN,			// line in
    MODULE_ID_I2SIN,            // I2s in
    MODULE_ID_USB_AUDIO,		// usb audio
    MODULE_ID_USB_READER,		// usb audio
    MODULE_ID_USB_AUDIO_READER,	// usb audio

    //add more herr
    MODULE_ID_RTC,				// rtc

    MODULE_ID_BT_HF,
	MODULE_ID_IDLE,
    // 以上应用模式，可以通过mode键循环切换进入
    //////////////////////////////////////////////////////////////
    // DO NOT MODIFY FOLLOWINGS
    MODULE_ID_END,				// end of moduleID
    // 以下应用模式不能通过mode键切换进入，而是根据实际用途 通过快捷键或特殊条件满足时才会进入

    //MODULE_ID_ALARM_REMIND,		// alarm remind
    MODULE_ID_POWEROFF,			// faked module ID for Power OFF
    MODULE_ID_STANDBY,			// faked module ID for StandBy mode
#ifdef FUNC_REC_PLAYBACK_EN
    MODULE_ID_REC_BACK_PLAY,	// 录音回放模式
#endif
    MODULE_ID_USER_PLUS,		// 用户扩展起始ID
};


//****************************************************************************************
//                 MEM分配        
//****************************************************************************************
//DEC
#define DEC_MEM_ADDR              		(VMEM_ADDR + 0 * 1024)		//decoder 28KB
#define DEC_MEM_MAX_SIZE          		(28 * 1024)            

//ENC
#define ENC_MEM_ADDR					(VMEM_ADDR + 1 * 1024)		//encoder 17KB mp3编码 定义方式 起始1k与pcm_sync.c中定义冲突  mp3只需16k  
#define ENC_MEM_SIZE					(17 * 1024)

//ENC BUF
#define MP3_OUT_SAMPLES_BUF             (VMEM_ADDR + 18 * 1024)		//record buf 19KB
#define MP3_OUT_SAMPLES_BUF_SIZE        (19 * 1024)

//ADPCM - ENCODE
#define ADPCM_ENC_MEM_ADDR				(VMEM_ADDR + 28 * 1024)		// adpcm for bt phone call recording
#define ADPCM_ENC_MEM_SIZE				(3*1024)

//ADPCM - ENCODE BUF
#define ADPCM_OUT_SAMPLES_BUF             (VMEM_ADDR + 31 * 1024)	//record buf 6KB
#define ADPCM_OUT_SAMPLES_BUF_SIZE        (6 * 1024)

//下面几个FIFO必须在PMEM中，即大于(VMEM_ADDR + 32 * 1024)
//PCM FIFO
#define PCM_FIFO_ADDR             		(VMEM_ADDR + 37 * 1024)		//pcm fifo 16KB
#define PCM_FIFO_LEN              		(16 * 1024)

//ADC FIFO
#define ADC_FIFO_ADDR         			(VMEM_ADDR + 53 * 1024)		//adc fifo 4KB
#define ADC_FIFO_LEN             		(4 * 1024)    

//I2S FIFO
#define I2SIN_FIFO_ADDR                 (VMEM_ADDR + 57 * 1024)
#define I2SIN_FIFO_LEN                  (3 * 1024)

//BUART
#define BUART_RX_TX_FIFO_ADDR  			(VMEM_ADDR + 60 * 1024)		//buart fifo 7KB，RX、TX连续相邻
#define BUART_RX_FIFO_SIZE             	(3 * 1024)         
#define BUART_TX_FIFO_SIZE             	(1 * 1024)         


////////////////////内存管理操作/////////////////////////
#define APP_MMM_MALLOC(MemSize, MemType)          OSMalloc(MemSize, MemType)
#define APP_MMM_REALLOC(MemPtr, MemSize, MemType) OSRealloc(MemPtr, MemSize, MemType)
#define APP_MMM_FREE(MemPtr)                      OSFree(MemPtr)

////////////////////OTP用户区域说明//////////////////////
// 蓝牙地址(用户烧录,全零表示为无效地址)
// 地址：0x7F6C~0x7F71
// 大小: 6Byte
// 
// 用户自定义数据(用户烧录，自己私有)
// 地址：0x7F10~0x7F1F
// 大小：16Byte
//
// 注意：
// 关于OTP写入烧录需要有MV配套的工具和上位机软件
// 读取OTP空间在有code Flash情况下需要偏移0x7C0000,才能获取到正确的数据
// 具体OTP如何读取请阅读bt_app_func.c中GetBtAddr() 函数
//////////////////////////////////////////////////////////

/////////////////////FLASH 操作/////////////////////////

//#define FLASH_ERASE_IN_TCM			//FLASH擦除代码放在TCM中,目前只适用于GD的FLASH

#include "debug.h"

#ifdef  __cplusplus
}
#endif//__cplusplus

#endif/*_APP_CONFIG_H_*/
