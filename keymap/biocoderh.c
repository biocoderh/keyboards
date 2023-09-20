// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#include "biocoderh.h"
#include "custom.c"

#ifdef AUTO_SHIFT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    if (layer == L_GAME0 || layer == L_GAME1) {
        autoshift_disable();
    } else {
        autoshift_enable();
    }

    return state;
}
#endif // AUTO_SHIFT_ENABLE


#ifdef LEADER_ENABLE
void leader_start_user(void) {}
void leader_end_user(void) { custom_leader(); }
#endif // LEADER_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (process_in_loop) return true;

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
        keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count
    );
#endif

    if (IS_LAYER_ON(L_GAME0) || IS_LAYER_ON(L_GAME1)) return true;

#ifdef LEADER_ENABLE
    if (leader_sequence_active()) return true;
#endif

    if (IS_USER_KEYCODE(keycode)) {
        custom_user(keycode, record);
        return false;
    }

    // fix for mod-tap shifted keys
    if (record->tap.count && record->event.pressed) {
        switch(keycode) {
            case LSFT_T(KC_LPRN):
                tap_code16(KC_LPRN);
                return false;
            case RSFT_T(KC_RPRN):
                tap_code16(KC_RPRN);
                return false;
        }
    }

#ifdef OS_KEYS_ENABLE
    if (!process_os_keys(keycode, record)) return false;
#endif

#ifdef TAP_HOLD_ENABLE
    switch(keycode) {
        case TH_CAPS: return process_tap_hold_two(keycode, record, CW_TOGG, TAP_HOLD_CAPS_WORD_TERM, KC_CAPS, TAP_HOLD_CAPS_LOCK_TERM);
        case TH_LEAD: return process_tap_hold(keycode, record, QK_LEAD, TAP_HOLD_LEADER_TERM);
        case KC_WAKE: return process_tap_hold_two(keycode, record, KC_SLEP, TAP_HOLD_SLEEP_TERM, KC_PWR, TAP_HOLD_PWR_TERM);
    }

    switch (keycode_at_keymap_location(L_BASE, record->event.key.row, record->event.key.col)) {
        case TH_BASE_L:
        case TH_BASE_R:
            return process_tap_hold_layer(keycode, record, L_BASE, TAP_HOLD_LAYER_TERM);

        case TH_NUM: return process_tap_hold_layer(keycode, record, L_NUM, TAP_HOLD_LAYER_TERM);
        case TH_SYM: return process_tap_hold_layer(keycode, record, L_SYM, TAP_HOLD_LAYER_TERM);
        case TH_MOUSE: return process_tap_hold_layer(keycode, record, L_MOUSE, TAP_HOLD_LAYER_TERM);
        case TH_FN: return process_tap_hold_layer(keycode, record, L_FN, TAP_HOLD_LAYER_TERM);
        case TH_PROG: return process_tap_hold_layer(keycode, record, L_PROG, TAP_HOLD_LAYER_TERM);
        case TH_MACRO: return process_tap_hold_layer(keycode, record, L_MACRO, TAP_HOLD_LAYER_TERM);
        case TH_GAME: return process_tap_hold_layer(keycode, record, L_GAME0, TAP_HOLD_LAYER_TERM);

        case TH_BOOT_L:
        case TH_BOOT_R:
            return process_tap_hold_two(keycode, record, QK_BOOT, TAP_HOLD_BOOT_TERM, QK_REBOOT, TAP_HOLD_REBOOT_TERM);
    }
#endif // TAP_HOLD_ENABLE

    return true;
}
