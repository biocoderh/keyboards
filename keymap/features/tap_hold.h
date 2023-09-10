// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#pragma once

#include QMK_KEYBOARD_H
#include "common.h"

typedef struct {
    bool process;
    uint16_t keycode;
    uint16_t timer;
} tap_hold_state_t;

tap_hold_state_t tap_hold_state;

static inline uint16_t tap_hold_elapsed(void) {
    return timer_elapsed(tap_hold_state.timer);
}

bool tap_hold_press(uint16_t keycode, keyrecord_t *record, uint16_t term);

bool process_tap_hold(uint16_t keycode, keyrecord_t *record, uint16_t holdKeycode, uint16_t term);
bool process_tap_hold_two(uint16_t keycode, keyrecord_t *record,
    uint16_t holdKeycode1, uint16_t term1,
    uint16_t holdKeycode2, uint16_t term2
);

bool process_tap_hold_layer(uint16_t keycode, keyrecord_t *record, uint16_t layer, uint16_t term);
