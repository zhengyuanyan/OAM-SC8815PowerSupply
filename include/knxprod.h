#pragma once


#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                         (time & 0x3FFF) * 3600000 ) : 0 )
                                             
#define ETS_ModuleId_NONE 0
#define ETS_ModuleId_BASE 1
#define ETS_ModuleId_UCT 2
#define ETS_ModuleId_BPS 3
#define ETS_ModuleId_BUZ 4
#define ETS_ModuleId_DSP 5
#define MAIN_FirmwareName "SC8815 - V10"
#define MAIN_OpenKnxId 0xAF
#define MAIN_ApplicationNumber 8
#define MAIN_ApplicationVersion 10
#define MAIN_ApplicationEncoding iso-8859-15
#define MAIN_ParameterSize 203
#define MAIN_MaxKoNumber 40
#define MAIN_OrderNumber "OpenKnxBusPowerSupply"
#define BASE_ModuleVersion 25
#define UCT_ModuleVersion 5
#define BPS_ModuleVersion 2
#define BUZ_ModuleVersion 1
#define DSP_ModuleVersion 1
// Parameter with single occurrence


#define BASE_StartupDelayBase                     0      // 2 Bits, Bit 7-6
#define     BASE_StartupDelayBaseMask 0xC0
#define     BASE_StartupDelayBaseShift 6
#define BASE_StartupDelayTime                     0      // 14 Bits, Bit 13-0
#define     BASE_StartupDelayTimeMask 0x3FFF
#define     BASE_StartupDelayTimeShift 0
#define BASE_HeartbeatDelayBase                   2      // 2 Bits, Bit 7-6
#define     BASE_HeartbeatDelayBaseMask 0xC0
#define     BASE_HeartbeatDelayBaseShift 6
#define BASE_HeartbeatDelayTime                   2      // 14 Bits, Bit 13-0
#define     BASE_HeartbeatDelayTimeMask 0x3FFF
#define     BASE_HeartbeatDelayTimeShift 0
#define BASE_Timezone                             4      // 5 Bits, Bit 7-3
#define     BASE_TimezoneMask 0xF8
#define     BASE_TimezoneShift 3
#define BASE_CombinedTimeDate                     4      // 1 Bit, Bit 2
#define     BASE_CombinedTimeDateMask 0x04
#define     BASE_CombinedTimeDateShift 2
#define BASE_SummertimeAll                        4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeAllMask 0x03
#define     BASE_SummertimeAllShift 0
#define BASE_SummertimeDE                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeDEMask 0x03
#define     BASE_SummertimeDEShift 0
#define BASE_SummertimeWorld                      4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeWorldMask 0x03
#define     BASE_SummertimeWorldShift 0
#define BASE_SummertimeKO                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeKOMask 0x03
#define     BASE_SummertimeKOShift 0
#define BASE_TimezoneCustom                       5      // char*, 63 Byte
#define     BASE_TimezoneCustomLength 63
#define BASE_Latitude                            69      // float (4 Byte)
#define BASE_Longitude                           73      // float (4 Byte)
#define BASE_Diagnose                            78      // 1 Bit, Bit 7
#define     BASE_DiagnoseMask 0x80
#define     BASE_DiagnoseShift 7
#define BASE_Watchdog                            78      // 1 Bit, Bit 6
#define     BASE_WatchdogMask 0x40
#define     BASE_WatchdogShift 6
#define BASE_ReadTimeDate                        78      // 1 Bit, Bit 5
#define     BASE_ReadTimeDateMask 0x20
#define     BASE_ReadTimeDateShift 5
#define BASE_HeartbeatExtended                   78      // 1 Bit, Bit 4
#define     BASE_HeartbeatExtendedMask 0x10
#define     BASE_HeartbeatExtendedShift 4
#define BASE_InternalTime                        78      // 1 Bit, Bit 3
#define     BASE_InternalTimeMask 0x08
#define     BASE_InternalTimeShift 3
#define BASE_ManualSave                          78      // 3 Bits, Bit 2-0
#define     BASE_ManualSaveMask 0x07
#define     BASE_ManualSaveShift 0
#define BASE_PeriodicSave                        79      // 8 Bits, Bit 7-0
#define BASE_Info1LedFunc                        80      // 16 Bits, Bit 15-0
#define BASE_Info2LedFunc                        82      // 16 Bits, Bit 15-0
#define BASE_Info3LedFunc                        84      // 16 Bits, Bit 15-0
#define BASE_DefaultLedFunc                      86      // 1 Bit, Bit 7
#define     BASE_DefaultLedFuncMask 0x80
#define     BASE_DefaultLedFuncShift 7
#define BASE_Dummy                               109      // uint8_t
#define BASE_ModuleEnabled_UCT                   110      // 1 Bit, Bit 6
#define     BASE_ModuleEnabled_UCTMask 0x40
#define     BASE_ModuleEnabled_UCTShift 6
#define BASE_ModuleEnabled_BPS                   110      // 1 Bit, Bit 5
#define     BASE_ModuleEnabled_BPSMask 0x20
#define     BASE_ModuleEnabled_BPSShift 5
#define BASE_ModuleEnabled_BUZ                   110      // 1 Bit, Bit 4
#define     BASE_ModuleEnabled_BUZMask 0x10
#define     BASE_ModuleEnabled_BUZShift 4
#define BASE_ModuleEnabled_DSP                   110      // 1 Bit, Bit 3
#define     BASE_ModuleEnabled_DSPMask 0x08
#define     BASE_ModuleEnabled_DSPShift 3

