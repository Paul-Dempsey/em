#include "../include/em-rounding.h"

void ResetRounding(Rounding* round) {
    round->rate  = 0;
    round->initial  = false;
    round->kind  = RoundKind_Normal;
    round->tuning  = Tuning_Equal;
    round->equal  = RoundEqual_Equal;
}

