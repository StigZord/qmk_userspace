#include QMK_KEYBOARD_H

#include "keycodes.h"


bool is_alt_tab_active = false;
// bool is_alt_shift_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}


// #ifdef ENCODER_ENABLE

void left_encoder(bool clockwise) {

    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _ADJUST:
            register_code(KC_LCTL);
            register_code(KC_LGUI);
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
            break;
        case _UO:
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            alt_tab_timer = timer_read();

            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }

            break;
        default:
            register_code(KC_LCTL);
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
            unregister_code(KC_LCTL);
    }

}

void right_encoder(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
        return;
    }

    tap_code(KC_VOLD);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        left_encoder(clockwise);
    } else if (index == 1) {
        right_encoder(clockwise);
    }
    return false;
}

// #endif
