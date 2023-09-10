// Copyright 2023 Biocoder.h <biocoder.h@gmail.com>

// Process keycodes: QK_USER_0 ... QK_USER_31
void custom_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case QK_USER_12:
            case QK_USER_13:
                process_tap(QK_BOOT, record);
        }
    }
}

#ifdef LEADER_ENABLE
void custom_leader(void) {
    if (leader_sequence_two_keys(KC_D, KC_D)) {
        tap_code16(KC_END);
        tap_code16(S(KC_HOME));
        tap_code16(KC_BSPC);
    } else if (leader_sequence_two_keys(KC_F, KC_N)) {
        SEND_STRING("function ");
    } else if (leader_sequence_two_keys(KC_S, KC_R)) {
        SEND_STRING(" site: reddit.com");
        tap_code16(KC_ENT);
    }
}
#endif
