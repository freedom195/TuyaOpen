#include "tal_cellular.h"
#include "tkl_init_cellular.h"

/**
 * @brief 蜂窝初始化
 * @return 0 成功  其它 失败
 */
OPERATE_RET tal_cellular_init(void)
{
    if (cellular_desc_get()->init == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->init();
}

/**
 * @brief 获取当前设备的通讯能力
 * @param ability @TKL_CELLULAR_ABILITY_E 类型
 * @return 0 成功  其它 失败
 */
OPERATE_RET tal_cellular_get_ability(TKL_CELLULAR_ABILITY_E *ability)
{
    if (cellular_desc_get()->get_ability == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_ability(ability);
}

/**
 * @brief 切换当前使能的SIM卡。
 * @param simid SIM卡ID.(0~1)
 * @return 0 成功  其它 失败
 */
OPERATE_RET tal_cellular_switch_sim(uint8_t sim_id)
{
    if (cellular_desc_get()->switch_sim == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->switch_sim(sim_id);
}

/**
 * @brief 注册SIM状态变化通知函数
 * @param fun 状态变化通知函数
 * @return 0 成功  其它 失败
 */
OPERATE_RET tal_cellular_register_sim_state_notify(uint8_t sim_id, TKL_SIM_NOTIFY fun)
{
    if (cellular_desc_get()->register_sim_state_notify == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->register_sim_state_notify(sim_id, fun);
}

/**
 * @brief 使能或禁止sim卡热拔插
 * @param simId sim卡ID
 * @param enable TRUE 使能 FALSE 禁止
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_sim_hotplug(uint8_t sim_id, bool enable)
{
    if (cellular_desc_get()->sim_hotplug_enable == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->sim_hotplug_enable(sim_id,enable);
}

/**
 * @brief 获取SIM卡的状态
 * @param simId sim卡ID
 * @param state 1：正常，0：异常
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_sim_get_status(uint8_t sim_id, uint8_t *state)
{
    if (cellular_desc_get()->sim_get_status == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->sim_get_status(sim_id, state);
}

/**
 * @brief 获取蜂窝设备当前的通信功能设置
 * @param cfun 获取的通信功能
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_fun_mode(uint8_t simd_id,int * cfun)
{
    if (cellular_desc_get()->get_cfun_mode == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_cfun_mode(simd_id,cfun); 
}

/**
 * @brief 设置蜂窝设备的通信功能模式
 * @param cfun 通信功能，取值含义如下：
 *            1：全功能模式
 *            4：飞行模式
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_set_fun_mode(uint8_t simd_id,int cfun)
{
    if (cellular_desc_get()->set_cfun_mode == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->set_cfun_mode(simd_id,cfun);    
}

/**
 * @brief 获取SIM卡中的国际移动用户识别码
 * @param simid,SIM卡id号(0,1,2...)
 * @param imsi识别码，为16字节的字符串
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_imsi(uint8_t sim_id,char imsi[15 + 1])
{
    if (cellular_desc_get()->get_imsi == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_imsi(sim_id,imsi);    
}

/**
 * @brief 获取SIM卡的ICCID
 * @param simid
 * @param ICCID识别码，为20字节的字符串
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_iccid(uint8_t sim_id,char iccid[20 + 1])
{
    if (cellular_desc_get()->get_iccid == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_iccid(sim_id,iccid);    
}

/**
 * @brief 获取SIM卡所在通道设备的IMEI号
 * @param simid
 * @param IMEI识别码，为15字节的字符串
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_imei(uint8_t sim_id,char imei[15 + 1])
{
    if (cellular_desc_get()->get_imei == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_imei(sim_id,imei);    
}

/**
 * @brief 设置设备的IMEI号
 * @param simid
 * @param IMEI识别码，为15字节的字符串
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_set_imei(uint8_t sim_id,char imei[15 + 1])
{
    if (cellular_desc_get()->set_imei == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->set_imei(sim_id,imei);    
}

/**
 * @brief 获取SIM卡所在通道蜂窝设备的信号接收功率——单位dbm
 * @param simid
 * @param rsrp 返回实际的信号强度(dbm)
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_rsrp(uint8_t sim_id,int *rsrp)
{
    if (cellular_desc_get()->get_rsrp == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_rsrp(sim_id,rsrp);    
}

/**
 * @brief 获取蜂窝设备SIM卡所在通道的信号噪声比及误码率
 * @param simid
 * @param sinr 干扰信噪比
 * @param bit_error (0~7,99) 99无网络
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_sinr(uint8_t sim_id,int *sinr,int *bit_error)
{
    if (cellular_desc_get()->get_sinr == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_sinr(sim_id,sinr,bit_error);   
}

/**
 * @brief SIM卡所在通道LBS的基站信息)
 * @param sim_id
 * @param lbs 返回基站信息
 * @param neighbour 是否搜索临近基站信息
 * @param timeout 搜索临近基站信息超时时间(一般需要4秒左右)
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_lbs(uint8_t sim_id,TKL_LBS_INFO_T *lbs,bool neighbour,int timeout)
{
    if (cellular_desc_get()->get_lbs == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_lbs(sim_id,lbs,neighbour,timeout);    
}

/**
 * @brief 获取默认的SIM ID
 * @return 小于0失败，其他SIM ID
 */
int8_t tal_cellular_get_default_simid(void)
{
    if (cellular_desc_get()->get_default_simid == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_default_simid();   
}

/**
 * @brief 蜂窝基础的通用控制功能，一般作为平台提供一些特殊的能力接口
 * @param cmd 参考CELL_IOCTRL_CMD
 * @param argc argv数组大小
 * @param argv 平台自定义
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_ioctl(int cmd,void* argv)
{
    if (cellular_desc_get()->ioctl == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->ioctl(cmd,argv);    
}

/**
 * @brief get the epoch time in second
 *
 * The time is seconds from 1970-01-01 UTC. To avoid overflow, the data
 * type is 64 bits.
 * - signed 32bits will overflow at year 2038
 * - unsigned 32bits will overflow at year 2106
 *
 * Epoch time is not monoclinic time. For example, when system time is
 * synchronized with network, there may exist a jump (forward or backward)
 * of epoch time.
 *
 * In 2 cases, this system time may be not reliable:
 * - During boot, and before RTC is initialized.
 * - During wakeup, and the elapsed sleep time hasn't compensated.
 *
 * @return      epoch time in seconds
 */
OPERATE_RET tal_cellular_get_epoch_sec(uint64_t *epoch_sec)
{
    if (cellular_desc_get()->get_epoch_sec == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_epoch_sec(epoch_sec);
}

/**
 * @brief 获取指定的SIM 卡所在网络的rssi dBm值
 * @param sim_id sim id
 * @param rssi_dBm 获取到的rssi dBm值
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_rssidbm(uint8_t sim_id,int  *rssi_dBm)
{
    if(cellular_desc_get()->get_rssidbm == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_rssidbm(sim_id,rssi_dBm);
}

/**
 * @brief 获取指定的SIM 卡所在网络的rssi值
 * @param sim_id sim id
 * @param rssi_dBm 获取到的rssi(0~31)
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_rssi(uint8_t sim_id,int *rssi)
{
    if(cellular_desc_get()->get_rssi == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_rssi(sim_id,rssi);
}

/**
 * @brief 获取指定的SIM 卡所在网络的网络类型
 * @param sim_id sim id
 * @param net_type 网络类型
 * @return 0 成功 其它 失败
 */
OPERATE_RET tal_cellular_get_nettype(uint8_t sim_id,TUYA_CELLULAR_RAT_E *net_type)
{
    if(cellular_desc_get()->get_nettype == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_nettype(sim_id, net_type);

}

/**
 * @brief 获取指定的SIM 卡所在网络信号质量(5个等级)
 * @param sim_id sim id
 * @return TUYA_CELLULAR_SINGAL_QAUL_E 类型
 */
TUYA_CELLULAR_SINGAL_QAUL_E tal_cellular_get_singal_quailty(uint8_t sim_id)
{
    OPERATE_RET ret = OPRT_OK;
    TUYA_CELLULAR_RAT_E net_type = 0;
    TUYA_CELLULAR_SINGAL_QAUL_E qual =CELLULAR_SINGAL_QUAL_UNKNOWN;

    ret = tal_cellular_get_nettype(sim_id, &net_type);
    if (OPRT_OK != ret) {
        return CELLULAR_SINGAL_QUAL_UNKNOWN;
    }

    if (net_type == TUYA_CELL_NET_TYPE_GSM) {  
        int rssi = 0;
        ret = tal_cellular_get_rssi(sim_id, &rssi);
        if (OPRT_OK != ret) {
            return CELLULAR_SINGAL_QUAL_UNKNOWN;
        }
        if (rssi <= 2 || rssi == 99) {
            qual = CELLULAR_SINGAL_QUAL_UNKNOWN;
        } else if (rssi >= 12) {
            qual = CELLULAR_SINGAL_QUAL_GREAT;
        } else if (rssi >= 8) {
            qual = CELLULAR_SINGAL_QUAL_GOOD;
        } else if (rssi >= 5) {
            qual = CELLULAR_SINGAL_QUAL_MIDDLE;
        } else {
            qual = CELLULAR_SINGAL_QUAL_POOR;
        }
    } else if (net_type == TUYA_CELL_NET_TYPE_LTE) {
        int rsrp;
        ret = tal_cellular_get_rsrp(sim_id,&rsrp);
        if (OPRT_OK != ret) {
            return CELLULAR_SINGAL_QUAL_UNKNOWN;
        }
        if (rsrp > -44) {
            qual = CELLULAR_SINGAL_QUAL_UNKNOWN;
        } else if (rsrp > -85) {
            qual = CELLULAR_SINGAL_QUAL_GREAT;
        } else if (rsrp > -95) {
            qual = CELLULAR_SINGAL_QUAL_GOOD;
        } else if (rsrp > -105) {
            qual = CELLULAR_SINGAL_QUAL_MIDDLE;
        } else if (rsrp > -115) {
            qual = CELLULAR_SINGAL_QUAL_POOR;
        } else if (rsrp > -140) {
            qual = CELLULAR_SINGAL_QUAL_UNKNOWN;
        }
    }
    return qual;
}

/**
 * @brief 获取蜂窝设备的本地时间。（本时间为通过基站时间同步的时间）
 * @param local_tm   struct tm类型时间指针
 * @return 0 其他失败
 */
OPERATE_RET tal_cellular_get_localtime(struct tm *local_tm)
{
    if (cellular_desc_get()->get_localtime == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_localtime(local_tm);
}

/**
 * @brief 获取通过基站网络信息同步获取到的时区
 *
 * @return 时区，单位秒
 */
OPERATE_RET tal_cellular_get_timezone(int *timezone)
{
    if(cellular_desc_get()->get_timezone == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_timezone(timezone);
}

/**
 * @brief 获取蜂窝的模块NV中的SN号，不是所有模块中的都会内置SN。
 * @param sn 获取的SN号
 * @return 0 其他失败
 */
OPERATE_RET tal_cellular_get_sn(char sn[25])
{
    if(cellular_desc_get()->get_sn == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->get_sn(sn);
}

/**
 * @brief 设置模组底层网络注册事件的回调
 * @note 主要底层上报TUYA_CELLULAR_MDS_STATUS_IDLE，TUYA_CELLULAR_MDS_STATUS_REG,TUYA_CELLULAR_MDS_STATUS_CAMPED 3个事件。
 * 分别表示搜网中，注网成功，停止搜网
 *
 * @param fun 回调函数
 * @return OPERATE_RET 操作结果，成功返回OPRT_OK，失败返回错误码
 */
OPERATE_RET tal_cellular_register_dev_reg_notify(uint8_t simd_id,TKL_REGISTION_NOTIFY fun)
{
    if(cellular_desc_get()->register_dev_reg_notify == NULL) {
        return OPRT_NOT_SUPPORTED;
    }
    return cellular_desc_get()->register_dev_reg_notify(simd_id, fun);
}