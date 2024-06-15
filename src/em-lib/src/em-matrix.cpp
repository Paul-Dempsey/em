#include "../include/em-alloc.h"
#include "../include/em-cc.h"
#include "../include/em-compressor.h"
#include "../include/em-hardware.h"
#include "../include/em-pedal.h"
#include "../include/em-recirculator.h"
#include "../include/em-util.hpp"
#include "../include/em-matrix.h"

struct EaganMatrix {
    uint16_t firmware_version;
    uint16_t cvc_version;
    EM_Hardware hardware;
    PedalInfo pedal1;
    PedalInfo pedal2;
    Recirculator recirculator;
    uint16_t recirculator_dials;
    Compressor compressor;
    uint8_t ch01cc[128];
    uint8_t ch16cc[128];
    uint8_t matrix_table[128];

    EaganMatrix();
    void initDefault();
    int receiveMidi(PackedMidiMessage message);
    
};

// C dispatch
uint64_t MatrixSize() { return sizeof(EaganMatrix); }

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



inline void SetMatrixBool(void* matrix, MatrixPokeId id, uint8_t value)
{
    EaganMatrix * em = reinterpret_cast<EaganMatrix *>(matrix);
    em->matrix_table[id] = value ? 1 : 0;
}
inline uint8_t GetMatrixBool(void* matrix, MatrixPokeId id) {
    EaganMatrix * em = reinterpret_cast<EaganMatrix *>(matrix);
    return em->matrix_table[id] ? 1 : 0;
}

void SetPreserveSurface(void* matrix, uint8_t preserve) {
    SetMatrixBool(matrix, MatrixPokeId::MPID_PreserveSurface, preserve);
}
void SetPreservePedal(void* matrix, uint8_t preserve){
    SetMatrixBool(matrix, MatrixPokeId::MPID_PreservePedal, preserve);
}
void SetPreserveMidiEncoding(void* matrix, uint8_t preserve) {
    SetMatrixBool(matrix, MatrixPokeId::MPID_PreserveMidiEncoding, preserve);
}
uint8_t GetPreserveSurface(void* matrix) {
    return GetMatrixBool(matrix, MatrixPokeId::MPID_PreserveSurface);
}
uint8_t GetPreservePedal(void* matrix) {
    return GetMatrixBool(matrix, MatrixPokeId::MPID_PreservePedal);
}
uint8_t GetPreserveMidiEncoding(void* matrix) {
    return GetMatrixBool(matrix, MatrixPokeId::MPID_PreserveMidiEncoding);
}


int EaganMatrixReceiveMidi(void* matrix, PackedMidiMessage message) {
    return reinterpret_cast<EaganMatrix*>(matrix)->receiveMidi(message);
}

// EM Impl

EaganMatrix::EaganMatrix() {
    initDefault();
}

void EaganMatrix::initDefault()
{
    firmware_version = 0;
    cvc_version = 0;
    hardware = EM_Hardware_Unknown;
    init_pedal(&pedal1, PedalId_One);
    init_pedal(&pedal2, PedalId_Two);

    zero_bytes(ch01cc, 128);
    zero_bytes(ch16cc, 128);
    zero_bytes(matrix_table, 128);

}

int EaganMatrix::receiveMidi(PackedMidiMessage message)
{

}
