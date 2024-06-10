#include "../include/em-common.h"
#include "../include/em-compressor.h"
#include "../include/em-hardware.h"
#include "../include/em-pedal.h"
#include "../include/em-matrix.h"

struct EaganMatrix {
    uint16_t firmware_version = 0;
    uint16_t cvc_version = 0;
    EM_Hardware hardware = EM_Hardware_Unknown;
    struct PedalInfo pedal1;
    struct PedalInfo pedal2;
    Compressor compressor;
    uint8_t cc_buffer[128]= {0};
    uint8_t matrix_table[128] = {0};

    EaganMatrix();
    void initDefault();
    int receiveMidi(PackedMidiMessage message);
};

// C dispatch

void* CreateMatrix(EM_ALLOCATE ally) {
    EaganMatrix * em = reinterpret_cast<EaganMatrix *>(ally(sizeof(EaganMatrix)));

    if (em) { 
         em->initDefault();
         return reinterpret_cast<void*>(em);
    } else {
        return nullptr;
    }
}

int EaganMatrixReceiveMidi(void* matrix, PackedMidiMessage message) {
    return reinterpret_cast<EaganMatrix*>(matrix)->receiveMidi(message);
}

// EM Impl

EaganMatrix::EaganMatrix() {
    initDefault();
}

void EaganMatrix::initDefault() {
    init_pedal(&pedal1, PedalId_One);
    init_pedal(&pedal2, PedalId_Two);
}

int EaganMatrix::receiveMidi(PackedMidiMessage message) {

}
