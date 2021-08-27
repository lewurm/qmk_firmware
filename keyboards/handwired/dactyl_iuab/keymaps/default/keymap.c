#include "kb.h"
#include "print.h"

extern keymap_config_t keymap_config;

// tap dance layers
enum {
 TD_CLN = 0, // ; or : or tap/dbl
 TD_CP = 3, // copy/paste/get last clipboard item/clipboard manager for tap/dbl/trpl/hold
 TD_DASH = 4, // - or _ for tap/dbl
 TD_QUOTE = 5, // ' or '' for tap/dbl
 TD_NUMTERM = 6, // hold for num layer, dbl tap toggle num layer, or tap for term
};

#define _QWERTY 0
#define _COLEMAK 1
#define _NAV 2
#define _SYMBOLS 3
#define _COMMAND 4
#define _NUMBERS 5

#define _CODE MO(_COMMAND)
#define _FSYM LT(_SYMBOLS,KC_F)
#define _ZCTL LCTL_T(KC_Z)
#define _XALT LALT_T(KC_X)
#define _CGUI LGUI_T(KC_C)
#define _TERM LGUI(KC_GRAVE)
#define _COMGUI RGUI_T(KC_COMM)
#define _DOTALT LALT_T(KC_DOT)
#define _SLSHCTL RCTL_T(KC_SLSH)
#define _ENTGUI LGUI_T(KC_ENT)
#define _SPCNAV LT(_NAV,KC_SPC)
#define _LINE_DOWN LALT(LSFT(KC_DOWN))
#define _LINE_UP LALT(LSFT(KC_UP))
#define _PREV_TAB LGUI(LSFT(KC_LBRC))
#define _NEXT_TAB LGUI(LSFT(KC_RBRC))
#define _TD_CLN TD(TD_CLN)
#define _TD_CP TD(TD_CP)
#define _TD_DASH TD(TD_DASH)
#define _TD_QUOTE TD(TD_QUOTE)
#define _TD_NUMTERM TD(TD_NUMTERM)
#define _WINMODE MAGIC_TOGGLE_CTL_GUI
#define ____ KC_NO
#define _QWERTY 0



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_2x1(
    //┌────────┐
        RGB_TOG, // KC_Q,   
    //├────────┤
        RGB_HUI // KC_N
    //└────────┘
    ),

};


// #define TAPPING_TERM 250
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _ENTGUI:
      return 190;
    case _SLSHCTL:
      return 300;
    default:
      return TAPPING_TERM;
  }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_mouse=true;
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  print("post init");
  for (int i = 0; i < RGBLED_NUM; i++) {
      switch (i % 6) {
          case 0:
            setrgb(0xff, 0, 0, &led[i]);
            break;
          case 1:
            setrgb(0, 0xff, 0, &led[i]);
            break;
          case 2:
            setrgb(0, 0, 0xff, &led[i]);
            break;
          case 3:
            setrgb(0xff, 0xff, 0, &led[i]);
            break;
          case 4:
            setrgb(0xff, 0, 0xff, &led[i]);
            break;
          case 5:
            setrgb(0, 0xff, 0xff, &led[i]);
            break;
      }
  }
  rgblight_set();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    xprintf("\nencoder update: index=%d, clockwise=%d\n", index, !!clockwise);
    if (index == 0) { /* First encoder */
        if (clockwise) {
            print("sending U");
            tap_code(KC_U);
        } else {
            print("sending D");
            tap_code(KC_D);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_P);
        } else {
            tap_code(KC_B);
        }
    }
    return true;
}
