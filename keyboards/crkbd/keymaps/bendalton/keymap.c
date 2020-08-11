#include QMK_KEYBOARD_H
#include <print.h>
#include <string.h>

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// tap dance layers
enum {
 TD_CLN = 0, // ; or : or tap/dbl
 TD_CP = 3, // copy/paste/get last clipboard item/clipboard manager for tap/dbl/trpl/hold
 TD_DASH = 4, // - or _ for tap/dbl
 TD_QUOTE = 5, // ' or '' for tap/dbl
 TD_NUMTERM = 6, // hold for num layer, dbl tap toggle num layer, or tap for term
 TD_ENTGUI = 7,
};

enum my_keycodes {
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


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  RGB_TOG,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RESET,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   CMD_Z,   CTRL_X,   ALT_C,   GUI_V,   NUM_B,                       NUM_N,    GUI_M,  ALT_COMM, CTRL_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     _NUM,  _SFT_DEL,_TD_ENTGUI,  _SPCNAV, _SFT_BSPC, SYM_OS
                                      //`--------------------------'  `--------------------------'

  ),

      [_COLEMAK] = LAYOUT(
    ____, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,               KC_J,    KC_L,    KC_U,    KC_Y,   _TD_CLN,____,
    ____, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,____,
    ____, CMD_Z,   CTRL_X,   ALT_C,   GUI_V,   NUM_B,               NUM_K,    GUI_M,  ALT_COMM, CTRL_DOT, KC_SLSH,____,
     _NUM,  _SFT_DEL,_TD_ENTGUI,                   _SPCNAV, _SFT_BSPC, SYM_OS
     ),

       [_NAV] = LAYOUT(
    ____,____, ____,  ____, ____,  ____,               KC_END, KC_PGDN, KC_PGUP, KC_HOME, ____,____,
   ____, ____, ____, KC_MUTE, KC_VOLU,  ____,               KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  ____,____,
   ____, KC_LALT, KC_LCTL, KC_LGUI, KC_VOLD, ____,              _PREV_TAB,_LINE_DOWN,_LINE_UP,_NEXT_TAB,   ____,____,
    _______,  _______, _______,  _______,  _______, _______
  ),
    [_SYMBOLS] = LAYOUT(
   ____,____,    ____,    ____,    ____,   ____,                       LSFT(KC_BSLASH),  KC_GRV,  KC_LCBR, KC_RCBR, LSFT(KC_MINUS),____,
   ____, ____,    ____,    ____,   ____, ____,                               KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINUS,____,
    ____,   KC_LCTRL, KC_LALT, KC_LGUI,  ____,   ____,    KC_PLUS,  KC_EQL,  KC_LT,   KC_GT,  KC_BSLASH,____,
      _______,  _______, _______,  _______,  _______, _______
    ),
    [_COMMAND] = LAYOUT(
  RGB_TOG,RESET, _WINMODE, ____, TO(_COLEMAK),TO(_QWERTY),                       HYPR(KC_Y),HYPR(KC_U),HYPR(KC_I),HYPR(KC_O),    HYPR(KC_B),____,
   RGB_MOD,____,   DEBUG,    ____,    ____, ____,                              HYPR(KC_H),HYPR(KC_J),HYPR(KC_K),HYPR(KC_L),    HYPR(KC_X),____,
   RGBRST,   ____,   LCTL(KC_LEFT),LCTL(KC_DOWN),LCTL(KC_UP),LCTL(KC_RIGHT),   HYPR(KC_N),HYPR(KC_M),HYPR(KC_T),HYPR(KC_G),  HYPR(KC_G),____,
    _______,  _______, _______,  _______,  _______, _______
    ),
    [_NUMBERS] = LAYOUT(
   ____,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                  LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),____,
   ____,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,____,
   ____, ____,    ____,    ____,    ____,  ____,   KC_PLUS, KC_EQL,  KC_COMM,  KC_DOT,  KC_SLSH,____,
      _______,  _______, _______,  _______,  _______, _______
    )


};

bool is_mac(void){
    keymap_config.raw = eeconfig_read_keymap();
    return !keymap_config.swap_lctl_lgui;
}

