// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_CC_H_INCLUDED
#define EM_CC_H_INCLUDED
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define INVALID_CC 0xFF
#define MAX14      0x3F80 // 1.0 value for 14' 0..1 controllers (max high 7', zero low 7': 127<<7)
#define ZERO14	   0x2000 // 0.0 value for 14' -1..1 controllers
#define MID7       64     /// middle value for 7' bytes
#define MAX7       127
#define CHANNEL16  15
#define CHANNEL01  0
#define CHANNEL02  1

/// @brief Channel 1,2 CCs
typedef enum EM_CC {
    EM_CC_BankSelect          = 0, // assignable for Y/Z
    EM_CC_ModDepth            = 1, // assignable for Y/Z
    EM_CC_Breath              = 2, // assignable for Y/Z
    EM_CC_Undefined3          = 3, // assignable for Y/Z
    EM_CC_Foot                = 4, // assignable for Y/Z
    EM_CC_Volume              = 7, // assignable for Y/Z
    EM_CC_OctaveShift         = 8,
    EM_CC_MonoSwitch          = 9,
    EM_CC_FineTune            = 10, // 4..124 = -60..+60 cents 
    EM_CC_Expression          = 11, // Z
    EM_CC_M1                  = 12,
    EM_CC_M2                  = 13,
    EM_CC_M3                  = 14,
    EM_CC_M4                  = 15,
    EM_CC_M5                  = 16,
    EM_CC_M6                  = 17,
    EM_CC_PostLevel           = 18,
    EM_CC_AudioInputLevel     = 19,
    EM_CC_R1                  = 20,
    EM_CC_R2                  = 21,
    EM_CC_R3                  = 22,
    EM_CC_R4                  = 23,
    EM_CC_RMix                = 24,
    EM_CC_RoundRate           = 25,
    EM_CC_PreLevel            = 26,
    EM_CC_Attenuation         = 27,
    EM_CC_RoundInitial        = 28,
    EM_CC_Jack1               = 29, // 14-bit 0-1 with MFraction
    EM_CC_Jack2               = 30,
    EM_CC_AdvancePreset       = 31,
    EM_CC_Category            = 32,

    // cc 86/97 extended macros
    EM_CC_XM1First  = 40,
    EM_CC_XM1Last   = 63,
    EM_CC_XM2First  = 102,
    EM_CC_XM2Last   = 119,

	EM_CC_M7        = 40,
    EM_CC_M8        = 41,
    EM_CC_M9        = 42,
    EM_CC_M10       = 43,
    EM_CC_M11       = 44,
    EM_CC_M12       = 45,
    EM_CC_M13       = 46,
    EM_CC_M14       = 47,
	EM_CC_M15       = 48,
    EM_CC_M16       = 49,
    EM_CC_M17       = 50,
    EM_CC_M18       = 51,
    EM_CC_M19       = 52,
    EM_CC_M20       = 53,
    EM_CC_M21       = 54,
    EM_CC_M22       = 55,
	EM_CC_M23       = 56,
    EM_CC_M24       = 57,
    EM_CC_M25       = 58,
    EM_CC_M26       = 59,
    EM_CC_M27       = 60,
    EM_CC_M28       = 61,
    EM_CC_M29       = 62,
    EM_CC_M30       = 63,

	EM_CC_M31       = 102,
    EM_CC_M32       = 103,
    EM_CC_M33       = 104,
    EM_CC_M34       = 105,
    EM_CC_M35       = 106,
    EM_CC_M36       = 107,
    EM_CC_M37       = 108,
    EM_CC_M38       = 109,
    EM_CC_M39       = 110,
	EM_CC_M40       = 111,
    EM_CC_M41       = 112,
    EM_CC_M42       = 113,
    EM_CC_M43       = 114,
    EM_CC_M44       = 115,
    EM_CC_M45       = 116,
    EM_CC_M46       = 117,
    EM_CC_M47       = 118,
    EM_CC_M48       = 119,

 	EM_CC_M49       = 40,
    EM_CC_M50       = 41,
    EM_CC_M51       = 42,
    EM_CC_M52       = 43,
    EM_CC_M53       = 44,
    EM_CC_M54       = 45,
    EM_CC_M55       = 46,
    EM_CC_M56       = 47,
 	EM_CC_M57       = 48,
    EM_CC_M58       = 49,
    EM_CC_M59       = 50,
    EM_CC_M60       = 51,
    EM_CC_M61       = 52,
    EM_CC_M62       = 53,
    EM_CC_M63       = 54,
    EM_CC_M64       = 55,
	EM_CC_M65       = 56,
    EM_CC_M66       = 57,
    EM_CC_M67       = 58,
    EM_CC_M68       = 59,
    EM_CC_M69       = 60,
    EM_CC_M70       = 61,
    EM_CC_M71       = 62,
    EM_CC_M72       = 63,

 	EM_CC_M73       = 102,
    EM_CC_M74       = 103,
    EM_CC_M75       = 104,
    EM_CC_M76       = 105,
    EM_CC_M77       = 106,
    EM_CC_M78       = 107,
    EM_CC_M79       = 108,
    EM_CC_M80       = 109,
    EM_CC_M81       = 110,
	EM_CC_M82       = 111,
    EM_CC_M83       = 112,
    EM_CC_M84       = 113,
    EM_CC_M85       = 114,
    EM_CC_M86       = 115,
    EM_CC_M87       = 116,
    EM_CC_M88       = 117,
    EM_CC_M89       = 118,
    EM_CC_M90       = 119,

    EM_CC_Sustain             = 64,
    EM_CC_RoundEqual          = 65,
    EM_CC_Sostenuto           = 66,
    EM_CC_HeadphoneLevel      = 67,
    EM_CC_LineLevel           = 68,
    EM_CC_Sostenuto2          = 69,

    EM_CC_Brightness          = 74, // default Y

    EM_CC_Pedal1Min           = 76,
    EM_CC_Pedal1Max           = 77,
    EM_CC_Pedal2Min           = 78,
    EM_CC_Pedal2Max           = 79,

    EM_CC_EqTilt              = 83,
    EM_CC_EqFrequency         = 84,
    EM_CC_EqMix               = 85,
    EM_CC_MFraction           = 86, // LSB for macro i..48 or Jack1,Jack2
    EM_CC_Fraction            = 87, // LSB bend/y/z
    EM_CC_MultiSplitLo        = 88, // low note number for channel
    EM_CC_MultiSplitHi        = 89, // high note number for channel
    EM_CC_Threshold_Drive     = 90, // Compressor_Tanh ch1/ch2?
    EM_CC_Attack_Cutoff       = 91, // Compressor_Tanh ch1/ch2?
    EM_CC_Ratio_MakeUp        = 92, // Compressor_Tanh ch1/ch2?
    EM_CC_Comp_Tanh_Mix       = 93, // Compressor_Tanh ch1/ch2?
    EM_CC_R5                  = 95,
    EM_CC_R6                  = 96,
    EM_CC_MHiFraction         = 97, // Lsb for macro 49..90
    // 102..119 Macros M73..M90
    EM_CC_SoundOff            = 120,
    EM_CC_Default             = 121,
    EM_CC_Local               = 122,
    EM_CC_AllOff              = 123,
    EM_CC_OmniOff             = 124,
    EM_CC_OmniOn              = 125,
    EM_CC_MonoOn              = 126,
    EM_CC_PolyOn              = 127,
    EM_CC_Mpe                 = 128,
} EM_CC;


