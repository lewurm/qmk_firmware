#include QMK_KEYBOARD_H
#include <bendalton.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //   [_QWERTY] = LAYOUT_wrapper(
    //  __DEBUG_12__,
    //  __DEBUG_12__,
    //  __DEBUG_12__,
    // __DEBUG_6__
//   ),
  [_QWERTY] = LAYOUT_wrapper(
      ____,____QWERTY_L1____,____QWERTY_R1____,____,
      ____,____QWERTY_L2____,____QWERTY_R2____,____,
      ____,____QWERTY_L3____,____QWERTY_R3____,____,
           ____THUMBS_L4____,____THUMBS_R4____
  ),
  [_COLEMAK] = LAYOUT_wrapper(
      ____,____COLEMAK_L1____,____COLEMAK_R1____,____,
      ____,____COLEMAK_L2____,____COLEMAK_R2____,____,
      ____,____COLEMAK_L3____,____COLEMAK_R3____,____,
            ____THUMBS_L4____,____THUMBS_R4____
  ),
  [_NUMBERS] = LAYOUT_wrapper(
      ____,____NUMBERS_L1____,____NUMBERS_R1____,____,
      ____,____NUMBERS_L2____,____NUMBERS_R2____,____,
      ____,____NUMBERS_L3____,____NUMBERS_R3____,____,
      ____THUMBS_TRNS____
  ),
  [_NAV] = LAYOUT_wrapper(
    ____,______NAV_L1______,______NAV_R1______,____,
    ____,______NAV_L2______,______NAV_R2______,____,
    ____,______NAV_L3______,______NAV_R3______,____,
    ____THUMBS_TRNS____
  ),
  [_SYMBOLS] = LAYOUT_wrapper(
    ____,____SYMBOLS_L1____,____SYMBOLS_R1____,____,
    ____,____SYMBOLS_L2____,____SYMBOLS_R2____,____,
    ____,____SYMBOLS_L3____,____SYMBOLS_R3____,____,
    ____THUMBS_TRNS____
  ),
  [_COMMAND] = LAYOUT_wrapper(
    ____,____COMMAND_L1____,____COMMAND_R1____,____,
    ____,____COMMAND_L2____,____COMMAND_R2____,____,
    ____,____COMMAND_L3____,____COMMAND_R3____,____,
    ____THUMBS_TRNS____
  )
};



// int RGB_current_mode;

// void matrix_init_user(void) {
//     default_layer_set(_QWERTY);

//     // #ifdef RGBLIGHT_ENABLE
//     //   RGB_current_mode = rgblight_config.mode;
//     // #endif
//     // //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//     // #ifdef SSD1306OLED
//     //     iota_gfx_init(!has_usb());   // turns on the display
//     // #endif
// }

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
// #ifdef SSD1306OLED

// // When add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// // void set_timelog(void);
// // const char *read_timelog(void);

// void matrix_scan_user(void) {
// //    iota_gfx_task();
// }

// void matrix_render_user(struct CharacterMatrix *matrix) {
//   if (is_master) {
//        matrix_write(matrix, read_logo());
//     // If you want to change the display of OLED, you need to change here
//     // matrix_write_ln(matrix, read_layer_state());
//     // matrix_write_ln(matrix, read_keylog());
//     //matrix_write_ln(matrix, read_keylogs());
//     // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
//     // matrix_write_ln(matrix, read_host_led_state());
//     //matrix_write_ln(matrix, read_timelog());
//   } else {
//     matrix_write(matrix, read_logo());
//   }
// }

// void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
// //   if (memcmp(dest->display, source->display, sizeof(dest->display))) {
// //     memcpy(dest->display, source->display, sizeof(dest->display));
// //     dest->dirty = true;
// //   }
// }

// void iota_gfx_task_user(void) {
//   struct CharacterMatrix matrix;
//   matrix_clear(&matrix);
//   matrix_render_user(&matrix);
//   matrix_update(&display, &matrix);
// }
// #endif//SSD1306OLED

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//   switch (keycode) {
//     case RGB_MOD:
//       #ifdef RGBLIGHT_ENABLE
//         if (record->event.pressed) {
//           rgblight_mode(RGB_current_mode);
//           rgblight_step();
//           RGB_current_mode = rgblight_config.mode;
//         }
//       #endif
//       return false;
//     case RGBRST:
//       #ifdef RGBLIGHT_ENABLE
//         if (record->event.pressed) {
//           eeconfig_update_rgblight_default();
//           rgblight_enable();
//           RGB_current_mode = rgblight_config.mode;
//         }
//       #endif
//       break;
//   }
//   return true;
// }

// // in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
// const char *read_layer_state(void) {
//   static char layer_state_str[24];
//   char layer_name[17];

//   switch (biton32(layer_state)) {
//     case _QWERTY:
//       strcpy(layer_name, "Qwerty");
//       break;
//     case _COLEMAK:
//       strcpy(layer_name, "Colemak");
//       break;
//     case _NAV:
//       strcpy(layer_name, "Navigation");
//       break;
//     case _NUMBERS:
//       strcpy(layer_name, "Numbers");
//       break;
//     case _SYMBOLS:
//       strcpy(layer_name, "Symbols");
//       break;
//     case _COMMAND:
//       strcpy(layer_name, "Command");
//       break;
//     default:
//       snprintf(layer_name, sizeof(layer_name), "Undef-%ld", layer_state);
//   }

//   strcpy(layer_state_str, "Layer: ");

//   strcat(layer_state_str, layer_name);
//   strcat(layer_state_str, "\n");
//   return layer_state_str;
// }
