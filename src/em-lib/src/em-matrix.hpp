// Copyright (C) Paul Chase Dempsey
#pragma once
#ifndef EM_MATRIX_HPP_INCLUDED
#define EM_MATRIX_HPP_INCLUDED
#include "../include/em-alloc.h"
#include "../include/em-cc.h"
#include "../include/em-compressor.h"
#include "../include/em-hardware.h"
#include "../include/em-macro.h"
#include "../include/em-pedal.h"
#include "../include/em-recirculator.h"
#include "../include/em-util.hpp"
#include "../include/em-matrix.h"

#define MATRIX_CAST(matrix) reinterpret_cast<EaganMatrix*>(matrix)

struct MidiState {
    uint8_t fraction; // lsb for following macro, bend, y, or z
    bool    hi_macro; // next macro value is macro 49..90
    uint8_t ch01cc[128];
    uint8_t ch16cc[128];
    uint8_t data_stream;
    uint8_t stream_pos;

    void reset() {
        fraction = 0;
        hi_macro = false;
        zero_bytes(ch01cc, sizeof(ch01cc));
        zero_bytes(ch16cc, sizeof(ch16cc));
        data_stream = DS_None;
        stream_pos = 0;
    }

    inline void set_lo_fraction(uint8_t value) {
        hi_macro = false;
        fraction = value;
    }

    inline void set_hi_fraction(uint8_t value) {
        hi_macro = true;
        fraction = value;
    }

    inline uint8_t consume_fraction() {
        auto r = fraction;
        fraction = 0;
        hi_macro = false;
        return r; 
    }

    inline uint16_t get14bit(uint8_t hi) {
        return (hi << 7) | consume_fraction();
    }
};

struct EaganMatrix {
    uint16_t firmware_version;
    uint16_t cvc_version;
    uint8_t hardware;

    MidiState midi_state;
    uint8_t midi_rate; // 1, 3, 20: 1/1 (full), 1/3, 1/20
    uint8_t sustain;
    uint8_t sostenuto1;
    uint8_t sostenuto2;
    uint8_t pre_level;
    uint8_t post_level;
    uint8_t headphone_level;
    uint8_t line_level;
    uint8_t attenuation;
    uint8_t audio_level;

    uint8_t middle_c;
    uint8_t tuning_grid;
    uint8_t bend_range;
    uint8_t multi_split_lo;
    uint8_t multi_split_hi;
    uint8_t split_point;
    uint8_t actuation;

    uint8_t poly_trad;
    uint8_t poly_dsp;
    uint8_t poly_cvc;

    bool preserve_surface;
    bool preserve_pedal;
    bool preserve_midi_encoding;

    // Rounding
    uint8_t round_rate;
    uint8_t round_initial;
    uint8_t round_equal;
    uint8_t round_mode;

    uint8_t pedal_shift;

    //PedalInfo pedal1;
    uint16_t jack1; // 14' data value
    uint8_t pedal1_min;
    uint8_t pedal1_max;
    uint8_t  pedal1_cc;
    uint8_t  pedal1_kind;

    //PedalInfo pedal2;
    uint16_t jack2;
    uint8_t pedal2_min;
    uint8_t pedal2_max;
    uint8_t  pedal2_cc;
    uint8_t  pedal2_kind;

    //Recirculator recirculator;
    uint8_t recirculator_kind;
    bool recirculator_disable;
    bool recirculator_extend;
    uint8_t recirculator_dials[7];

    uint16_t macro[90];

    //Compressor compressor;
    uint8_t comp_tanh_type; // 0=comp, 1=tanh
    uint8_t threshold_drive;
    uint8_t attack_cutoff;
    uint8_t ratio_makeup;
    uint8_t comp_tanh_mix;

    // TiltEQ
    uint8_t eq_tilt; // 64 = flat
    uint8_t eq_frequency; // 0..127 = 120Hz..15kHz	
    uint8_t eq_mix;  // 0=dry, 127=wet

    // preset
    uint8_t bank_hi; // cc0
    uint8_t bank_lo; // cc32
    uint8_t preset_number;  // program change
    uint8_t preset_name[32];
    uint8_t preset_text[256];

    void* midi_out_context;
    MidiHandler midi_out_handler;

    EaganMatrix();
    void initDefault();
    bool isLegacy() { return firmware_version <= 1009; }

    // API
    void GetPedal(PedalId id, PedalInfo* pedal);

    uint8_t GetMidiRate() { return midi_rate; }
    uint8_t SetMidiRate(uint8_t rate);
    void RequestConfiguration();
    void RequestUserPresets();
    void RequestSystemPresets();
    void NextSysPreset();
    void PreviousSysPreset();
    void ResetCalibration();
    void RefineCalibration();
    //void ToggleSurfaceAlignment(); //TaskId_SurfAlign
    //void FactoryCalibration(); // TaskId_DoFactCalib

    // Midi output
    void SetMidiOutput(void* context, MidiHandler handler);

    // internal

    void PokeMatrix(uint8_t id, uint8_t value);

    void EndDataStream();

    inline void sendMidi(PackedMidiMessage message) {
        if (midi_out_handler) {
            auto r = midi_out_handler(midi_out_context, message);
        }
    }

    // src/em-matrix-midi.cpp
    int receiveMidi(PackedMidiMessage message);
    int Ch01CC(uint8_t cc, uint8_t value);
    int Ch16CC(uint8_t cc, uint8_t value);
    int onTask(TaskId task_id);
    int onInfo(InfoId info_id);
};

#endif