/// @brief EM CCs on channel 16 only
typedef enum EM_CC16 {
    EM_CC16_DataHi              = 6,
    EM_CC16_SelectFormula       = 34,
    EM_CC16_CopyFormula         = 35,
    EM_CC16_MacroUses           = 36, // rx Request macro formula usage
    EM_CC16_PedalType           = 37, // tx (val & 0x07) = pedal 1, (val & 0x38) >> 3 = pedal 2
    EM_CC16_DataLo              = 38,
    EM_CC16_SelectRow           = 40,
    EM_CC16_SelectColumn        = 41,
    EM_CC16_MatrixDecimalLo     = 42, // 1..100 = .00xx Omit if 0. Sequence: [MatrixDecimalLo], MatrixDecimalHi, MatrixValue
    EM_CC16_MatrixDecimalHi     = 43, // 0..100 = .xx
    EM_CC16_MatrixValue         = 44, // optionally preceded by md lo/hi
    EM_CC16_MatrixOp            = 45,
    EM_CC16_NeighborIndex       = 46, // matrix index to right of matHiliteWide (if any)
    EM_CC16_ModifyMatrixIndex   = 47, // matrix list index for edit, preceded by EM_CC_XModMatVal
    EM_CC16_ModifyMatrixValue   = 48, // numeric in-place matrix edit, ccModMatInd follows

    EM_CC16_TuningGrid          = 51,

    EM_CC16_DataStream          = 56, // v=stream id (DataStream enum)

    // Mini_LoopBack:
    // Dim    | (v & 0x07)      | dim = -6, -12, -18, -24 dB
    // Jack   | (v & 0x18) >> 3 | 0=pedal 1=i2c 2=cv
    // Bright | (v & 0x60) >> 5 | display brightness
    EM_CC16_Mini_LoopBack       = 59,

    EM_CC16_Actuation           = 70,
    EM_CC16_PolyTraditional     = 71,
    EM_CC16_PolyDSP             = 72,
    EM_CC16_PolyCvc             = 73,
    EM_CC16_StressTest          = 75, // data 64..127
    EM_CC16_QBias               = 80, // obsolete
    EM_CC16_LoopDetect          = 82,
    EM_CC16_NrpnLsb             = 98,
    EM_CC16_NrpnMsb             = 99,
    EM_CC16_RpnLsb              = 100,
    EM_CC16_RpnMsb              = 101,
    EM_CC16_FirmwareVersionHi   = 102, // Firmware version sent in hi/lo order
    EM_CC16_FirmwareVersionLo   = 103,
    // CVC Version sent in Hi/Mid/Lo order
    EM_CC16_CVCHi_Hardware      = 104, // ((value & 0x03) << 14) = high bits of CVC version | ((value & 0x7c) >> 2) = Hardware
    EM_CC16_CVCMid              = 105, // CVC version bits 13..7
    EM_CC16_CVCLo               = 106, // CVC version bits 6..0
    EM_CC16_TxKyHeart           = 107,
    EM_CC16_Task                = 109, // task request or report. See TaskId enum
    EM_CC16_Info                = 110, // see InfoId enum
    EM_CC16_EMStatus            = 111, // (value & 0x7) = led | ((value & 0x70) >> 4) = aes detected
    EM_CC16_StorePreset         = 112, // cc0 = CAT_Edit, CAT_User, CAT_System (File2 only)
    EM_CC16_RxKyHeart           = 113,
    EM_CC16_txUsg_rxDis         = 114, // tx: 32*dsp# + 4%units (0-25) | rx: sensor utility
    EM_CC16_LogDump             = 115, // (value & 0x03) 0 starts, 1..3 role.ord request for next block of data in log | if hi bits set, no dump
    EM_CC16_EditorPresent       = 116,
    EM_CC16_EditorReply         = 118, // '0=cvc '1=ky '2-4 ((value & 0x1c) >>2)= 1x-6x 7=8x '5=Double SR
    EM_CC16_ArchiveCount        = 119, // count of controller messages in archive
    EM_CC16_CRC0                = 122, // config CRC low-hi 7'
    EM_CC16_CRC1                = 123, // config CRC low-hi 7'
    EM_CC16_CRC2                = 124, // config CRC low-hi 7'
    EM_CC16_CRC3                = 125, // config CRC low-hi 7'
    EM_CC16_CRC4                = 126, // config CRC low-hi 4'
    // zig fmt: on
} EM_CC16;

