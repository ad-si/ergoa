#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

enum layers {
  base,
  shift,
  symbols,
  move_numbers,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [base] = KEYMAP(
    // Left side
    _______,   _______,  _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE,
    OSL(3),    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_MEDIA_PREV_TRACK,
    OSL(2),    KC_A,     KC_S,    KC_D,    KC_F,    KC_G,
    OSL(1),    KC_B,     KC_Z,    KC_X,    KC_C,    KC_V,    _______,
    KC_LSHIFT, KC_LALT,  KC_ESC,  KC_LCTL, KC_LGUI,

    // Thumb cluster
               KC_SPACE, KC_ENTER,
                         _______,
    KC_BSPACE, KC_TAB,   KC_TAB,


    // Right side
    KC_AUDIO_MUTE,       KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______,  _______, _______,   KC_SLEP,
    KC_MEDIA_NEXT_TRACK, KC_Y,              KC_U,            KC_I,     KC_O,    KC_P,      OSL(3),
                         KC_H,              KC_J,            KC_K,     KC_L,    KC_SCOLON, OSL(2),
    ALL_T(KC_NO),        KC_N,              KC_M,            KC_COMMA, KC_DOT,  KC_SLASH,  OSL(1),
                                            KC_LGUI,         KC_LCTL,  KC_ESC,  KC_LALT,   KC_RSHIFT,

    // Thumb cluster
    _______, _______,
    _______,
    KC_ENT,  KC_ENT, KC_SPC
  ),


  [shift] = KEYMAP(
    // Left side
    _______, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,
    _______, RSFT(KC_Q), RSFT(KC_W), RSFT(KC_E), RSFT(KC_R), RSFT(KC_T), _______,
    _______, RSFT(KC_A), RSFT(KC_S), RSFT(KC_D), RSFT(KC_F), RSFT(KC_G),
    _______, RSFT(KC_B), RSFT(KC_Z), RSFT(KC_X), RSFT(KC_C), RSFT(KC_V), _______,
    _______, _______,    _______,    _______,    _______,

    // Thumb cluster
                    _______,      _______,
                                  _______,
    KC_DELETE, RSFT(KC_TAB), RSFT(KC_TAB),


    // Right side
    _______,    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,
    _______,    LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P),  KC_F12,
                LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), _______,     _______,
    _______,    LSFT(KC_N), LSFT(KC_M), _______,    _______,    _______,     _______,
                            _______,    _______,    _______,    _______,     _______,

    // Thumb cluster
    _______,      _______,
    _______,
    LSFT(KC_ENT), LSFT(KC_ENT), LSFT(KC_SPC)
  ),


  [symbols] = KEYMAP(
    // Left side
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_CIRC,
    _______, KC_PERC, KC_AMPR, KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, _______, _______, _______,

    // Thumb cluster
             _______, _______,
                      _______,
    _______, _______, _______,


    // Right side
    _______, _______,   _______, _______,  _______, _______, _______,
    _______, KC_ASTR,   KC_EQL,  KC_MINUS, KC_UNDS, KC_PLUS, _______,
             KC_BSLASH, KC_DQUO, KC_QUOT,  KC_GRV,  KC_COLN, _______,
    _______, _______,   KC_TILD, KC_LABK,  KC_RABK, KC_QUES, _______,
                        _______, _______,  _______, _______, _______,

    // Thumb cluster
    _______, _______,
    _______,
    _______, _______, _______
  ),


  [move_numbers] = KEYMAP(
    // Left side
    _______, _______,   _______,    LGUI(KC_UP),   _______,    _______, _______,
    _______, _______,   LCTL(KC_A), KC_UP,         LCTL(KC_E), _______, _______,
    _______, KC_PGUP,   KC_LEFT,    KC_DOWN,       KC_RIGHT,   _______,
    _______, KC_PGDOWN, _______,    LGUI(KC_DOWN), _______,    _______, _______,
    _______, _______,   _______,    _______,       _______,

    // Thumb cluster
             _______, _______,
                      _______,
    _______, _______, _______,


    // Right side
    _______,    _______,    _______,  _______,     _______,  _______, _______,
    _______,    _______,    KC_1,     KC_2,        KC_3,     _______, _______,
                _______,    KC_4,     KC_5,        KC_6,     _______, _______,
    _______,    _______,    KC_7,     KC_8,        KC_9,     _______, _______,
                            _______,  _______,  _______,  _______, _______,

    // Thumb cluster
    _______, _______,
    _______,
    _______, _______, KC_0
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

void matrix_scan_user (void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
};