// 时间基准
#define ParamBASE_StartupDelayBase                    ((knx.paramByte(BASE_StartupDelayBase) & BASE_StartupDelayBaseMask) >> BASE_StartupDelayBaseShift)
// 时间
#define ParamBASE_StartupDelayTime                    (knx.paramWord(BASE_StartupDelayTime) & BASE_StartupDelayTimeMask)
// 时间 (in Millisekunden)
#define ParamBASE_StartupDelayTimeMS                  (paramDelay(knx.paramWord(BASE_StartupDelayTime)))
// 时间基准
#define ParamBASE_HeartbeatDelayBase                  ((knx.paramByte(BASE_HeartbeatDelayBase) & BASE_HeartbeatDelayBaseMask) >> BASE_HeartbeatDelayBaseShift)
// 时间
#define ParamBASE_HeartbeatDelayTime                  (knx.paramWord(BASE_HeartbeatDelayTime) & BASE_HeartbeatDelayTimeMask)
// 时间 (in Millisekunden)
#define ParamBASE_HeartbeatDelayTimeMS                (paramDelay(knx.paramWord(BASE_HeartbeatDelayTime)))
// 时区
#define ParamBASE_Timezone                            ((knx.paramByte(BASE_Timezone) & BASE_TimezoneMask) >> BASE_TimezoneShift)
// 接收方式
#define ParamBASE_CombinedTimeDate                    ((bool)(knx.paramByte(BASE_CombinedTimeDate) & BASE_CombinedTimeDateMask))
// 夏令时判定方式
#define ParamBASE_SummertimeAll                       (knx.paramByte(BASE_SummertimeAll) & BASE_SummertimeAllMask)
// 夏令时判定方式
#define ParamBASE_SummertimeDE                        (knx.paramByte(BASE_SummertimeDE) & BASE_SummertimeDEMask)
// 夏令时判定方式
#define ParamBASE_SummertimeWorld                     (knx.paramByte(BASE_SummertimeWorld) & BASE_SummertimeWorldMask)
// 夏令时判定方式
#define ParamBASE_SummertimeKO                        (knx.paramByte(BASE_SummertimeKO) & BASE_SummertimeKOMask)
// POSIX TZ-String
#define ParamBASE_TimezoneCustom                      (knx.paramData(BASE_TimezoneCustom))
#define ParamBASE_TimezoneCustomStr                   (knx.paramString(BASE_TimezoneCustom, BASE_TimezoneCustomLength))
// 纬度
#define ParamBASE_Latitude                            (knx.paramFloat(BASE_Latitude, Float_Enc_IEEE754Single))
// 经度
#define ParamBASE_Longitude                           (knx.paramFloat(BASE_Longitude, Float_Enc_IEEE754Single))
// 显示诊断对象
#define ParamBASE_Diagnose                            ((bool)(knx.paramByte(BASE_Diagnose) & BASE_DiagnoseMask))
// 启用看门狗
#define ParamBASE_Watchdog                            ((bool)(knx.paramByte(BASE_Watchdog) & BASE_WatchdogMask))
// 重启时从总线读取
#define ParamBASE_ReadTimeDate                        ((bool)(knx.paramByte(BASE_ReadTimeDate) & BASE_ReadTimeDateMask))
// 扩展的“运行中”状态
#define ParamBASE_HeartbeatExtended                   ((bool)(knx.paramByte(BASE_HeartbeatExtended) & BASE_HeartbeatExtendedMask))
// 内部时间
#define ParamBASE_InternalTime                        ((bool)(knx.paramByte(BASE_InternalTime) & BASE_InternalTimeMask))
// 手动保存
#define ParamBASE_ManualSave                          (knx.paramByte(BASE_ManualSave) & BASE_ManualSaveMask)
// 周期保存
#define ParamBASE_PeriodicSave                        (knx.paramByte(BASE_PeriodicSave))
// 信息 1
#define ParamBASE_Info1LedFunc                        (knx.paramWord(BASE_Info1LedFunc))
// 信息 2
#define ParamBASE_Info2LedFunc                        (knx.paramWord(BASE_Info2LedFunc))
// 信息 3
#define ParamBASE_Info3LedFunc                        (knx.paramWord(BASE_Info3LedFunc))
// 
#define ParamBASE_DefaultLedFunc                      ((bool)(knx.paramByte(BASE_DefaultLedFunc) & BASE_DefaultLedFuncMask))
// 
#define ParamBASE_Dummy                               (knx.paramByte(BASE_Dummy))
// UCT
#define ParamBASE_ModuleEnabled_UCT                   ((bool)(knx.paramByte(BASE_ModuleEnabled_UCT) & BASE_ModuleEnabled_UCTMask))
// BPS
#define ParamBASE_ModuleEnabled_BPS                   ((bool)(knx.paramByte(BASE_ModuleEnabled_BPS) & BASE_ModuleEnabled_BPSMask))
// BUZ
#define ParamBASE_ModuleEnabled_BUZ                   ((bool)(knx.paramByte(BASE_ModuleEnabled_BUZ) & BASE_ModuleEnabled_BUZMask))
// DSP
#define ParamBASE_ModuleEnabled_DSP                   ((bool)(knx.paramByte(BASE_ModuleEnabled_DSP) & BASE_ModuleEnabled_DSPMask))

#define BASE_KoHeartbeat 1
#define BASE_KoTime 2
#define BASE_KoDate 3
#define BASE_KoDateTime 4
#define BASE_KoIsSummertime 5
#define BASE_KoManualSave 6
#define BASE_KoDiagnose 7

// 运行中
#define KoBASE_Heartbeat                           (knx.getGroupObject(BASE_KoHeartbeat))
// 时间
#define KoBASE_Time                                (knx.getGroupObject(BASE_KoTime))
// 日期
#define KoBASE_Date                                (knx.getGroupObject(BASE_KoDate))
// 时间/日期
#define KoBASE_DateTime                            (knx.getGroupObject(BASE_KoDateTime))
// 夏令时激活
#define KoBASE_IsSummertime                        (knx.getGroupObject(BASE_KoIsSummertime))
// 保存
#define KoBASE_ManualSave                          (knx.getGroupObject(BASE_KoManualSave))
// 诊断
#define KoBASE_Diagnose                            (knx.getGroupObject(BASE_KoDiagnose))