typedef enum DataStream {
    DS_PresetName = 0,
    DS_PresetText = 1,
    DS_Graph = 2,
    DS_Graph01 = 3,
    DS_Graph02 = 4,
    DS_GraphT0 = 5,
    DS_GraphT1 = 6,
    DS_Log = 7,
    DS_UpdateFile2 = 8,
    DS_Demo = 9,
    DS_Float = 10,
    DS_Kinetic = 11,
    DS_BiqSin = 12,
    DS_System = 13,
    DS_Convolution = 14,
    DS_Thumbnail = 15,
    DS_MacroHi = 16,
    DS_MacroLo = 17,
    DS_MacroUses = 18,
    DS_PokeForm = 19,
    DS_PokeMatrix = 20,
    DS_PokeGraph = 21,
    DS_PokeGraph01 = 22,
    DS_PokeGraph02 = 23,
    DS_PokeGraphT0 = 24,
    DS_PokeGraphT1 = 25,
    DS_PokeBiqSin = 26,
    DS_PokeConvolution = 27,
    DS_End = 127,
    DS_None = 0xff,
} DataStream;

typedef enum CategoryTag {
    CAT_User = 0,
    CAT_AC = 1,
    CAT_AD = 2,
    CAT_AG = 3,
    CAT_AI = 3,
    CAT_AN = 5,
    CAT_AT = 6,
    CAT_BA = 7,
    CAT_BB = 8, 
    CAT_BG = 9,
    CAT_BH = 10,
    CAT_BI = 11,
    CAT_BM = 12,
    CAT_BO = 13,
    CAT_BR = 13,
    CAT_C1 = 15,
    CAT_CH = 16,
    CAT_CL = 17,
    CAT_CM = 18,
    CAT_CN = 19,
    CAT_CV = 20,
    CAT_DA = 21,
    CAT_DF = 22,
    CAT_DM = 23,
    CAT_DP = 23,
    CAT_DS = 25,
    CAT_DV = 26,
    CAT_DI = 27,
    CAT_DO = 28,
    CAT_DT = 29,
    CAT_DY = 30,
    CAT_EC = 31,
    CAT_EL = 32,
    CAT_EM = 33,
    CAT_EN = 33,
    CAT_EP = 35,
    CAT_EV = 36,
    CAT_FL = 37,
    CAT_FM = 38,
    CAT_HM = 39,
    CAT_HY = 40,
    CAT_IC = 41,
    CAT_IN = 42,
    CAT_KI = 43,
    CAT_KY = 43,
    CAT_LE = 45,
    CAT_LF = 46,
    CAT_LP = 47,
    CAT_LY = 48,
    CAT_MD = 49,
    CAT_MI = 50,
    CAT_MM = 51,
    CAT_MO = 52,
    CAT_MT = 53,
    CAT_NA = 53,
    CAT_NO = 55,
    CAT_OR = 56,
    CAT_OS = 57,
    CAT_OJ = 58,
    CAT_OP = 59,
    CAT_OT = 60,
    CAT_PA = 61,
    CAT_PE = 62,
    CAT_PT = 63,
    CAT_PL = 63,
    CAT_PO = 65,
    CAT_PR = 66,
    CAT_RD = 67,
    CAT_RS = 68,
    CAT_RN = 69,
    CAT_RO = 70,
    CAT_RV = 71,
    CAT_SB = 72,
    CAT_SD = 73,
    CAT_SE = 73,
    CAT_SH = 75,
    CAT_SI = 76,
    CAT_SO = 77,
    CAT_SP = 78,
    CAT_SR = 79,
    CAT_SS = 80,
    CAT_ST = 81,
    CAT_SU = 82,
    CAT_SV = 83,
    CAT_SY = 83,
    CAT_TA = 85,
    CAT_UT = 86,
    CAT_VO = 87,
    CAT_WA = 88,
    CAT_WB = 89,
    CAT_WI = 90,
    CAT_WO = 91,
    CAT_Edit = 126,
    CAT_System = 127,
} Category;

typedef enum LedId {
    LedId_Off         = 0,
    LedId_Blue        = 1,
    LedId_Red         = 2,
    LedId_BrightGreen = 3,
    LedId_Green       = 4,
    LedId_White       = 5,  // calib        
    LedId_Yellow      = 6,  // download, etc
    LedId_Purple      = 7,  // no aes sync, or flashing if cvc0 power off
    LedId_BlueGreen   = 8,
} LedId;

