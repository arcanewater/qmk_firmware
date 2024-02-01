#include QMK_KEYBOARD_H
#include "keycodes.h"

static const char base_layer_extra_keys[] = {6, 33, 24, 25, 26, 51, 52, 53};
static const char gaming_leds[] = {18, 22, 19, 16};
static const char gaming2_leds[] = {23, 18, 17, 10, 9, 22, 19, 16, 11, 8};
static const char nav_leds[] = {38, 43, 44, 46};
static const char fun_leds[] = {45, 44, 37, 46, 43, 38, 47, 42, 39, 40};
static const char mouse_leds[] = {11, 16, 17, 19};
static const char adjust_leds[] = {6, 33};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(26, RGB_RED);
    }
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
            for (uint8_t i = 0; i < 8; i++) {
                rgb_matrix_set_color(base_layer_extra_keys[i], RGB_SPRINGGREEN);
            }
            break;
        case _GAMING:
            if (is_keyboard_master()) {
                for (uint8_t i = 0; i < 4; i++) {
                    rgb_matrix_set_color(gaming_leds[i], 0x88, 0x00, 0x00);
                }
            }
            break;
        case _GAMING2:
            if (is_keyboard_master()) {
                for (uint8_t i = 0; i < 10; i++) {
                    rgb_matrix_set_color(gaming2_leds[i], RGB_GREEN);
                }
            }
            break;
        case _NAV:
            for (uint8_t i = 0; i < 4; i++) {
                rgb_matrix_set_color(nav_leds[i], RGB_BLUE);
            }
            break;
        case _FUN:
            for (uint8_t i = 0; i < 10; i++) {
                rgb_matrix_set_color(fun_leds[i], RGB_GREEN);
            }
            break;
        case _ADJUST:
            for (uint8_t i = 0; i < 2; i++) {
                rgb_matrix_set_color(adjust_leds[i], RGB_RED);
            }
            break;
        case _MOUSE:
            if (is_keyboard_master()) {
                for (uint8_t i = 0; i < 4; i++) {
                    rgb_matrix_set_color(mouse_leds[i], RGB_PURPLE);
                }
            }
            break;

    }
    return false;
}
