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

#include <SDL.h>

#define I2D_FMT_IL_WIDTH 94
#define I2D_FMT_IL_HEIGHT 78
int i2d_fmt_il_read(SDL_Renderer* renderer, SDL_Texture** dst_ptr \
    , int i2d_scan_mode,int i2d_bpp_mode \
    , int i2d_byte_invert, int i2d_msb_first \
    , int i2d_r2l_scan, int i2d_b2t_scan );
