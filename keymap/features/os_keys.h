// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#pragma once

#include QMK_KEYBOARD_H
#include "common.h"

#ifndef OS_KEYS_WIN_UNDO
#   define OS_KEYS_WIN_UNDO C(KC_Z)
#endif
#ifndef OS_KEYS_WIN_CUT
#   define OS_KEYS_WIN_CUT C(KC_X)
#endif
#ifndef OS_KEYS_WIN_COPY
#   define OS_KEYS_WIN_COPY C(KC_C)
#endif
#ifndef OS_KEYS_WIN_PASTE
#   define OS_KEYS_WIN_PASTE C(KC_V)
#endif
#ifndef OS_KEYS_WIN_AGIN
#   define OS_KEYS_WIN_AGIN C(KC_Y)
#endif

#ifndef OS_KEYS_MAC_UNDO
#   define OS_KEYS_MAC_UNDO LCMD(KC_Z)
#endif
#ifndef OS_KEYS_MAC_CUT
#   define OS_KEYS_MAC_CUT LCMD(KC_X)
#endif
#ifndef OS_KEYS_MAC_COPY
#   define OS_KEYS_MAC_COPY LCMD(KC_C)
#endif
#ifndef OS_KEYS_MAC_PASTE
#   define OS_KEYS_MAC_PASTE LCMD(KC_V)
#endif
#ifndef OS_KEYS_MAC_AGIN
#   define OS_KEYS_MAC_AGIN SCMD(KC_Z)
#endif

#ifdef AUTO_SHIFT_ENABLE
static inline bool os_keys_auto_shifted_key(uint16_t keycode) {
# ifdef OS_KEYS_AUTO_SHIFT
    switch (keycode) {
        case OS_KEYS_WIN_UNDO:
        case OS_KEYS_WIN_CUT:
        case OS_KEYS_WIN_COPY:
        case OS_KEYS_WIN_PASTE:
        case OS_KEYS_WIN_AGIN:
        case OS_KEYS_MAC_UNDO:
        case OS_KEYS_MAC_CUT:
        case OS_KEYS_MAC_COPY:
        case OS_KEYS_MAC_PASTE:
        case OS_KEYS_MAC_AGIN:
            return true;
    }
# endif // OS_KEYS_AUTO_SHIFT
    return false;
}
#endif // AUTO_SHIFT_ENABLE

bool process_os_keys(uint16_t keycode, keyrecord_t *record);
