#include QMK_KEYBOARD_H
#include "version.h"

//#include "rev3.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  L2  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  Z   |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |  /   |RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |Grv/L1| LCtrl| LAlt | Left | Right|                                  |  Up  | Down | [/L2 |]/Ctrl| ~L1  |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |App/Al| LGui |  |      |Esc/Al|
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Home |  | PgUp |      |      |
 *                               | Space|Backsp|------|  |------|  Tab |Enter |
 *                               |      |ace   | End  |  | PgDn |      |      |
 *                               `--------------------'  `--------------------'
 */
/*
[BASE] = LAYOUT(  // layer 0 : default
        // left hand
           KC_EQL,         KC_1,           KC_2,     KC_3,     KC_4,  KC_5,      KC_6,   KC_7,  KC_8,       KC_9,  KC_0,  KC_MINS,
          KC_DELT,         KC_Q,           KC_W,     KC_E,     KC_R,  KC_T,      KC_Y,   KC_U,  KC_I,       KC_O,  KC_P,  KC_BSLS,
          KC_BSPC,         KC_A,           KC_S,     KC_D,     KC_F,  KC_G,      KC_H,   KC_J,  KC_K,       KC_L,  LT(MDIA, KC_SCLN),  GUI_T(KC_QUOT),
          KC_LSFT,  CTL_T(KC_Z),           KC_X,     KC_C,     KC_V,  KC_B,      KC_N,   KC_M,  KC_COMM,  KC_DOT,     CTL_T(KC_SLSH),         KC_RSFT,
  LT(SYMB,KC_GRV),      KC_QUOT,  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT, KC_NO,     KC_NO,  KC_UP,  KC_DOWN, KC_LBRC,            KC_RBRC,          KC_FN1,
    ALT_T(KC_APP),      KC_LGUI,        KC_HOME,   KC_SPC,  KC_BSPC,KC_END,   KC_PGDN, KC_TAB, KC_ENT, KC_PGUP, KC_RALT, CTL_T(KC_ESC)  
    ),
  [BASE] = LAYOUT(  // layer 0 : default
        // left hand
           KC_EQL,         KC_1,           KC_2,     KC_3,     KC_4,  KC_5,      KC_6,   KC_7,  KC_8,       KC_9,  KC_0,  KC_MINS,
          KC_DELT,         KC_Q,           KC_W,     KC_E,     KC_R,  KC_T,      KC_Y,   KC_U,  KC_I,       KC_O,  KC_P,  KC_BSLS,
          KC_BSPC,         KC_A,           KC_S,     KC_D,     KC_F,  KC_G,      KC_H,   KC_J,  KC_K,       KC_L,  KC_SCLN,  KC_QUOT,
          KC_LSFT,  CTL_T(KC_Z),           KC_X,     KC_C,     KC_V,  KC_B,      KC_N,   KC_M,  KC_COMM,  KC_DOT,     CTL_T(KC_SLSH),         KC_RSFT,
  LT(SYMB,KC_GRV),      KC_QUOT,  LALT(KC_LSFT),  KC_LEFT,  KC_RGHT, KC_NO,     KC_NO,  KC_UP,  KC_DOWN, KC_LBRC,            KC_RBRC,          KC_FN1,
    ALT_T(KC_APP),      KC_LGUI,        KC_HOME,   KC_SPC,  KC_BSPC,KC_END,   KC_PGDN, KC_TAB, KC_ENT, KC_PGUP, KC_RALT, CTL_T(KC_ESC)  
    ),
*/
  [BASE] = LAYOUT(  // layer 0 : default
        // left hand
           KC_EQL,      KC_1,       KC_2,     KC_3,     KC_4,  KC_5,      KC_6,   KC_7,  KC_8,       KC_9,  KC_0,  KC_MINS,
          KC_DELT,      KC_Q,       KC_W,     KC_E,     KC_R,  KC_T,      KC_Y,   KC_U,  KC_I,       KC_O,  KC_P,  KC_BSLS,
           LT(MDIA,KC_CAPS),      KC_A,       KC_S,     KC_D,     KC_F,  KC_G,      KC_H,   KC_J,  KC_K,       KC_L,  KC_SCLN,  KC_QUOT,
          KC_LSFT,      KC_Z,       KC_X,     KC_C,     KC_V,  KC_B,      KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
  LT(SYMB,KC_GRV),  KC_LCTRL,   KC_LALT ,  KC_LEFT,  KC_RGHT, KC_NO,     KC_NO,  KC_UP,  KC_DOWN, ALT_T(KC_LBRC), CTL_T(KC_RBRC), KC_FN1,
    ALT_T(KC_APP),   KC_LGUI,    KC_HOME,   KC_SPC,  KC_BSPC,KC_END,   KC_PGDN, KC_TAB,   KC_ENT,          KC_PGUP,        KC_TRNS, ALT_T(KC_ESC)  
    ),

/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   Up |      | PgUp |      |                    |      |   7  |   8  |   9  |   *  | Versn|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left |Down  |Right |PgDown|      |                    |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |RESET |      |      |      |      |                                  |      |   .  |   0  |   =  |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT(
       // left hand
        KC_F12,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,    KC_F7,     KC_F8, KC_F9,  KC_F10,   KC_F11,
       KC_TRNS,  KC_TRNS,    KC_UP,  KC_TRNS,  KC_PGUP,  KC_PIPE, KC_TRNS,     KC_7,      KC_8,  KC_9, KC_ASTR,  KC_VOLU,
       KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,   KC_GRV, KC_TRNS,     KC_4,      KC_5,  KC_6, KC_PLUS,  KC_VOLD,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TILD, KC_TRNS,     KC_1,      KC_2,  KC_3, KC_BSLS,  KC_MUTE,
         RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,   KC_TRNS,    KC_DOT,  KC_0,  KC_EQL,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS       // right hand
),

/* Keymap 2: Media and mouse keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   Up |      | PgUp |      |                    |      |      | MsUp | VolDn|VolUp |Mute  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left |Down  |Right |PgDown|      |                    |      |MsLeft|MsDown|MsRght|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      |      |      |                                  |      |      |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|RClck | LClck|
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */  
// MEDIA AND MOUSE
[MDIA] = LAYOUT(
        KC_F12,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,
       KC_TRNS,  KC_TRNS,    KC_UP,  KC_TRNS,  KC_PGUP,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_MS_U,  KC_VOLD,  KC_VOLU,  KC_MUTE,
       KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_TRNS, KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_NO,   KC_NO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_BTN2,  KC_BTN1,  KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};
