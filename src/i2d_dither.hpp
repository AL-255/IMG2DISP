#pragma once
#include <SDL.h>
#include "i2d_types.hpp"

void i2d_dither(SDL_Surface* src, SDL_Surface* dst, i2d_context_t* ctx);