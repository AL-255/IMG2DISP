#include <SDL.h>
#include "i2d_types.hpp"

void i2d_dither(SDL_Surface* src, SDL_Surface* dst, i2d_context_t* ctx){
    // Do basic floyd-steinberg dithering from src to dst
    // src is the input image, it should be gray
    // dst is the output image, it should be 1bpp

    /*
    float kernel [3][3] = {
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 7.0f},
        {3.0f, 5.0f, 1.0f}
    };
    float kernel_sum = 16.0f;
    */
   // Use J. F. Jarvis, C. N. Judice, and W. H. Ninke 
    float kernel [3][5] = {
        {0.0f, 0.0f, 0.0f, 7.0f, 5.0f},
        {3.0f, 5.0f, 7.0f, 5.0f, 3.0f},
        {1.0f, 3.0f, 5.0f, 3.0f, 1.0f}
    };
    float kernel_sum = 48.0f;

    // Copy src
    int w = src->w;
    int h = src->h;
    float tmp[w*h];
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            Uint8 r, g, b, a;
            Uint32 pixel = *(Uint32*)((Uint8*)src->pixels + y * src->pitch + x * src->format->BytesPerPixel);
            SDL_GetRGBA(pixel, src->format, &r, &g, &b, &a);
            tmp[y*w + x] = (float)(0.299 * r + 0.587 * g + 0.114 * b);
        }
    }

    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            float gray = tmp[y*w + x];
            Uint8 val = gray > ctx->threshold[0] ? 255 : 0;
            *(Uint32*)((Uint8*)dst->pixels + y * dst->pitch + x * dst->format->BytesPerPixel) = SDL_MapRGB(dst->format, val, val, val);
            float error = (gray - val)*(ctx->dither_strength);

            for (int ky = 0; ky <= 2; ky++){
                for (int kx = -2; kx <= 2; kx++){
                    if (x + kx >= 0 && x + kx < w && y + ky >= 0 && y + ky < h){
                        float gray = tmp[(y + ky) * w + x + kx];
                        gray += error * kernel[ky + 0][kx + 2] / kernel_sum;
                        tmp[(y + ky) * w + x + kx] = gray;
                    }
                }
            }
        }
    }

}