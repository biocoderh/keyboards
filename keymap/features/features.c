// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#include "features.h"

#ifdef AUTO_SHIFT_ENABLE
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
#if defined(RETRO_SHIFT) && !defined(NO_ACTION_TAPPING)
    if (IS_RETRO(keycode)) keycode = get_basic_keycode(keycode);
#endif

    switch (keycode) {
#ifndef NO_AUTO_SHIFT_ALPHA
        case AUTO_SHIFT_ALPHA:
#endif
#ifndef NO_AUTO_SHIFT_NUMERIC
        case AUTO_SHIFT_NUMERIC:
#endif
#ifndef NO_AUTO_SHIFT_SPECIAL
#    ifndef NO_AUTO_SHIFT_TAB
        case KC_TAB:
#    endif
#    ifndef NO_AUTO_SHIFT_SYMBOLS
        case AUTO_SHIFT_SYMBOLS:
#    endif
#endif
#ifdef AUTO_SHIFT_ENTER
        case KC_ENT:
#endif
            return true;
    }

    return (
#if defined(OS_KEYS_ENABLE) && defined(OS_KEYS_AUTO_SHIFT)
        os_keys_auto_shifted_key(keycode) ||
#endif
        get_custom_auto_shifted_key(keycode, record)
    );
}
#endif // AUTO_SHIFT_ENABLE
