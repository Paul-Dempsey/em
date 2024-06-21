// Copyright (C) Paul Chase Dempsey
#include "em-matrix.hpp"

int EaganMatrix::onTask(TaskId task_id)
{
    switch (task_id) {
    case TaskId_DownloadOkBoot: break;
    case TaskId_DownloadFail: break;
    case TaskId_DownloadOkChained: break;
    case TaskId_DoneCopy: break;
    case TaskId_DownloadOkData: break;
    case TaskId_ArchiveOk: break;
    case TaskId_ArchiveFail: break;
    case TaskId_CurGloToFlash: break;
    case TaskId_ReduceGain: break;
    case TaskId_ReducePoly: break;
    case TaskId_InFactCalib: break;
    case TaskId_EraseMessage: break;
    case TaskId_AesSyncFail: break;
    case TaskId_CvcPower: break;
    case TaskId_CeeMismatch: break;
    case TaskId_ConfigToMidi: break;
    case TaskId_StartFirmware: break;
    case TaskId_StartData: break;
    case TaskId_BurnUser364: break;
    case TaskId_EndDataDownload: break;
    case TaskId_MidiLoopback: break;

    case TaskId_BegTxDsp: break;
    case TaskId_EndTxDsp: break;
    case TaskId_DoneTxDsp: break;
    case TaskId_TxDspFail: break;

    case TaskId_DoUpdF2: break;
    case TaskId_CreateLed:
        // turn on yellow led for archive creation
        break;
    case TaskId_TestBegin: break;
    case TaskId_TestErr: break;

    case TaskId_UserToMidi: // request user preset names
        break;
    case TaskId_ManualUpdate: break;

    // calibration
    case TaskId_DoResetCalib: break;
    case TaskId_DoRefineCalib: break;

    // Midi transmission rate
    case TaskId_MidiTxFull: break;
    case TaskId_MidiTxThird: break;
    case TaskId_MidiTxTweenth: break;

    case TaskId_SysToMidi: 
        // request system preset names
        break;
    case TaskId_EndSysNames:
        // end of system preset list
        break;
    case TaskId_DoFactCalib: break;
    case TaskId_DoUpdate1: break;
    case TaskId_BurnUser489: break;
    case TaskId_RebootUpdF1: break;
    case TaskId_SurfAlign: break;
    case TaskId_AddTrim: break;
    case TaskId_DelTrim: break;
    case TaskId_ResetTrim: break;
    case TaskId_BeginSysNames: break;
    case TaskId_MiniFactSetup: break;
    case TaskId_DecPreset: break;
    case TaskId_IncPreset: break;
    case TaskId_BeginUserNames: break;
    case TaskId_EndUserNames: break;
    case TaskId_PreEraseUpdF1: break;
    case TaskId_PreEraseUpdF2: break;
    case TaskId_PreEraseUpdF3: break;
    case TaskId_RemakeSRMahl: break;
    case TaskId_DoneFactProg: break;
    case TaskId_FailFactProg: break;
    case TaskId_UsbTxNoAck: break;
    case TaskId_RxOver: break;
    case TaskId_TxOver: break;
    case TaskId_RxSynErr: break;
    case TaskId_RxBitErr: break;
    case TaskId_SensComm: break;
    case TaskId_NanErr: break;
    case TaskId_CeeSeq: break;
    case TaskId_BurnUserMini: break;
    case TaskId_DoMidiLog0: break;
    case TaskId_DoMidiLog1: break;
    case TaskId_DoMidiLog2: break;
    case TaskId_DoMidiLog3: break;
    case TaskId_BurnRecovery489: break;
    case TaskId_BurnRecovery364: break;
    case TaskId_BurnRecoveryMini: break;
    case TaskId_LoadsToMidi: break;
    case TaskId_DefFirstTuning: break;
    case TaskId_DefLastTuning: break;
    case TaskId_NumDecMat: break;
    case TaskId_NumIncMat: break;
    case TaskId_MendDisco: break;
    case TaskId_RebootRecov: break;
    case TaskId_StageUp: break;
    case TaskId_StageDown: break;
    case TaskId_StageDownOk1: break;
    case TaskId_StageDownOk2: break;
    case TaskId_StageDownOk3: break;
    case TaskId_StageDownFail1: break;
    case TaskId_StageDownFail2: break;
    case TaskId_StageDownFail3: break;
    case TaskId_RebootFinaliz: break;
    case TaskId_GridToFlash: break;
    case TaskId_MendDivided: break;
    case TaskId_StartUpdF2: break;
    case TaskId_Demo1: break;
    case TaskId_Demo2: break;
    case TaskId_Demo3: break;
    case TaskId_Demo4: break;
    case TaskId_Demo5: break;
    case TaskId_Demo6: break;
    case TaskId_Demo7: break;
    case TaskId_Demo8: break;
    case TaskId_Empty1: break;
    case TaskId_Empty2: break;
    case TaskId_Empty3: break;
    case TaskId_Empty4: break;
    case TaskId_Empty5: break;
    case TaskId_Empty6: break;
    case TaskId_Empty7: break;
    case TaskId_Empty8: break;
    case TaskId_BurnUser593: break;
    case TaskId_BurnRecovery593: break;
    case TaskId_RebootUser: break;
    }

    return 0;
}