#define BPS_ResetTime                           114      // uint8_t
#define BPS_PowerSupply1ChangeSend              115      // 1 Bit, Bit 7
#define     BPS_PowerSupply1ChangeSendMask 0x80
#define     BPS_PowerSupply1ChangeSendShift 7
#define BPS_PowerSupply2ChangeSend              115      // 1 Bit, Bit 6
#define     BPS_PowerSupply2ChangeSendMask 0x40
#define     BPS_PowerSupply2ChangeSendShift 6
#define BPS_BusVoltageChangeSend                115      // 1 Bit, Bit 5
#define     BPS_BusVoltageChangeSendMask 0x20
#define     BPS_BusVoltageChangeSendShift 5
#define BPS_BusCurrentChangeSend                115      // 1 Bit, Bit 4
#define     BPS_BusCurrentChangeSendMask 0x10
#define     BPS_BusCurrentChangeSendShift 4
#define BPS_BusLoadChangeSend                   115      // 1 Bit, Bit 3
#define     BPS_BusLoadChangeSendMask 0x08
#define     BPS_BusLoadChangeSendShift 3
#define BPS_AuxVoltageChangeSend                115      // 1 Bit, Bit 2
#define     BPS_AuxVoltageChangeSendMask 0x04
#define     BPS_AuxVoltageChangeSendShift 2
#define BPS_AuxCurrentChangeSend                115      // 1 Bit, Bit 1
#define     BPS_AuxCurrentChangeSendMask 0x02
#define     BPS_AuxCurrentChangeSendShift 1
#define BPS_TemperatureChangeSend               115      // 1 Bit, Bit 0
#define     BPS_TemperatureChangeSendMask 0x01
#define     BPS_TemperatureChangeSendShift 0
#define BPS_PowerSupply1SendCyclicBase          116      // 2 Bits, Bit 7-6
#define     BPS_PowerSupply1SendCyclicBaseMask 0xC0
#define     BPS_PowerSupply1SendCyclicBaseShift 6
#define BPS_PowerSupply1SendCyclicTime          116      // 14 Bits, Bit 13-0
#define     BPS_PowerSupply1SendCyclicTimeMask 0x3FFF
#define     BPS_PowerSupply1SendCyclicTimeShift 0
#define BPS_PowerSupply2SendCyclicBase          118      // 2 Bits, Bit 7-6
#define     BPS_PowerSupply2SendCyclicBaseMask 0xC0
#define     BPS_PowerSupply2SendCyclicBaseShift 6
#define BPS_PowerSupply2SendCyclicTime          118      // 14 Bits, Bit 13-0
#define     BPS_PowerSupply2SendCyclicTimeMask 0x3FFF
#define     BPS_PowerSupply2SendCyclicTimeShift 0
#define BPS_BusVoltageSendMinChangePercent      120      // uint8_t
#define BPS_BusVoltageSendMinChangeAbsolute     121      // int16_t
#define BPS_BusVoltageSendCyclicBase            123      // 2 Bits, Bit 7-6
#define     BPS_BusVoltageSendCyclicBaseMask 0xC0
#define     BPS_BusVoltageSendCyclicBaseShift 6
#define BPS_BusVoltageSendCyclicTime            123      // 14 Bits, Bit 13-0
#define     BPS_BusVoltageSendCyclicTimeMask 0x3FFF
#define     BPS_BusVoltageSendCyclicTimeShift 0
#define BPS_BusCurrentSendMinChangePercent      125      // uint8_t
#define BPS_BusCurrentSendMinChangeAbsolute     126      // int16_t
#define BPS_BusCurrentSendCyclicBase            128      // 2 Bits, Bit 7-6
#define     BPS_BusCurrentSendCyclicBaseMask 0xC0
#define     BPS_BusCurrentSendCyclicBaseShift 6
#define BPS_BusCurrentSendCyclicTime            128      // 14 Bits, Bit 13-0
#define     BPS_BusCurrentSendCyclicTimeMask 0x3FFF
#define     BPS_BusCurrentSendCyclicTimeShift 0
#define BPS_BusLoadSendMinChangePercent         130      // uint8_t
#define BPS_BusLoadSendMinChangeAbsolute        131      // uint8_t
#define BPS_BusLoadSendCyclicBase               132      // 2 Bits, Bit 7-6
#define     BPS_BusLoadSendCyclicBaseMask 0xC0
#define     BPS_BusLoadSendCyclicBaseShift 6
#define BPS_BusLoadSendCyclicTime               132      // 14 Bits, Bit 13-0
#define     BPS_BusLoadSendCyclicTimeMask 0x3FFF
#define     BPS_BusLoadSendCyclicTimeShift 0
#define BPS_AuxVoltageSendMinChangePercent      134      // uint8_t
#define BPS_AuxVoltageSendMinChangeAbsolute     135      // int16_t
#define BPS_AuxVoltageSendCyclicBase            137      // 2 Bits, Bit 7-6
#define     BPS_AuxVoltageSendCyclicBaseMask 0xC0
#define     BPS_AuxVoltageSendCyclicBaseShift 6
#define BPS_AuxVoltageSendCyclicTime            137      // 14 Bits, Bit 13-0
#define     BPS_AuxVoltageSendCyclicTimeMask 0x3FFF
#define     BPS_AuxVoltageSendCyclicTimeShift 0
#define BPS_AuxCurrentSendMinChangePercent      139      // uint8_t
#define BPS_AuxCurrentSendMinChangeAbsolute     140      // int16_t
#define BPS_AuxCurrentSendCyclicBase            142      // 2 Bits, Bit 7-6
#define     BPS_AuxCurrentSendCyclicBaseMask 0xC0
#define     BPS_AuxCurrentSendCyclicBaseShift 6
#define BPS_AuxCurrentSendCyclicTime            142      // 14 Bits, Bit 13-0
#define     BPS_AuxCurrentSendCyclicTimeMask 0x3FFF
#define     BPS_AuxCurrentSendCyclicTimeShift 0
#define BPS_TemperatureSendMinChangePercent     144      // uint8_t
#define BPS_TemperatureSendMinChangeAbsolute    145      // uint8_t
#define BPS_TemperatureSendCyclicBase           146      // 2 Bits, Bit 7-6
#define     BPS_TemperatureSendCyclicBaseMask 0xC0
#define     BPS_TemperatureSendCyclicBaseShift 6
#define BPS_TemperatureSendCyclicTime           146      // 14 Bits, Bit 13-0
#define     BPS_TemperatureSendCyclicTimeMask 0x3FFF
#define     BPS_TemperatureSendCyclicTimeShift 0
#define BPS_SC8815BusCurrent                    148      // 16 Bits, Bit 15-0
#define BPS_SC8815AuxVoltage                    150      // 5 Bits, Bit 7-3
#define     BPS_SC8815AuxVoltageMask 0xF8
#define     BPS_SC8815AuxVoltageShift 3
#define BPS_SC8815AuxCurrent                    151      // 16 Bits, Bit 15-0
#define BPS_SC8815AuxEnabled                    150      // 1 Bit, Bit 2
#define     BPS_SC8815AuxEnabledMask 0x04
#define     BPS_SC8815AuxEnabledShift 2
#define BPS_InputVoltageChangeSend              153      // 1 Bit, Bit 7
#define     BPS_InputVoltageChangeSendMask 0x80
#define     BPS_InputVoltageChangeSendShift 7
#define BPS_InputVoltageSendMinChangePercent    154      // uint8_t
#define BPS_InputVoltageSendMinChangeAbsolute   155      // int16_t
#define BPS_InputVoltageSendCyclicBase          157      // 2 Bits, Bit 7-6
#define     BPS_InputVoltageSendCyclicBaseMask 0xC0
#define     BPS_InputVoltageSendCyclicBaseShift 6
#define BPS_InputVoltageSendCyclicTime          157      // 14 Bits, Bit 13-0
#define     BPS_InputVoltageSendCyclicTimeMask 0x3FFF
#define     BPS_InputVoltageSendCyclicTimeShift 0
#define BPS_InputCurrentChangeSend              153      // 1 Bit, Bit 6
#define     BPS_InputCurrentChangeSendMask 0x40
#define     BPS_InputCurrentChangeSendShift 6
#define BPS_InputCurrentSendMinChangePercent    159      // uint8_t
#define BPS_InputCurrentSendMinChangeAbsolute   160      // int16_t
#define BPS_InputCurrentSendCyclicBase          162      // 2 Bits, Bit 7-6
#define     BPS_InputCurrentSendCyclicBaseMask 0xC0
#define     BPS_InputCurrentSendCyclicBaseShift 6
#define BPS_InputCurrentSendCyclicTime          162      // 14 Bits, Bit 13-0
#define     BPS_InputCurrentSendCyclicTimeMask 0x3FFF
#define     BPS_InputCurrentSendCyclicTimeShift 0
#define BPS_SC8815Frequency                     164      // 9 Bits, Bit 15-7
#define     BPS_SC8815FrequencyMask 0xFF80
#define     BPS_SC8815FrequencyShift 7
#define BPS_AuxTemperatureChangeSend            166      // 1 Bit, Bit 7
#define     BPS_AuxTemperatureChangeSendMask 0x80
#define     BPS_AuxTemperatureChangeSendShift 7
#define BPS_AuxTemperatureSendMinChangePercent  167      // uint8_t
#define BPS_AuxTemperatureSendMinChangeAbsolute 168      // uint8_t
#define BPS_AuxTemperatureSendCyclicBase        169      // 2 Bits, Bit 7-6
#define     BPS_AuxTemperatureSendCyclicBaseMask 0xC0
#define     BPS_AuxTemperatureSendCyclicBaseShift 6
#define BPS_AuxTemperatureSendCyclicTime        169      // 14 Bits, Bit 13-0
#define     BPS_AuxTemperatureSendCyclicTimeMask 0x3FFF
#define     BPS_AuxTemperatureSendCyclicTimeShift 0
#define BPS_AuxInputVoltageChangeSend           171      // 1 Bit, Bit 7
#define     BPS_AuxInputVoltageChangeSendMask 0x80
#define     BPS_AuxInputVoltageChangeSendShift 7
#define BPS_AuxInputVoltageSendMinChangePercent 172      // uint8_t
#define BPS_AuxInputVoltageSendMinChangeAbsolute 173      // int16_t
#define BPS_AuxInputVoltageSendCyclicBase       175      // 2 Bits, Bit 7-6
#define     BPS_AuxInputVoltageSendCyclicBaseMask 0xC0
#define     BPS_AuxInputVoltageSendCyclicBaseShift 6
#define BPS_AuxInputVoltageSendCyclicTime       175      // 14 Bits, Bit 13-0
#define     BPS_AuxInputVoltageSendCyclicTimeMask 0x3FFF
#define     BPS_AuxInputVoltageSendCyclicTimeShift 0
#define BPS_AuxInputCurrentChangeSend           171      // 1 Bit, Bit 6
#define     BPS_AuxInputCurrentChangeSendMask 0x40
#define     BPS_AuxInputCurrentChangeSendShift 6
#define BPS_AuxInputCurrentSendMinChangePercent 177      // uint8_t
#define BPS_AuxInputCurrentSendMinChangeAbsolute 178      // int16_t
#define BPS_AuxInputCurrentSendCyclicBase       180      // 2 Bits, Bit 7-6
#define     BPS_AuxInputCurrentSendCyclicBaseMask 0xC0
#define     BPS_AuxInputCurrentSendCyclicBaseShift 6
#define BPS_AuxInputCurrentSendCyclicTime       180      // 14 Bits, Bit 13-0
#define     BPS_AuxInputCurrentSendCyclicTimeMask 0x3FFF
#define     BPS_AuxInputCurrentSendCyclicTimeShift 0
#define BPS_AuxSC8815Frequency                  182      // 9 Bits, Bit 15-7
#define     BPS_AuxSC8815FrequencyMask 0xFF80
#define     BPS_AuxSC8815FrequencyShift 7
#define BPS_AuxLoadChangeSend                   171      // 1 Bit, Bit 5
#define     BPS_AuxLoadChangeSendMask 0x20
#define     BPS_AuxLoadChangeSendShift 5
#define BPS_AuxLoadSendMinChangePercent         184      // uint8_t
#define BPS_AuxLoadSendMinChangeAbsolute        185      // uint8_t
#define BPS_AuxLoadSendCyclicBase               186      // 2 Bits, Bit 7-6
#define     BPS_AuxLoadSendCyclicBaseMask 0xC0
#define     BPS_AuxLoadSendCyclicBaseShift 6
#define BPS_AuxLoadSendCyclicTime               186      // 14 Bits, Bit 13-0
#define     BPS_AuxLoadSendCyclicTimeMask 0x3FFF
#define     BPS_AuxLoadSendCyclicTimeShift 0
#define BPS_AuxResetTime                        188      // uint8_t

