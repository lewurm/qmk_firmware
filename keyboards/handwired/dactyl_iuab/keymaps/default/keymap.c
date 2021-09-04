#include "kb.h"
#include "print.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _NAV 2
#define _SYMBOLS 3
#define _COMMAND 4
#define _NUMBERS 5


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_2x1(
    //┌────────┐
        RGB_TOG, // KC_Q,   
    //├────────┤
        RGB_HUI // KC_N
    //└────────┘
    ),

};


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

