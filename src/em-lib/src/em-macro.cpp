#include "../include/em-macro.h"
#include "../include/em-cc.h"

// input: one-based macro number 1-90
// output: CC number for the macro
uint8_t MacroNumberCC(uint8_t macro_number)
{
    if (0 == macro_number) return INVALID_CC;
    if (macro_number <= 6) return macro_number + EM_CC_M1 - 1;
    if (macro_number <= 30) return macro_number + EM_CC_M7 - 1;
    if (macro_number <= 48) return macro_number + EM_CC_M31 - 1;
    if (macro_number <= 72) return macro_number + EM_CC_M49 - 1;
    if (macro_number <= 90) return macro_number + EM_CC_M73 - 1;
    return INVALID_CC;
}

int MacroToMidi(uint8_t macro_number, int16_t value, void *handlerContext, MidiHandler handlerFn)
{
    int16_t ti = value + 0x2000; // offset by zero point
    if (ti < 0) return M2MError_ValueOutOfRange; // out of range (negative)
    uint16_t tu = ti;
    if (tu > 0x3f80) return M2MError_ValueOutOfRange; // out of range (positive)

    uint8_t lo = tu & 0x7f;
    uint8_t hi = tu >> 7;
    uint8_t lo_cc = (macro_number <= 48) ? EM_CC_MFraction : EM_CC_MFractionEx;

    auto macro_cc = MacroNumberCC(macro_number);
    if (INVALID_CC == macro_cc) return M2MError_InvalidMacroNumber;

    int e = handlerFn(handlerContext, MakeCC(0, lo_cc, lo));
    if (e) return e;

    return handlerFn(handlerContext, MakeCC(0, macro_cc, hi));
}