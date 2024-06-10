// Copyright (C) Paul Chase Dempsey
#include "../include/em-compressor.h"

void ResetCompressor(Compressor* self) {
    self->threshold = 127;
    self->attack = 64;
    self->ratio = 64;
    self->mix = 0;
}