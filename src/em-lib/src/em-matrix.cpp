// Copyright (C) Paul Chase Dempsey
#include "em-matrix.hpp"

uint64_t MatrixSize() { return sizeof(EaganMatrix); }

EaganMatrix::EaganMatrix() {
    initDefault();
}

void EaganMatrix::initDefault()
{
    firmware_version = 0;
    cvc_version = 0;
    hardware = EM_Hardware_Unknown;
    midi_state.reset();
    sustain = 0;
    sostenuto1 = 0;
    sostenuto2 = 0;

    preserve_surface = false;
    preserve_pedal = false;
    preserve_midi_encoding = false;

    bend_range = 96;
    round_mode = 0; // TODO: enum

    pedal_shift = 48;
    multi_split_lo = 0;
    multi_split_hi = 0;
    split_point = 0;

    jack1 = 0;
    pedal1_min = 0;
    pedal1_max = MAX14;
    pedal1_cc = EM_CC_Sustain;
    pedal1_kind = PedalType_None;

    jack2 = 0;
    pedal2_min = 0;
    pedal2_max = MAX14;
    pedal2_cc = EM_CC_Sostenuto;
    pedal2_kind = PedalType_None;

    // Recirculator (according to Empty.mid)
    recirculator_kind = R8orKind_ShortReverb;
    recirculator_dials[R8orValue_R1]= 99;
    recirculator_dials[R8orValue_R2]= 53;
    recirculator_dials[R8orValue_R3]= 17;
    recirculator_dials[R8orValue_R4]= 40;
    recirculator_dials[R8orValue_R5]= 40;
    recirculator_dials[R8orValue_R6]= 40;
    recirculator_dials[R8orValue_RMix]= 37;

    comp_tanh_type      = 0;
    threshold_drive     = MAX7;
    attack_cutoff       = MID7;
    ratio_makeup        = MID7;
    comp_tanh_mix       = 0;

    eq_tilt  = MID7;
    eq_frequency  = MID7;
    eq_mix   = 0;

    headphone_level = 0;
    line_level      = 0;
    pre_level       = MID7;
    post_level      = MID7;
    audio_level     = 0;
    attenuation     = 0;
    zero_bytes(preset_name, sizeof(preset_name));
    zero_bytes(preset_text, sizeof(preset_text));
    zero_bytes(recirculator_dials, sizeof(recirculator_dials));
    zero_bytes(macro, sizeof(macro));

    midi_out_context = nullptr;
    midi_out_handler = nullptr;
}

void EaganMatrix::GetPedal(PedalId id, PedalInfo *pedal)
{
    if (nullptr == pedal) return;
    switch (id) {
    case PedalId_One:
        pedal->value = jack1;
        pedal->cc = pedal1_cc;
        pedal->min = pedal1_min;
        pedal->max = pedal1_max;
        pedal->kind = pedal1_kind;
        pedal->jack = PedalId_One;
        break;

    case PedalId_Two:
        pedal->value = jack2;
        pedal->cc = pedal2_cc;
        pedal->min = pedal2_min;
        pedal->max = pedal2_max;
        pedal->kind = pedal2_kind;
        pedal->jack = PedalId_Two;
        break;

    default: 
        pedal->jack = PedalId_Invalid;
        break;
    }
}

uint8_t EaganMatrix::SetMidiRate(uint8_t rate)
{
    uint8_t task = TaskId_MidiTxFull;
    switch (rate) {
    case 1:
        midi_rate = rate;
        break;
    case 3:
        midi_rate = rate;
        task = TaskId_MidiTxThird;
        break;
    case 20:
        midi_rate = rate;
        task = TaskId_MidiTxTweenth;
        break;
    default:
        return midi_rate;
    }
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, task));
    return midi_rate;
}

void EaganMatrix::RequestConfiguration() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_ConfigToMidi));

}
void EaganMatrix::RequestUserPresets() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_UserToMidi));
}
void EaganMatrix::RequestSystemPresets() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_SysToMidi));
}

void EaganMatrix::PreviousSysPreset() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_DecPreset));
}
void EaganMatrix::NextSysPreset() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_IncPreset));
}
void EaganMatrix::ResetCalibration() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_DoResetCalib));
}
void EaganMatrix::RefineCalibration() {
    sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_DoRefineCalib));
}

// void EaganMatrix::ToggleSurfaceAlignment() {
//     sendMidi(MakeCC(CHANNEL16, EM_CC16_Task, TaskId_SurfAlign));
// }

