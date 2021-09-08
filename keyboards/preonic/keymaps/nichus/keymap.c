/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_MMUT C(A(KC_PAST))

enum preonic_layers {
  _QWERTY,
  _WORKMAN,
  _FUNC,
  _NUMPAD,
  _SUGAR,
  _RAISE,
  _LOWER,
  _ADJUST,
  _BACKLIT
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  FUNC,
  NUMPAD,
  SUGAR,
  RAISE,
  LOWER,
  ADJUST,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mo(F)| LGUI | Alt  |OSL(S)|    Enter    |    Space    | TG(N)|   -  |   =  |  [   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u (
  KC_GESC,      KC_1,    KC_2,        KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,        KC_9,    KC_0,    KC_BSPC,
  KC_TAB,       KC_Q,    KC_W,        KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,        KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,      KC_A,    KC_S,        KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,        KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,      KC_Z,    KC_X,        KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLSH, KC_RSFT,
  MO(_FUNC), KC_LGUI, KC_LALT, OSL(_SUGAR),           KC_ENT,           KC_SPC,    TG(_NUMPAD), KC_MINS, KC_EQL,  KC_LBRC
),

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   D  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Gui  | Alt  |OSL(S)|   Enter     |    Space    |TG(N) | Gui  | App  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_preonic_2x2u (
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  MO(_FUNC),   KC_LGUI, KC_LALT, OSL(_SUGAR), KC_ENT,          KC_SPC,    TG(_NUMPAD),   KC_RGUI, KC_APP,  KC_RCTL
),

/* Func
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Prev | Play | Next |      |      |      |      |      | Home |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |MiMute|      | VolD | VolU | Mute |      | Left | Down |  Up  | Right| Ins  | PgUp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | End  |      | PgDn |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Trans|      |      |      |    Enter    |    Space    |Qwerty|Workmn|      |CtAlDe|
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_preonic_2x2u (
  KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_F5,  KC_F6,    KC_F7,    KC_F8,  KC_F9,  KC_F10, KC_DEL,
  KC_NO,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_HOME,KC_NO,  KC_NO,
  KC_MMUT,  KC_NO,    KC_VOLD,  KC_VOLU,  KC_MUTE,KC_NO,  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,KC_INS, KC_PGUP,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_END, KC_NO,  KC_PGDN,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,           KC_ENT,           KC_SPC,    QWERTY, WORKMAN,KC_NO,  KC_CAD
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |BlTogg|      |      |      |      |      |      | Num  |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BlBrTg|      | PrtS | ScrL | Paus |      |      |   7  |   8  |   9  |   ,  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |BlStep|      | Ins  | Home | PgUp |      |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Del  | End  | PgDn |      |      |   1  |   2  |   3  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Tg(N)|             |      0      |   0  |   .  | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_2x2u (
  BL_TOGG,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,KC_BSPC,
  BL_BRTG,  KC_NO,  KC_PSCR,KC_SLCK,KC_PAUS,KC_NO,  KC_NO,  KC_P7,  KC_P8,  KC_P9,  KC_PCMM,KC_DEL,
  BL_STEP,  KC_NO,  KC_INS, KC_HOME,KC_PGUP,KC_NO,  KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,KC_NO,
  KC_NO,    KC_NO,  KC_DEL, KC_END, KC_PGDN,KC_NO,  KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PEQL,KC_NO,
  KC_NO,    KC_NO,  KC_NO,  TG(_NUMPAD),    KC_NO,          KC_P0,  KC_P0,  KC_PDOT,KC_PENT,KC_NO
),

/* Sugar
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F0  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   /  |      |      |   \  |      |      |      |BackSp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   [  |   {  |   -  |   _  |      |      |   =  |   +  |   }  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |    Enter    |    Space    |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SUGAR] = LAYOUT_preonic_2x2u (
  KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,   KC_F9,   KC_F10, KC_F12,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_SLSH,  KC_NO,    KC_NO,    KC_BSLS,   KC_NO,   KC_NO,   KC_NO,  KC_BSPC,
  KC_LCTL,  KC_LBRC,  KC_LCBR,  KC_MINS,  KC_UNDS,  KC_NO,    KC_NO,    KC_EQL,  KC_PLUS, KC_RCBR, KC_RBRC,  KC_NO,
  KC_LSFT,  KC_NO,    KC_NO,    KC_NO,    KC_PLUS,  KC_MINS,  KC_UNDS,  KC_EQL,    KC_NO,   KC_NO,   KC_NO,  KC_RSFT,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_ENT,             KC_SPC,    KC_NO,   KC_NO,   KC_NO,  KC_NO
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case WORKMAN:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WORKMAN);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