int EaganMatrix::onInfo(InfoId info_id)
{
    if (InfoId_percentFirst <= info_id && info_id <= InfoId_percentLast) {
        // handle progress
    }
    else if (InfoId_CreateArch0 <= info_id && info_id <= InfoId_CreateArch16) {
        // InfoId_CreateArch0 == EditBuffer
        int archive_number = (int)info_id - (int)InfoId_CreateArch0;
        // begin archive creation
    }
    else {
        switch (info_id) {
        case InfoId_profileEnd:
            // end of profile
            break;
        case InfoId_inProgress: break;
        case InfoId_archiveNop: break;
        case InfoId_RecordArchive: 
            // start recording archive, not stored in archive
            break;
        case InfoId_RetrieveArchive:
            // start retrieving archive: stored in archive
            break;
        case InfoId_archiveEof: 
            break;
        case InfoId_archiveToFile: 
            // stop recording, save to file
            break;
        case InfoId_finalizing: break;
        case InfoId_profileStart: 
            // start of profile
            break;
        }
    }
    return 0;
}

void EaganMatrix::PokeMatrix(uint8_t id, uint8_t value)
{
    switch (id) {
    case MPID_RoundMode: round_mode = value;

    case MPID_BendRange: bend_range = value; break;
    case MPID_MiddleC: middle_c = value; break;
    case MPID_Pedal1CC: pedal1_cc = value; break;
    case MPID_Pedal2CC: pedal2_cc = value; break;
    case MPID_PedalShiftAmount: pedal_shift = value; break;

    case MPID_PreserveSurface: preserve_surface = value != 0; break;
    case MPID_PreservePedal: preserve_pedal =  value != 0; break;
    case MPID_PreserveMidiEncoding: preserve_midi_encoding = value != 0; break;

    case MPID_RecirculatorType: recirculator_kind = value; break;

    default:
        break;
    }
}