// Combo Stuff
enum combo_events {
  WE_ESC,
  SD_TAB,
  LCLN_QUOTE,
  XC_COPY,
  CV_PASTE,
  WF_ESC,
  RS_TAB,
  IO_QUOTE,
};

const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM tabQ_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM escQ_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM quoteQ_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM tabC_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM escC_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM quoteC_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [XC_COPY] = COMBO_ACTION(copy_combo),
  [CV_PASTE] = COMBO_ACTION(paste_combo),
  [SD_TAB] = COMBO_ACTION(tabQ_combo),
  [WE_ESC] = COMBO_ACTION(escQ_combo),
  [LCLN_QUOTE] = COMBO_ACTION(quoteQ_combo),
  [RS_TAB] = COMBO_ACTION(tabC_combo),
  [WF_ESC] = COMBO_ACTION(escC_combo),
  [IO_QUOTE] = COMBO_ACTION(quoteC_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
//   uprintf("Combo Event: index: %u (%d)\n", combo_index, pressed);
  switch(combo_index) {
    case XC_COPY:
      if (pressed) {
        tap_code16(LGUI(KC_C));
      }
      break;
    case CV_PASTE:
      if (pressed) {
        tap_code16(LGUI(KC_V));
      }
      break;
    case SD_TAB:
    case RS_TAB:
      if (pressed) {
        if (keyboard_report->mods & MOD_BIT (KC_LCTL) && !is_mac()) {
            unregister_mods(MOD_BIT (KC_LCTL));
            register_mods(MOD_BIT (KC_LALT));
        }
        tap_code(KC_TAB);
      }else{
        if (keyboard_report->mods & MOD_BIT (KC_LALT) && !is_mac()) {
            unregister_mods(MOD_BIT (KC_LALT));
            register_mods(MOD_BIT (KC_LCTL));
        }
      }
      break;
    case WE_ESC:
    case WF_ESC:
      if (pressed) {
        if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
            tap_code16(LSFT(KC_GRAVE));
        }else if (keyboard_report->mods & MOD_BIT(KC_LGUI)) {
            tap_code(KC_GRAVE);
        }else{
            tap_code(KC_ESC);
        }
      }
      break;
    case LCLN_QUOTE:
    case IO_QUOTE:
      if (pressed) {
        tap_code(KC_QUOT);
      }
      break;
  }
}

// Tap Dance Stuff

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  HOLD = 1,
  SINGLE_TAP = 2,
  DOUBLE_TAP = 3,
  TRIPLE_TAP = 4,
  QUAD_TAP = 5
};

int cur_dance (qk_tap_dance_state_t *state) {
  if(state->pressed)
    return HOLD;

  if (state->count == 1)
    return SINGLE_TAP;

  if (state->count == 2)
    return DOUBLE_TAP;

  if (state->count == 3)
    return TRIPLE_TAP;

  if (state->count == 4)
    return QUAD_TAP;

   return -1;
}

// TODO add triple tap to undo a copy - e.g., open clipboard history, hit down twice and enter
static int dance_entgui_state = -1;
void dance_entgui_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_entgui_state = cur_dance(state);
  switch (dance_entgui_state) {
    case SINGLE_TAP:
        register_code(KC_ENT);
        break;
    case DOUBLE_TAP:
        if(is_mac()){
            register_mods(MOD_BIT(KC_LGUI));
        }else{
            register_mods(MOD_BIT(KC_LCTL));
        }
        register_code(KC_ENT);
        break;
    case HOLD:
        if(is_mac()){
            register_mods(MOD_BIT(KC_LGUI));
        }else{
            register_mods(MOD_BIT(KC_LCTL));
        }

    }
}

void dance_entgui_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_entgui_state) {
    case SINGLE_TAP:
        unregister_code(KC_ENT);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_ENT);
         if(is_mac()){
            unregister_mods(MOD_BIT(KC_LGUI));
        }else{
            unregister_mods(MOD_BIT(KC_LCTL));
        }
        break;
    case HOLD:
        if(is_mac()){
            unregister_mods(MOD_BIT(KC_LGUI));
        }else{
            unregister_mods(MOD_BIT(KC_LCTL));
        }
    }
    dance_entgui_state = -1;
}

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

