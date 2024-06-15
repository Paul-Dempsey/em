#include "../include/em-recirculator.h"


void InitDefault(Recirculator* recirculator)
{
    recirculator->kind = R8orKind_ShortReverb;
    recirculator->disable = false;
    recirculator->extend = false;
}

const char * RecirculatorName(R8orKind kind)
{
    switch (kind) {
    case R8orKind_ShortReverb:      return "Short Reverb";
    case R8orKind_ModDelay:         return "Modulated Delay";
    case R8orKind_SweptEcho:        return "Swept Echo";
    case R8orKind_AnalogEcho:       return "Analog Echo";
    case R8orKind_DigitalEchoLPF:   return "Delay HPF";
    case R8orKind_DigitalEchoHPF:   return "Delay LPF";
    case R8orKind_LongReverb:       return "Long Reverb";
    default: return "";
    }
}