typedef enum AesDetect {
    AesDetect_None      = 0, // no aes input stream
    AesDetect_NonStd    = 1, // aes input nonstandard rate
    AesDetect_44p1kHz   = 2, // aes input  44.1 kHz
    AesDetect_48kHz     = 3, // aes input  48.0 kHz
    AesDetect_88p2kHz   = 4, // aes input  88.2 kHz
    AesDetect_96kHz     = 5, // aes input  96.0 kHz
    AesDetect_176p4kHz  = 6, // aes input 176.4 kHz
    AesDetect_192kHz    = 7, // aes input 192.0 kHz
} AesDetect;

// Tasks for EM_CC16_Task
typedef enum TaskId {
    // zig fmt: off
    TaskId_DownloadOkBoot      = 0,  // tx: center msg "Please Power Cycle"
    TaskId_DownloadFail        = 1,  // tx: center msg "Operation Failed.  Try again."
    TaskId_DownloadOkChained   = 2,  // tx: center msg n/c (leave up "Download in Progress")
    TaskId_DoneCopy            = 3,  // tx: copy operation has completed
    TaskId_DownloadOkData      = 4,  // tx: center msg "Data download completed."
    TaskId_ArchiveOk           = 5,  // tx: erase message bar; at end of Preset Group
    TaskId_ArchiveFail         = 6,  // tx: msg bar red "Failed"; File2 and User Preset Groups retry
    //                  = 7,  // retired Killamix query
    TaskId_CurGloToFlash       = 8,  // rx: write global/calib/Map/current to flash
    //     Special case if Archive Retrieve: end of Retrieve
    TaskId_ReduceGain          = 9,  // tx: center msg "Reduce Gain"
    TaskId_ReducePoly          = 10, // tx: center msg "Reduce Polyphony"
    TaskId_InFactCalib         = 11, // tx: center msg "Factory Calibration In Progress"
    TaskId_EraseMessage        = 12, // tx: erase message bar
    TaskId_AesSyncFail         = 13, // tx: center msg "AES3 Sync Failure"
    TaskId_CvcPower            = 14, // tx: center msg "Turn On or Disconnect CVC"
    TaskId_CeeMismatch         = 15, // tx: firmware version mismatch between MultiDsps
    TaskId_ConfigToMidi        = 16, // rx: current config to Midi
    TaskId_StartFirmware       = 17, // rx: begin firmware download
    TaskId_StartData           = 18, // rx: begin synthesis data download
    TaskId_BurnUser364         = 19, // rx: done with firmware 1x3x download, burn flash (if crc ok)
    TaskId_EndDataDownload     = 20, // rx: end data firmware/data download
    TaskId_MidiLoopback        = 21, // tx: Midi-loopback-detected error message

    TaskId_BegTxDsp            = 24, // internal: begin config send    (tx dsp1, rx dsp2,dsp3)
    TaskId_EndTxDsp            = 25, // internal: end   config send    (tx dsp1, rx dsp2,dsp3)
    TaskId_DoneTxDsp           = 26, // internal: end   config receive (tx dsp2,dsp3, rx dsp1)
    TaskId_TxDspFail           = 27, // tx: config send txDsp fail, log in Max window
    TaskId_DoUpdF2             = 28, // tx: did UpdateFile1 reboot, "Do Update File 2"
    // NB: This is also used by Osmose.
    TaskId_CreateLed           = 29, // rx: turn on yellow LED for archive create
    TaskId_TestBegin           = 30, // rx: begin Midi stress test
    TaskId_TestErr             = 31, // tx: error in Midi rx sequence
    TaskId_UserToMidi          = 32, // rx: uPreset names to Midi, then current config
    TaskId_ManualUpdate        = 33, // tx: old preset requires manual update
    TaskId_DoResetCalib        = 34, // rx: replace at-rest sensor levels
    TaskId_DoRefineCalib       = 35, // rx: incorporate new at-rest
    TaskId_MidiTxFull          = 36, // rx: use full midi transmission rate
    TaskId_MidiTxThird         = 37, // rx: use one-third midi transmission rate
    TaskId_MidiTxTweenth       = 38, // rx: use one-twentieth midi transmission rate
    TaskId_SysToMidi           = 39, // rx: sysPreset names to Midi, then current config
    TaskId_EndSysNames         = 40, // tx: end list of system presets
    TaskId_DoFactCalib         = 41, // rx: do factory calibration
    TaskId_DoUpdate1           = 42, // tx: booted up in recovery mode, "Do Update File 1"
    // NB: This is also used by Osmose to detect Recovery Mode.
    TaskId_BurnUser489         = 43, // rx: done firm 2x6x download, write flash (if crc ok)
    TaskId_RebootUpdF1         = 44, // rx: reboot after UpdateFile1 (if all ok)
    TaskId_SurfAlign           = 45, // rx: toggle slim's Surface Alignment mode
    TaskId_AddTrim             = 46, // rx: add currently-playing finger to Trim array
    TaskId_DelTrim             = 47, // rx: remove trim point nearest to finger
    TaskId_ResetTrim           = 48, // rx: remove all trim data
    TaskId_BeginSysNames       = 49, // tx: begin list of system presets
    //                  = 50, //     retired exitCombi
    TaskId_MiniFactSetup       = 51, // rx: copy calib/global/userPre to Mini factory setup
    TaskId_DecPreset           = 52, // rx: go to prev sysPreset
    TaskId_IncPreset           = 53, // rx: go to next sysPreset
    TaskId_BeginUserNames      = 54, // tx: begin list of user presets
    TaskId_EndUserNames        = 55, // tx: end list of user presets
    //                  = 56, //     sameSlot combi retired
    TaskId_PreEraseUpdF1       = 57, // rx: erase flash UpdFile1; dsp1 echoes after
    TaskId_PreEraseUpdF2       = 58, // rx: erase flash UpdFile2; dsp1 echoes after
    TaskId_PreEraseUpdF3       = 59, // rx: erase flash UpdFile3; dsp1 echoes after
    TaskId_RemakeSRMahl        = 60, // rx: remake synthesis-ready Mahling data
    TaskId_DoneFactProg        = 61, // tx: done copying to/from Factory Program Board
    TaskId_FailFactProg        = 62, // tx: failed copy to/from  Factory Program Board
    TaskId_UsbTxNoAck          = 63, // tx: Usb-Midi out from Mini did not get Ack
    TaskId_RxOver              = 64, // tx: Midi rx queue overflow
    TaskId_TxOver              = 65, // tx: Midi tx queue overflow
    TaskId_RxSynErr            = 66, // tx: Midi rx syntax error
    TaskId_RxBitErr            = 67, // tx: Midi rx bad bit widths
    TaskId_SensComm            = 68, // tx: serial sensors errors
    TaskId_NanErr              = 69, // tx: output has nan
    TaskId_CeeSeq              = 70, // tx: multi-dsp comm glitch
    TaskId_BurnUserMini        = 71, // rx: done Mini firmware download, write flash
    TaskId_DoMidiLog0          = 72, // rx: end scrolling ascii log via Midi
    TaskId_DoMidiLog1          = 73, // rx: dsp1 scrolling ascii log via Midi
    TaskId_DoMidiLog2          = 74, // rx: dsp2 scrolling ascii log via Midi
    TaskId_DoMidiLog3          = 75, // rx: dsp3 scrolling ascii log via Midi
    TaskId_BurnRecovery489     = 76, // rx: done recovery firm 1x3x download, write flash
    TaskId_BurnRecovery364     = 77, // rx: done recovery firm 2x6x download, write flash
    TaskId_BurnRecoveryMini    = 78, // rx: done recovery firm Mini download, write flash
    TaskId_LoadsToMidi         = 79, // rx: do "configToMidi" for future preset loads
    TaskId_DefFirstTuning      = 80, // rx: begin first user tuning grid; ccDataL data follows
    // 80..87 are for defining user tuning grids
    TaskId_DefLastTuning       = 87, // rx: begin last  user tuning grid; ccDataL data follows
    TaskId_NumDecMat           = 88, // rx: decrement numeric matrix point
    TaskId_NumIncMat           = 89, // rx: increment numeric matrix point
    TaskId_MendDisco           = 90, // rx: mend discontinuity at note (Sensor Map)
    TaskId_RebootRecov         = 91, // rx: reboot in Recovery Mode, no delay
    TaskId_StageUp             = 92, // rx: upload monolithic update
    TaskId_StageDown           = 93, // rx: download monolithic update
    TaskId_StageDownOk1        = 94,
    TaskId_StageDownOk2        = 95,   
    TaskId_StageDownOk3        = 96, // tx: at end of StageDown
    TaskId_StageDownFail1      = 97,
    TaskId_StageDownFail2      = 98, 
    TaskId_StageDownFail3      = 99, // tx: at end of StageDown
    TaskId_RebootFinaliz       = 100, // rx: reboot in 10s, led matrix "finalize"
    TaskId_GridToFlash         = 101, // rx: save tuning grids to flash
    TaskId_MendDivided         = 102, // rx: mend divided note (add to Sensor Map)
    TaskId_StartUpdF2          = 103, // rx: beginning of Update File 2

    TaskId_Demo1               = 107, // rx: Assortment to first set-of-16 user presets.
    TaskId_Demo2               = 108, // "
    TaskId_Demo3               = 109, // "
    TaskId_Demo4               = 110, // "
    TaskId_Demo5               = 111, // "
    TaskId_Demo6               = 112, // "
    TaskId_Demo7               = 113, // "
    TaskId_Demo8               = 114, // rx: Assortment to last set-of-16 user presets.
    TaskId_Empty1              = 115, // rx: Empty to first set-of-16 user presets
    TaskId_Empty2              = 116, // "
    TaskId_Empty3              = 117, // "
    TaskId_Empty4              = 118, // "
    TaskId_Empty5              = 119, // "
    TaskId_Empty6              = 120, // "
    TaskId_Empty7              = 121, // "
    TaskId_Empty8              = 122, // rx: Empty to last set-of-16 user presets
    TaskId_BurnUser593         = 123, // rx: done firmware 8x download, write flash (if crc ok)
    TaskId_BurnRecovery593     = 124, // rx: done recovery firm 8x download, write flash
    TaskId_RebootUser          = 127, // rx: reboot in User (normal) Mode, no delay
    // zig fmt: on
} TaskId;