// TODO add triple tap to undo a copy - e.g., open clipboard history, hit down twice and enter
static int dance_copypaste_state = -1;
void dance_copypaste_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_copypaste_state = cur_dance(state);
  switch (dance_copypaste_state) {
    case SINGLE_TAP:
        register_mods(MOD_BIT(KC_LGUI));
        register_code(KC_C);
        break;
    case DOUBLE_TAP:
        register_mods(MOD_BIT(KC_LGUI));
        register_code(KC_V);
        break;
    case TRIPLE_TAP:
        SEND_STRING(SS_LGUI(SS_LALT("c")) SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_ENTER));
        break;
    case HOLD:
        register_mods(MOD_BIT(KC_LGUI));
        register_mods(MOD_BIT(KC_LALT));
        register_code(KC_C);
    }
}

void dance_copypaste_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_copypaste_state) {
    case SINGLE_TAP:
        unregister_code(KC_C);
        unregister_mods(MOD_BIT(KC_LGUI));
        break;
    case DOUBLE_TAP:
        unregister_code(KC_V);
        unregister_mods(MOD_BIT(KC_LGUI));
        break;
    case HOLD:
        unregister_code(KC_C);
        unregister_mods(MOD_BIT(KC_LGUI));
        unregister_mods(MOD_BIT(KC_LALT));
    }
    dance_copypaste_state = -1;
}

static int dance_dash_state = -1;
void dance_dash_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_dash_state = cur_dance(state);
  switch (dance_dash_state) {
    case SINGLE_TAP:
        register_code(KC_MINUS);
        break;
    case DOUBLE_TAP:
        register_mods(MOD_BIT(KC_LSFT));
        register_code(KC_MINUS);
        break;
    }
}

void dance_dash_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_dash_state) {
    case SINGLE_TAP:
        unregister_code(KC_MINUS);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_MINUS);
        unregister_mods(MOD_BIT(KC_LSFT));
        break;
    }
    dance_dash_state = -1;
}
static int dance_quote_state = -1;
void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data) {
    dance_quote_state = cur_dance(state);
     switch (dance_quote_state) {
    case SINGLE_TAP:
        register_code (KC_QUOT);
        break;
    case DOUBLE_TAP:
        register_code (KC_RSFT);
        register_code (KC_QUOT);
        break;
    case HOLD:
        layer_on(_NUMBERS);
    }
}

void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_quote_state) {
    case SINGLE_TAP:
        unregister_code (KC_QUOT);
        break;
    case DOUBLE_TAP:
        unregister_code (KC_RSFT);
        unregister_code (KC_QUOT);
        break;
    case HOLD:
        layer_off(_NUMBERS);
    }
    dance_quote_state = -1;
}

// TODO add triple tap to undo a copy - e.g., open clipboard history, hit down twice and enter
static int dance_numterm_state = -1;
void dance_numterm_fin (qk_tap_dance_state_t *state, void *user_data) {
  dance_numterm_state = cur_dance(state);
  switch (dance_numterm_state) {
    case SINGLE_TAP:
        register_mods(MOD_BIT(KC_LGUI));
        register_code(KC_GRV);
        break;
    case DOUBLE_TAP:
        // do nothing here
        break;
    case HOLD:
        layer_on(_NUMBERS);
    }
}

void dance_numterm_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dance_numterm_state) {
    case SINGLE_TAP:
        unregister_code(KC_GRV);
        unregister_mods(MOD_BIT(KC_LGUI));
        break;
    case DOUBLE_TAP:
        if (layer_state_is(_NUMBERS))
        {
            layer_off(_NUMBERS);
        } else {
            layer_on(_NUMBERS);
        }
        break;
    case HOLD:
        layer_off(_NUMBERS);
    }
    dance_numterm_state = -1;
}

// TODO: ADD doubletap to code key for capslock w/ color managment
// void dance_capslock_fin (qk_tap_dance_state_t *state, void *user_data) {
//   switch (dance_dash_state) {
//     case SINGLE_TAP:
//         unregister_code(KC_MINUS);
//         break;
//     case DOUBLE_TAP:
//         unregister_code(KC_MINUS);
//         unregister_mods(MOD_BIT(KC_LSFT));
//         break;
//     case HOLD:

