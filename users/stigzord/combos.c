#include "combos.h"
#include "keycodes.h"

enum combo_events { TAB_Q, QW, WE, ER, RT, CTRL_A, AS, SD, DF, FG, SHFT_Z, ZX, XC, CV, VB, COMBO_LENGTH };

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM tab_q_combo[] = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM qw_combo[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM we_combo[]    = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[]    = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo[]    = {KC_R, KC_T, COMBO_END};

const uint16_t PROGMEM ctrl_a_combo[] = {MOD_LCTL, KC_A, COMBO_END};
const uint16_t PROGMEM as_combo[]     = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[]     = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[]     = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fg_combo[]     = {KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM shft_z_combo[] = {KC_LSFT, KC_Z, COMBO_END};
const uint16_t PROGMEM zx_combo[]     = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[]     = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]     = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[]     = {KC_V, KC_B, COMBO_END};

combo_t key_combos[] = {
    [TAB_Q] = COMBO_ACTION(tab_q_combo),
    [QW] = COMBO_ACTION(qw_combo),
    [WE] = COMBO_ACTION(we_combo),
    [ER] = COMBO_ACTION(er_combo),
    [RT] = COMBO_ACTION(rt_combo),
    [CTRL_A] = COMBO_ACTION(ctrl_a_combo),
    [AS] = COMBO_ACTION(as_combo),
    [SD] = COMBO_ACTION(sd_combo),
    [DF] = COMBO_ACTION(df_combo),
    [FG] = COMBO_ACTION(fg_combo),
    [SHFT_Z] = COMBO_ACTION(shft_z_combo),
    [ZX] = COMBO_ACTION(zx_combo),
    [XC] = COMBO_ACTION(xc_combo),
    [CV] = COMBO_ACTION(cv_combo),
    [VB] = COMBO_ACTION(vb_combo)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
    // TODO Refactor combos, and add symbols on combos for programming
    switch (get_highest_layer(default_layer_state)) {
        case _UO:
            switch (combo_index) {
                case TAB_Q:
                    if (pressed) {
                        tap_code16(KC_F19);
                    }
                    break;
                case QW:
                    if (pressed) {
                        tap_code16(KC_F16);
                    }
                    break;
                case WE:
                    if (pressed) {
                        tap_code16(KC_1);
                    }
                    break;
                case ER:
                    if (pressed) {
                        tap_code16(KC_2);
                    }
                    break;
                case RT:
                    if (pressed) {
                        tap_code16(KC_3);
                    }
                    break;
                case CTRL_A:
                    if (pressed) {
                        tap_code16(KC_F18);
                    }
                    break;
                case AS:
                    if (pressed) {
                        tap_code16(KC_F15);
                    }
                    break;
                case SD:
                    if (pressed) {
                        tap_code16(KC_4);
                    }
                    break;
                case DF:
                    if (pressed) {
                        tap_code16(KC_5);
                    }
                    break;
                case FG:
                    if (pressed) {
                        tap_code16(KC_6);
                    }
                    break;
                case SHFT_Z:
                    if (pressed) {
                        tap_code16(KC_F17);
                    }
                    break;
                case ZX:
                    if (pressed) {
                        tap_code16(KC_F14);
                    }
                    break;
                case XC:
                    if (pressed) {
                        tap_code16(KC_7);
                    }
                    break;
                case CV:
                    if (pressed) {
                        tap_code16(KC_8);
                    }
                    break;
                case VB:
                    if (pressed) {
                        tap_code16(KC_9);
                    }
                    break;
                default:
                    break;
            }
            break;
        case _DEFAULT_RPG:
            switch (combo_index) {
                case TAB_Q:
                    if (pressed) {
                        tap_code16(KC_F19);
                    }
                    break;
                case QW:
                    if (pressed) {
                        tap_code16(KC_F16);
                    }
                    break;
                case RT:
                    if (pressed) {
                        tap_code16(KC_3);
                    }
                    break;
                case CTRL_A:
                    if (pressed) {
                        tap_code16(KC_F18);
                    }
                    break;
                case AS:
                    if (pressed) {
                        tap_code16(KC_F15);
                    }
                    break;
                case FG:
                    if (pressed) {
                        tap_code16(KC_6);
                    }
                    break;
                case SHFT_Z:
                    if (pressed) {
                        tap_code16(KC_F17);
                    }
                    break;
                case ZX:
                    if (pressed) {
                        tap_code16(KC_F14);
                    }
                    break;
                case XC:
                    if (pressed) {
                        tap_code16(KC_7);
                    }
                    break;
                case CV:
                    if (pressed) {
                        tap_code16(KC_M);
                    }
                    break;
                case VB:
                    if (pressed) {
                        register_code(KC_LCTL);
                        tap_code16(KC_C);
                        unregister_code(KC_LCTL);
                    }
                    break;
                default:
                    break;
            }
            break;

        default:
            case VB:
                if (pressed) {
                    tap_code16(KC_7);
                }
            break;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Only use combos in _COLEMAK_DH layer
    if (layer_state_cmp(layer_state | default_layer_state, _COLEMAK_DH)) {
        return true;
    }

    return false;
}
