#include "../include/em-macro.h"
#include "../include/em-cc.h"

// input: one-based macro number 1..90
// output: CC number for the macro, or INVALID_CC if not 1..90
uint8_t MacroNumberCC(uint8_t macro_number)
{
    if (macro_number <= 48) {
        if (macro_number <= 6) {
            return (macro_number != 0)
                ? macro_number + EM_CC_M1 - 1
                : INVALID_CC;
        }
        return macro_number + (macro_number <= 30) ? EM_CC_M7 - 1 : EM_CC_M31 - 1;
    }
    if (macro_number <= 72) return macro_number + EM_CC_M49 - 1;
    if (macro_number <= 90) return macro_number + EM_CC_M73 - 1;
    return INVALID_CC;
}

uint8_t MacroNumber(uint8_t macro_cc, bool hi_bank)
{
    uint8_t result = 0;
    switch (macro_cc) {
    case EM_CC_M1:  result = 1; break;
    case EM_CC_M2:  result = 2; break;
    case EM_CC_M3:  result = 3; break;
    case EM_CC_M4:  result = 4; break;
    case EM_CC_M5:  result = 5; break;
    case EM_CC_M6:  result = 6; break;
    case EM_CC_M7:  result = 7; break;
    case EM_CC_M8:  result = 8; break;
    case EM_CC_M9:  result = 9; break;
    case EM_CC_M10: result = 10; break;
    case EM_CC_M11: result = 11; break;
    case EM_CC_M12: result = 12; break;
    case EM_CC_M13: result = 13; break;
    case EM_CC_M14: result = 14; break;
    case EM_CC_M15: result = 15; break;
    case EM_CC_M16: result = 16; break;
    case EM_CC_M17: result = 17; break;
    case EM_CC_M18: result = 18; break;
    case EM_CC_M19: result = 19; break;
    case EM_CC_M20: result = 20; break;
    case EM_CC_M21: result = 21; break;
    case EM_CC_M22: result = 22; break;
    case EM_CC_M23: result = 23; break;
    case EM_CC_M24: result = 24; break;
    case EM_CC_M25: result = 25; break;
    case EM_CC_M26: result = 26; break;
    case EM_CC_M27: result = 27; break;
    case EM_CC_M28: result = 28; break;
    case EM_CC_M29: result = 29; break;
    case EM_CC_M30: result = 30; break;
    case EM_CC_M31: result = 31; break;
    case EM_CC_M32: result = 32; break;
    case EM_CC_M33: result = 33; break;
    case EM_CC_M34: result = 34; break;
    case EM_CC_M35: result = 35; break;
    case EM_CC_M36: result = 36; break;
    case EM_CC_M37: result = 37; break;
    case EM_CC_M38: result = 38; break;
    case EM_CC_M39: result = 39; break;
    case EM_CC_M40: result = 40; break;
    case EM_CC_M41: result = 41; break;
    case EM_CC_M42: result = 42; break;
    case EM_CC_M43: result = 43; break;
    case EM_CC_M44: result = 44; break;
    case EM_CC_M45: result = 45; break;
    case EM_CC_M46: result = 46; break;
    case EM_CC_M47: result = 47; break;
    case EM_CC_M48: result = 48; break;
    default: return 0;
    }
    return hi_bank ? result + 48 : result;
}

int MacroToMidiData(uint8_t macro_number, int16_t value, PackedMidiMessage* data)
{
    if (!data) return M2MError_Error;
    auto macro_cc = MacroNumberCC(macro_number);
    if (INVALID_CC == macro_cc) return M2MError_InvalidMacroNumber;

    int16_t ti = macro_number > 6 ? value + 0x2000 : value; // offset by zero point for macro > 6
    if (ti < 0) return M2MError_Underflow; // out of range (negative)
    uint16_t tu = ti;
    if (tu > 0x3f80) return M2MError_Overflow; // out of range (positive)

    uint8_t lo = tu & 0x7F;
    uint8_t hi = tu >> 7;
    uint8_t lo_cc = (macro_number <= 48) ? EM_CC_MFraction : EM_CC_MHiFraction;
    *data++ = MakeCC(0, lo_cc, lo);
    *data = MakeCC(0, macro_cc, hi);
    return M2MError_Ok;
}

int MacroToMidi(uint8_t macro_number, int16_t value, void *handlerContext, MidiHandler handlerFn)
{
    PackedMidiMessage data[2];
    int e;
    if (e = MacroToMidiData(macro_number, value, data)) return e;
    if (e = handlerFn(handlerContext, data[0])) return e;
    return handlerFn(handlerContext, data[1]);
}