//     }
//     dance_dash_state = -1;
// }

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset), // semicolon and colon on tap/dbltap
 [TD_CP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_copypaste_fin, dance_copypaste_reset), // copy/paste/undo-copy/clipboard history
 [TD_DASH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_dash_fin, dance_dash_reset), // - or _ for tap/dbl
 [TD_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quote_finished, dance_quote_reset), // ' or '' for tap/dbl
 [TD_NUMTERM] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_numterm_fin, dance_numterm_reset),
 [TD_ENTGUI] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_entgui_fin, dance_entgui_reset)
};
// Custom tapping terms

// #define TAPPING_TERM 150
uint16_t get_tapping_term(uint16_t keycode) {

//   uprintf("Looking for TappingTerm: kc: %u (%u?)\n", keycode, _SPCNAV);
  switch (keycode) {
    case _SPCNAV:
        return 200;
    case TD_ENTGUI:
       return 190;
    case _SFT_BSPC:
    case _SFT_DEL:
        return 130;
    case CTRL_X:
    case CTRL_DOT:
    case ALT_COMM:
    case ALT_C:
    case GUI_M:
    case GUI_V:
      return 500;
    default:
      return TAPPING_TERM;
  }
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _QWERTY:
        if(isLeftHand) {

          rgblight_setrgb_at(148, 0, 211, 13); // sets LED number 13 (lower) to purple on left hand

        } else {

          for(int i=10; i < 21; i ++) {
            if(i != 13){
              rgblight_setrgb_at(0, 255, 150, i); // sets LED 10-21 but not 13 to cyan on right hand
            }
          }
        }
        break;
    case _NUMBERS:

        // if(!isLeftHand) {
          rgblight_setrgb_at(148, 0, 211, 13); // same thing here, sets LED 13 (raise) to purple and HJKL to cyan
          rgblight_setrgb_at(0, 255, 150, 8);
          rgblight_setrgb_at(0, 255, 150, 11);
          rgblight_setrgb_at(0, 255, 150, 16);
          rgblight_setrgb_at(0, 255, 150, 19);
        // }

        break;
    // case _ADJUST:
    //   if(isLeftHand){
    //     rgblight_setrgb_at(148,0,211, 26); // control purple, ZXCV cyan.
    //     rgblight_setrgb_at(0,255,150,21);
    //     rgblight_setrgb_at(0,255,150,20);
    //     rgblight_setrgb_at(0,255,150,15);
    //     rgblight_setrgb_at(0,255,150,12);
    //   }
    //   break;
    default:
    //  rgblight_disable();
        rgblight_enable();

        // if(isLeftHand) {                        // this sets the underside LEDs (1-6) to cyan on both sides and does nothing with the rest.
        //   for(int i=0; i < 6; i ++) {           // this also means that if I manually change LED color to red, the bottom 6 LEDS will ALWAYS be cyan.
        //     rgblight_setrgb_at(0, 0, 255, i); // it's the only way I found to make it switch back to underglow LEDs after I've used another layer.
        //   }
        // } else {
        //   for(int j=0; j < 6; j ++) {
        //     rgblight_setrgb_at(0, 0, 255, j);
        //   }
        // }
        break;
    }
  return state;
}




int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    // matrix_write_ln(matrix, read_layer_state());
    // matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    // matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    // set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    // case QWERTY:
    //   if (record->event.pressed) {
    //     persistent_default_layer_set(1UL<<_QWERTY);
    //   }
    //   return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
const char *read_layer_state(void) {
  static char layer_state_str[24];
  char layer_name[17];

  switch (biton32(layer_state)) {
    case _QWERTY:
      strcpy(layer_name, "Qwerty");
      break;
    case _COLEMAK:
      strcpy(layer_name, "Colemak");
      break;
    case _NAV:
      strcpy(layer_name, "Navigation");
      break;
    case _NUMBERS:
      strcpy(layer_name, "Numbers");
      break;
    case _SYMBOLS:
      strcpy(layer_name, "Symbols");
      break;
    case _COMMAND:
      strcpy(layer_name, "Command");
      break;
    default:
      snprintf(layer_name, sizeof(layer_name), "Undef-%ld", layer_state);
  }

  strcpy(layer_state_str, "Layer: ");

  strcat(layer_state_str, layer_name);
  strcat(layer_state_str, "\n");
  return layer_state_str;
}
