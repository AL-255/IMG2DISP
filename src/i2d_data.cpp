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
#include "i2d_data.hpp"
#include <imgui.h>

uint8_t byte_invert(uint8_t byte) {
    uint8_t result = 0;
    for (int i = 0; i < 8; i++) {
        result <<= 1;
        result |= byte & 1;
        byte >>= 1;
    }
    return result;
}

int calculate_file_size(i2d_context_t* ctx) {
    int n_bytes;
    if(ctx->scan_mode==0) {
        // Horizontal Scan
        if(ctx->pad_to_full) n_bytes = ctx->target_size[0] * (int)ceil((float)(ctx->target_size[1]) / 8.0f);
        else                 n_bytes = (int)ceil((float)(ctx->target_size[0] * ctx->target_size[1]) / 8.0f);
    } else {
        n_bytes = -1;
    }
    return n_bytes;
}

// Commit the image to the output buffer
// Be careful, dst is malloced in this function
uint8_t* i2d_commit(SDL_Surface* src, i2d_context_t* ctx) {
    uint8_t byte_counter=7;
    uint8_t byte = 0;
    int     byte_index = 0;
    int     n_bytes = calculate_file_size(ctx);
    uint8_t* dst;
    if (n_bytes < 0) {
        fprintf(stderr, "Invalid file size\n");
        dst = NULL;
        return NULL;
    } else {
        fprintf(stderr, "File size: %d\n", n_bytes);
    }
    
    // Create the output buffer
    dst = (uint8_t*)IM_ALLOC(n_bytes);

    // Src is the input image, it should already be 1bpp
    if(ctx->scan_mode==0) {
        // Horizontal Scan
        for (int y = 0; y < src->h; y++) {
            for (int x = 0; x < src->w; x++) {
                Uint8 r, g, b, a;
                int xx, yy;
                if (ctx->r2l_scan) xx = src->w - x - 1;
                else               xx = x;
                if (ctx->b2t_scan) yy = src->h - y - 1;
                else               yy = y;
                Uint32 pixel = *(Uint32*)((Uint8*)src->pixels + yy * src->pitch + xx * src->format->BytesPerPixel);
                SDL_GetRGBA(pixel, src->format, &r, &g, &b, &a);
                Uint8 val = (Uint8)(0.299 * r + 0.587 * g + 0.114 * b);
                
                if (val > 128) byte |= 1<<byte_counter;
                if (byte_counter == 0) {
                    if (ctx->byte_invert) byte = byte_invert(byte);
                    dst[byte_index++] = byte;
                    byte = 0;
                    byte_counter = 7;
                } else {
                    byte_counter--;
                }
            }
            // Pad to full bytes
            if (ctx->pad_to_full) {
                if (byte_counter != 7) {
                    if (ctx->byte_invert) byte = byte_invert(byte);
                    dst[byte_index++] = byte;
                    byte = 0;
                    byte_counter = 7;
                } 
            }
        }
        // Pad the last byte
        if (byte_counter != 7) {
            if (ctx->byte_invert) byte = byte_invert(byte);
            dst[byte_index++] = byte;
            byte = 0;
            byte_counter = 7;
        } 
    } else {
        // Undefined scan mode
        fprintf(stderr, "Undefined scan mode\n");
        dst  = NULL;
        return NULL;
    }
    return dst;
}


int i2d_write_c_array(const char* filename, uint8_t* data, i2d_context_t* ctx){
    FILE* file = fopen(filename, "w");
    if (file == NULL) return 1;
    int n_bytes = calculate_file_size(ctx);
    if (n_bytes < 0) {
        fprintf(stderr, "Invalid file size\n");
        fclose(file);
        return -1;
    }
    fprintf(file, "const uint8_t data[%d] = {\n", n_bytes);
    for (int i = 0; i < n_bytes; i++) {
        fprintf(file, "0x%02X", data[i]);
        if (i != n_bytes - 1) fprintf(file, ",");
        if ((i + 1) % 16 == 0) fprintf(file, "\n");
    }
    fprintf(file, "};\n");
    fclose(file);
    return 0;
}

int i2d_write_bin(const char* filename, uint8_t* data, i2d_context_t* ctx){
    FILE* file = fopen(filename, "wb");
    if (file == NULL) return 1;
    int n_bytes = calculate_file_size(ctx);
    if (n_bytes < 0) {
        fprintf(stderr, "Invalid file size\n");
        fclose(file);
        return -1;
    }
    fwrite(data, 1, n_bytes, file);
    fclose(file);
    return 0;
}


