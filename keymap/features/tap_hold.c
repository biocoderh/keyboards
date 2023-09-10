// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#include "tap_hold.h"

// return true if hold
bool tap_hold_press(uint16_t keycode, keyrecord_t *record, uint16_t term) {
    if (record->event.pressed) {
        tap_hold_state.process = true;
        tap_hold_state.keycode = keycode;
        tap_hold_state.timer = record->event.time;
    } else if (tap_hold_state.process && tap_hold_state.keycode == keycode) {
        tap_hold_state.process = false;

        if (tap_hold_elapsed() < term) {
            process_tap(keycode, record);
        } else {
            return true;
        }
    }

    return false;
}

bool process_tap_hold(uint16_t keycode, keyrecord_t *record, uint16_t holdKeycode, uint16_t term) {
    if (tap_hold_press(keycode, record, term)) {
        process_tap(holdKeycode, record);
    }

    return false;
}

bool process_tap_hold_two(uint16_t keycode, keyrecord_t *record,
    uint16_t holdKeycode1, uint16_t term1,
    uint16_t holdKeycode2, uint16_t term2
) {
    if (tap_hold_press(keycode, record, term1)) {
        if (tap_hold_elapsed() < term2) {
            process_tap(holdKeycode1, record);
        } else  {
            process_tap(holdKeycode2, record);
        }
    }

    return false;
}

bool process_tap_hold_layer(uint16_t keycode, keyrecord_t *record, uint16_t layer, uint16_t term) {
    if (tap_hold_press(keycode, record, term)) {
        if (IS_LAYER_ON(layer)) {
            layer_clear();
        } else {
            layer_move(layer);
        }
    }

    return false;
}