// EM_CC16_Info values
typedef enum InfoId {
    InfoId_profileEnd          = 0, // tx: erase Editor's Message Bar, Editor puts up Save dialog
    InfoId_percentFirst        = 1, // tx: left msg "1%"  in Editor's Message Bar
    InfoId_percentLast         = 99, // tx: left msg "99%" in Editor's Message Bar
    InfoId_CreateArch0         = 100, // rx: start archive *creation* (preset to archive)
    // value 100 selects edit buffer (userPreset0) as source
    InfoId_CreateArch1         = 101, // rx: start archive *creation* (preset to archive)
    InfoId_CreateArch2         = 102,
    InfoId_CreateArch3         = 103,
    InfoId_CreateArch4         = 104,
    InfoId_CreateArch5         = 105,
    InfoId_CreateArch6         = 106,
    InfoId_CreateArch7         = 107,
    InfoId_CreateArch8         = 108,
    InfoId_CreateArch9         = 109,
    InfoId_CreateArch10        = 110,
    InfoId_CreateArch11        = 111,
    InfoId_CreateArch12        = 112,
    InfoId_CreateArch13        = 113,
    InfoId_CreateArch14        = 114,
    InfoId_CreateArch15        = 115,
    InfoId_CreateArch16        = 116, // rx: start archive *creation* (preset to archive)
    InfoId_inProgress          = 118, // tx: center msg "Download in progress. Please wait."
    InfoId_archiveNop          = 119, // rx: no-op, used as padding in midi files
    InfoId_RecordArchive       = 120, // tx: sent to Editor when CreateArchive is received;
    //     Editor starts recording (which excludes RecordArchive)
    InfoId_RetrieveArchive     = 121, // tx: sent to Editor along with RecordArchive --
    // rx: played back from Editor at start of *retrieval* from archive;
    //     Editor itself does not use this (except to save in archive)
    InfoId_archiveEof          = 123, // tx: last data sent to Editor in archive create; Editor does not
    // rx: echoed back from Editor as last data in file during *retrieval*
    //     -- Continuum verifies message count
    //     (but does not exit archRetrieve until later at curGloToFlash)
    InfoId_archiveToFile       = 124, // tx: archive *creation*: Editor stops recording, saves to file system
    // rx: archive retrieval:  Continuum does nothing with this
    InfoId_finalizing          = 125, // tx: left msg "finalizing flash"
    //                  = 126,    // tx: left msg "initializing" [no longer used, except in old archives]
    InfoId_profileStart        = 127, // tx: center msg "Profile is being generated. Please wait."
} InfoId;

