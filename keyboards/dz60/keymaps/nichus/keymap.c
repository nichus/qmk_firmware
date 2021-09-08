#include QMK_KEYBOARD_H

#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_MMUT C(A(KC_PAST))

enum dz60_layers {
  _QWERTY,
  _FUNC
};
enum dz60_keycodes {
  QWERTY = SAFE_RANGE,
  FUNC,
  MD_BOOT
}
// Override any default bootkey duration, use a 3 second (3*1000ms) duration instead
#ifdef BOOTKEY_HOLD_MS
#undef BOOTKEY_HOLD_MS
#endif
#define BOOTKEY_HOLD_MS 3000

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-------------------------------------------------------------------------.
     * | Esc|  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  Backs |
     * |-------------------------------------------------------------------------|
     * | Tab  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [  | ] |   \  |
     * |-------------------------------------------------------------------------|
     * | Ctrl  |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |   Enter  |
     * |-------------------------------------------------------------------------|
     * | Shft     |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |   Shift    |
     * |-------------------------------------------------------------------------|
     * | Mo(F)| Gui | Alt |            Space             | Alt | Gui | App | Ctrl|
     * `-------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_60_ansi(
      KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS, KC_EQL,  KC_BSPC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,          KC_ENT,
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,          KC_RSFT,
      MO(_FUNC),          KC_LGUI,  KC_LALT,                      KC_SPC,                       KC_RALT,  KC_RGUI,  KC_APP,           KC_RCTL
    ),

    /* Layer 1: Function Layer
     * ,-------------------------------------------------------------------------.
     * |  ` | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|   Del  |
     * |-------------------------------------------------------------------------|
     * |      |Prev|Play|Next|    |    |    |    |    |Home|Pscr|Slck|Paus| Reset|
     * |-------------------------------------------------------------------------|
     * | MiMute|    |VolD|VolU|Mute|    |Left|Down| Up |Rght| Ins|PgUp|          |
     * |-------------------------------------------------------------------------|
     * |          |    |    |    |    |    |    |    |    | End|PgDn|            |
     * |-------------------------------------------------------------------------|
     * | Trns |     |     |                              | Stop|     |     | CAD |
     * `-------------------------------------------------------------------------'
     */
    [_FUNC] = LAYOUT_60_ansi(
      KC_GRAVE, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12, KC_DEL,
      KC_NO,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_PSCR,  KC_SLCK,  KC_PAUS,RESET,
      KC_MMUT,  KC_NO,    KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_INS,   KC_PGUP,          KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_END,   KC_PGDN,                    KC_NO,
      KC_TRNS,  KC_NO,    KC_NO,                        KC_NO,                        KC_STOP,  KC_NO,    KC_NO,                      KC_CAD
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t key_timer;

  switch(keycode) {
    case MD_BOOT:
      if(record->event.pressed) {
        key_timer = timer_read32();
      } else {
        if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
          reset_keyboard();
        }
      }
      return false;
    default:
      // Process all other keycodes normally
      return true;
  }
}
