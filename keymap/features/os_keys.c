// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#include "os_keys.h"

bool process_os_keys(uint16_t keycode, keyrecord_t *record) {
    switch(get_os_variant()) {
        case OS_UNSURE: break;
        case OS_LINUX: break;
        case OS_WINDOWS:
            switch(keycode) {
                case KC_UNDO: return process_key(OS_KEYS_WIN_UNDO, record);
                case KC_CUT: return process_key(OS_KEYS_WIN_CUT, record);
                case KC_COPY: return process_key(OS_KEYS_WIN_COPY, record);
                case KC_PASTE: return process_key(OS_KEYS_WIN_PASTE, record);
                case KC_AGIN: return process_key(OS_KEYS_WIN_AGIN, record);
            }
            break;
        case OS_MACOS:
            switch(keycode) {
                case KC_UNDO: return process_key(OS_KEYS_MAC_UNDO, record);
                case KC_CUT: return process_key(OS_KEYS_MAC_CUT, record);
                case KC_COPY: return process_key(OS_KEYS_MAC_COPY, record);
                case KC_PASTE: return process_key(OS_KEYS_MAC_PASTE, record);
                case KC_AGIN: return process_key(OS_KEYS_MAC_AGIN, record);
            }
            break;
        case OS_IOS: break;
    }

    return true;
}
