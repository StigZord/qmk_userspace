/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keycodes.h"

#include "stigzord.h"

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define WOW      DF(_DEFAULT_RPG)
#define UO       DF(_UO)
#define DEADLOCK       DF(_DEADLOCK)
#define RPG_SHIFT       DF(_RPG_SHIFT)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define NUM_PAD MO(_NUM_PAD)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define SYM_LEAD LT(SYM, KC_DQUO)
#define SOURCE_SWITCH C(A(KC_F24)) // My custom binding that changes monitor input source

// Gaming specific aliases
#define CTL_RABK MT(MOD_LCTL, KC_RABK)


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L   , KC_U ,   KC_Y,   KC_SCLN, KC_BSPC,
     CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N   , KC_E ,   KC_I,   KC_O,    CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_J,         FKEYS,   KC_RBRC,KC_K,   KC_H   , KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, NUM_PAD, SYM_LEAD, ALT_ENT,    _______, KC_SPC, NAV ,   KC_RALT, KC_APP
    ),

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,_______,     FKEYS, KC_RBRC, KC_N,   KC_M   ,  KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 ADJUST, KC_LGUI, NUM_PAD, SYM_LEAD, ALT_ENT,     _______, KC_SPC, NAV ,   KC_RALT, KC_APP
    ),

/*
 * Base Layer: Defautl RPG (for gaming)
 */
    [_DEFAULT_RPG] = LAYOUT(
     KC_TAB   , KC_T ,  KC_Q ,  KC_W  ,  KC_E  ,  KC_R ,                                          KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_LCTL  , KC_G ,  KC_A ,  KC_S  ,  KC_D  ,  KC_F ,                                          KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT  , KC_B ,  KC_Z ,  KC_X  ,  KC_C  ,  KC_V ,   KC_LBRC, FKEYS,     COLEMAK, KC_RBRC,  KC_N,   KC_M ,  KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST,  KC_LALT ,  NUM_PAD, KC_SPC,  KC_GT,       KC_E , SYM_LEAD, NAV,    KC_RALT, KC_APP
    ),

/*
 * Base Layer: DEADLOCK (for gaming)
 */
    [_DEADLOCK] = LAYOUT(
     KC_TAB   , KC_T ,  KC_Q ,  KC_W  ,  KC_E  ,  KC_R ,                                          KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_LCTL  , KC_G ,  KC_A ,  KC_S  ,  KC_D  ,  KC_F ,                                          KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT  , KC_B ,  KC_Z ,  KC_X  ,  KC_C  ,  KC_V ,   KC_LBRC, KC_COMMA,     COLEMAK, KC_RBRC,  KC_N,   KC_M ,  KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST,  KC_LALT ,  NUM_PAD, KC_SPC,  KC_DOT,       KC_E , SYM_LEAD, NAV,    KC_RALT, KC_APP
    ),

/*
 * Base Layer: RPG Shift (for gaming)
 */
    [_RPG_SHIFT] = LAYOUT(
     KC_GRV  , KC_0 ,  KC_1 ,  KC_2  ,  KC_3  ,  KC_4 ,                                          KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_LCTL  , KC_T ,  KC_Q ,  KC_W  ,  KC_E  ,  KC_R ,                                          KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_LSFT  , KC_G ,  KC_A ,  KC_S  ,  KC_D  ,  KC_F ,    KC_LBRC, KC_COMMA,      COLEMAK, KC_RBRC, KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
                                ADJUST,  KC_LALT ,  NUM_PAD, KC_SPC,  KC_DOT,       KC_E , SYM_LEAD, NAV,    KC_RALT, KC_APP
    ),

/*
 * Base Layer: UO (for gaming)
 */
    [_UO] = LAYOUT(
     KC_GRV   , KC_Q ,  KC_W  ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_LCTL  , KC_A , KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT  , KC_Z ,  KC_X  ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC, FKEYS,       COLEMAK, KC_RBRC,  KC_N,   KC_M   ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST, KC_LT, NUM_PAD, KC_SPC, KC_GT,      KC_E , SYM_LEAD, NAV ,   KC_RALT, KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_TILD,  _______, KC_EXLM,  KC_EQUAL,  KC_PLUS, KC_END,                                        KC_UNDERSCORE, KC_LBRC,    KC_DOLLAR, KC_RBRC, KC_CIRCUMFLEX,  _______,
      _______, _______,   KC_LCBR, KC_ASTERISK,  KC_RCBR, KC_GRV,                                     KC_MINUS,       KC_LPRN,    KC_COLON,  KC_RPRN, KC_SEMICOLON, KC_PIPE,
      _______, KC_BACKSLASH, _______, _______, _______, KC_HASH, _______, _______, _______, _______, KC_PERC, _______, _______,  _______, KC_SLASH, KC_AT,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_UNDERSCORE,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , KC_HASH,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_DOLLAR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______  , WOW,     COLEMAK, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      KC_ESC , RPG_SHIFT, UO ,     QWERTY , _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, DEADLOCK, _______, _______, _______,_______, SOURCE_SWITCH, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Numpad layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM_PAD] = LAYOUT(
      KC_TAB, KC_PSLS,  KC_P7,  KC_P8,  KC_P9, KC_PMNS,                                     _______, _______, _______, _______, _______, _______,
      KC_ESC, KC_PAST,  KC_P4,  KC_P5,  KC_P6, KC_PPLS,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_PDOT, KC_P1,  KC_P2,  KC_P3,  KC_P0, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef LEADER_ENABLE
    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
            case SYM_LEAD:
                if (record->tap.count && record->event.pressed) {
                    leader_start();
                    return false;        // Return false to ignore further processing of key
                }
                break;
        }
        return true;
    }

    void leader_end_user(void) {
        if (leader_sequence_two_keys(KC_C, KC_W)) {
            // Leader, c, w => caps_word
            #ifdef CAPS_WORD_ENABLE
                toggle_caps_word_mode(CAPS_WORD_MODE_DEFAULT);
            #endif
        } else if (leader_sequence_two_keys(KC_C, KC_C)) {
            // Leader, c, c => camelCase
            #ifdef CAPS_WORD_ENABLE
                toggle_caps_word_mode(CWMODE_CAMEL_CASE);
            #endif
        } else if (leader_sequence_two_keys(KC_G)) {
            // Leader, g => GUI
            tap_code16(LGUI);
        }
    }
#endif