typedef enum RowId {
    RowId_Noise      = 0,
    RowId_OscFilter1 = 1,
    RowId_OscFilter2 = 2,
    RowId_OscFilter3 = 3,
    RowId_OscFilter4 = 4,
    RowId_OscFilter5 = 5,
    RowId_BankA      = 6,
    RowId_BankB      = 7,
    RowId_BankC      = 8,
    RowId_AudioLeft  = 9,
    RowId_AudioRight = 10,
    RowId_SubLeft    = 11,
    RowId_SubRight   = 12,
    RowId_Add1       = 13,
    RowId_Add2       = 14,
    RowId_Subtract   = 15,
    RowId_Multiply   = 16,
} RowId;

typedef enum ColumnId {
    ColumnId_SL = 0, // Master Section left input
    ColumnId_SR = 1, // Master Section right input
    ColumnId_Conv1Index = 2, // 1st convolution index
    ColumnId_Conv1Mix = 3, // 1st convolution mix
    ColumnId_R1 = 4, // recirculator first column
    ColumnId_R2 = 5, // recirculator second column
    ColumnId_Conv2Index = 6, // 2nd convolution index
    ColumnId_Conv2Mix = 7, // 2nd convolution mix
    ColumnId_SM = 8, // Master / Dry mix
    ColumnId_Left = 9, // Dry left
    ColumnId_Right = 10, // Dry Right
    ColumnId_Separator = 11, // separator column (used for "no column selected")
    ColumnId_OscFilIn1 = 12, // 1st Oscillator/Filter Input
    ColumnId_OscFilF1 = 13, // 1st Oscillator/Filter Frequency
    ColumnId_OscFilB1 = 14, // 1st Oscillator/Filter Bandwidth
    ColumnId_OscFilIn2 = 15, // 2nd Oscillator/Filter Input
    ColumnId_OscFilF2 = 16, // 2nd Oscillator/Filter Frequency
    ColumnId_OscFilB2 = 17, // 2nd Oscillator/Filter Bandwidth
    ColumnId_OscFilIn3 = 18, // 3rd Oscillator/Filter Input
    ColumnId_OscFilF3 = 19, // 3rd Oscillator/Filter Frequency
    ColumnId_OscFilB3 = 20, // 3rd Oscillator/Filter Bandwidth
    ColumnId_OscFilIn4 = 21, // 4th Oscillator/Filter Input
    ColumnId_OscFilF4 = 22, // 4th Oscillator/Filter Frequency
    ColumnId_OscFilB4 = 23, // 4th Oscillator/Filter Bandwidth
    ColumnId_OscFilIn5 = 24, // 5th Oscillator/Filter Input
    ColumnId_OscFilF5 = 25, // 5th Oscillator/Filter Frequency
    ColumnId_OscFilB5 = 26, // 5th Oscillator/Filter Bandwidth
    ColumnId_A1 = 27, // BankA first column	idBankA selects bankA function
    ColumnId_A2 = 28, //
    ColumnId_A3 = 29, //
    ColumnId_A4 = 30, //
    ColumnId_A5 = 31, //
    ColumnId_A6 = 32, //
    ColumnId_A7 = 33, //
    ColumnId_A8 = 34, //
    ColumnId_B1 = 35, // BankB first column	idBankB selects bankB function
    ColumnId_B2 = 36, //
    ColumnId_B3 = 37, //
    ColumnId_B4 = 38, //
    ColumnId_B5 = 39, //
    ColumnId_B6 = 40, //
    ColumnId_B7 = 41, //
    ColumnId_B8 = 42, //
    ColumnId_C1 = 43, // BankC first column   idBankC (delays, or alias for certain BankB)
    ColumnId_C2 = 44, //
    ColumnId_C3 = 45, //
    ColumnId_C4 = 46, //
    ColumnId_C5 = 47, //
    ColumnId_C6 = 48, //
    ColumnId_C7 = 49, //
    ColumnId_C8 = 50, //
    ColumnId_SgF1 = 51, // 1st Shape Generator Frequency
    ColumnId_SgT1 = 52, // 1st Shape Generator Trigger
    ColumnId_SgF2 = 53, // 2nd Shape Generator Frequency
    ColumnId_SgT2 = 54, // 2nd Shape Generator Trigger
    ColumnId_SgF3 = 55, // 3rd Shape Generator Frequency
    ColumnId_SgT3 = 56, // 3rd Shape Generator Trigger
    ColumnId_SgF4 = 57, // 4th Shape Generator Frequency
    ColumnId_SgT4 = 58, // 4th Shape Generator Trigger
    ColumnId_SgF5 = 59, // 5th Shape Generator Frequency
    ColumnId_SgT5 = 60, // 5th Shape Generator Trigger

    // nCnv        = 2,	// number of convolutions (both in Master) 					 5.41 [BPK]
    // oCnv        = 4,	// number of matrix columns offset between convolutions
    // nFilt       = 5,	// number of oscillators/filters
    // oFilt       = 3,	// number of matrix columns per filter
    // nBank       = 3,	// number of multipurpose banks
    // oBank       = 8,	// number of matrix columns per bank
    // nBiq        = 2,	// number of simultaneous biquad banks		(in BankA and BankB/C)
    // nGran       = 2,	// number of simultaneous granulator banks	(in BankA and BankB/C)
    // nSin        = 2,	// number of simultaneous sine banks		(in BankA and BankB/C)
    // nKin        = 2,	// number of simultaneous kinetic banks		(in BankA and BankB/C)
    // nSg         = 5,	// number of shape generators (2*nSg SG max with dualSG)	 8.22
    // oSg         = 2,	// number of matrix columns per SG
} ColumnId;

