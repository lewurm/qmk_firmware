#include "bendalton.h"

extern keymap_config_t keymap_config;


bool is_mac(void){
    keymap_config.raw = eeconfig_read_keymap();
    return !keymap_config.swap_lctl_lgui;
}

const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM tabQ_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM escQ_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM quoteQ_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM tabC_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM escC_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM quoteC_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
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


qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset), // semicolon and colon on tap/dbltap
 [TD_DASH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_dash_fin, dance_dash_reset), // - or _ for tap/dbl
 [TD_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quote_finished, dance_quote_reset), // ' or '' for tap/dbl
 [TD_NUMTERM] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_numterm_fin, dance_numterm_reset),
 [TD_ENTGUI] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_entgui_fin, dance_entgui_reset)
};

// // Custom tapping terms

uint16_t get_tapping_term(uint16_t keycode) {

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


// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

