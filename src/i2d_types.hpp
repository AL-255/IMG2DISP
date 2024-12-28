/* 
 * This file is part of the IMG2DISP distribution (https://github.com/AL-255/IMG2DISP).
 * Copyright (c) 2024 Anhang Li.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <stdint.h>
#include <stddef.h>
#include <SDL.h>
#include "i2d_config.hpp"

typedef struct {
    float* data;
    int    width  = 5;
    int    height = 5;
} i2d_ed_kernel_t;

typedef struct {
    bool  include_header = true;
    bool  byte_invert    = false;
    bool  r2l_scan       = false;
    bool  b2t_scan       = false;
    bool  msb_first      = false;
    bool  pad_to_full    = false;
    int   output_type    = 0;
    int   scan_mode      = 0;
    int   bpp_mode       = 0;
    int   resize_method  = 0;
    int   target_size[2] = {I2D_PREVIEW_WIDTH,I2D_PREVIEW_HEIGHT};
    int   threshold[16];
    int             dither_type     = 0;
    i2d_ed_kernel_t dither_ed_kernel;
    float           dither_strength = 0.5f;

    float bezier_cp[5]   = { 0.0f, 0.0f, 1.0f, 1.0f };
} i2d_context_t;