// 总线复位时间
#define ParamBPS_ResetTime                           (knx.paramByte(BPS_ResetTime))
// 发送总线电源状态
#define ParamBPS_PowerSupply1ChangeSend              ((bool)(knx.paramByte(BPS_PowerSupply1ChangeSend) & BPS_PowerSupply1ChangeSendMask))
// 发送辅助电源状态
#define ParamBPS_PowerSupply2ChangeSend              ((bool)(knx.paramByte(BPS_PowerSupply2ChangeSend) & BPS_PowerSupply2ChangeSendMask))
// 发送总线电源电压
#define ParamBPS_BusVoltageChangeSend                ((bool)(knx.paramByte(BPS_BusVoltageChangeSend) & BPS_BusVoltageChangeSendMask))
// 发送总线电源电流
#define ParamBPS_BusCurrentChangeSend                ((bool)(knx.paramByte(BPS_BusCurrentChangeSend) & BPS_BusCurrentChangeSendMask))
// 发送总线负载
#define ParamBPS_BusLoadChangeSend                   ((bool)(knx.paramByte(BPS_BusLoadChangeSend) & BPS_BusLoadChangeSendMask))
// 发送辅助电源电压
#define ParamBPS_AuxVoltageChangeSend                ((bool)(knx.paramByte(BPS_AuxVoltageChangeSend) & BPS_AuxVoltageChangeSendMask))
// 发送辅助电源电流
#define ParamBPS_AuxCurrentChangeSend                ((bool)(knx.paramByte(BPS_AuxCurrentChangeSend) & BPS_AuxCurrentChangeSendMask))
// 发送总线电源温度
#define ParamBPS_TemperatureChangeSend               ((bool)(knx.paramByte(BPS_TemperatureChangeSend) & BPS_TemperatureChangeSendMask))
// 时间基准
#define ParamBPS_PowerSupply1SendCyclicBase          ((knx.paramByte(BPS_PowerSupply1SendCyclicBase) & BPS_PowerSupply1SendCyclicBaseMask) >> BPS_PowerSupply1SendCyclicBaseShift)
// 时间
#define ParamBPS_PowerSupply1SendCyclicTime          (knx.paramWord(BPS_PowerSupply1SendCyclicTime) & BPS_PowerSupply1SendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_PowerSupply1SendCyclicTimeMS        (paramDelay(knx.paramWord(BPS_PowerSupply1SendCyclicTime)))
// 时间基准
#define ParamBPS_PowerSupply2SendCyclicBase          ((knx.paramByte(BPS_PowerSupply2SendCyclicBase) & BPS_PowerSupply2SendCyclicBaseMask) >> BPS_PowerSupply2SendCyclicBaseShift)
// 时间
#define ParamBPS_PowerSupply2SendCyclicTime          (knx.paramWord(BPS_PowerSupply2SendCyclicTime) & BPS_PowerSupply2SendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_PowerSupply2SendCyclicTimeMS        (paramDelay(knx.paramWord(BPS_PowerSupply2SendCyclicTime)))
// 相对最小变化量
#define ParamBPS_BusVoltageSendMinChangePercent      (knx.paramByte(BPS_BusVoltageSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_BusVoltageSendMinChangeAbsolute     ((int16_t)knx.paramWord(BPS_BusVoltageSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_BusVoltageSendCyclicBase            ((knx.paramByte(BPS_BusVoltageSendCyclicBase) & BPS_BusVoltageSendCyclicBaseMask) >> BPS_BusVoltageSendCyclicBaseShift)
// 时间
#define ParamBPS_BusVoltageSendCyclicTime            (knx.paramWord(BPS_BusVoltageSendCyclicTime) & BPS_BusVoltageSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_BusVoltageSendCyclicTimeMS          (paramDelay(knx.paramWord(BPS_BusVoltageSendCyclicTime)))
// 相对最小变化量
#define ParamBPS_BusCurrentSendMinChangePercent      (knx.paramByte(BPS_BusCurrentSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_BusCurrentSendMinChangeAbsolute     ((int16_t)knx.paramWord(BPS_BusCurrentSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_BusCurrentSendCyclicBase            ((knx.paramByte(BPS_BusCurrentSendCyclicBase) & BPS_BusCurrentSendCyclicBaseMask) >> BPS_BusCurrentSendCyclicBaseShift)
// 时间
#define ParamBPS_BusCurrentSendCyclicTime            (knx.paramWord(BPS_BusCurrentSendCyclicTime) & BPS_BusCurrentSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_BusCurrentSendCyclicTimeMS          (paramDelay(knx.paramWord(BPS_BusCurrentSendCyclicTime)))
// 相对最小变化量
#define ParamBPS_BusLoadSendMinChangePercent         (knx.paramByte(BPS_BusLoadSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_BusLoadSendMinChangeAbsolute        (knx.paramByte(BPS_BusLoadSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_BusLoadSendCyclicBase               ((knx.paramByte(BPS_BusLoadSendCyclicBase) & BPS_BusLoadSendCyclicBaseMask) >> BPS_BusLoadSendCyclicBaseShift)
// 时间
#define ParamBPS_BusLoadSendCyclicTime               (knx.paramWord(BPS_BusLoadSendCyclicTime) & BPS_BusLoadSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_BusLoadSendCyclicTimeMS             (paramDelay(knx.paramWord(BPS_BusLoadSendCyclicTime)))
// 相对最小变化量
#define ParamBPS_AuxVoltageSendMinChangePercent      (knx.paramByte(BPS_AuxVoltageSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_AuxVoltageSendMinChangeAbsolute     ((int16_t)knx.paramWord(BPS_AuxVoltageSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_AuxVoltageSendCyclicBase            ((knx.paramByte(BPS_AuxVoltageSendCyclicBase) & BPS_AuxVoltageSendCyclicBaseMask) >> BPS_AuxVoltageSendCyclicBaseShift)
// 时间
#define ParamBPS_AuxVoltageSendCyclicTime            (knx.paramWord(BPS_AuxVoltageSendCyclicTime) & BPS_AuxVoltageSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_AuxVoltageSendCyclicTimeMS          (paramDelay(knx.paramWord(BPS_AuxVoltageSendCyclicTime)))
// 相对最小变化量
#define ParamBPS_AuxCurrentSendMinChangePercent      (knx.paramByte(BPS_AuxCurrentSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_AuxCurrentSendMinChangeAbsolute     ((int16_t)knx.paramWord(BPS_AuxCurrentSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_AuxCurrentSendCyclicBase            ((knx.paramByte(BPS_AuxCurrentSendCyclicBase) & BPS_AuxCurrentSendCyclicBaseMask) >> BPS_AuxCurrentSendCyclicBaseShift)
// 时间
#define ParamBPS_AuxCurrentSendCyclicTime            (knx.paramWord(BPS_AuxCurrentSendCyclicTime) & BPS_AuxCurrentSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_AuxCurrentSendCyclicTimeMS          (paramDelay(knx.paramWord(BPS_AuxCurrentSendCyclicTime)))
// 相对最小变化量
#define ParamBPS_TemperatureSendMinChangePercent     (knx.paramByte(BPS_TemperatureSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_TemperatureSendMinChangeAbsolute    (knx.paramByte(BPS_TemperatureSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_TemperatureSendCyclicBase           ((knx.paramByte(BPS_TemperatureSendCyclicBase) & BPS_TemperatureSendCyclicBaseMask) >> BPS_TemperatureSendCyclicBaseShift)
// 时间
#define ParamBPS_TemperatureSendCyclicTime           (knx.paramWord(BPS_TemperatureSendCyclicTime) & BPS_TemperatureSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_TemperatureSendCyclicTimeMS         (paramDelay(knx.paramWord(BPS_TemperatureSendCyclicTime)))
// 总线电源电流
#define ParamBPS_SC8815BusCurrent                    (knx.paramWord(BPS_SC8815BusCurrent))
// 辅助电源电压
#define ParamBPS_SC8815AuxVoltage                    ((knx.paramByte(BPS_SC8815AuxVoltage) & BPS_SC8815AuxVoltageMask) >> BPS_SC8815AuxVoltageShift)
// 辅助电源电流
#define ParamBPS_SC8815AuxCurrent                    (knx.paramWord(BPS_SC8815AuxCurrent))
// SC8815 辅助电源使能
#define ParamBPS_SC8815AuxEnabled                    ((bool)(knx.paramByte(BPS_SC8815AuxEnabled) & BPS_SC8815AuxEnabledMask))
// 发送总线电源输入电压
#define ParamBPS_InputVoltageChangeSend              ((bool)(knx.paramByte(BPS_InputVoltageChangeSend) & BPS_InputVoltageChangeSendMask))
// 相对最小变化量
#define ParamBPS_InputVoltageSendMinChangePercent    (knx.paramByte(BPS_InputVoltageSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_InputVoltageSendMinChangeAbsolute   ((int16_t)knx.paramWord(BPS_InputVoltageSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_InputVoltageSendCyclicBase          ((knx.paramByte(BPS_InputVoltageSendCyclicBase) & BPS_InputVoltageSendCyclicBaseMask) >> BPS_InputVoltageSendCyclicBaseShift)
// 时间
#define ParamBPS_InputVoltageSendCyclicTime          (knx.paramWord(BPS_InputVoltageSendCyclicTime) & BPS_InputVoltageSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_InputVoltageSendCyclicTimeMS        (paramDelay(knx.paramWord(BPS_InputVoltageSendCyclicTime)))
// 发送总线电源输入电流
#define ParamBPS_InputCurrentChangeSend              ((bool)(knx.paramByte(BPS_InputCurrentChangeSend) & BPS_InputCurrentChangeSendMask))
// 相对最小变化量
#define ParamBPS_InputCurrentSendMinChangePercent    (knx.paramByte(BPS_InputCurrentSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_InputCurrentSendMinChangeAbsolute   ((int16_t)knx.paramWord(BPS_InputCurrentSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_InputCurrentSendCyclicBase          ((knx.paramByte(BPS_InputCurrentSendCyclicBase) & BPS_InputCurrentSendCyclicBaseMask) >> BPS_InputCurrentSendCyclicBaseShift)
// 时间
#define ParamBPS_InputCurrentSendCyclicTime          (knx.paramWord(BPS_InputCurrentSendCyclicTime) & BPS_InputCurrentSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_InputCurrentSendCyclicTimeMS        (paramDelay(knx.paramWord(BPS_InputCurrentSendCyclicTime)))
// 开关频率
#define ParamBPS_SC8815Frequency                     ((knx.paramWord(BPS_SC8815Frequency) & BPS_SC8815FrequencyMask) >> BPS_SC8815FrequencyShift)
// 发送辅助电源温度
#define ParamBPS_AuxTemperatureChangeSend            ((bool)(knx.paramByte(BPS_AuxTemperatureChangeSend) & BPS_AuxTemperatureChangeSendMask))
// 相对最小变化量
#define ParamBPS_AuxTemperatureSendMinChangePercent  (knx.paramByte(BPS_AuxTemperatureSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_AuxTemperatureSendMinChangeAbsolute (knx.paramByte(BPS_AuxTemperatureSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_AuxTemperatureSendCyclicBase        ((knx.paramByte(BPS_AuxTemperatureSendCyclicBase) & BPS_AuxTemperatureSendCyclicBaseMask) >> BPS_AuxTemperatureSendCyclicBaseShift)
// 时间
#define ParamBPS_AuxTemperatureSendCyclicTime        (knx.paramWord(BPS_AuxTemperatureSendCyclicTime) & BPS_AuxTemperatureSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_AuxTemperatureSendCyclicTimeMS      (paramDelay(knx.paramWord(BPS_AuxTemperatureSendCyclicTime)))
// 发送辅助电源输入电压
#define ParamBPS_AuxInputVoltageChangeSend           ((bool)(knx.paramByte(BPS_AuxInputVoltageChangeSend) & BPS_AuxInputVoltageChangeSendMask))
// 相对最小变化量
#define ParamBPS_AuxInputVoltageSendMinChangePercent (knx.paramByte(BPS_AuxInputVoltageSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_AuxInputVoltageSendMinChangeAbsolute ((int16_t)knx.paramWord(BPS_AuxInputVoltageSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_AuxInputVoltageSendCyclicBase       ((knx.paramByte(BPS_AuxInputVoltageSendCyclicBase) & BPS_AuxInputVoltageSendCyclicBaseMask) >> BPS_AuxInputVoltageSendCyclicBaseShift)
// 时间
#define ParamBPS_AuxInputVoltageSendCyclicTime       (knx.paramWord(BPS_AuxInputVoltageSendCyclicTime) & BPS_AuxInputVoltageSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_AuxInputVoltageSendCyclicTimeMS     (paramDelay(knx.paramWord(BPS_AuxInputVoltageSendCyclicTime)))
// 发送辅助电源输入电流
#define ParamBPS_AuxInputCurrentChangeSend           ((bool)(knx.paramByte(BPS_AuxInputCurrentChangeSend) & BPS_AuxInputCurrentChangeSendMask))
// 相对最小变化量
#define ParamBPS_AuxInputCurrentSendMinChangePercent (knx.paramByte(BPS_AuxInputCurrentSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_AuxInputCurrentSendMinChangeAbsolute ((int16_t)knx.paramWord(BPS_AuxInputCurrentSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_AuxInputCurrentSendCyclicBase       ((knx.paramByte(BPS_AuxInputCurrentSendCyclicBase) & BPS_AuxInputCurrentSendCyclicBaseMask) >> BPS_AuxInputCurrentSendCyclicBaseShift)
// 时间
#define ParamBPS_AuxInputCurrentSendCyclicTime       (knx.paramWord(BPS_AuxInputCurrentSendCyclicTime) & BPS_AuxInputCurrentSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_AuxInputCurrentSendCyclicTimeMS     (paramDelay(knx.paramWord(BPS_AuxInputCurrentSendCyclicTime)))
// 开关频率
#define ParamBPS_AuxSC8815Frequency                  ((knx.paramWord(BPS_AuxSC8815Frequency) & BPS_AuxSC8815FrequencyMask) >> BPS_AuxSC8815FrequencyShift)
// 发送辅助电源负载
#define ParamBPS_AuxLoadChangeSend                   ((bool)(knx.paramByte(BPS_AuxLoadChangeSend) & BPS_AuxLoadChangeSendMask))
// 相对最小变化量
#define ParamBPS_AuxLoadSendMinChangePercent         (knx.paramByte(BPS_AuxLoadSendMinChangePercent))
// 绝对最小变化量
#define ParamBPS_AuxLoadSendMinChangeAbsolute        (knx.paramByte(BPS_AuxLoadSendMinChangeAbsolute))
// 时间基准
#define ParamBPS_AuxLoadSendCyclicBase               ((knx.paramByte(BPS_AuxLoadSendCyclicBase) & BPS_AuxLoadSendCyclicBaseMask) >> BPS_AuxLoadSendCyclicBaseShift)
// 时间
#define ParamBPS_AuxLoadSendCyclicTime               (knx.paramWord(BPS_AuxLoadSendCyclicTime) & BPS_AuxLoadSendCyclicTimeMask)
// 时间 (in Millisekunden)
#define ParamBPS_AuxLoadSendCyclicTimeMS             (paramDelay(knx.paramWord(BPS_AuxLoadSendCyclicTime)))
// 辅助电源复位时间
#define ParamBPS_AuxResetTime                        (knx.paramByte(BPS_AuxResetTime))

