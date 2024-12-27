#pragma once

#include <SDL.h>

#define I2D_FMT_IL_WIDTH 94
#define I2D_FMT_IL_HEIGHT 78
int i2d_fmt_il_read(SDL_Renderer* renderer, SDL_Texture** dst_ptr \
    , int i2d_scan_mode,int i2d_bpp_mode \
    , int i2d_byte_invert, int i2d_msb_first \
    , int i2d_r2l_scan, int i2d_b2t_scan );
