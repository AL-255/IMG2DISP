#pragma once
// Illustrations of the byte formatting
// Gif raw data

#include <stdint.h>
#include <stddef.h>

const uint8_t fmt_il_00[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x9A, 0xC2, 0xFF, 0x14, 0x1F, 0x10, 0x28, 0x1C,
    0xEA, 0x02, 0x8A, 0x64, 0xC0, 0x98, 0x43, 0x2A, 0x99, 0xB9, 0x64, 0x11, 0x6A, 0x43, 0x2E, 0xA9,
    0xB8, 0x29, 0xB6, 0xB6, 0x4C, 0x78, 0x11, 0xE0, 0x83, 0xD8, 0x40, 0x2E, 0x98, 0x09, 0xE8, 0x81,
    0x5A, 0xC0, 0x9E, 0x78, 0x13, 0x60, 0x84, 0xF8, 0x40, 0x36, 0x98, 0x0B, 0x68, 0x82, 0x7A, 0xC0,
    0x16, 0x34, 0x03, 0x6F, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7D, 0x01, 0x89, 0x81, 0x61, 0x63,
    0x65, 0x67, 0x69, 0x6B, 0x6C, 0x89, 0x39, 0x8B, 0x72, 0x8D, 0x76, 0x8F, 0x7A, 0x91, 0x7E, 0x12,
    0x95, 0x83, 0x8E, 0x78, 0x90, 0x7C, 0x6D, 0x57, 0x5B, 0x55, 0x37, 0x89, 0xA9, 0xAA, 0xAB, 0xAC,
    0xAD, 0xAE, 0xAF, 0xB0, 0xA5, 0x34, 0xB2, 0xA6, 0x33, 0x5D, 0x5F, 0x8C, 0x74, 0xA0, 0x86, 0x9B,
    0x6E, 0xB8, 0x96, 0xBA, 0x98, 0xA1, 0x9A, 0xA3, 0x9C, 0xA8, 0x80, 0xBF, 0x9F, 0xC2, 0xBC, 0xC5,
    0xA9, 0x9E, 0x97, 0x85, 0xA2, 0x88, 0xB4, 0x34, 0xCF, 0xC1, 0xD1, 0xC4, 0x7D, 0xBE, 0x70, 0xB9,
    0x84, 0x99, 0x87, 0xA4, 0xB5, 0xA7, 0x55, 0xB1, 0xE5, 0xE6, 0xE7, 0xAA, 0xA8, 0xE2, 0x5C, 0x00,
    0xD6, 0xDE, 0xC3, 0xE0, 0xC6, 0xEE, 0xBB, 0xD2, 0x6D, 0x38, 0x8A, 0xC9, 0xD0, 0xDF, 0x9B, 0xCE,
    0xF9, 0xD7, 0xFB, 0xCD, 0xA8, 0xCD, 0x98, 0xB7, 0xAC, 0x9E, 0x3C, 0x7F, 0xEF, 0x98, 0x69, 0x13,
    0xB8, 0xAE, 0x05, 0xC3, 0x86, 0x2A, 0x26, 0x51, 0xD1, 0x02, 0x43, 0x22, 0x16, 0x8A, 0x0E, 0x1F,
    0x0E, 0xC1, 0x18, 0x51, 0x23, 0xC4, 0x12, 0xA0, 0x16, 0x3F, 0xAE, 0x08, 0xD9, 0x90, 0xE3, 0x08,
    0x92, 0x10, 0x4D, 0x82, 0x40, 0xF9, 0x51, 0x65, 0x07, 0x96, 0x22, 0x4D, 0xC0, 0x8C, 0x49, 0x62,
    0x26, 0x4D, 0x97, 0x16, 0x6C, 0xD2, 0x04, 0x80, 0x73, 0x82, 0xCE, 0x9D, 0x3C, 0x5F, 0x7A, 0x04,
    0xEA, 0xE1, 0x27, 0x51, 0x0E, 0x46, 0x8F, 0x4A, 0xC0, 0x98, 0x54, 0xE9, 0xD2, 0x0A, 0x4D, 0x9D,
    0x3E, 0x95, 0x10, 0x55, 0x2A, 0x85, 0xAA, 0x56, 0xA9, 0x0E, 0xCD, 0x9A, 0x13, 0x09, 0xD7, 0x95,
    0x57, 0x7A, 0x7E, 0x0D, 0x29, 0xD6, 0x2A, 0xD6, 0xAC, 0x67, 0xCD, 0x6E, 0xFD, 0x7A, 0x95, 0xAD,
    0x88, 0x5B, 0xDC, 0x80, 0x25, 0x34, 0xB8, 0x4D, 0x90, 0x3E, 0x78, 0xBD, 0xEE, 0x21, 0x8B, 0xAB,
    0x0C, 0x5B, 0xBC, 0x7E, 0x7C, 0xEF, 0x2A, 0x94, 0x94, 0xEA, 0x06, 0x41, 0xBF, 0x79, 0xDB, 0x21,
    0xA4, 0x97, 0xCD, 0x1E, 0x80, 0xB5, 0x6E, 0x27, 0x94, 0x8D, 0x1C, 0x94, 0xB2, 0x87, 0xC9, 0x6C,
    0x9D, 0x28, 0x80, 0x3C, 0x56, 0x0A, 0xE7, 0xAF, 0x52, 0x2C, 0x23, 0xDD, 0x2C, 0x9A, 0x03, 0xE6,
    0xD2, 0xA8, 0x53, 0xAB, 0x5E, 0x0D, 0x31, 0x02, 0x00, 0x3B,
};
const uint8_t fmt_il_01[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x9A, 0xC2, 0xFF, 0x14, 0x1F, 0x10, 0x28, 0x1C,
    0xEA, 0x02, 0x8A, 0x64, 0xC0, 0x98, 0x43, 0x2A, 0x99, 0xB9, 0x64, 0x11, 0x6A, 0x43, 0x2E, 0xA9,
    0xB8, 0x29, 0xB6, 0xB6, 0x14, 0x78, 0x07, 0x60, 0x82, 0xB8, 0x40, 0x36, 0x98, 0x0F, 0x68, 0x84,
    0x3A, 0xC1, 0x9E, 0x78, 0x05, 0xE0, 0x81, 0x98, 0x40, 0x2E, 0x98, 0x0D, 0xE8, 0x83, 0x1A, 0xC1,
    0x4E, 0x34, 0x03, 0x6F, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7D, 0x01, 0x89, 0x81, 0x61, 0x63,
    0x65, 0x67, 0x69, 0x6B, 0x6C, 0x89, 0x39, 0x8B, 0x72, 0x8D, 0x76, 0x8F, 0x7A, 0x91, 0x7E, 0x12,
    0x95, 0x83, 0x8E, 0x78, 0x90, 0x7C, 0x6D, 0x57, 0x5B, 0x55, 0x37, 0x89, 0xA9, 0xAA, 0xAB, 0xAC,
    0xAD, 0xAE, 0xAF, 0xB0, 0xA5, 0x34, 0xB2, 0xA6, 0x33, 0x5D, 0x5F, 0x8C, 0x74, 0xA0, 0x86, 0x9B,
    0x6E, 0xB8, 0x96, 0xBA, 0x98, 0xA1, 0x9A, 0xA3, 0x9C, 0xA8, 0x80, 0xBF, 0x9F, 0xC2, 0xBC, 0xC5,
    0xA9, 0x9E, 0x97, 0x85, 0xA2, 0x88, 0xB4, 0x34, 0xCF, 0xC1, 0xD1, 0xC4, 0x7D, 0xBE, 0x70, 0xB9,
    0x84, 0x99, 0x87, 0xA4, 0xB5, 0xA7, 0x55, 0xB1, 0xE5, 0xE6, 0xE7, 0xAA, 0xA8, 0xE2, 0x5C, 0x00,
    0xD6, 0xDE, 0xC3, 0xE0, 0xC6, 0xEE, 0xBB, 0xD2, 0x6D, 0x38, 0x8A, 0xC9, 0xD0, 0xDF, 0x9B, 0xCE,
    0xF9, 0xD7, 0xFB, 0xCD, 0xA8, 0xCD, 0x98, 0xB7, 0xAC, 0x9E, 0x3C, 0x7F, 0xEF, 0x98, 0x69, 0x13,
    0xB8, 0xAE, 0x05, 0xC3, 0x86, 0x2A, 0x26, 0x51, 0xD1, 0x02, 0x43, 0x22, 0x16, 0x8A, 0x0E, 0x1F,
    0x0E, 0xC1, 0x18, 0x51, 0x23, 0xC4, 0x12, 0xA0, 0x16, 0x3F, 0xAE, 0x08, 0xD9, 0x90, 0xE3, 0x08,
    0x92, 0x10, 0x4D, 0x82, 0x40, 0xF9, 0x51, 0x65, 0x07, 0x96, 0x22, 0x4D, 0xC0, 0x8C, 0x49, 0x62,
    0x26, 0x4D, 0x97, 0x16, 0x6C, 0xD2, 0x04, 0x80, 0x73, 0x82, 0xCE, 0x9D, 0x3C, 0x5F, 0x7A, 0x04,
    0xEA, 0xE1, 0x27, 0x51, 0x0E, 0x46, 0x8F, 0x4A, 0xC0, 0x98, 0x54, 0xE9, 0xD2, 0x0A, 0x4D, 0x9D,
    0x3E, 0x95, 0x10, 0x55, 0x2A, 0x85, 0xAA, 0x56, 0xA9, 0x0E, 0xCD, 0x9A, 0x13, 0x09, 0xD7, 0x95,
    0x57, 0x7A, 0x7E, 0x0D, 0x29, 0xD6, 0x2A, 0xD6, 0xAC, 0x67, 0xCD, 0x6E, 0xFD, 0x7A, 0x95, 0xAD,
    0x88, 0x5B, 0xDC, 0x80, 0x25, 0x34, 0xB8, 0x4D, 0x90, 0x3E, 0x78, 0xBD, 0xEE, 0x21, 0x8B, 0xAB,
    0x0C, 0x5B, 0xBC, 0x7E, 0x7C, 0xEF, 0x2A, 0x94, 0x94, 0xEA, 0x06, 0x41, 0xBF, 0x79, 0xDB, 0x21,
    0xA4, 0x97, 0xCD, 0x1E, 0x80, 0xB5, 0x6E, 0x27, 0x94, 0x8D, 0x1C, 0x94, 0xB2, 0x87, 0xC9, 0x6C,
    0x9D, 0x28, 0x80, 0x3C, 0x56, 0x0A, 0xE7, 0xAF, 0x52, 0x2C, 0x23, 0xDD, 0x2C, 0x9A, 0x03, 0xE6,
    0xD2, 0xA8, 0x53, 0xAB, 0x5E, 0x0D, 0x31, 0x02, 0x00, 0x3B,
};
const uint8_t fmt_il_10[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x5B, 0x10, 0xF0, 0xC0, 0x89, 0x62, 0xF8, 0x0B,
    0xE2, 0x86, 0x48, 0xA4, 0x4F, 0xE2, 0x5B, 0x02, 0x9A, 0xC5, 0x55, 0x73, 0xA7, 0x64, 0x5A, 0x9F,
    0xD7, 0x68, 0xAA, 0xA8, 0xBD, 0x39, 0x01, 0x89, 0x30, 0x36, 0x9C, 0x18, 0x8B, 0x55, 0x3F, 0xB2,
    0x51, 0x9D, 0x16, 0xB7, 0xCB, 0x5B, 0x89, 0x3A, 0xC8, 0x06, 0xBB, 0xED, 0x70, 0x54, 0x71, 0x0E,
    0x44, 0xF8, 0xB1, 0x7E, 0x08, 0x80, 0x7F, 0x7A, 0x13, 0x81, 0x46, 0x87, 0x3F, 0x89, 0x00, 0x87,
    0x85, 0x12, 0x8D, 0x7D, 0x7F, 0x8A, 0x92, 0x8C, 0x84, 0x26, 0x5A, 0x90, 0x3C, 0x07, 0x9B, 0x58,
    0x9B, 0x07, 0x9D, 0x9C, 0x27, 0x5A, 0x9E, 0x46, 0xA4, 0x3F, 0xA6, 0x00, 0xA4, 0x97, 0x15, 0xAA,
    0x40, 0xA8, 0xAF, 0xA1, 0x25, 0x5D, 0xAD, 0x3C, 0x06, 0xB6, 0x58, 0xB6, 0x06, 0xB8, 0xB7, 0xB2,
    0x16, 0xB9, 0x46, 0xBF, 0x3F, 0xC1, 0x00, 0xBF, 0xBD, 0x15, 0xC5, 0x40, 0xC3, 0xCA, 0xBC, 0x48,
    0x12, 0xCD, 0x00, 0xCF, 0xCD, 0x01, 0xCF, 0x12, 0xC8, 0x3C, 0x05, 0xD8, 0x58, 0xD8, 0x05, 0xDA,
    0xD9, 0x24, 0x5D, 0x12, 0xDB, 0x46, 0xE2, 0x3F, 0xE4, 0x00, 0xE2, 0x23, 0xE0, 0xE1, 0xDE, 0x40,
    0xE6, 0xEE, 0xEC, 0x21, 0xEA, 0xE7, 0xF0, 0x3B, 0x04, 0xF6, 0x58, 0xF6, 0x04, 0xF8, 0xF7, 0x22,
    0xF2, 0x00, 0xF9, 0x46, 0x00, 0xFE, 0x10, 0xF8, 0x8F, 0x5F, 0xBC, 0x0C, 0x00, 0x83, 0x10, 0x5C,
    0x68, 0xF0, 0x83, 0xBF, 0x82, 0xFA, 0x82, 0x0C, 0x98, 0x88, 0x65, 0xE2, 0x80, 0x8A, 0x14, 0x0F,
    0x66, 0xB0, 0x68, 0x84, 0xE3, 0x0F, 0x8F, 0xFE, 0x00, 0x38, 0x82, 0x78, 0x18, 0x32, 0x23, 0x10,
    0x90, 0x28, 0x4D, 0x7A, 0x20, 0x29, 0x12, 0x88, 0x80, 0x97, 0x58, 0x5E, 0x0A, 0x88, 0x09, 0xD3,
    0x21, 0x07, 0x99, 0x46, 0x70, 0xFE, 0xD0, 0x09, 0x00, 0xA7, 0xCD, 0x0D, 0x3E, 0x5D, 0xC2, 0xDC,
    0x39, 0xB4, 0x67, 0xCD, 0x0E, 0x24, 0x25, 0x04, 0x05, 0xC2, 0x25, 0xCB, 0x95, 0x95, 0x50, 0x8D,
    0x60, 0x99, 0xDA, 0x74, 0x2A, 0xD2, 0x9F, 0x46, 0xAA, 0x6A, 0xC5, 0xCA, 0x21, 0x29, 0x8D, 0x3A,
    0x60, 0xCF, 0xF4, 0xF8, 0xC0, 0x87, 0x47, 0xD8, 0x32, 0x6F, 0xAE, 0x7A, 0x28, 0xBB, 0xE3, 0xAC,
    0x99, 0x3C, 0x19, 0xBC, 0x4E, 0x60, 0xAB, 0x63, 0x91, 0x5D, 0x4B, 0x71, 0x41, 0x64, 0xDA, 0x71,
    0x57, 0xD0, 0x24, 0x41, 0x1A, 0xE4, 0x1A, 0xC2, 0xCB, 0x97, 0x52, 0xDF, 0xB1, 0x7A, 0x09, 0xEB,
    0x80, 0xF5, 0xE9, 0x54, 0xAC, 0x0B, 0x82, 0x27, 0xD0, 0xDA, 0xC1, 0x18, 0xD4, 0xA7, 0xBC, 0x21,
    0x26, 0x2F, 0xE6, 0xE4, 0xB8, 0x71, 0xAA, 0xC7, 0x15, 0x22, 0x4B, 0x06, 0xAD, 0x63, 0x99, 0x2E,
    0x61, 0xBC, 0x20, 0x8F, 0xB0, 0xB6, 0xC3, 0xF4, 0x2E, 0x5D, 0xAA, 0x57, 0xA7, 0xAE, 0x75, 0x0B,
    0xF5, 0x69, 0x62, 0xB3, 0x29, 0x88, 0x9E, 0xC0, 0x5A, 0xC7, 0x3B, 0x6E, 0xE5, 0xE8, 0x3D, 0x15,
    0x81, 0xAE, 0x5D, 0xB6, 0xE0, 0xC0, 0xE7, 0x71, 0xB3, 0xB0, 0x7B, 0x42, 0xF1, 0x6B, 0xC7, 0x95,
    0x77, 0x5B, 0xAE, 0xDB, 0xC4, 0xF3, 0x7A, 0xF7, 0x06, 0x66, 0x87, 0xC8, 0xDC, 0x44, 0x42, 0x20,
    0x0C, 0xF5, 0x69, 0x8F, 0x38, 0xA1, 0x39, 0x85, 0xEF, 0x3C, 0xC2, 0xEF, 0x23, 0x3F, 0x7C, 0x04,
    0xFA, 0x1D, 0x29, 0x2F, 0x7E, 0x54, 0x69, 0x9E, 0x42, 0x4B, 0x1E, 0xF1, 0x31, 0x5E, 0x2C, 0x8F,
    0xE2, 0x3E, 0x7C, 0x8A, 0xF3, 0xC9, 0x56, 0x57, 0xD2, 0x7E, 0x56, 0x99, 0xE0, 0x9F, 0x0E, 0x3C,
    0x25, 0x78, 0x54, 0x7D, 0x14, 0x2C, 0xB5, 0x83, 0x82, 0x33, 0x11, 0x35, 0x53, 0x81, 0x26, 0x38,
    0x88, 0x60, 0x51, 0x10, 0xB6, 0x57, 0x82, 0x85, 0x3A, 0x6C, 0x45, 0x95, 0x86, 0xAB, 0x48, 0x05,
    0x05, 0x13, 0x53, 0x3C, 0x51, 0x22, 0x1A, 0xBA, 0x31, 0x28, 0x95, 0x46, 0xCE, 0x10, 0xB1, 0x22,
    0x0D, 0x3E, 0x24, 0x91, 0xC4, 0x8B, 0x37, 0x54, 0x41, 0xA3, 0x0D, 0x5F, 0xDC, 0xA8, 0xE3, 0x8E,
    0x3C, 0xF6, 0xE8, 0xE3, 0x8F, 0x40, 0x06, 0x29, 0xE4, 0x90, 0x52, 0x45, 0x00, 0x00, 0x3B,
};
const uint8_t fmt_il_11[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x5B, 0x10, 0xF0, 0xC0, 0x89, 0x62, 0xF8, 0x0B,
    0xE2, 0x86, 0x48, 0xA4, 0x4F, 0xE2, 0x5B, 0x02, 0x9A, 0xC5, 0x55, 0x73, 0xA7, 0x64, 0x5A, 0x9F,
    0xD7, 0x68, 0xAA, 0xA8, 0xBD, 0x39, 0x01, 0x82, 0x30, 0x36, 0x2C, 0x18, 0x8B, 0x55, 0x3F, 0xB2,
    0x51, 0x9D, 0x16, 0xB7, 0xCB, 0x5B, 0x89, 0x3A, 0xC8, 0x06, 0xBB, 0xED, 0x70, 0x54, 0x71, 0x0E,
    0x1C, 0xF8, 0xB1, 0x7E, 0x03, 0x80, 0x7F, 0x7A, 0x13, 0x81, 0x46, 0x87, 0x3F, 0x89, 0x00, 0x87,
    0x85, 0x12, 0x8D, 0x7D, 0x7F, 0x8A, 0x92, 0x8C, 0x84, 0x26, 0x5A, 0x90, 0x3C, 0x04, 0x9B, 0x58,
    0x9B, 0x04, 0x9D, 0x9C, 0x27, 0x5A, 0x9E, 0x46, 0xA4, 0x3F, 0xA6, 0x00, 0xA4, 0x97, 0x15, 0xAA,
    0x40, 0xA8, 0xAF, 0xA1, 0x25, 0x5D, 0xAD, 0x3C, 0x05, 0xB6, 0x58, 0xB6, 0x05, 0xB8, 0xB7, 0xB2,
    0x16, 0xB9, 0x46, 0xBF, 0x3F, 0xC1, 0x00, 0xBF, 0xBD, 0x15, 0xC5, 0x40, 0xC3, 0xCA, 0xBC, 0x48,
    0x12, 0xCD, 0x00, 0xCF, 0xCD, 0x01, 0xCF, 0x12, 0xC8, 0x3C, 0x06, 0xD8, 0x58, 0xD8, 0x06, 0xDA,
    0xD9, 0x24, 0x5D, 0x12, 0xDB, 0x46, 0xE2, 0x3F, 0xE4, 0x00, 0xE2, 0x23, 0xE0, 0xE1, 0xDE, 0x40,
    0xE6, 0xEE, 0xEC, 0x21, 0xEA, 0xE7, 0xF0, 0x3B, 0x07, 0xF6, 0x58, 0xF6, 0x07, 0xF8, 0xF7, 0x22,
    0xF2, 0x00, 0xF9, 0x46, 0x00, 0xFE, 0x10, 0xF8, 0x8F, 0x5F, 0xBC, 0x0C, 0x00, 0x83, 0x10, 0x5C,
    0x68, 0xF0, 0x83, 0xBF, 0x82, 0xFA, 0x82, 0x20, 0x98, 0x88, 0x65, 0x22, 0x82, 0x8A, 0x14, 0x0F,
    0x66, 0xB0, 0x68, 0x84, 0xE3, 0x0F, 0x8F, 0xFE, 0x00, 0x38, 0x82, 0x78, 0x18, 0x32, 0x23, 0x10,
    0x90, 0x28, 0x4D, 0x7A, 0x20, 0x29, 0x12, 0x48, 0x82, 0x97, 0x58, 0x5E, 0x26, 0x88, 0x09, 0xD3,
    0x21, 0x07, 0x99, 0x46, 0x70, 0xFE, 0xD0, 0x09, 0x00, 0xA7, 0xCD, 0x0D, 0x3E, 0x5D, 0xC2, 0xDC,
    0x39, 0xB4, 0x67, 0xCD, 0x0E, 0x24, 0x25, 0x04, 0x05, 0xC2, 0x25, 0xCB, 0x95, 0x95, 0x50, 0x8D,
    0x60, 0x99, 0xDA, 0x74, 0x2A, 0xD2, 0x9F, 0x46, 0xAA, 0x6A, 0xC5, 0xCA, 0x21, 0x29, 0x8D, 0x3A,
    0x60, 0xCF, 0xF4, 0xF8, 0xC0, 0x87, 0x47, 0xD8, 0x32, 0x6F, 0xAE, 0x7A, 0x28, 0xBB, 0xE3, 0xAC,
    0x99, 0x3C, 0x19, 0xBC, 0x4E, 0x60, 0xAB, 0x63, 0x91, 0x5D, 0x4B, 0x71, 0x41, 0x64, 0xDA, 0x71,
    0x57, 0xD0, 0x24, 0x41, 0x1A, 0xE4, 0x1A, 0xC2, 0xCB, 0x97, 0x52, 0xDF, 0xB1, 0x7A, 0x09, 0xEB,
    0x80, 0xF5, 0xE9, 0x54, 0xAC, 0x0B, 0x82, 0x27, 0xD0, 0xDA, 0xC1, 0x18, 0xD4, 0xA7, 0xBC, 0x21,
    0x26, 0x2F, 0xE6, 0xE4, 0xB8, 0x71, 0xAA, 0xC7, 0x15, 0x22, 0x4B, 0x06, 0xAD, 0x63, 0x99, 0x2E,
    0x61, 0xBC, 0x20, 0x8F, 0xB0, 0xB6, 0xC3, 0xF4, 0x2E, 0x5D, 0xAA, 0x57, 0xA7, 0xAE, 0x75, 0x0B,
    0xF5, 0x69, 0x62, 0xB3, 0x29, 0x88, 0x9E, 0xC0, 0x5A, 0xC7, 0x3B, 0x6E, 0xE5, 0xE8, 0x3D, 0x15,
    0x81, 0xAE, 0x5D, 0xB6, 0xE0, 0xC0, 0xE7, 0x71, 0xB3, 0xB0, 0x7B, 0x42, 0xF1, 0x6B, 0xC7, 0x95,
    0x77, 0x5B, 0xAE, 0xDB, 0xC4, 0xF3, 0x7A, 0xF7, 0x06, 0x66, 0x87, 0xC8, 0xDC, 0x44, 0x42, 0x20,
    0x0C, 0xF5, 0x69, 0x8F, 0x38, 0xA1, 0x39, 0x85, 0xEF, 0x3C, 0xC2, 0xEF, 0x23, 0x3F, 0x7C, 0x04,
    0xFA, 0x1D, 0x29, 0x2F, 0x7E, 0x54, 0x69, 0x9E, 0x42, 0x4B, 0x1E, 0xF1, 0x31, 0x5E, 0x2C, 0x8F,
    0xE2, 0x3E, 0x7C, 0x8A, 0xF3, 0xC9, 0x56, 0x57, 0xD2, 0x7E, 0x56, 0x99, 0xE0, 0x9F, 0x0E, 0x3C,
    0x25, 0x78, 0x54, 0x7D, 0x14, 0x2C, 0xB5, 0x83, 0x82, 0x33, 0x11, 0x35, 0x53, 0x81, 0x26, 0x38,
    0x88, 0x60, 0x51, 0x10, 0xB6, 0x57, 0x82, 0x85, 0x3A, 0x6C, 0x45, 0x95, 0x86, 0xAB, 0x48, 0x05,
    0x05, 0x13, 0x53, 0x3C, 0x51, 0x22, 0x1A, 0xBA, 0x31, 0x28, 0x95, 0x46, 0xCE, 0x10, 0xB1, 0x22,
    0x0D, 0x3E, 0x24, 0x91, 0xC4, 0x8B, 0x37, 0x54, 0x41, 0xA3, 0x0D, 0x5F, 0xDC, 0xA8, 0xE3, 0x8E,
    0x3C, 0xF6, 0xE8, 0xE3, 0x8F, 0x40, 0x06, 0x29, 0xE4, 0x90, 0x52, 0x45, 0x00, 0x00, 0x3B,
};
const uint8_t fmt_il_20[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x5B, 0x10, 0xF0, 0xC0, 0x89, 0x62, 0xF8, 0x0B,
    0xE2, 0x86, 0x48, 0xA4, 0x4F, 0xE2, 0x5B, 0x02, 0x9A, 0xC5, 0x95, 0x53, 0xA7, 0x64, 0x5A, 0x9F,
    0xD7, 0x68, 0xEA, 0xA7, 0xC5, 0x4D, 0x13, 0x60, 0x2C, 0x38, 0x21, 0x0E, 0x6F, 0x01, 0x63, 0x23,
    0x3A, 0xFC, 0x4B, 0xB7, 0xCD, 0xA7, 0x62, 0xDA, 0xE8, 0x5E, 0x93, 0xDF, 0xE4, 0xF8, 0x64, 0x1E,
    0x44, 0xF8, 0xB1, 0x7E, 0x08, 0x80, 0x7F, 0x26, 0x5A, 0x81, 0x6A, 0x87, 0x3F, 0x89, 0x00, 0x87,
    0x25, 0x5D, 0x8D, 0x7D, 0x7F, 0x8A, 0x92, 0x8C, 0x84, 0x23, 0x5D, 0x95, 0x82, 0x46, 0x07, 0x9C,
    0x58, 0x9C, 0x07, 0x9E, 0x9D, 0x97, 0x17, 0x9F, 0x6A, 0xA5, 0x3F, 0xA7, 0x00, 0xA5, 0x22, 0x98,
    0x12, 0xAB, 0x41, 0xA9, 0xB1, 0xA2, 0x20, 0xAD, 0xAE, 0xB3, 0x40, 0x06, 0xB9, 0x58, 0xB9, 0x06,
    0xBB, 0xBA, 0xB4, 0x1A, 0xBC, 0x6A, 0xC2, 0x3F, 0xC4, 0x00, 0xC2, 0x1F, 0xB5, 0x13, 0xC8, 0x41,
    0xC6, 0xCE, 0xBF, 0x48, 0x12, 0xD1, 0x00, 0x55, 0xD3, 0xD3, 0xC7, 0xBF, 0x41, 0x05, 0xDB, 0x58,
    0xDB, 0x05, 0xDD, 0xDC, 0x1D, 0xCA, 0x14, 0xDE, 0x6A, 0xE5, 0x3F, 0xE7, 0x00, 0xE5, 0x1C, 0xE3,
    0xE4, 0xE1, 0xDA, 0xDC, 0xE8, 0xF1, 0xEA, 0xEF, 0x19, 0xED, 0xEE, 0xDF, 0x46, 0x04, 0xFB, 0x58,
    0xFB, 0x04, 0xFD, 0xFC, 0x34, 0xDC, 0xA3, 0xE0, 0x4F, 0x4D, 0xC1, 0x1F, 0x07, 0x01, 0x14, 0xB4,
    0x17, 0x62, 0x61, 0x90, 0x84, 0x10, 0x03, 0x5E, 0x18, 0x58, 0xC1, 0x21, 0x90, 0x01, 0x18, 0xB1,
    0x60, 0x1C, 0xA0, 0x31, 0xE3, 0xC4, 0x11, 0xFE, 0x1B, 0xD5, 0x84, 0xFC, 0x31, 0x12, 0x40, 0x48,
    0x0B, 0x14, 0x2D, 0x9C, 0x0C, 0x52, 0xB2, 0xA5, 0x47, 0x0A, 0x29, 0x55, 0xBE, 0x04, 0x22, 0xA0,
    0x26, 0x96, 0x9A, 0x02, 0x6E, 0xDA, 0x84, 0x69, 0x02, 0xA7, 0x1A, 0x9F, 0x3F, 0x80, 0x02, 0xF0,
    0x39, 0x21, 0xE6, 0x05, 0xA2, 0x41, 0x84, 0x2A, 0xDD, 0x89, 0xE5, 0x04, 0xD2, 0x20, 0x45, 0xA2,
    0x66, 0x29, 0xAA, 0xC2, 0x68, 0x0C, 0x28, 0x4C, 0x9A, 0x64, 0x9D, 0x82, 0xC2, 0xAA, 0x1A, 0x29,
    0x5F, 0x9F, 0x40, 0x19, 0x4B, 0xB6, 0xAC, 0xD9, 0xB3, 0x58, 0xBF, 0x7A, 0x0D, 0xDB, 0x75, 0x6B,
    0x54, 0xAD, 0x2C, 0xB8, 0x42, 0x9D, 0xDA, 0x74, 0x2D, 0x06, 0x2E, 0x5F, 0xEB, 0xE8, 0x85, 0xA3,
    0x87, 0x0F, 0x90, 0xBD, 0x77, 0xEC, 0x9C, 0x11, 0x4C, 0x87, 0x8D, 0x60, 0x3C, 0x6D, 0x25, 0xF8,
    0xE5, 0xB1, 0xA8, 0xB1, 0x25, 0x12, 0x86, 0x1E, 0x33, 0xA6, 0xE4, 0x58, 0x13, 0xE4, 0x0A, 0x90,
    0x80, 0x54, 0x1E, 0x64, 0x99, 0x95, 0x85, 0xCC, 0x3C, 0x64, 0x81, 0x42, 0x75, 0x0B, 0x98, 0x85,
    0x57, 0x40, 0x44, 0x87, 0x02, 0xE5, 0x99, 0x54, 0xE9, 0x1D, 0xAA, 0x49, 0xB3, 0x36, 0xED, 0x7A,
    0x36, 0x2E, 0x5D, 0xC5, 0x70, 0x63, 0xEB, 0x45, 0xFB, 0x02, 0xB3, 0xDB, 0xBD, 0x72, 0x07, 0xDF,
    0xDD, 0xDB, 0x77, 0x36, 0xE0, 0xBE, 0x86, 0x23, 0xB3, 0x36, 0x44, 0x1A, 0x11, 0x6A, 0xCD, 0xA1,
    0x2B, 0x58, 0x76, 0x9C, 0x47, 0xBA, 0xEB, 0xF5, 0x04, 0x76, 0x58, 0x07, 0xEF, 0x9B, 0x3C, 0xEF,
    0xF4, 0xF2, 0xF5, 0xF0, 0xC0, 0x1D, 0x08, 0x76, 0xF0, 0xE5, 0xEF, 0x7E, 0x48, 0xBF, 0x23, 0xE2,
    0x3F, 0x84, 0x12, 0xD5, 0x7F, 0xB0, 0xC8, 0xC3, 0x3D, 0xC0, 0x7F, 0x0C, 0x41, 0xD0, 0x6F, 0xCF,
    0x0F, 0xFE, 0x7B, 0x85, 0xF1, 0x55, 0x6A, 0x60, 0xD5, 0x7E, 0x3A, 0xB8, 0xC4, 0x11, 0x49, 0x33,
    0xF1, 0x24, 0xC2, 0x4A, 0x17, 0x65, 0x84, 0xE0, 0x81, 0x26, 0x25, 0x78, 0xC5, 0x82, 0x12, 0x16,
    0xE8, 0x60, 0x84, 0x10, 0x32, 0x38, 0x21, 0x85, 0x1C, 0x19, 0xB1, 0x54, 0x4E, 0x41, 0x31, 0xB5,
    0xA1, 0x08, 0x4F, 0xF1, 0xF0, 0xA1, 0x4E, 0x39, 0x51, 0xD5, 0x93, 0x88, 0x26, 0xDA, 0x14, 0x22,
    0x88, 0x43, 0x31, 0x65, 0xD7, 0x04, 0x25, 0xF2, 0x20, 0x55, 0x5D, 0x13, 0xCE, 0xA8, 0xA0, 0x1A,
    0x69, 0xF5, 0x08, 0xD7, 0x60, 0x62, 0xB1, 0x55, 0x43, 0x14, 0x55, 0x08, 0x79, 0x55, 0x12, 0x49,
    0x18, 0x49, 0x43, 0x91, 0x4A, 0xCA, 0x20, 0x57, 0x93, 0x50, 0x46, 0x29, 0xE5, 0x94, 0x1E, 0x44,
    0x00, 0x00, 0x3B,
};
const uint8_t fmt_il_21[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x5B, 0x10, 0xF0, 0xC0, 0x89, 0x62, 0xF8, 0x0B,
    0xE2, 0x86, 0x48, 0xA4, 0x4F, 0xE2, 0x5B, 0x02, 0x9A, 0xC5, 0x95, 0x53, 0xA7, 0x64, 0x5A, 0x9F,
    0xD7, 0x68, 0xEA, 0xA7, 0xC5, 0x4D, 0x05, 0x60, 0x2C, 0x58, 0x20, 0x0E, 0x6F, 0x01, 0x63, 0x23,
    0x3A, 0xFC, 0x4B, 0xB7, 0xCD, 0xA7, 0x62, 0xDA, 0xE8, 0x5E, 0x93, 0xDF, 0xE4, 0xF8, 0x64, 0x1E,
    0x1C, 0xF8, 0xB1, 0x7E, 0x03, 0x80, 0x7F, 0x26, 0x5A, 0x81, 0x6A, 0x87, 0x3F, 0x89, 0x00, 0x87,
    0x25, 0x5D, 0x8D, 0x7D, 0x7F, 0x8A, 0x92, 0x8C, 0x84, 0x23, 0x5D, 0x95, 0x82, 0x46, 0x04, 0x9C,
    0x58, 0x9C, 0x04, 0x9E, 0x9D, 0x97, 0x17, 0x9F, 0x6A, 0xA5, 0x3F, 0xA7, 0x00, 0xA5, 0x22, 0x98,
    0x12, 0xAB, 0x41, 0xA9, 0xB1, 0xA2, 0x20, 0xAD, 0xAE, 0xB3, 0x40, 0x05, 0xB9, 0x58, 0xB9, 0x05,
    0xBB, 0xBA, 0xB4, 0x1A, 0xBC, 0x6A, 0xC2, 0x3F, 0xC4, 0x00, 0xC2, 0x1F, 0xB5, 0x13, 0xC8, 0x41,
    0xC6, 0xCE, 0xBF, 0x48, 0x12, 0xD1, 0x00, 0x55, 0xD3, 0xD3, 0xC7, 0xBF, 0x41, 0x06, 0xDB, 0x58,
    0xDB, 0x06, 0xDD, 0xDC, 0x1D, 0xCA, 0x14, 0xDE, 0x6A, 0xE5, 0x3F, 0xE7, 0x00, 0xE5, 0x1C, 0xE3,
    0xE4, 0xE1, 0xDA, 0xDC, 0xE8, 0xF1, 0xEA, 0xEF, 0x19, 0xED, 0xEE, 0xDF, 0x46, 0x07, 0xFB, 0x58,
    0xFB, 0x07, 0xFD, 0xFC, 0x34, 0xDC, 0xA3, 0xE0, 0x4F, 0x4D, 0xC1, 0x1F, 0x07, 0x01, 0x14, 0xB4,
    0x17, 0x62, 0x61, 0x90, 0x84, 0x10, 0x03, 0x5E, 0x18, 0x58, 0xC1, 0x21, 0x10, 0x04, 0x18, 0xB1,
    0x60, 0x44, 0xA0, 0x31, 0xE3, 0xC4, 0x11, 0xFE, 0x1B, 0xD5, 0x84, 0xFC, 0x31, 0x12, 0x40, 0x48,
    0x0B, 0x14, 0x2D, 0x9C, 0x0C, 0x52, 0xB2, 0xA5, 0x47, 0x0A, 0x29, 0x55, 0xBE, 0x04, 0x92, 0xA0,
    0x26, 0x96, 0x9A, 0x09, 0x6E, 0xDA, 0x84, 0x69, 0x02, 0xA7, 0x1A, 0x9F, 0x3F, 0x80, 0x02, 0xF0,
    0x39, 0x21, 0xE6, 0x05, 0xA2, 0x41, 0x84, 0x2A, 0xDD, 0x89, 0xE5, 0x04, 0xD2, 0x20, 0x45, 0xA2,
    0x66, 0x29, 0xAA, 0xC2, 0x68, 0x0C, 0x28, 0x4C, 0x9A, 0x64, 0x9D, 0x82, 0xC2, 0xAA, 0x1A, 0x29,
    0x5F, 0x9F, 0x40, 0x19, 0x4B, 0xB6, 0xAC, 0xD9, 0xB3, 0x58, 0xBF, 0x7A, 0x0D, 0xDB, 0x75, 0x6B,
    0x54, 0xAD, 0x2C, 0xB8, 0x42, 0x9D, 0xDA, 0x74, 0x2D, 0x06, 0x2E, 0x5F, 0xEB, 0xE8, 0x85, 0xA3,
    0x87, 0x0F, 0x90, 0xBD, 0x77, 0xEC, 0x9C, 0x11, 0x4C, 0x87, 0x8D, 0x60, 0x3C, 0x6D, 0x25, 0xF8,
    0xE5, 0xB1, 0xA8, 0xB1, 0x25, 0x12, 0x86, 0x1E, 0x33, 0xA6, 0xE4, 0x58, 0x13, 0xE4, 0x0A, 0x90,
    0x80, 0x54, 0x1E, 0x64, 0x99, 0x95, 0x85, 0xCC, 0x3C, 0x64, 0x81, 0x42, 0x75, 0x0B, 0x98, 0x85,
    0x57, 0x40, 0x44, 0x87, 0x02, 0xE5, 0x99, 0x54, 0xE9, 0x1D, 0xAA, 0x49, 0xB3, 0x36, 0xED, 0x7A,
    0x36, 0x2E, 0x5D, 0xC5, 0x70, 0x63, 0xEB, 0x45, 0xFB, 0x02, 0xB3, 0xDB, 0xBD, 0x72, 0x07, 0xDF,
    0xDD, 0xDB, 0x77, 0x36, 0xE0, 0xBE, 0x86, 0x23, 0xB3, 0x36, 0x44, 0x1A, 0x11, 0x6A, 0xCD, 0xA1,
    0x2B, 0x58, 0x76, 0x9C, 0x47, 0xBA, 0xEB, 0xF5, 0x04, 0x76, 0x58, 0x07, 0xEF, 0x9B, 0x3C, 0xEF,
    0xF4, 0xF2, 0xF5, 0xF0, 0xC0, 0x1D, 0x08, 0x76, 0xF0, 0xE5, 0xEF, 0x7E, 0x48, 0xBF, 0x23, 0xE2,
    0x3F, 0x84, 0x12, 0xD5, 0x7F, 0xB0, 0xC8, 0xC3, 0x3D, 0xC0, 0x7F, 0x0C, 0x41, 0xD0, 0x6F, 0xCF,
    0x0F, 0xFE, 0x7B, 0x85, 0xF1, 0x55, 0x6A, 0x60, 0xD5, 0x7E, 0x3A, 0xB8, 0xC4, 0x11, 0x49, 0x33,
    0xF1, 0x24, 0xC2, 0x4A, 0x17, 0x65, 0x84, 0xE0, 0x81, 0x26, 0x25, 0x78, 0xC5, 0x82, 0x12, 0x16,
    0xE8, 0x60, 0x84, 0x10, 0x32, 0x38, 0x21, 0x85, 0x1C, 0x19, 0xB1, 0x54, 0x4E, 0x41, 0x31, 0xB5,
    0xA1, 0x08, 0x4F, 0xF1, 0xF0, 0xA1, 0x4E, 0x39, 0x51, 0xD5, 0x93, 0x88, 0x26, 0xDA, 0x14, 0x22,
    0x88, 0x43, 0x31, 0x65, 0xD7, 0x04, 0x25, 0xF2, 0x20, 0x55, 0x5D, 0x13, 0xCE, 0xA8, 0xA0, 0x1A,
    0x69, 0xF5, 0x08, 0xD7, 0x60, 0x62, 0xB1, 0x55, 0x43, 0x14, 0x55, 0x08, 0x79, 0x55, 0x12, 0x49,
    0x18, 0x49, 0x43, 0x91, 0x4A, 0xCA, 0x20, 0x57, 0x93, 0x50, 0x46, 0x29, 0xE5, 0x94, 0x1E, 0x44,
    0x00, 0x00, 0x3B,
};
const uint8_t fmt_il_30[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x9A, 0xC2, 0xFF, 0x14, 0x1F, 0x10, 0x28, 0x1C,
    0xEA, 0x02, 0x8A, 0x64, 0xC0, 0x98, 0x43, 0x2A, 0x99, 0xB9, 0x64, 0x11, 0x6A, 0x43, 0x2E, 0xA9,
    0xB8, 0x29, 0xB6, 0xB6, 0x4C, 0x78, 0x11, 0xE0, 0x83, 0xD8, 0x40, 0x2E, 0x98, 0x09, 0xE8, 0x81,
    0x5A, 0xC0, 0xBE, 0x78, 0x13, 0x60, 0x84, 0xF8, 0x40, 0x36, 0x98, 0x0B, 0x68, 0x82, 0x7A, 0xC0,
    0x16, 0x70, 0x03, 0x6F, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7D, 0x01, 0x4B, 0x89, 0x89, 0x81,
    0x61, 0x63, 0x65, 0x67, 0x69, 0x6B, 0x6C, 0x89, 0x35, 0x8D, 0x72, 0x8F, 0x76, 0x91, 0x7A, 0x93,
    0x7E, 0x8A, 0x13, 0x97, 0x83, 0x90, 0x78, 0x92, 0x7C, 0x6D, 0x57, 0x5B, 0x17, 0x9F, 0x2B, 0xA8,
    0x30, 0x8B, 0xAF, 0xB0, 0xB1, 0xB2, 0x8B, 0x00, 0x8A, 0xB3, 0xB7, 0xB8, 0x33, 0xAD, 0x28, 0xAB,
    0xA9, 0x16, 0x5D, 0x5F, 0x8E, 0x74, 0xA3, 0x86, 0x9D, 0x13, 0x9F, 0xA1, 0x99, 0x85, 0xA5, 0x7D,
    0x7F, 0xC9, 0xC3, 0x9A, 0xA4, 0x9C, 0xA6, 0x02, 0x95, 0xB6, 0xCF, 0x84, 0x9B, 0x87, 0x94, 0xBB,
    0x30, 0xD8, 0xC4, 0xCC, 0xA7, 0xB5, 0xA0, 0xC1, 0x98, 0xD0, 0xCB, 0xD3, 0xCD, 0xDD, 0xBE, 0xE3,
    0xEB, 0x25, 0xEE, 0xAC, 0xB8, 0xF2, 0xB1, 0xED, 0xF3, 0xF6, 0x95, 0x32, 0xF0, 0x23, 0xBD, 0xEC,
    0xC7, 0x00, 0xDF, 0xD1, 0x8A, 0x51, 0xF3, 0x07, 0x0C, 0x8E, 0xB0, 0x6C, 0xD2, 0xB6, 0xF9, 0xA1,
    0xC1, 0xA8, 0x9C, 0xA8, 0x80, 0xE1, 0xAA, 0x7D, 0x6A, 0x68, 0xD0, 0x1C, 0x42, 0x81, 0x88, 0xF4,
    0xAD, 0x00, 0x88, 0x4E, 0x61, 0x3B, 0x72, 0xEC, 0x15, 0x1F, 0x76, 0x34, 0xA6, 0x91, 0x0A, 0x3F,
    0x5E, 0xFD, 0x2A, 0x9C, 0x3C, 0x51, 0x92, 0x86, 0x16, 0x55, 0x12, 0x5A, 0x02, 0x78, 0xF9, 0x8B,
    0x09, 0x4D, 0x0A, 0xA8, 0x64, 0xDE, 0xF4, 0x67, 0x53, 0x43, 0x2B, 0x9D, 0x3E, 0x53, 0xF2, 0x1C,
    0xFA, 0x4E, 0x68, 0xCC, 0x9A, 0x26, 0x64, 0xDE, 0xA0, 0xB9, 0x0E, 0x28, 0x52, 0x2C, 0x2F, 0xDD,
    0x39, 0xC5, 0xE9, 0x4B, 0x0B, 0xBC, 0xA9, 0x47, 0x8D, 0xEA, 0x53, 0x4A, 0x55, 0xEB, 0x06, 0xAE,
    0x59, 0xD9, 0x09, 0x29, 0xE9, 0x14, 0xAC, 0x0E, 0x1F, 0x2D, 0x81, 0x9A, 0x3D, 0x2B, 0x53, 0xE7,
    0xDA, 0x23, 0x1F, 0xDA, 0x1A, 0x1D, 0x17, 0xB7, 0xC3, 0xDB, 0x26, 0x33, 0xEB, 0x7E, 0xCD, 0x9B,
    0xF2, 0xCA, 0xCE, 0xA7, 0x18, 0xFC, 0xF6, 0x9D, 0xF0, 0x57, 0x65, 0x50, 0x09, 0x85, 0x81, 0xBC,
    0xBD, 0x3A, 0xF7, 0xAE, 0xD4, 0xC6, 0x16, 0x12, 0x13, 0x9D, 0xCC, 0x17, 0xCB, 0x3A, 0xC9, 0x61,
    0x29, 0x57, 0x86, 0xE2, 0x0E, 0x33, 0x5D, 0xCD, 0x9B, 0x8D, 0xDC, 0xED, 0x9A, 0xB9, 0xDF, 0x68,
    0xD2, 0xA7, 0xAB, 0xB0, 0x2A, 0xCD, 0xAE, 0xA0, 0x20, 0x65, 0xDA, 0x8C, 0x1D, 0x75, 0x7D, 0x10,
    0x5C, 0xBA, 0x36, 0x0C, 0x01, 0x39, 0x84, 0x9D, 0xB0, 0xD3, 0xAB, 0x5A, 0xBA, 0x43, 0xF2, 0xC6,
    0xC8, 0x0D, 0x5F, 0x0C, 0x8E, 0xB1, 0x07, 0x5A, 0x40, 0xDE, 0x5B, 0x79, 0xE8, 0xB9, 0x2B, 0x3C,
    0x43, 0x07, 0x21, 0x7D, 0x3A, 0x07, 0x27, 0x0A, 0x52, 0x5B, 0xAF, 0x25, 0x45, 0xFB, 0x76, 0x29,
    0xDB, 0x55, 0x58, 0x09, 0xAF, 0xA2, 0x3A, 0xF9, 0xF3, 0xE8, 0xD3, 0xAB, 0x5F, 0xCF, 0xBE, 0xBD,
    0xFB, 0x11, 0x11, 0x00, 0x00, 0x3B,
};
const uint8_t fmt_il_31[] = {
    0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x5E, 0x00, 0x4E, 0x00, 0xE3, 0x0B, 0x00, 0xEC, 0xD6, 0xC0,
    0x80, 0x80, 0x80, 0x0F, 0x32, 0xE8, 0x2E, 0x32, 0xC9, 0x4D, 0x32, 0xAA, 0x6C, 0x32, 0x8B, 0x8B,
    0x32, 0x6C, 0xAA, 0x32, 0x4D, 0xC9, 0x32, 0x2E, 0xE8, 0x32, 0x0F, 0x00, 0x00, 0x00, 0xE8, 0xDF,
    0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0xE8, 0xDF, 0xDF, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x5E, 0x00, 0x4E, 0x00, 0x00, 0x04, 0xFE, 0x10, 0xC8, 0x49, 0xAB, 0xBD, 0x38, 0xEB,
    0xCD, 0xBB, 0xFF, 0x60, 0x28, 0x8E, 0x64, 0x69, 0x9E, 0x68, 0xAA, 0xAE, 0x6C, 0xEB, 0xBE, 0x70,
    0x2C, 0xCF, 0x74, 0x6D, 0xDF, 0x78, 0xAE, 0xEF, 0x9A, 0xC2, 0xFF, 0x14, 0x1F, 0x10, 0x28, 0x1C,
    0xEA, 0x02, 0x8A, 0x64, 0xC0, 0x98, 0x43, 0x2A, 0x99, 0xB9, 0x64, 0x11, 0x6A, 0x43, 0x2E, 0xA9,
    0xB8, 0x29, 0xB6, 0xB6, 0x14, 0x78, 0x07, 0x60, 0x82, 0xB8, 0x40, 0x36, 0x98, 0x0F, 0x68, 0x84,
    0x3A, 0xC1, 0xBE, 0x78, 0x05, 0xE0, 0x81, 0x98, 0x40, 0x2E, 0x98, 0x0D, 0xE8, 0x83, 0x1A, 0xC1,
    0x4E, 0x70, 0x03, 0x6F, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7D, 0x01, 0x4B, 0x89, 0x89, 0x81,
    0x61, 0x63, 0x65, 0x67, 0x69, 0x6B, 0x6C, 0x89, 0x35, 0x8D, 0x72, 0x8F, 0x76, 0x91, 0x7A, 0x93,
    0x7E, 0x8A, 0x13, 0x97, 0x83, 0x90, 0x78, 0x92, 0x7C, 0x6D, 0x57, 0x5B, 0x17, 0x9F, 0x2B, 0xA8,
    0x30, 0x8B, 0xAF, 0xB0, 0xB1, 0xB2, 0x8B, 0x00, 0x8A, 0xB3, 0xB7, 0xB8, 0x33, 0xAD, 0x28, 0xAB,
    0xA9, 0x16, 0x5D, 0x5F, 0x8E, 0x74, 0xA3, 0x86, 0x9D, 0x13, 0x9F, 0xA1, 0x99, 0x85, 0xA5, 0x7D,
    0x7F, 0xC9, 0xC3, 0x9A, 0xA4, 0x9C, 0xA6, 0x09, 0x95, 0xB6, 0xCF, 0x84, 0x9B, 0x87, 0x94, 0xBB,
    0x30, 0xD8, 0xC4, 0xCC, 0xA7, 0xB5, 0xA0, 0xC1, 0x98, 0xD0, 0xCB, 0xD3, 0xCD, 0xDD, 0xBE, 0xE3,
    0xEB, 0x25, 0xEE, 0xAC, 0xB8, 0xF2, 0xB1, 0xED, 0xF3, 0xF6, 0x95, 0x32, 0xF0, 0x23, 0xBD, 0xEC,
    0xC7, 0x00, 0xDF, 0xD1, 0x8A, 0x51, 0xF3, 0x07, 0x0C, 0x8E, 0xB0, 0x6C, 0xD2, 0xB6, 0xF9, 0xA1,
    0xC1, 0xA8, 0x9C, 0xA8, 0x80, 0xE1, 0xAA, 0x7D, 0x6A, 0x68, 0xD0, 0x1C, 0x42, 0x81, 0x88, 0xF4,
    0xAD, 0x00, 0x88, 0x4E, 0x61, 0x3B, 0x72, 0xEC, 0x15, 0x1F, 0x76, 0x34, 0xA6, 0x91, 0x0A, 0x3F,
    0x5E, 0xFD, 0x2A, 0x9C, 0x3C, 0x51, 0x92, 0x86, 0x16, 0x55, 0x12, 0x5A, 0x02, 0x78, 0xF9, 0x8B,
    0x09, 0x4D, 0x0A, 0xA8, 0x64, 0xDE, 0xF4, 0x67, 0x53, 0x43, 0x2B, 0x9D, 0x3E, 0x53, 0xF2, 0x1C,
    0xFA, 0x4E, 0x68, 0xCC, 0x9A, 0x26, 0x64, 0xDE, 0xA0, 0xB9, 0x0E, 0x28, 0x52, 0x2C, 0x2F, 0xDD,
    0x39, 0xC5, 0xE9, 0x4B, 0x0B, 0xBC, 0xA9, 0x47, 0x8D, 0xEA, 0x53, 0x4A, 0x55, 0xEB, 0x06, 0xAE,
    0x59, 0xD9, 0x09, 0x29, 0xE9, 0x14, 0xAC, 0x0E, 0x1F, 0x2D, 0x81, 0x9A, 0x3D, 0x2B, 0x53, 0xE7,
    0xDA, 0x23, 0x1F, 0xDA, 0x1A, 0x1D, 0x17, 0xB7, 0xC3, 0xDB, 0x26, 0x33, 0xEB, 0x7E, 0xCD, 0x9B,
    0xF2, 0xCA, 0xCE, 0xA7, 0x18, 0xFC, 0xF6, 0x9D, 0xF0, 0x57, 0x65, 0x50, 0x09, 0x85, 0x81, 0xBC,
    0xBD, 0x3A, 0xF7, 0xAE, 0xD4, 0xC6, 0x16, 0x12, 0x13, 0x9D, 0xCC, 0x17, 0xCB, 0x3A, 0xC9, 0x61,
    0x29, 0x57, 0x86, 0xE2, 0x0E, 0x33, 0x5D, 0xCD, 0x9B, 0x8D, 0xDC, 0xED, 0x9A, 0xB9, 0xDF, 0x68,
    0xD2, 0xA7, 0xAB, 0xB0, 0x2A, 0xCD, 0xAE, 0xA0, 0x20, 0x65, 0xDA, 0x8C, 0x1D, 0x75, 0x7D, 0x10,
    0x5C, 0xBA, 0x36, 0x0C, 0x01, 0x39, 0x84, 0x9D, 0xB0, 0xD3, 0xAB, 0x5A, 0xBA, 0x43, 0xF2, 0xC6,
    0xC8, 0x0D, 0x5F, 0x0C, 0x8E, 0xB1, 0x07, 0x5A, 0x40, 0xDE, 0x5B, 0x79, 0xE8, 0xB9, 0x2B, 0x3C,
    0x43, 0x07, 0x21, 0x7D, 0x3A, 0x07, 0x27, 0x0A, 0x52, 0x5B, 0xAF, 0x25, 0x45, 0xFB, 0x76, 0x29,
    0xDB, 0x55, 0x58, 0x09, 0xAF, 0xA2, 0x3A, 0xF9, 0xF3, 0xE8, 0xD3, 0xAB, 0x5F, 0xCF, 0xBE, 0xBD,
    0xFB, 0x11, 0x11, 0x00, 0x00, 0x3B,
};

const uint8_t* fmt_il_list[] = {
    fmt_il_00,
    fmt_il_01,
    fmt_il_10,
    fmt_il_11,
    fmt_il_20,
    fmt_il_21,
    fmt_il_30,
    fmt_il_31,
};

const size_t fmt_il_list_len[] = {
    sizeof(fmt_il_00),
    sizeof(fmt_il_01),
    sizeof(fmt_il_10),
    sizeof(fmt_il_11),
    sizeof(fmt_il_20),
    sizeof(fmt_il_21),
    sizeof(fmt_il_30),
    sizeof(fmt_il_31),
};