int EaganMatrix::Ch01CC(uint8_t cc, uint8_t value)
{
    midi_state.ch01cc[cc] = value;

    switch (cc) {
    case EM_CC_BankSelect: this->bank_hi = value; break;
    //EM_CC_ModDepth
    //EM_CC_Breath
    //EM_CC_Undefined3
    //EM_CC_Foot
    //EM_CC_Volume
    //EM_CC_OctaveShift
    //EM_CC_MonoSwitch
    //EM_CC_FineTune
    //EM_CC_Expression

    case EM_CC_M1: case EM_CC_M2: case EM_CC_M3: case EM_CC_M4:
    case EM_CC_M5: case EM_CC_M6: case EM_CC_M7: case EM_CC_M8: case EM_CC_M9: 
    case EM_CC_M10: case EM_CC_M11:case EM_CC_M12:case EM_CC_M13: case EM_CC_M14:
    case EM_CC_M15: case EM_CC_M16: case EM_CC_M17:case EM_CC_M18: case EM_CC_M19:
    case EM_CC_M20: case EM_CC_M21: case EM_CC_M22: case EM_CC_M23: case EM_CC_M24:
    case EM_CC_M25: case EM_CC_M26: case EM_CC_M27: case EM_CC_M28: case EM_CC_M29:
    case EM_CC_M30: case EM_CC_M31: case EM_CC_M32: case EM_CC_M33: case EM_CC_M34:
    case EM_CC_M35: case EM_CC_M36: case EM_CC_M37: case EM_CC_M38: case EM_CC_M39:
    case EM_CC_M40: case EM_CC_M41: case EM_CC_M42: case EM_CC_M43: case EM_CC_M44:
    case EM_CC_M45: case EM_CC_M46: case EM_CC_M47: case EM_CC_M48: {
        uint8_t macro_index = MacroNumber(cc, this->midi_state.hi_macro) - 1;
        macro[macro_index] = this->midi_state.get14bit(value);
    } break;

    case EM_CC_PostLevel: this->post_level = value; break;
    case EM_CC_AudioInputLevel: this->audio_level = value; break;
    case EM_CC_R1: this->recirculator_dials[R8orValue_R1] = value; break;
    case EM_CC_R2: this->recirculator_dials[R8orValue_R2] = value; break;
    case EM_CC_R3: this->recirculator_dials[R8orValue_R3] = value; break;
    case EM_CC_R4: this->recirculator_dials[R8orValue_R4] = value; break;
    case EM_CC_RMix: this->recirculator_dials[R8orValue_RMix] = value; break;
    case EM_CC_RoundRate: this->round_rate = value; break;
    case EM_CC_PreLevel: this->pre_level = value; break;
    case EM_CC_Attenuation: this->attenuation = value; break;
    case EM_CC_RoundInitial: this->round_initial = value; break;
    case EM_CC_Jack1: this->jack1 = this->midi_state.get14bit(value); break;
    case EM_CC_Jack2: this->jack2 = this->midi_state.get14bit(value); break;
    case EM_CC_Category: this->bank_lo = value; break;

    case EM_CC_Sustain: this->sustain = value; break;
    case EM_CC_RoundEqual: this->round_equal = value; break;
    case EM_CC_Sostenuto: this->sostenuto1 = value; break;
    case EM_CC_HeadphoneLevel: this->headphone_level = value; break;
    case EM_CC_LineLevel: this->line_level = value; break;
    case EM_CC_Sostenuto2: this->sostenuto2 = value; break;
    case EM_CC_Pedal1Min: this->pedal1_min = value; break;
    case EM_CC_Pedal1Max: this->pedal1_max = value; break;
    case EM_CC_Pedal2Min: this->pedal2_min = value; break;
    case EM_CC_Pedal2Max: this->pedal2_max = value; break;
    case EM_CC_EqTilt:          this->eq_tilt = value; break;
    case EM_CC_EqFrequency:     this->eq_frequency = value; break;
    case EM_CC_EqMix:           this->eq_mix = value; break;
    case EM_CC_MFraction:
    case EM_CC_Fraction:
        this->midi_state.set_lo_fraction(value);
        break;
    case EM_CC_MultiSplitLo:    this->multi_split_lo = value; break;
    case EM_CC_MultiSplitHi:    this->multi_split_hi = value; break;
    case EM_CC_Threshold_Drive: this->threshold_drive = value; break;
    case EM_CC_Attack_Cutoff:   this->attack_cutoff = value; break;
    case EM_CC_Ratio_MakeUp:    this->ratio_makeup = value; break;
    case EM_CC_Comp_Tanh_Mix:   this->comp_tanh_mix = value; break;
    case EM_CC_R5: this->recirculator_dials[R8orValue_R5] = value; break;
    case EM_CC_R6: this->recirculator_dials[R8orValue_R6] = value; break;
    case EM_CC_MHiFraction:
        this->midi_state.set_hi_fraction(value);
        break;
    }

    // TODO: do these change any state that we need to capture?
    // EM_CC_SoundOff
    // EM_CC_Default
    // EM_CC_Local
    // EM_CC_AllOff
    // EM_CC_OmniOff
    // EM_CC_OmniOn
    // EM_CC_MonoOn
    // EM_CC_PolyOn
    // EM_CC_Mpe

    return 0;
}

