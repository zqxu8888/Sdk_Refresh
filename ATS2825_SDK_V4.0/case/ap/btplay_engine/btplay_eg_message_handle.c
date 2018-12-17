/********************************************************************************
 *        Copyright(c) 2014-2015 Actions (Zhuhai) Technology Co., Limited,
 *                            All Rights Reserved.
 *
 * 描述：蓝牙推歌引擎应用业务逻辑消息响应实现。
 * 作者：cailizhen
 ********************************************************************************/

#include  "btplay_engine.h"

#define DSP_FREE_TIMES_DEFAULT      6
#define DEC_SLOW_TIMES_DEFAULT      15

static uint8 count_free_dsp_timer = 0;

void count_free_dsp_deal(void)
{
    uint16 dec_slow_times, dsp_free_times;
    msg_apps_t msg;
    btstack_event_t tmp_ev;
    int times = 0;
    int ret;

    //两分钟进入一次统计分析dsp卸载次数和出现dsp dec slow次数
    count_free_dsp_timer++;
    if(count_free_dsp_timer < 2) {
        return;
    } else {
        count_free_dsp_timer = 0;
    }

    if(mp_handle == NULL) {
        return;
    }

    mmm_bp_cmd(mp_handle, MMM_BP_GET_ERRORNO, (unsigned int) &times);
    libc_print("free times:", times, 2);
    dsp_free_times = times & 0xffff;
    dec_slow_times = (times >> 16) & 0xffff;

    if((dec_slow_times > (dsp_free_times * 2)) && (dec_slow_times >= DEC_SLOW_TIMES_DEFAULT)
            && (dsp_free_times >= DSP_FREE_TIMES_DEFAULT)) {
        //消息类型(即消息名称)
        msg.type = MSG_ENGINE_FORCE_UNLINK;
        //发送同步消息
        send_sync_msg_btmanager(NULL, &msg, NULL, 0);
    } else {
        return;
    }
}

void btplay_engine_pipe_control(uint8 op)
{
    msg_apps_t msg;
    msg.content.data[0] = op;
    //消息类型(即消息名称)
    msg.type = MSG_BTSTACK_PLAY_PIPE_CTRL_SYNC;

    //发送同步消息
    send_sync_msg_btmanager(NULL, &msg, NULL, 0);
}

void tws_sync_cmd_parase(void)
{
    switch(g_p_tws_info->tws_sync_cmd) {
        case TWS_MASTER_SMART_MODE :
            //libc_print("slave exit play", 0, 0);
            btplay_engine_pipe_control(PIPE_OP_FLUSH | PIPE_OP_FILTER);
            a2dp_decode_quit();
            //btplayeg_enter_speech_mode();
            //smart_enter_speech_mode(&btplay_gl_var.speech_flag);
            a2dp_decode_init(g_p_bt_stack_cur_info->rmt_dev[g_p_bt_stack_cur_info->a2dp_active_id].a2dp_attr.media_type);
            btplay_engine_pipe_control(PIPE_OP_UNFILTER);
            //btplayeg_exit_speech_mode();
            //smart_exit_speech_mode(&btplay_gl_var.speech_flag);
            break;

        case TWS_MASTER_EXIT_SMART_MODE:
            //libc_print("slave enter play", 0, 0);
            //a2dp_decode_init();
            //btplay_engine_pipe_control(PIPE_OP_UNFILTER);
            //btplayeg_exit_speech_mode();
            //smart_exit_speech_mode(&btplay_gl_var.speech_flag);
            break;

        default:
            break;
    }
}

/******************************************************************************/
/*!
 * \par  Description:
 * \app_result_e btplay_reply_msg(void* msg_ptr, bool ret_vals)
 * \回复同步消息
 * \param[in]    void  msg_ptr 消息结构体
 * \param[in]    bool  ret_vals 相关事件处理结果 TRUE 成功 FALSE 失败
 * \param[out]   none
 * \return       app_result_E
 * \retval       RESULT_IGNOR 忽略
 * \ingroup      mengine_control.c
 * \note  回复消息时，根据ret_vals的结果，设置应答成功或失败
 */
/*******************************************************************************/
void btplay_reply_msg(void *msg_ptr, bool ret_vals)
{
    //消息指针
    private_msg_t *data_ptr = (private_msg_t *) msg_ptr;

    if(ret_vals == TRUE) {
        data_ptr->reply->type = MSG_REPLY_SUCCESS;
    } else {
        data_ptr->reply->type = MSG_REPLY_FAILED;
    }

    //回复同步消息(发送信号量)
    libc_sem_post(data_ptr->sem);

    return;
}

app_result_e app_msg_deal_app_quit(void)
{
    // libc_print("G3",0,0);
    btplay_engine_pipe_control(PIPE_OP_FILTER | PIPE_OP_CLEAR_PAUSE);

    if(btplay_gl_var.codec_flag == TRUE) {
        a2dp_decode_quit();
        g_p_btplay_info->status = BTPLAY_STOP;
    }
    btplay_engine_pipe_control(PIPE_OP_FLUSH);

    return RESULT_APP_QUIT;
}

