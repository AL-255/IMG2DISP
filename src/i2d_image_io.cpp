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
#include <imgui.h>
#include <imgui_internal.h>
#include <SDL.h>
#include <utility>
#include "i2d_fmt_il.h"
#include "stb_image.h"

int i2d_fmt_il_read(SDL_Renderer* renderer, SDL_Texture** dst_ptr\
    , int i2d_scan_mode,int i2d_bpp_mode \
    , int i2d_byte_invert, int i2d_msb_first \
    , int i2d_r2l_scan, int i2d_b2t_scan ) {
    
    int id = 0;
    id += i2d_scan_mode*2;
    id += i2d_byte_invert;

    uint8_t* raw_data = const_cast<uint8_t*>(fmt_il_list[id]);
    size_t raw_size   = fmt_il_list_len[id];
    // Read image using stb
    int width, height, channels;
    unsigned char* image_data = stbi_load_from_memory(raw_data, raw_size, &width, &height, &channels, 4);
    if (image_data == nullptr) {
        fprintf(stderr, "Failed to load image: %s\n", stbi_failure_reason());
        return -1;
    }
    // If R2L scan mode, horizontal flip the image; if B2T scan mode, vertical flip the image
    if (i2d_r2l_scan) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width / 2; x++) {
                for (int c = 0; c < channels; c++) {
                    int i0 = (y * width + x) * channels + c;
                    int i1 = (y * width + width - 1 - x) * channels + c;
                    std::swap(image_data[i0], image_data[i1]);
                }
            }
        }
    }
    if (i2d_b2t_scan) {
        for (int y = 0; y < height / 2; y++) {
            for (int x = 0; x < width; x++) {
                for (int c = 0; c < channels; c++) {
                    int i0 = (y * width + x) * channels + c;
                    int i1 = ((height - 1 - y) * width + x) * channels + c;
                    std::swap(image_data[i0], image_data[i1]);
                }
            }
        }
    }
    // Create surface from image data
    SDL_Surface* surf = SDL_CreateRGBSurfaceFrom((void*)image_data, width, height, channels * 8, channels * width, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
    if (surf == nullptr) {
        fprintf(stderr, "Failed to create SDL surface: %s\n", SDL_GetError());
        return -1;
    }

    // Create texture from surface
    *dst_ptr = SDL_CreateTextureFromSurface(renderer, surf);
    if (*dst_ptr == nullptr) {
        fprintf(stderr, "Failed to create SDL texture: %s\n", SDL_GetError());
        return -1;
    }

    // Free image data
    stbi_image_free(image_data);
    SDL_FreeSurface(surf);
    return 0;
    
}