#define BPS_KoPowerSupply1Status 20
#define BPS_KoPowerSupply2Status 21
#define BPS_KoBusReset 22
#define BPS_KoBusVoltage 23
#define BPS_KoBusCurrent 24
#define BPS_KoBusLoad 25
#define BPS_KoAuxVoltage 26
#define BPS_KoAuxCurrent 27
#define BPS_KoTemperature 28
#define BPS_KoSC8815Status 29
#define BPS_KoSC8815ErrorCode 30
#define BPS_KoInputVoltage 31
#define BPS_KoInputCurrent 32
#define BPS_KoTemperature2 33
#define BPS_KoAuxInputVoltage 34
#define BPS_KoAuxInputCurrent 35
#define BPS_KoAuxSC8815Status 36
#define BPS_KoAuxSC8815ErrorCode 37
#define BPS_KoAuxLoad 38
#define BPS_KoAuxReset 39

// 总线电源状态
#define KoBPS_PowerSupply1Status                  (knx.getGroupObject(BPS_KoPowerSupply1Status))
// 辅助电源状态
#define KoBPS_PowerSupply2Status                  (knx.getGroupObject(BPS_KoPowerSupply2Status))
// 总线电源复位
#define KoBPS_BusReset                            (knx.getGroupObject(BPS_KoBusReset))
// 总线电源电压
#define KoBPS_BusVoltage                          (knx.getGroupObject(BPS_KoBusVoltage))
// 总线电源电流
#define KoBPS_BusCurrent                          (knx.getGroupObject(BPS_KoBusCurrent))
// 总线电源负载
#define KoBPS_BusLoad                             (knx.getGroupObject(BPS_KoBusLoad))
// 辅助电源电压
#define KoBPS_AuxVoltage                          (knx.getGroupObject(BPS_KoAuxVoltage))
// 辅助电源电流
#define KoBPS_AuxCurrent                          (knx.getGroupObject(BPS_KoAuxCurrent))
// 总线电源温度
#define KoBPS_Temperature                         (knx.getGroupObject(BPS_KoTemperature))
// 总线 SC8815 运行状态
#define KoBPS_SC8815Status                        (knx.getGroupObject(BPS_KoSC8815Status))
// 总线 SC8815 故障代码
#define KoBPS_SC8815ErrorCode                     (knx.getGroupObject(BPS_KoSC8815ErrorCode))
// 总线电源输入电压
#define KoBPS_InputVoltage                        (knx.getGroupObject(BPS_KoInputVoltage))
// 总线电源输入电流
#define KoBPS_InputCurrent                        (knx.getGroupObject(BPS_KoInputCurrent))
// 辅助电源温度
#define KoBPS_Temperature2                        (knx.getGroupObject(BPS_KoTemperature2))
// 辅助电源输入电压
#define KoBPS_AuxInputVoltage                     (knx.getGroupObject(BPS_KoAuxInputVoltage))
// 辅助电源输入电流
#define KoBPS_AuxInputCurrent                     (knx.getGroupObject(BPS_KoAuxInputCurrent))
// 辅助 SC8815 运行状态
#define KoBPS_AuxSC8815Status                     (knx.getGroupObject(BPS_KoAuxSC8815Status))
// 辅助 SC8815 故障代码
#define KoBPS_AuxSC8815ErrorCode                  (knx.getGroupObject(BPS_KoAuxSC8815ErrorCode))
// 辅助电源负载
#define KoBPS_AuxLoad                             (knx.getGroupObject(BPS_KoAuxLoad))
// 辅助电源复位
#define KoBPS_AuxReset                            (knx.getGroupObject(BPS_KoAuxReset))

