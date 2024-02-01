#pragma once

enum crkbd_layers {
  _BASE,
  _GAMING,
  _GAMING2,
  _ACCENTS,
  _LOWER,
  _RAISE,
  _FUN,
  _NAV,
  _MOUSE,
  _ADJUST
};

#define CTRLSC LCTL_T(KC_ESC)
#define QUORCTL RCTL_T(KC_QUOT)
#define MOSCLN LT(_MOUSE,KC_SCLN)
#define ACCENTS LT(_ACCENTS,KC_RALT)
#define FUN LT(_FUN,KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SPCNAV LT(_NAV,KC_SPC)
#define SFTENT MT(MOD_RSFT,KC_ENT)
#define TABLGUI LGUI_T(KC_TAB)
#define BASE DF(_BASE)
#define GAMING DF(_GAMING)
#define GAMING2 MO(_GAMING2)

#define SC_F1 LSFT(LCTL(KC_F1))
#define SC_F2 LSFT(LCTL(KC_F2))
#define SC_F3 LSFT(LCTL(KC_F3))
#define SC_F4 LSFT(LCTL(KC_F4))

#define SC_TILD RALT(KC_1)  // ~
#define SC_LCBR RALT(KC_B)  // {
#define SC_RCBR RALT(KC_N)  // }
#define SC_LPRN LSFT(KC_8)  // (
#define SC_RPRN LSFT(KC_9)  // )
#define SC_PIPE RALT(KC_W)  // |
#define SC_AT RALT(KC_V)    // @
#define SC_EXLM LSFT(KC_1)  // !
#define SC_HASH LSFT(KC_3)  // #
#define SC_DLR LSFT(KC_4)   // $
#define SC_PERC LSFT(KC_5)  // %
#define SC_VOLU RGUI(KC_F12) // Volume UP
#define SC_VOLD RGUI(KC_F11) // Volume DOWN
#define SC_MUTE RGUI(KC_F11) // Volume MUTE
