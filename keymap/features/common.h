// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#pragma once

#include QMK_KEYBOARD_H

#ifdef OS_DETECTION_ENABLE
#   include "os_detection.h"
#elif
typedef enum {
    OS_UNSURE,
    OS_LINUX,
    OS_WINDOWS,
    OS_MACOS,
    OS_IOS,
} os_variant_t;
#endif

os_variant_t get_os_variant(void);

uint8_t get_basic_keycode(uint16_t keycode);

bool process_in_loop;

bool process_key(uint16_t keycode, keyrecord_t *record);
bool process_tap(uint16_t keycode, keyrecord_t *record);