#define BUZ_Enabled                             189      // 1 Bit, Bit 7
#define     BUZ_EnabledMask 0x80
#define     BUZ_EnabledShift 7
#define BUZ_Frequency                           190      // 6 Bits, Bit 7-2
#define     BUZ_FrequencyMask 0xFC
#define     BUZ_FrequencyShift 2
#define BUZ_BusSC8815NoAnswer                   191      // 1 Bit, Bit 7
#define     BUZ_BusSC8815NoAnswerMask 0x80
#define     BUZ_BusSC8815NoAnswerShift 7
#define BUZ_BusINANoAnswer                      191      // 1 Bit, Bit 6
#define     BUZ_BusINANoAnswerMask 0x40
#define     BUZ_BusINANoAnswerShift 6
#define BUZ_BusTempNoAnswer                     191      // 1 Bit, Bit 5
#define     BUZ_BusTempNoAnswerMask 0x20
#define     BUZ_BusTempNoAnswerShift 5
#define BUZ_BusVbusShort                        191      // 1 Bit, Bit 4
#define     BUZ_BusVbusShortMask 0x10
#define     BUZ_BusVbusShortShift 4
#define BUZ_BusOTP                              191      // 1 Bit, Bit 3
#define     BUZ_BusOTPMask 0x08
#define     BUZ_BusOTPShift 3
#define BUZ_BusOverCurrent                      191      // 1 Bit, Bit 2
#define     BUZ_BusOverCurrentMask 0x04
#define     BUZ_BusOverCurrentShift 2
#define BUZ_BusInputHigh                        191      // 1 Bit, Bit 1
#define     BUZ_BusInputHighMask 0x02
#define     BUZ_BusInputHighShift 1
#define BUZ_BusInputLow                         191      // 1 Bit, Bit 0
#define     BUZ_BusInputLowMask 0x01
#define     BUZ_BusInputLowShift 0
#define BUZ_AuxSC8815NoAnswer                   192      // 1 Bit, Bit 7
#define     BUZ_AuxSC8815NoAnswerMask 0x80
#define     BUZ_AuxSC8815NoAnswerShift 7
#define BUZ_AuxINANoAnswer                      192      // 1 Bit, Bit 6
#define     BUZ_AuxINANoAnswerMask 0x40
#define     BUZ_AuxINANoAnswerShift 6
#define BUZ_AuxTempNoAnswer                     192      // 1 Bit, Bit 5
#define     BUZ_AuxTempNoAnswerMask 0x20
#define     BUZ_AuxTempNoAnswerShift 5
#define BUZ_AuxVbusShort                        192      // 1 Bit, Bit 4
#define     BUZ_AuxVbusShortMask 0x10
#define     BUZ_AuxVbusShortShift 4
#define BUZ_AuxOTP                              192      // 1 Bit, Bit 3
#define     BUZ_AuxOTPMask 0x08
#define     BUZ_AuxOTPShift 3
#define BUZ_AuxOverCurrent                      192      // 1 Bit, Bit 2
#define     BUZ_AuxOverCurrentMask 0x04
#define     BUZ_AuxOverCurrentShift 2
#define BUZ_AuxInputHigh                        192      // 1 Bit, Bit 1
#define     BUZ_AuxInputHighMask 0x02
#define     BUZ_AuxInputHighShift 1
#define BUZ_AuxInputLow                         192      // 1 Bit, Bit 0
#define     BUZ_AuxInputLowMask 0x01
#define     BUZ_AuxInputLowShift 0
#define BUZ_BusSC8815NoAnswerRhythm             193      // 3 Bits, Bit 7-5
#define     BUZ_BusSC8815NoAnswerRhythmMask 0xE0
#define     BUZ_BusSC8815NoAnswerRhythmShift 5
#define BUZ_BusINANoAnswerRhythm                193      // 3 Bits, Bit 4-2
#define     BUZ_BusINANoAnswerRhythmMask 0x1C
#define     BUZ_BusINANoAnswerRhythmShift 2
#define BUZ_BusTempNoAnswerRhythm               194      // 3 Bits, Bit 7-5
#define     BUZ_BusTempNoAnswerRhythmMask 0xE0
#define     BUZ_BusTempNoAnswerRhythmShift 5
#define BUZ_BusVbusShortRhythm                  194      // 3 Bits, Bit 4-2
#define     BUZ_BusVbusShortRhythmMask 0x1C
#define     BUZ_BusVbusShortRhythmShift 2
#define BUZ_BusOTPRhythm                        195      // 3 Bits, Bit 7-5
#define     BUZ_BusOTPRhythmMask 0xE0
#define     BUZ_BusOTPRhythmShift 5
#define BUZ_BusOverCurrentRhythm                195      // 3 Bits, Bit 4-2
#define     BUZ_BusOverCurrentRhythmMask 0x1C
#define     BUZ_BusOverCurrentRhythmShift 2
#define BUZ_BusInputHighRhythm                  196      // 3 Bits, Bit 7-5
#define     BUZ_BusInputHighRhythmMask 0xE0
#define     BUZ_BusInputHighRhythmShift 5
#define BUZ_BusInputLowRhythm                   196      // 3 Bits, Bit 4-2
#define     BUZ_BusInputLowRhythmMask 0x1C
#define     BUZ_BusInputLowRhythmShift 2
#define BUZ_AuxSC8815NoAnswerRhythm             197      // 3 Bits, Bit 7-5
#define     BUZ_AuxSC8815NoAnswerRhythmMask 0xE0
#define     BUZ_AuxSC8815NoAnswerRhythmShift 5
#define BUZ_AuxINANoAnswerRhythm                197      // 3 Bits, Bit 4-2
#define     BUZ_AuxINANoAnswerRhythmMask 0x1C
#define     BUZ_AuxINANoAnswerRhythmShift 2
#define BUZ_AuxTempNoAnswerRhythm               198      // 3 Bits, Bit 7-5
#define     BUZ_AuxTempNoAnswerRhythmMask 0xE0
#define     BUZ_AuxTempNoAnswerRhythmShift 5
#define BUZ_AuxVbusShortRhythm                  198      // 3 Bits, Bit 4-2
#define     BUZ_AuxVbusShortRhythmMask 0x1C
#define     BUZ_AuxVbusShortRhythmShift 2
#define BUZ_AuxOTPRhythm                        199      // 3 Bits, Bit 7-5
#define     BUZ_AuxOTPRhythmMask 0xE0
#define     BUZ_AuxOTPRhythmShift 5
#define BUZ_AuxOverCurrentRhythm                199      // 3 Bits, Bit 4-2
#define     BUZ_AuxOverCurrentRhythmMask 0x1C
#define     BUZ_AuxOverCurrentRhythmShift 2
#define BUZ_AuxInputHighRhythm                  200      // 3 Bits, Bit 7-5
#define     BUZ_AuxInputHighRhythmMask 0xE0
#define     BUZ_AuxInputHighRhythmShift 5
#define BUZ_AuxInputLowRhythm                   200      // 3 Bits, Bit 4-2
#define     BUZ_AuxInputLowRhythmMask 0x1C
#define     BUZ_AuxInputLowRhythmShift 2

