// Copyright 2023 Biocoder <biocoder.h@gmail.com>

#include QMK_KEYBOARD_H

#define _QWERTY 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_4x6_5(
        KC_ESC , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_CAPS, KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,

                                                KC_LGUI, KC_LCTL, KC_LALT,       KC_RALT, KC_RCTL, KC_RGUI,
                                                          KC_BSPC, KC_DEL,       KC_ENT, KC_SPACE
    ),
    [1] = LAYOUT_split_4x6_5(
        KC_ESC , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_CAPS, KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,

                                                KC_LGUI, KC_LCTL, KC_LALT,       KC_RALT, KC_RCTL, KC_RGUI,
                                                          KC_BSPC, KC_DEL,       KC_ENT, KC_SPACE
    ),
    [2] = LAYOUT_split_4x6_5(
        KC_ESC , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_CAPS, KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,

                                                KC_LGUI, KC_LCTL, KC_LALT,       KC_RALT, KC_RCTL, KC_RGUI,
                                                          KC_BSPC, KC_DEL,       KC_ENT, KC_SPACE
    )
};
