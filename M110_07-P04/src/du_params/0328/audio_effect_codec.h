/*******************************************************
 *         MVSilicon Audio Effects Parameters
 *   The File is Auto Generated by ACPWorkbench V8.2.5
 *              Firmware Version: EFFECT 8.2.2
 *                All Right Reserved
 *******************************************************/

#ifndef __AUDIO_EFFECT_CODEC_H__
#define __AUDIO_EFFECT_CODEC_H__

#ifdef  __cplusplus
extern "C" {
#endif//__cplusplus

//ADC settings
#define CFG_ADC_SRA_EN                         (    0)
#define CFG_ADC_SRA_PPM                        (    0)  //0.0
#define CFG_ADC_NG_EN                          (    0)
#define CFG_ADC_NG_THRESHOLD                   (    0)  //-76.5 dB
#define CFG_ADC_NG_TYPE                        (    0)  //Const Gain
#define CFG_ADC_ALC_ATTACK_TIME                (    2)  //24 ms
#define CFG_ADC_ALC_DECAY_TIME                 (    3)  //192 ms
#define CFG_ADC_ALC_HOLD_TIME                  (    0)  //0 ms
#define CFG_ADC_ALC_MIN_GAIN                   (    7)  //-30 dB
#define CFG_ADC_ALC_MAX_GAIN                   (    2)  // 0 dB
#define CFG_ADC_ALC_SEL                        (    0)  //Stereo
#define CFG_ADC_ALC_TARGET_LEVEL               (   13)  //-12.0 dB
//DAC settings
#define CFG_DAC_SRA_EN                         (    0)
#define CFG_DAC_SRA_PPM                        (    0)  //0.0
#define CFG_DAC_DITHER_EN                      (    0)
#define CFG_DAC_MODE                           (    0)  //STEREO
#define CFG_DAC_SCRAMBLE                       (    0)  //OFF
#define CFG_DAC_SIDETONE_L                     (    0)
#define CFG_DAC_SIDETONE_R                     (    0)
//Volume settings
#define CFG_VOLUME_ADC_ANA_MIC                 (   42)  //42: 22.00 dB
#define CFG_VOLUME_ADC_ANA_LIN1                (   53)  //53: -5.26 dB
#define CFG_VOLUME_ADC_ANA_LIN23               (   40)  //47: -5.86 dB
#define CFG_VOLUME_ADC_DIGITAL                 (  255)  //255: 0.000 dB
#define CFG_VOLUME_DAC_ANALOG                  (   47)  //47: 1.66 dB
#define CFG_VOLUME_DAC_DIGITAL                 (  255)  //255: 0.000 dB
//The following volume macros are defined for SDK
#define VOLUME_ADC_ANA_MIC                     (   21)
#define VOLUME_ADC_ANA_LIN1                    (   11)
#define VOLUME_ADC_ANA_LIN23                   (   16)
#define VOLUME_ADC_DIGITAL                     ( 4095)
#define VOLUME_DAC_ANALOG                      (   16)
#define VOLUME_DAC_DIGITAL                     ( 4095)

//Audio effects settings
//#define FUNC_AUDIO_PS_EFFECT_EN
#define FUNC_AUDIO_VB_EFFECT_EN
//#define FUNC_AUDIO_3D_EFFECT_EN
//#define FUNC_AUDIO_REVERB_EFFECT_EN
//#define FUNC_AUDIO_DRC_EFFECT_EN

#define AUDIO_EFFECT_VERSION_PS                (010702)
#define AUDIO_EFFECT_VERSION_VB                (040100)
#define AUDIO_EFFECT_VERSION_3D                (030200)
#define AUDIO_EFFECT_VERSION_REVERB            (010300)
#define AUDIO_EFFECT_VERSION_DRC               (030000)

#define AUDIO_EFFECT_PREGAIN                   ( 4096)  //  0.000 dB

#define AUDIO_EFFECT_PARAM_PS_SEMITONE_STEP    (    0)  //unit in cents
#define AUDIO_EFFECT_PARAM_PS_FRAME_SIZE       (  576)  //unit in sample

#define AUDIO_EFFECT_PARAM_VB_CUTOFF_FREQ      (  125)  //unit in Hz
#define AUDIO_EFFECT_PARAM_VB_INTENSITY        (    5)  //unit in percent
#define AUDIO_EFFECT_PARAM_VB_ENHANCED         (    1)

#define AUDIO_EFFECT_PARAM_3D_DEPTH            (   50)  //unit in percent

#define AUDIO_EFFECT_PARAM_REVERB_DRY_SCALE    (   50)  //unit in percent
#define AUDIO_EFFECT_PARAM_REVERB_WET_SCALE    (  100)  //unit in percent
#define AUDIO_EFFECT_PARAM_REVERB_WIDTH_SCALE  (  100)  //unit in percent
#define AUDIO_EFFECT_PARAM_REVERB_ROOM_SIZE    (   50)  //unit in percent
#define AUDIO_EFFECT_PARAM_REVERB_DAMPING      (   50)  //unit in percent

#define AUDIO_EFFECT_PARAM_DRC_MODE            (    0)  //Full Band
#define AUDIO_EFFECT_PARAM_DRC_CROSSOVER_FREQ  (  300)  //unit in Hz
#define AUDIO_EFFECT_PARAM_DRC_CROSSOVER_FQ1   (  724)  //0.707
#define AUDIO_EFFECT_PARAM_DRC_CROSSOVER_FQ2   (  724)  //0.707
#define AUDIO_EFFECT_PARAM_DRC_PREGAIN1        ( 7284)  //5.00dB
#define AUDIO_EFFECT_PARAM_DRC_PREGAIN2        ( 4096)  //0.00dB
#define AUDIO_EFFECT_PARAM_DRC_THRESHHOLD1     (    0)  // 10.00dB
#define AUDIO_EFFECT_PARAM_DRC_RATIO1          (  100)  //100:1
#define AUDIO_EFFECT_PARAM_DRC_ATTACK_TIME1    (    1)  //unit in ms
#define AUDIO_EFFECT_PARAM_DRC_RELEASE_TIME1   ( 1000)  //unit in ms
#define AUDIO_EFFECT_PARAM_DRC_THRESHHOLD2     (    0)  //  0.00dB
#define AUDIO_EFFECT_PARAM_DRC_RATIO2          (  100)  //100:1
#define AUDIO_EFFECT_PARAM_DRC_ATTACK_TIME2    (    1)  //unit in ms
#define AUDIO_EFFECT_PARAM_DRC_RELEASE_TIME2   ( 1000)  //unit in ms
#define AUDIO_EFFECT_PARAM_DRC_THRESHHOLD3     ( -500)  //  5.00dB
#define AUDIO_EFFECT_PARAM_DRC_RATIO3          (  100)  //100:1
#define AUDIO_EFFECT_PARAM_DRC_ATTACK_TIME3    (    1)  //unit in ms
#define AUDIO_EFFECT_PARAM_DRC_RELEASE_TIME3   (  500)  //unit in ms

#ifdef  __cplusplus
}
#endif//__cplusplus

#endif//__AUDIO_EFFECT_CODEC_H__