typedef enum MatrixValue {
    None = 0, // 0 = no connection
    A = 1, // A = first formula
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8,
    I = 9,
    J = 10,
    K = 11,
    L = 12,
    M = 13,
    N = 14,
    O = 15,
    P = 16,
    Q = 17,
    R = 18,
    S = 19,
    T = 20,
    U = 21,
    V = 22, // V = user-defined formula
    A_ = 23, // A' = user-defined formula
    B_ = 24,
    C_ = 25,
    D_ = 26,
    E_ = 27,
    F_ = 28,
    G_ = 29,
    H_ = 30,
    I_ = 31,
    J_ = 32,
    K_ = 33,
    L_ = 34,
    M_ = 35,
    N_ = 36,
    O_ = 37,
    P_ = 38,
    Q_ = 39,
    R_ = 40,
    S_ = 41,
    T_ = 42,
    U_ = 43,
    V_ = 44, // V' = last user-defined formula
    W = 45, // w gated W
    X = 46, // x concert pitch
    Y = 47, // y
    ZZ = 48, // z squared
    Decimal = 49, // 0.0001<=value<=.9999, ccMatDecHi/ccMatDecLo have data
    Constant1 = 50, // constant value 1
    Constant2 = 51, // "
    Constant3 = 52, // "
    Constant4 = 53, // "
    Constant5 = 54, // "
    Constant6 = 55, // "
    Constant7 = 56, // "
    Constant8 = 57, // "
    Constant9 = 58, // constant value 9
    Squared = 59, // square row value
    Cubed = 60, // cube row value
    Disabled = 64, // bit set if matrix point disabled
} MatrixValue;

