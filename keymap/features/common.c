// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#include "common.h"

os_variant_t get_os_variant(void) {
#ifdef WINDOWS
    return OS_WINDOWS;
#endif
#ifdef MACOS
    return OS_MACOS;
#endif
#ifdef OS_DETECTION_ENABLE
    return detected_host_os();
#endif

    return OS_UNSURE;
}

uint8_t get_basic_keycode(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode)) {
        return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode)) {
        return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    return QK_MODS_GET_BASIC_KEYCODE(keycode);
}

bool process_key(uint16_t keycode, keyrecord_t *record) {
    process_in_loop = true;
#if defined(COMBO_ENABLE) || defined(REPEAT_KEY_ENABLE)
    record->keycode = keycode;
#endif
    process_record(record);
    process_in_loop = false;

    return false;
}

bool process_tap(uint16_t keycode, keyrecord_t *record) {
    record->event.pressed = true;
    process_key(keycode, record);
    record->event.pressed = false;
    return process_key(keycode, record);
}
