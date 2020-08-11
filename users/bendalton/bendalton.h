/*
Copyright 2020 Ben Dalton

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu/org/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H

enum shared_layers {
  _QWERTY,
  _COLEMAK,
  _NAV,
  _SYMBOLS,
  _COMMAND,
  _NUMBERS,
  _ADJUST
};

// KEYCODES ============================================================================

enum bendalton_keycodes {
  TOGGLE_LIGHTS = SAFE_RANGE,
  BRIGHTER,
  DIMMER,
  BACKLIT,
  RGBRST
};

#define _QWERTY 0
#define _COLEMAK 1
#define _NAV 2
#define _SYMBOLS 3
#define _COMMAND 4
#define _NUMBERS 5
#define _ADJUST 6

#define _CODE MO(_COMMAND)
#define _SYM MO(_SYMBOLS)
#define _NUM MO(_NUMBERS)
#define _FSYM LT(_SYMBOLS,KC_F)
#define _ASFT LSFT_T(KC_Z)
#define _SLSHFT LSFT_T(KC_SLSH)
#define _XALT LALT_T(KC_X)
#define _CGUI LGUI_T(KC_C)
#define _ZCTL LCTL_T(KC_Z)
#define _XALT LALT_T(KC_X)
#define _CGUI LGUI_T(KC_C)
#define _TERM LGUI(KC_GRAVE)
#define _COMGUI RGUI_T(KC_COMM)
#define _DOTALT LALT_T(KC_DOT)
#define _SLSHCTL RCTL_T(KC_SLSH)
#define _TD_ENTGUI TD(TD_ENTGUI)
#define _SPCNAV LT(_NAV,KC_SPC)
#define _LINE_DOWN LALT(LSFT(KC_DOWN))
#define _LINE_UP LALT(LSFT(KC_UP))
#define _PREV_TAB LGUI(LSFT(KC_LBRC))
#define _NEXT_TAB LGUI(LSFT(KC_RBRC))
#define _TD_CLN TD(TD_CLN)
#define _TD_CP TD(TD_CP)
#define _TD_DASH TD(TD_DASH)
#define _TD_QUOTE TD(TD_QUOTE)
#define _SFT_BSPC LSFT_T(KC_BSPC)
#define _TD_NUMTERM TD(TD_NUMTERM)
#define _WINMODE MAGIC_TOGGLE_CTL_GUI
#define _SFT_DEL LSFT_T(KC_DEL)
#define ALT_C LALT_T(KC_C)
#define ALT_COMM LALT_T(KC_COMM)
#define ALT_D LALT_T(KC_D)
#define CTRL_X LCTL_T(KC_X)
#define CTRL_DOT LCTL_T(KC_DOT)
#define GUI_V LGUI_T(KC_V)
#define GUI_M LGUI_T(KC_M)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))
#define CMD_Z LT(_COMMAND,KC_Z)
#define SYM_OS OSL(_SYMBOLS)
#define NUM_B LT(_NUMBERS,KC_B)
#define NUM_N LT(_NUMBERS,KC_N)
#define NUM_K LT(_NUMBERS,KC_K)

#define ____ KC_NO

// COMBOS ==============================================================================

enum combo_events {
  WE_ESC,
  SD_TAB,
  LCLN_QUOTE,
  WF_ESC,
  RS_TAB,
  IO_QUOTE,
};

// TAP DANCE

// tap dance layers
enum {
 TD_CLN = 0, // ; or : or tap/dbl
 TD_CP = 3, // copy/paste/get last clipboard item/clipboard manager for tap/dbl/trpl/hold
 TD_DASH = 4, // - or _ for tap/dbl
 TD_QUOTE = 5, // ' or '' for tap/dbl
 TD_NUMTERM = 6, // hold for num layer, dbl tap toggle num layer, or tap for term
 TD_ENTGUI = 7,
};


// LAYOUT WRAPPERS =====================================================================
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)

/* THUMBS ============================================================================== */

#define ____THUMBS_L4____    _NUM,    _SFT_DEL,  _TD_ENTGUI
#define ____THUMBS_R4____    _SPCNAV, _SFT_BSPC, SYM_OS



/* QWERTY ============================================================================== */

// LEFT
// - CORE
#define ____QWERTY_L1____    KC_Q,   KC_W,   KC_E,     KC_R,    KC_T
#define ____QWERTY_L2____    KC_A,   KC_S,   KC_D,     KC_F,    KC_G
#define ____QWERTY_L3____    CMD_Z,  CTRL_X, ALT_C,    GUI_V,   NUM_B