void EaganMatrix::EndDataStream() {
    switch (this->midi_state.data_stream) {
    case DS_PresetName: {
        this->preset_name[this->midi_state.stream_pos] = 0;
    } break;
    case DS_PresetText: {
        this->preset_text[this->midi_state.stream_pos] = 0;
    } break;
    case DS_Graph: {
    } break;
    case DS_Graph01: {
    } break;
    case DS_Graph02: {
    } break;
    case DS_GraphT0: {
    } break;
    case DS_GraphT1: {
    } break;
    case DS_Log: {
    } break;
    case DS_UpdateFile2: {
    } break;
    case DS_Demo: {
    } break;
    case DS_Float: {
    } break;
    case DS_Kinetic: {
    } break;
    case DS_BiqSin: {
    } break;
    case DS_System: {
    } break;
    case DS_Convolution: {
    } break;
    case DS_Thumbnail: {
    } break;
    case DS_MacroHi: {
    } break;
    case DS_MacroLo: {
    } break;
    case DS_MacroUses: {
    } break;
    case DS_PokeForm: {
    } break;
    case DS_PokeMatrix: {
    } break;
    case DS_PokeGraph: {
    } break;
    case DS_PokeGraph01: {
    } break;
    case DS_PokeGraph02: {
    } break;
    case DS_PokeGraphT0: {
    } break;
    case DS_PokeGraphT1: {
    } break;
    case DS_PokeBiqSin: {
    } break;
    case DS_PokeConvolution: {
    } break;
    case DS_End:
    case DS_None: break;
    }
    this->midi_state.stream_pos = 0;
    this->midi_state.data_stream = DS_None;
}

int EaganMatrix::Ch16CC(uint8_t cc, uint8_t value)
{
    this->midi_state.ch16cc[cc] = value;

    switch (cc) {
    //EM_CC16_DataHi
    //EM_CC16_SelectFormula
    //EM_CC16_CopyFormula
    //case EM_CC16_MacroUses: return 0; // request macro usage

    case EM_CC16_PedalType: {
        uint8_t kind = value & 0x07;
        this->pedal1_kind = kind;
        kind = (value & 0x38) >> 3;
        this->pedal2_kind = kind;
    } break;

    //EM_CC16_DataLo
    //EM_CC16_SelectRow
    //EM_CC16_SelectColumn
    //EM_CC16_MatrixDecimalLo
    //EM_CC16_MatrixDecimalHi
    //EM_CC16_MatrixValue
    //EM_CC16_MatrixOp
    //EM_CC16_NeighborIndex
    //EM_CC16_ModifyMatrixIndex
    //EM_CC16_ModifyMatrixValue

    case EM_CC16_TuningGrid: this->tuning_grid = value; break;

    case EM_CC16_DataStream: {
        switch (value) {
        case DS_PresetName: {
            midi_state.stream_pos = 0;
            zero_bytes(this->preset_name, sizeof(this->preset_name));
        } break;
        case DS_PresetText: {
            this->midi_state.stream_pos = 0;
            zero_bytes(this->preset_text, sizeof(this->preset_text));
        } break;

        case DS_End: EndDataStream(); return 0;
        default: break;
        }
        this->midi_state.data_stream = value;
    } break;

    //EM_CC16_Mini_LoopBack
    case EM_CC16_Actuation: this->actuation = value; break;
    case EM_CC16_PolyTraditional: this->poly_trad = value; break;
    case EM_CC16_PolyDSP: this->poly_dsp = value; break;
    case EM_CC16_PolyCvc: this->poly_cvc = value; break;
    //EM_CC16_StressTest
    //EM_CC16_QBias (obsolete)
    case EM_CC16_LoopDetect: return 0;
    // EM_CC16_NrpnLsb
    // EM_CC16_NrpnMsb
    // EM_CC16_RpnLsb
    // EM_CC16_RpnMsb
    // Firmware version always sent in hi, lo order
    case EM_CC16_FirmwareVersionHi: firmware_version = value << 7; break;
    case EM_CC16_FirmwareVersionLo: firmware_version |= value; break;

    // CVC version always sent in hi, mid, lo order
    case EM_CC16_CVCHi_Hardware: {
        this->hardware = ((value & 0x7c) >> 2);
        this->cvc_version = ((value & 0x03) << 14);
    } break;
    case EM_CC16_CVCMid: this->cvc_version |= value << 7; break;
    case EM_CC16_CVCLo: this->cvc_version |= value; break;

    //EM_CC16_TxKyHeart
    EM_CC16_Task: return onTask((TaskId)value);
    EM_CC16_Info: return onInfo((InfoId)value);
    //EM_CC16_EMStatus
    //EM_CC16_StorePreset
    //EM_CC16_RxKyHeart
    //EM_CC16_txUsg_rxDis
    //EM_CC16_LogDump
    //EM_CC16_EditorPresent
    //EM_CC16_EditorReply
    //EM_CC16_ArchiveCount
    //EM_CC16_CRC0
    //EM_CC16_CRC1
    //EM_CC16_CRC2
    //EM_CC16_CRC3
    //EM_CC16_CRC4

    default:
        break;
    }
    return 0;
}