// 启用蜂鸣器报警
#define ParamBUZ_Enabled                             ((bool)(knx.paramByte(BUZ_Enabled) & BUZ_EnabledMask))
// 报警频率
#define ParamBUZ_Frequency                           ((knx.paramByte(BUZ_Frequency) & BUZ_FrequencyMask) >> BUZ_FrequencyShift)
// 总线 SC8815 无应答
#define ParamBUZ_BusSC8815NoAnswer                   ((bool)(knx.paramByte(BUZ_BusSC8815NoAnswer) & BUZ_BusSC8815NoAnswerMask))
// 总线 INA238 无应答
#define ParamBUZ_BusINANoAnswer                      ((bool)(knx.paramByte(BUZ_BusINANoAnswer) & BUZ_BusINANoAnswerMask))
// 总线温度传感器无应答
#define ParamBUZ_BusTempNoAnswer                     ((bool)(knx.paramByte(BUZ_BusTempNoAnswer) & BUZ_BusTempNoAnswerMask))
// 总线输出短路
#define ParamBUZ_BusVbusShort                        ((bool)(knx.paramByte(BUZ_BusVbusShort) & BUZ_BusVbusShortMask))
// 总线芯片过温
#define ParamBUZ_BusOTP                              ((bool)(knx.paramByte(BUZ_BusOTP) & BUZ_BusOTPMask))
// 总线输出过流
#define ParamBUZ_BusOverCurrent                      ((bool)(knx.paramByte(BUZ_BusOverCurrent) & BUZ_BusOverCurrentMask))
// 总线输入电压过高
#define ParamBUZ_BusInputHigh                        ((bool)(knx.paramByte(BUZ_BusInputHigh) & BUZ_BusInputHighMask))
// 总线输入电压过低
#define ParamBUZ_BusInputLow                         ((bool)(knx.paramByte(BUZ_BusInputLow) & BUZ_BusInputLowMask))
// 辅助 SC8815 无应答
#define ParamBUZ_AuxSC8815NoAnswer                   ((bool)(knx.paramByte(BUZ_AuxSC8815NoAnswer) & BUZ_AuxSC8815NoAnswerMask))
// 辅助 INA238 无应答
#define ParamBUZ_AuxINANoAnswer                      ((bool)(knx.paramByte(BUZ_AuxINANoAnswer) & BUZ_AuxINANoAnswerMask))
// 辅助温度传感器无应答
#define ParamBUZ_AuxTempNoAnswer                     ((bool)(knx.paramByte(BUZ_AuxTempNoAnswer) & BUZ_AuxTempNoAnswerMask))
// 辅助输出短路
#define ParamBUZ_AuxVbusShort                        ((bool)(knx.paramByte(BUZ_AuxVbusShort) & BUZ_AuxVbusShortMask))
// 辅助芯片过温
#define ParamBUZ_AuxOTP                              ((bool)(knx.paramByte(BUZ_AuxOTP) & BUZ_AuxOTPMask))
// 辅助输出过流
#define ParamBUZ_AuxOverCurrent                      ((bool)(knx.paramByte(BUZ_AuxOverCurrent) & BUZ_AuxOverCurrentMask))
// 辅助输入电压过高
#define ParamBUZ_AuxInputHigh                        ((bool)(knx.paramByte(BUZ_AuxInputHigh) & BUZ_AuxInputHighMask))
// 辅助输入电压过低
#define ParamBUZ_AuxInputLow                         ((bool)(knx.paramByte(BUZ_AuxInputLow) & BUZ_AuxInputLowMask))
// 报警节奏
#define ParamBUZ_BusSC8815NoAnswerRhythm             ((knx.paramByte(BUZ_BusSC8815NoAnswerRhythm) & BUZ_BusSC8815NoAnswerRhythmMask) >> BUZ_BusSC8815NoAnswerRhythmShift)
// 报警节奏
#define ParamBUZ_BusINANoAnswerRhythm                ((knx.paramByte(BUZ_BusINANoAnswerRhythm) & BUZ_BusINANoAnswerRhythmMask) >> BUZ_BusINANoAnswerRhythmShift)
// 报警节奏
#define ParamBUZ_BusTempNoAnswerRhythm               ((knx.paramByte(BUZ_BusTempNoAnswerRhythm) & BUZ_BusTempNoAnswerRhythmMask) >> BUZ_BusTempNoAnswerRhythmShift)
// 报警节奏
#define ParamBUZ_BusVbusShortRhythm                  ((knx.paramByte(BUZ_BusVbusShortRhythm) & BUZ_BusVbusShortRhythmMask) >> BUZ_BusVbusShortRhythmShift)
// 报警节奏
#define ParamBUZ_BusOTPRhythm                        ((knx.paramByte(BUZ_BusOTPRhythm) & BUZ_BusOTPRhythmMask) >> BUZ_BusOTPRhythmShift)
// 报警节奏
#define ParamBUZ_BusOverCurrentRhythm                ((knx.paramByte(BUZ_BusOverCurrentRhythm) & BUZ_BusOverCurrentRhythmMask) >> BUZ_BusOverCurrentRhythmShift)
// 报警节奏
#define ParamBUZ_BusInputHighRhythm                  ((knx.paramByte(BUZ_BusInputHighRhythm) & BUZ_BusInputHighRhythmMask) >> BUZ_BusInputHighRhythmShift)
// 报警节奏
#define ParamBUZ_BusInputLowRhythm                   ((knx.paramByte(BUZ_BusInputLowRhythm) & BUZ_BusInputLowRhythmMask) >> BUZ_BusInputLowRhythmShift)
// 报警节奏
#define ParamBUZ_AuxSC8815NoAnswerRhythm             ((knx.paramByte(BUZ_AuxSC8815NoAnswerRhythm) & BUZ_AuxSC8815NoAnswerRhythmMask) >> BUZ_AuxSC8815NoAnswerRhythmShift)
// 报警节奏
#define ParamBUZ_AuxINANoAnswerRhythm                ((knx.paramByte(BUZ_AuxINANoAnswerRhythm) & BUZ_AuxINANoAnswerRhythmMask) >> BUZ_AuxINANoAnswerRhythmShift)
// 报警节奏
#define ParamBUZ_AuxTempNoAnswerRhythm               ((knx.paramByte(BUZ_AuxTempNoAnswerRhythm) & BUZ_AuxTempNoAnswerRhythmMask) >> BUZ_AuxTempNoAnswerRhythmShift)
// 报警节奏
#define ParamBUZ_AuxVbusShortRhythm                  ((knx.paramByte(BUZ_AuxVbusShortRhythm) & BUZ_AuxVbusShortRhythmMask) >> BUZ_AuxVbusShortRhythmShift)
// 报警节奏
#define ParamBUZ_AuxOTPRhythm                        ((knx.paramByte(BUZ_AuxOTPRhythm) & BUZ_AuxOTPRhythmMask) >> BUZ_AuxOTPRhythmShift)
// 报警节奏
#define ParamBUZ_AuxOverCurrentRhythm                ((knx.paramByte(BUZ_AuxOverCurrentRhythm) & BUZ_AuxOverCurrentRhythmMask) >> BUZ_AuxOverCurrentRhythmShift)
// 报警节奏
#define ParamBUZ_AuxInputHighRhythm                  ((knx.paramByte(BUZ_AuxInputHighRhythm) & BUZ_AuxInputHighRhythmMask) >> BUZ_AuxInputHighRhythmShift)
// 报警节奏
#define ParamBUZ_AuxInputLowRhythm                   ((knx.paramByte(BUZ_AuxInputLowRhythm) & BUZ_AuxInputLowRhythmMask) >> BUZ_AuxInputLowRhythmShift)

