// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include "mitosis.h"

enum mitosis_layers
{
  _STD,
  _NUM,
  _SYM,
  _FUN
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___M___ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_STD] = {
    {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,     KC_U,    KC_I,    KC_O,    KC_P    },
    {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_H,     KC_J,    KC_K,    KC_L,    KC_PENT },
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_RSFT },
    {XXXXXXX, _______, _______, _______, KC_LCTL,        KC_RCTL,  KC_RGUI, KC_SCLN, KC_SLSH, XXXXXXX },
    {XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI ,MO(_FUN),       KC_SPC,   MO(_NUM),_______, LCTL(KC_A),XXXXXXX},
  },


  [_FUN] = {
    {KC_GRV,     _______, _______, _______, _______,       KC_MINS, KC_EQL,   KC_LBRC, KC_RBRC, KC_BSPC},
    {KC_TAB,     _______, _______, _______, _______,       KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_PENT},
    {LCTL(KC_A), _______, _______, _______, _______,       KC_ESC,  _______,  _______, _______, _______},
    {XXXXXXX,    _______, _______, _______, _______,       _______, _______,  _______, _______, XXXXXXX},
    {XXXXXXX,    _______, _______, _______, ___M___,       _______, MO(_SYM), _______, _______, XXXXXXX},
  },


  [_NUM] = {
    {KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,       KC_6   , KC_7,    KC_8,    KC_9,    KC_0},
    {_______, _______, _______, _______, _______,       _______, KC_4,    KC_5,    KC_6,    KC_QUOT},
    {_______, _______, _______, _______, _______,       _______, KC_1,    KC_2,    KC_3,    _______},
    {XXXXXXX, _______, _______, _______, _______,       _______, _______, _______, _______, XXXXXXX},
    {XXXXXXX, _______, _______, _______, MO(_SYM),      _______, ___M___, _______, _______, XXXXXXX},
  },


[_SYM] = {
    {KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 },
    {_______, _______, _______, _______, _______,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______},
    {_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______},
    {XXXXXXX, _______, _______, _______, ___M___,       ___M___, _______, _______, _______, XXXXXXX},
    {XXXXXXX, _______, _______, _______, ___M___,       _______, _______, _______, _______, XXXXXXX},
  },

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
      case _STD:
        set_led_off;
        break;
        case _FUN:
            set_led_blue;
            break;
        case _NUM:
            set_led_green;
            break;
        case _SYM:
            set_led_red;
            break;
        default:
            break;
    }
};