int EaganMatrix::receiveMidi(PackedMidiMessage msg)
{
    uint8_t status = midi_status(msg);
    uint8_t channel = midi_channel(msg);
    switch (channel) {
    case 0: {
        switch (status) {
        case MidiStatus_NoteOff:
        case MidiStatus_NoteOn:
        case MidiStatus_PolyKeyPressure:
            break;
        case MidiStatus_CC:
            return Ch01CC(msg.bytes.data1, msg.bytes.data2);
        case MidiStatus_ProgramChange:
            this->preset_number = msg.bytes.data1;
            break;
        case MidiStatus_ChannelPressure:
        case MidiStatus_PitchBend:
        case MidiStatus_SysEx:
        default: break;
        }
    } break;
    case 15: {
        switch (status) {
        case MidiStatus_NoteOff:
        case MidiStatus_NoteOn:
            break;

        case MidiStatus_PolyKeyPressure: // post 10.09 data stream value
            switch (this->midi_state.data_stream) {
            case DS_PresetName:
                if (this->midi_state.stream_pos < 30) {
                    this->preset_name[this->midi_state.stream_pos++] = msg.bytes.data1;
                    this->preset_name[this->midi_state.stream_pos++] = msg.bytes.data2;
                }
            case DS_PresetText:
                if (this->midi_state.stream_pos < 254) {
                    this->preset_text[this->midi_state.stream_pos++] = msg.bytes.data1;
                    this->preset_name[this->midi_state.stream_pos++] = msg.bytes.data2;
                }
            }
            break;

        case MidiStatus::MidiStatus_CC:
            return Ch16CC(msg.bytes.data1, msg.bytes.data2);

        case MidiStatus_ProgramChange:
            this->preset_number = msg.bytes.data1;
            break;

        case MidiStatus_ChannelPressure: // 10.09 and earlier data stream value
            switch (this->midi_state.data_stream) {
            case DS_PresetName:
                if (this->midi_state.stream_pos < 31) {
                    this->preset_name[this->midi_state.stream_pos++] = msg.bytes.data1;
                }
            case DS_PresetText:
                if (this->midi_state.stream_pos < 255) {
                    this->preset_text[this->midi_state.stream_pos++] = msg.bytes.data1;
                }
            }
            break;

        case MidiStatus_PitchBend:
        case MidiStatus_SysEx:
        default: break;
        }
    } break;
    }

    return 0;
}
