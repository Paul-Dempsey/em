// Copyright (C) Paul Chase Dempsey
#include "../include/em-hardware.h"

const char * HardwarePresetClass(EM_Hardware hw) {
    switch (hw) {
        default:
        EM_Hardware_Unknown     : return "Unknown";
        EM_Hardware_LightFull   :
        EM_Hardware_LightHalf   :
        EM_Hardware_ClassicFull :
        EM_Hardware_ClassicHalf :
        EM_Hardware_Slim22      :
        EM_Hardware_Slim46      :
        EM_Hardware_Slim70      :
        EM_Hardware_LightFullUp :
        EM_Hardware_LightHalfUp : return "Continuum";
        EM_Hardware_Mini        : return "Mini";
        EM_Hardware_Osmose49    : return "Osmose";
        EM_Hardware_EMM         : return "EMM";
    };
}

const char * ShortHardwareName(EM_Hardware hw) {
    switch (hw) {
        default:
        EM_Hardware_Unknown     : return "Unknown";
        EM_Hardware_LightFull   : return "CFL";
        EM_Hardware_LightHalf   : return "CHL";
        EM_Hardware_ClassicFull : return "CFC";
        EM_Hardware_ClassicHalf : return "CHC";
        EM_Hardware_Mini        : return "CMini";
        EM_Hardware_Osmose49    : return "Osmose";
        EM_Hardware_Slim22      : return "Slim22";
        EM_Hardware_Slim46      : return "Slim46";
        EM_Hardware_Slim70      : return "Slim70";
        EM_Hardware_EMM         : return "EMM";
        EM_Hardware_LightFullUp : return "CFL6";
        EM_Hardware_LightHalfUp : return "CHL6";
    };

}

const char * HardwareName(EM_Hardware hw) {
    switch (hw) {
        default: 
        EM_Hardware_Unknown     : return "Unknown";
        EM_Hardware_LightFull   : return "Full (Light)";        // light action full, not UP version
        EM_Hardware_LightHalf   : return "Half (Light)";        // light action, not UP version
        EM_Hardware_ClassicFull : return "Full (Classic)";      // classic action full size
        EM_Hardware_ClassicHalf : return "Half (Classic)";      // classic action half size
        EM_Hardware_Mini        : return "ContinuuMini";        // ContinuuMini 
        EM_Hardware_Osmose49    : return "Osmose";              // Osmose
        EM_Hardware_Slim22      : return "Slim 22";             // slim 22L6x
        EM_Hardware_Slim46      : return "Slim 46";             // slim 46L6x
        EM_Hardware_Slim70      : return "Slim 70";             // slim 70L6x
        EM_Hardware_EMM         : return "EaganMatrix Module";  // Eurorack EaganMatrix Module
        EM_Hardware_LightFullUp : return "Full (Light) 6x";     // light action full, UP triple-dsp board
        EM_Hardware_LightHalfUp : return "Half (Light) 6x";     // light action half, UP triple-dsp board
    };
}