//实际的AVRCP控制由前台代理，引擎不再需要处理
app_result_e __section__(".text.bank4")app_message_deal(private_msg_t *pri_msg)
{
    app_result_e app_ret;
    bool ret_val;

    app_ret = RESULT_NULL;

    switch(pri_msg->msg.type) {

        case MSG_SET_DAE_CFG_SYNC: //设置DAE
            if(mp_handle != NULL) {
                adjust_freq_add_value(0, g_dae_cfg_shm->run_freq);

                mmm_bp_cmd(mp_handle, MMM_BP_SET_EQ, (unsigned int) NULL);
            }
            btplay_reply_msg(pri_msg, TRUE);
            break;

        case MSG_TTS_START_SYNC: //准备进入TTS播报
        case MSG_SWITCH_AOUT_START_SYNC: //准备切换音频输出
            //临时停止播歌，该消息等同于STOP消息
        {

            btplay_engine_pipe_control(PIPE_OP_FILTER);
            if(btplay_gl_var.codec_flag == TRUE) {

                a2dp_decode_quit();
                ret_val = TRUE;
            } else {
                ret_val = TRUE;
            }
#ifdef ENABLE_TRUE_WIRELESS_STEREO
            send_tts_start_cmd();
#endif
            btplay_engine_pipe_control(PIPE_OP_FLUSH);

            btplay_gl_var.tts_play_flag = TRUE;
            btplay_reply_msg(pri_msg, ret_val);
        }
        break;

        case MSG_TTS_STOP_SYNC: //TTS播报完成
        case MSG_SWITCH_AOUT_STOP_SYNC: //完成切换音频输出
            //恢复播歌，该消息等同于PLAY消息
        {
            btplay_gl_var.tts_play_flag = FALSE;
#ifdef ENABLE_TRUE_WIRELESS_STEREO
            send_tts_stop_cmd();
#endif
            if(btplay_gl_var.filter_after_pause == 0) {
#ifdef ENABLE_TRUE_WIRELESS_STEREO
                if((g_p_bt_stack_cur_info->dev_role == 1) && (g_p_bt_stack_cur_info->tws_master_phonecon == 0)) {
                    //tts 播放完成后不要接收数据
                } else {
                    if(g_p_tws_info->sub_quit_bl_flag == 1) {
                        //do no
                    } else {
                        if((g_p_bt_stack_cur_info->dev_role == 1) && (g_p_bt_stack_cur_info->tws_master_phonecon == 1)) {
                            if(clear_tts_filter_timer_id != -1) {
                                kill_app_timer(clear_tts_filter_timer_id);
                                clear_tts_filter_timer_id = -1;
                            }
                            clear_tts_filter_timer_id = set_single_shot_app_timer(APP_TIMER_ATTRB_CONTROL,
                                                        500, Tws_clear_filter);
                        } else {
                            btplay_engine_pipe_control(PIPE_OP_UNFILTER);
                        }
                    }


                }
#else
                btplay_engine_pipe_control(PIPE_OP_UNFILTER);

#endif

            }

            btplay_reply_msg(pri_msg, TRUE);
        }
        break;

        case MSG_ENGINE_STANDBY_SYNC: {
            os_event_t *standby_sem = (os_event_t *)(pri_msg->msg.content.addr);

            //备份现场，准备进入睡眠模式
            //     PRINT_INFO("eng stdby en");

            //回复前台，然后接着跑就会睡眠
            btplay_reply_msg(pri_msg, TRUE);

            libc_sem_wait(standby_sem, 0);

            //从睡眠模式回来，恢复现场
            // PRINT_INFO("eng stdby exit");
            standby_restart_all_app_timer(g_app_timer_vector, g_app_timer_count);
        }
        break;


        case MSG_APP_QUIT: //退出引擎
            PRINT_INFO("btplay quit");
            if((pri_msg->msg.content.data[0] & 0x01) != 0) {
                //  PRINT_INFO("eg enter s3bt");
            }
            app_ret = app_msg_deal_app_quit();
            break;

        default:
            //if(pri_msg->msg.type == MSG_PLAYEREG_RECOGNIZE_START)
            if(pri_msg->msg.type == MSG_PLAYEREG_RECOGNIZE_PAUSE_MUSIC) {
                if(btplay_gl_var.codec_flag == FALSE) {
                    a2dp_decode_init(g_p_bt_stack_cur_info->rmt_dev[g_p_bt_stack_cur_info->a2dp_active_id].a2dp_attr.media_type);
                }
            }
            app_ret = smart_process_message_deal(pri_msg, mp_handle, mmm_bp_cmd, &btplay_gl_var.speech_flag);
//      btplay_reply_msg(pri_msg, TRUE);
            libc_sem_post(pri_msg->sem);
            break;
    }

    return app_ret;
}
