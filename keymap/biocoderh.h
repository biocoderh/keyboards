// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

#pragma once

#include QMK_KEYBOARD_H
#include "keymap_introspection.h"

#include "features/features.h"

enum layers {
    L_BASE,
    L_NUM,
    L_SYM,
    L_MOUSE,
    L_FN,
    L_PROG,
    L_MACRO,
    L_GAME0,
    L_GAME1,
};

#define LT_NUM(kc) LT(L_NUM, kc)
#define LT_SYM(kc) LT(L_SYM, kc)
#define LT_MOUSE(kc) LT(L_MOUSE, kc)
#define LT_FN(kc) LT(L_FN, kc)
#define LT_MACRO(kc) LT(L_MACRO, kc)
#define LT_PROG(kc) LT(L_PROG, kc)

#define TH_NUM KC_D
#define TH_SYM KC_L
#define TH_MOUSE KC_U
#define TH_FN KC_C
#define TH_MACRO KC_M
#define TH_PROG KC_P
#define TH_GAME KC_F

#define TH_BOOT_L KC_J
#define TH_BOOT_R KC_Z
#define TH_CAPS KC_G
#define TH_LEAD KC_B

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_biocoderh(
        KC_F,               KC_M,               KC_C,               KC_D,                                                       KC_L,               KC_U,               KC_P,               KC_H,
        LGUI_T(KC_S),       LALT_T(KC_A),       LCTL_T(KC_N),       LSFT_T(KC_E),       KC_Z,               KC_J,               RSFT_T(KC_T),       RCTL_T(KC_I),       RALT_T(KC_R),       RGUI_T(KC_O),
        KC_Q,               KC_W,               KC_X,               KC_G,                                                       KC_B,               KC_Y,               KC_V,               KC_K,

                                                LT_MACRO(KC_ESC),   LT_NUM(KC_SPC),     LT_MOUSE(KC_TAB),   LT_FN(KC_ENT),      LT_SYM(KC_BSPC),    LT_PROG(KC_DEL)
    ),
    [L_NUM] = LAYOUT_biocoderh(
        KC_6,               KC_4,               KC_2,               KC_0,                                                       KC_1,               KC_3,               KC_5,               KC_7,
        LGUI_T(KC_PAST),    LALT_T(KC_PSLS),    LCTL_T(KC_DOT),     LSFT_T(KC_LPRN),    KC_8,               KC_9,               RSFT_T(KC_RPRN),    RCTL_T(KC_EQL),     RALT_T(KC_PMNS),    RGUI_T(KC_PPLS),
        KC_CALC,            KC_INS,             KC_COMM,            KC_PERC,                                                    KC_HOME,            KC_PGDN,            KC_PGUP,            KC_END,

                                                KC_APP,             KC_SPC,             KC_TAB,             KC_ENT,             KC_BSPC,            KC_DEL
    ),
    [L_SYM] = LAYOUT_biocoderh(
        KC_BSLS,            KC_DLR,             KC_LABK,            KC_LCBR,                                                    KC_RCBR,            KC_RABK,            KC_HASH,            KC_PIPE,
        KC_LBRC,            KC_QUOT,            KC_COLN,            KC_COMM,            KC_EXLM,            KC_RPRN,            KC_DQUO,            KC_SCLN,            KC_UNDS,            KC_RBRC,
        KC_GRV,             KC_CIRC,            KC_TILD,            KC_EXLM,                                                    KC_AMPR,            KC_AT,              KC_QUES,            KC_BSLS,

                                                KC_APP,             KC_SPC,             KC_TAB,             KC_ENT,             KC_BSPC,            KC_DEL
    ),
    [L_MOUSE] = LAYOUT_biocoderh(
        KC_NO,              A(KC_F4),           KC_NO,              KC_NO,                                                      KC_BTN4,            KC_NO,              C(KC_F5),           KC_BTN5,
        KC_UNDO,            KC_CUT,             KC_COPY,            KC_PASTE,           KC_AGIN,            KC_NO,              KC_MS_L,            KC_MS_DOWN,         KC_MS_UP,           KC_MS_R,
        KC_NO,              KC_ACL2,            KC_ACL1,            KC_ACL0,                                                    KC_WH_L,            KC_WH_D,            KC_WH_U,            KC_WH_R,

                                                KC_NO,              KC_NO,              KC_NO,              KC_BTN3,            KC_BTN1,            KC_BTN2
    ),
    [L_FN] = LAYOUT_biocoderh(
        KC_F6,              KC_F4,              KC_F2,              KC_F10,                                                     KC_F1,              KC_F3,              KC_F5,              KC_F7,
        LGUI_T(KC_SCRL),    LALT_T(KC_PSCR),    LCTL_T(KC_F12),     LSFT_T(KC_F11),     KC_F8,              KC_F9,              KC_LEFT,            KC_DOWN,            KC_UP,              KC_RIGHT,
        KC_NO,              KC_BRID,            KC_BRIU,            KC_PAUS,                                                    KC_MPRV,            KC_VOLD,            KC_VOLU,            KC_MNXT,

                                                KC_WAKE,            KC_MPLY,            KC_MUTE,            KC_NO,              KC_NO,              KC_NO
    ),
    [L_MACRO] = LAYOUT_biocoderh(
        QK_USER_0,          QK_USER_1,          QK_USER_2,          QK_USER_3,                                                  QK_USER_4,          QK_USER_5,          QK_USER_6,          QK_USER_7,
        QK_USER_8,          QK_USER_9,          QK_USER_10,         QK_USER_11,         QK_USER_12,         QK_USER_13,         QK_USER_14,         QK_USER_15,         QK_USER_16,         QK_USER_17,
        QK_USER_18,         QK_USER_19,         QK_USER_20,         QK_USER_21,                                                 QK_USER_22,         QK_USER_23,         QK_USER_24,         QK_USER_25,

                                                QK_USER_26,         QK_USER_27,         QK_USER_28,         QK_USER_29,         QK_USER_30,         QK_USER_31
    ),
    [L_PROG] = LAYOUT_biocoderh(
        PB_1,               PB_2,               PB_3,               PB_4,                                                       PB_5,               PB_6,               PB_7,               PB_8,
        PB_9,               PB_10,              PB_11,              PB_12,              PB_13,              PB_14,              PB_15,              PB_16,              PB_17,              PB_18,
        PB_19,              PB_20,              PB_21,              PB_22,                                                      PB_23,              PB_24,              PB_25,              PB_26,

                                                PB_27,              PB_28,              PB_29,              PB_30,              PB_31,              PB_32
    ),
    [L_GAME0] = LAYOUT_biocoderh(
        KC_TAB,             KC_Q,               KC_W,               KC_E,                                                       KC_O,               KC_P,               KC_F1,              KC_F2,
        KC_LSFT,            KC_A,               KC_S,               KC_D,               KC_F,               A(KC_TAB),          KC_H,               KC_J,               KC_K,               KC_L,
        KC_LCTL,            KC_Z,               KC_X,               KC_C,                                                       KC_MPRV,            KC_VOLD,            KC_VOLU,            KC_MNXT,

                                                KC_R,               MO(L_GAME1),        KC_SPC,             KC_ESC,             KC_MPLY,            KC_MUTE
    ),
    [L_GAME1] = LAYOUT_biocoderh(
        KC_I,               KC_U,               KC_Y,               KC_T,                                                       KC_9,               KC_0,               KC_F5,              KC_F6,
        KC_4,               KC_3,               KC_2,               KC_1,               KC_G,               KC_TRNS,            KC_5,               KC_6,               KC_7,               KC_8,
        KC_M,               KC_N,               KC_B,               KC_V,                                                       KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,

                                                KC_NO,              KC_TRNS,            KC_NO,              TO(L_BASE),         KC_BSPC,            KC_ENT
    )
};
