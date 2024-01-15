/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _BASE,  // default layer
    _SYMB,  // symbols
    _NUM,   // numbers
    _MDIA,  // media
};

#define MO_NUM MO(_NUM)
#define MO_SYMB MO(_SYMB)

#define NUM_LEDS_PER_SIDE 27

// The LEDs are so bright on the Corne, so we set the intensity pretty low.
#define LED_INTENSITY 0x16

// Define the usual colors using the desired LED_INTENSITY defined above.
#define RGB_DARK_BLUE 0x00, 0x00, LED_INTENSITY
#define RGB_DARK_CYAN 0x00, LED_INTENSITY, LED_INTENSITY
#define RGB_DARK_GREEN 0x00, LED_INTENSITY, 0x00
#define RGB_DARK_MAGENTA LED_INTENSITY, 0x00, LED_INTENSITY
#define RGB_DARK_RED LED_INTENSITY, 0x00, 0x00
#define RGB_DARK_WHITE LED_INTENSITY, LED_INTENSITY, LED_INTENSITY
#define RGB_DARK_YELLOW LED_INTENSITY, LED_INTENSITY, 0x00

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO_NUM,  KC_SPC,     KC_ENT,   MO_NUM, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO_NUM, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_MINS, KC_7,     KC_8,   KC_9,    KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_4,     KC_5,   KC_6,    KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_1,     KC_2,   KC_3,    KC_TILD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO_NUM,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_MDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// Wrapper
void set_color_split(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {
#ifdef MASTER_LEFT
    bool is_left = true;
#endif
#ifdef MASTER_RIGHT
    bool is_left = false;
#endif

    bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

    if ((is_left && key_code >= NUM_LEDS_PER_SIDE) || (!is_left && key_code < NUM_LEDS_PER_SIDE)) {
        return;
    }

    if(left_is_master && key_code >= NUM_LEDS_PER_SIDE)
        key_code -= NUM_LEDS_PER_SIDE;
    else if (!left_is_master && key_code < NUM_LEDS_PER_SIDE)
        key_code += NUM_LEDS_PER_SIDE;

    rgb_matrix_set_color(key_code, r, g, b);
}

// Sets all keycodes specified in the array to the given color. This is good for
// coloring arbitrary keys like WASD or all of the number keys at once.
void set_all_keys_colors(const uint8_t keycodes[], uint8_t len, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < len; ++i) {
        set_color_split(keycodes[i], r, g, b);
    }
}

void light_up_left_mods(uint8_t r, uint8_t g, uint8_t b) {
    const uint8_t left_mod_keycodes[] = {22, 19, 16, 11};
    set_all_keys_colors(left_mod_keycodes, sizeof(left_mod_keycodes) / sizeof(uint8_t), r, g, b);
}

void light_up_right_mods(uint8_t r, uint8_t g, uint8_t b) {
    const uint8_t right_mod_keycodes[] = {38, 43, 46, 49};
    set_all_keys_colors(right_mod_keycodes, sizeof(right_mod_keycodes) / sizeof(uint8_t), r, g, b);
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
            break;
        case _SYMB:
            break;
        case _NUM:
            const uint8_t numpad_keycodes[] = {57, 52, 47, 42, 58, 53, 48, 43, 59, 54, 49, 44};
            set_all_keys_colors(numpad_keycodes, sizeof(numpad_keycodes) / sizeof(uint8_t), RGB_DARK_WHITE);
            break;
        default:
            break;
    }

    return true;
}
#endif