// RIGHT
// - CORE
#define ____QWERTY_R1____    KC_Y,  KC_U,   KC_I,     KC_O,     KC_P
#define ____QWERTY_R2____    KC_H,  KC_J,   KC_K,     KC_L,     KC_SCLN
#define ____QWERTY_R3____    NUM_N, GUI_M,  ALT_COMM, CTRL_DOT, KC_SLSH

/* COLEMAK ============================================================================== */

// LEFT
// - CORE
#define ____COLEMAK_L1____    KC_Q,   KC_W,   KC_F,     KC_P,    KC_G
#define ____COLEMAK_L2____    KC_A,   KC_R,   KC_S,     KC_T,    KC_D
#define ____COLEMAK_L3____    CMD_Z,  CTRL_X, ALT_C,    GUI_V,   NUM_B

// RIGHT
// - CORE
#define ____COLEMAK_R1____    KC_J,   KC_L,  KC_U,     KC_Y,     _TD_CLN
#define ____COLEMAK_R2____    KC_H,   KC_N,  KC_KE     KC_I,     KC_O
#define ____COLEMAK_R3____    NUM_K,  GUI_M, ALT_COMM, CTRL_DOT, KC_SLSH

/* NUMBERS ============================================================================== */

// LEFT
// - CORE
#define ____NUMBERS_L1____    LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5)
#define ____NUMBERS_L2____    KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define ____NUMBERS_L3____    ____,    ____,    ____,    ____,  ____

// RIGHT
// - CORE
#define ____NUMBERS_R1____    LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0)
#define ____NUMBERS_R2____    KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define ____NUMBERS_R3____    KC_PLUS, KC_EQL,  KC_COMM,  KC_DOT,  KC_SLSH

/* NAV ============================================================================== */

// LEFT
// - CORE
#define ______NAV_L1______    ____,    ____,    ____,    ____,    ____
#define ______NAV_L2______    ____,    ____,    KC_MUTE, KC_VOLU, ____
#define ______NAV_L3______    KC_LALT, KC_LCTL, KC_LGUI, KC_VOLD, ____

// RIGHT
// - CORE
#define ______NAV_R1______    KC_END,    KC_PGDN,    KC_PGUP,  KC_HOME,   ____
#define ______NAV_R2______    KC_LEFT,   KC_DOWN,    KC_UP,    KC_RGHT,   ____
#define ______NAV_R3______    _PREV_TAB, _LINE_DOWN, _LINE_UP, _NEXT_TAB, ____

/* SYMBOLS ============================================================================== */

// LEFT
// - CORE
#define ____SYBMOLS_L1____    ____,    ____,    ____,    ____,   ____
#define ____SYBMOLS_L2____    ____,    ____,    ____,    ____,   ____
#define ____SYBMOLS_L3____    KC_LCTRL, KC_LALT, KC_LGUI,  ____,   ____

// RIGHT
// - CORE
#define ____SYBMOLS_R1____    LSFT(KC_BSLASH),  KC_GRV,  KC_LCBR, KC_RCBR, LSFT(KC_MINUS)
#define ____SYBMOLS_R2____    KC_LBRC,          KC_RBRC, KC_LPRN, KC_RPRN, KC_MINUS
#define ____SYBMOLS_R3____    KC_PLUS,          KC_EQL,  KC_LT,   KC_GT,   KC_BSLASH

/* COMMAND ============================================================================== */

// LEFT
// - CORE
#define ____COMMAND_L1____    RESET,     _WINMODE,      ____,          TO(_COLEMAK),  TO(_QWERTY)
#define ____COMMAND_L2____    ____,      DEBUG,         ____,          ____, ____
#define ____COMMAND_L3____    ____,      LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP),LCTL(KC_RIGHT)

// RIGHT
// - CORE
#define ____COMMAND_R1____    HYPR(KC_Y),HYPR(KC_U),HYPR(KC_I),HYPR(KC_O),HYPR(KC_B)
#define ____COMMAND_R2____    HYPR(KC_H),HYPR(KC_J),HYPR(KC_K),HYPR(KC_L),HYPR(KC_X)
#define ____COMMAND_R3____    HYPR(KC_N),HYPR(KC_M),HYPR(KC_T),HYPR(KC_G),HYPR(KC_G)





