// Copyright (C) Paul Chase Dempsey
//#include <assert.h>
#include "../include/em-pedal.h"
#include "../include/em-cc.h"

void init_pedal(PedalInfo* pedal, uint8_t jack)
{
    pedal->value = 0;
    pedal->jack = jack;
    switch (jack) {
    case PedalId_One:
        pedal->cc = EM_CC_Sustain;
        break;
    case PedalId_Two:
        pedal->cc = EM_CC_Sostenuto;
        break;
    default:
        //assert(false);
        pedal->jack = PedalId_One;
        pedal->cc = EM_CC_Sustain;
        break;
    };
    pedal->min = 0;
    pedal->max = 127;
    pedal->kind = PedalType_None;
}

void reset_pedal(PedalInfo* pedal)
{
    pedal->value = 0;
    switch (pedal->jack) {
    case PedalId_One:
        pedal->cc = EM_CC_Sustain;
        break;
    case PedalId_Two:
        pedal->cc = EM_CC_Sostenuto;
        break;
    default:
        //assert(false);
        break;
    };
    pedal->min = 0;
    pedal->max = 127;
    pedal->kind = PedalType_None;
}

const char * PedalKindName(uint8_t kind) {
    switch (kind) {
    default:
    case PedalType_None: return "None";
    case PedalType_Switch: return "Switch";
    case PedalType_Expression: return "Expression";
    case PedalType_Damper: return "Damper";
    case PedalType_TriValue: return "Tri-value";
    case PedalType_CV: return "CV";
    case PedalType_Potentiometer: return "Knob";
    }
}