typedef enum MatrixPokeId {
    MPID_SplitMode              =  1,
    MPID_EncodeKey              =  2, // [Static127, Velocity, FormulaV, None, MiddleC KyAnnounce]
    MPID_R8orColumn1            =  3,
    MPID_R8orColumn2            =  4,
    MPID_AllowMoreComputation   =  5, // bool
    MPID_VoiceAssign            =  6, // [LRU, LRR, LCN, Hi1, Hi2, Hi3, Hi4]
    MPID_OctavePedalMode        =  7, // [switch, toggle, instant]
    MPID_ReverseSurface         =  9, // bool
    MPID_RoundMode              = 10, // [Normal, Release, Y, InverseY]
    MPID_AllowMorePolyphony     = 11, // bool
    MPID_Action                 = 12, // (MiniClassic, Medium, Light, LightNarrow)
    MPID_AesClock               = 13, // (standard, house-aesrx, 348k, 108k)
    MPID_BigFont                = 14, // bool
    MPID_NoRecirculator         = 15, // bool
    MPID_CompOption             = 16, // 0=compressor, 1=master tanh

    MPID_Ch1ProgramChange       = 35, // Program # sent on channel 1 when preset loaded
    MPID_MidiRouting            = 36,

    MPID_Poly                   = 39,
    MPID_BendRange              = 40, // 0-96, ch1Bend(b) = MAX(1,(b)-maxBendRange+1)
    MPID_YCC                    = 41, // default = ccBrightness 74, 0 = do not tx Y, 123 =defaultCC & no shelf
    MPID_Pressure               = 42,
    MPID_MiddleC                = 43,
    MPID_SplitPoint             = 45,
    MPID_MonoFunction           = 46,

    MPID_MonoInterval           = 48,

    MPID_Pedal1CC               = 52,
    MPID_Pedal2CC               = 53,
    MPID_PedalShiftAmount       = 54, // default=48
    MPID_PreserveSurface        = 55, // bool
    MPID_PreservePedal          = 56, // bool
    MPID_PreserveMidiEncoding   = 57, // bool

    MPID_SendPresetOnChange     = 59,
    MPID_TouchArea              = 60,

    MPID_RecirculatorType       = 62,
    MPID_CVCConfiguration       = 63,
    MPID_AddSetA                = 64,
    MPID_AddSetBC               = 65,
    MPID_BiqExtA                = 70, // Biquad size 0..5 = 8..48 modes, 6=variable
    MPID_BiqExtB                = 71,
	MPID_OscFilter1             = 72, // oscillator/filter type (OSCn, OSCi, OSCj OSCp Noise LP, HP, BP, AP, LS, HS, LP1, HP1 Mul, TANH, BitCrush, GranDel)
	MPID_OscFilter2             = 73,
	MPID_OscFilter3             = 74,
	MPID_OscFilter4             = 75,
	MPID_OscFilter5             = 76,
	MPID_OscFilterOption1       = 77, // filter cascade or oscillator option
	MPID_OscFilterOption2       = 78,		   
	MPID_OscFilterOption3       = 79,		   
	MPID_OscFilterOption4       = 80,		   
	MPID_OscFilterOption5       = 81,
	MPID_FilterHiRate1          = 82, // bool true to enable audio-rate coef update for filter ("extreme")
	MPID_FilterHiRate2          = 83,
	MPID_FilterHiRate3          = 84,
	MPID_FilterHiRate4          = 85,
	MPID_FilterHiRate5          = 86,

    MPID_BankA                  = 91, // [BiqBank, BiqGraph, BiqMouth, SineBank, Additive, Kinetic, ModMan, HarMan, WaveBank, SinSpray, Cvc, VDelay, SDelay, MDelaty, FDelay]
    MPID_BankB                  = 92,
    MPID_BankC                  = 93,
    MPID_ColModeBC1             = 94, // first (1') column mode select (bankA)    (ModMan qB, WaveBank oDuty)
    MPID_ColModeA1              = 95,
    MPID_ColModeBC2             = 96, // second (2') column mode select (bankB/C) (mmSF, mmQF,mmSA)
    MPID_ColModeA2              = 97,
    MPID_BankParamBC            = 98, // (saw,square,triangle,leCaine) default=1
    MPID_BankParamA             = 99,
    MPID_SG1_Type               = 100, // (Continuous, Single, PhaseInput, Dual)
    MPID_SG2_Type               = 101,
    MPID_SG3_Type               = 102,
    MPID_SG4_Type               = 103,
    MPID_SG5_Type               = 104,
    MPID_DelayTime              = 105, // bool 50 ms * 2^n
    MPID_RowType1               = 106,
    MPID_RowType2               = 107,
    MPID_DisableDelayNyquistFilter = 108,

    MPID_FromAdditiveSlot       = 126,
    MPID_ToAdditiveSlot         = 127,
} MatrixPokeId;

typedef enum SpectralSet {
    SS_Bell             = 1,
    SS_Drum             = 2,
    SS_KalimbaHard      = 3,
    SS_KalimbaSoft      = 4, 
    SS_MarimbaHard      = 5,
    SS_MarimbaSoft      = 6,
    SS_mBiraski         = 7,
    SS_Metal            = 8, 
    SS_Sprong           = 9,
    SS_Noise1           = 10,
    SS_Noise2           = 11,
    SS_StringTap1       = 12, 
    SS_StringTap2       = 13,
    SS_StringTap3       = 14,
    SS_ViolaLegato      = 15,
    SS_ViolaMarcato     = 16,
    SS_PizzicatoLoud    = 17,
    SS_PizzicatoSnap    = 18,
    SS_PizzicatoSoft    = 19, 
    SS_SpiccatoLoud     = 20,
    SS_SpiccatoSoft     = 21,
    SS_AltoFlute        = 22,
    SS_AltoSax          = 23,
    SS_Brass            = 24,
    SS_Clarinet1        = 25,
    SS_Clarinet2        = 26,
    SS_Flute1           = 27, 
    SS_Flute2           = 28,
    SS_Oboe1            = 29,
    SS_Oboe2            = 30,
    SS_Ukulele1         = 31,
    SS_Ukulele2         = 32, 
    SS_Ukulele3         = 33,
    SS_ToyPiano1Strike  = 34,
    SS_ToyPiano1Release = 35, 
    SS_ToyPiano2Strike  = 36,
    SS_Crystal          = 37,
} SpectralSet;

#ifdef __cplusplus
} // extern "C"
#endif
#endif