#define BUZ_KoMute 40

// 蜂鸣器静音
#define KoBUZ_Mute                                (knx.getGroupObject(BUZ_KoMute))

#define DSP_Enabled                             201      // 1 Bit, Bit 7
#define     DSP_EnabledMask 0x80
#define     DSP_EnabledShift 7
#define DSP_BacklightTimeout                    201      // 3 Bits, Bit 6-4
#define     DSP_BacklightTimeoutMask 0x70
#define     DSP_BacklightTimeoutShift 4
#define DSP_Brightness                          202      // uint8_t

// 启用显示屏
#define ParamDSP_Enabled                             ((bool)(knx.paramByte(DSP_Enabled) & DSP_EnabledMask))
// 背光超时
#define ParamDSP_BacklightTimeout                    ((knx.paramByte(DSP_BacklightTimeout) & DSP_BacklightTimeoutMask) >> DSP_BacklightTimeoutShift)
// 背光亮度
#define ParamDSP_Brightness                          (knx.paramByte(DSP_Brightness))


// enumeration types


#ifdef MAIN_FirmwareRevision
#ifndef FIRMWARE_REVISION
#define FIRMWARE_REVISION MAIN_FirmwareRevision
#endif
#endif
#ifdef MAIN_FirmwareName
#ifndef FIRMWARE_NAME
#define FIRMWARE_NAME MAIN_FirmwareName
#endif
#endif
