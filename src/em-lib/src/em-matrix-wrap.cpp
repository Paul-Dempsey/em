// Copyright (C) Paul Chase Dempsey
//
// C interface to matrix
//
#include "em-matrix.hpp"

void* CreateMatrix()
{
    void * mem = AllocMemory(MatrixSize());
    if (mem) {
        EaganMatrix * em = reinterpret_cast<EaganMatrix *>(mem);
        em->initDefault();
        return mem;
    } else {
        return nullptr;
    }
}

uint8_t SetMidiRate(void* matrix, uint8_t rate) {
    return MATRIX_CAST(matrix)->SetMidiRate(rate);
}
void RequestConfiguration(void* matrix) {
    MATRIX_CAST(matrix)->RequestConfiguration();
}
void RequestUserPresets(void* matrix) {
    MATRIX_CAST(matrix)->RequestUserPresets();
}
void RequestSystemPresets(void* matrix) {
    MATRIX_CAST(matrix)->RequestSystemPresets();
}
void NextSysPreset(void* matrix) {
    MATRIX_CAST(matrix)->NextSysPreset();
}
void PreviousSysPreset(void* matrix){
    MATRIX_CAST(matrix)->PreviousSysPreset();
}
void ResetCalibration(void* matrix) {
    MATRIX_CAST(matrix)->ResetCalibration();
}
void RefineCalibration(void* matrix) {
    MATRIX_CAST(matrix)->ResetCalibration();
}

// getters

uint16_t FirmwareVersion(void* matrix) {
    return MATRIX_CAST(matrix)->firmware_version;
}
uint16_t CvcVersion(void* matrix) {
    return MATRIX_CAST(matrix)->cvc_version;
}
uint8_t Hardware(void* matrix) {
    return MATRIX_CAST(matrix)->hardware;
}
void GetPedal(void* matrix, PedalId id, PedalInfo* pedal) {
    MATRIX_CAST(matrix)->GetPedal(id, pedal);
}

// direct wrappers

const char * GetPresetName(void* matrix) {
    return (const char *) &MATRIX_CAST(matrix)->preset_name[0];
}
const char * GetPresetText(void* matrix) {
    return (const char *) &MATRIX_CAST(matrix)->preset_text[0];
}

uint8_t EaganMatrixReceiveMidi(void* matrix, PackedMidiMessage message) {
    return MATRIX_CAST(matrix)->receiveMidi(message);
}

void SetMidiOutput(void* v_matrix, void* context, MidiHandler handler) {
    if (v_matrix) {
        EaganMatrix* matrix = MATRIX_CAST(matrix);
        matrix->midi_out_context = context;
        matrix->midi_out_handler = handler;
    }
}
