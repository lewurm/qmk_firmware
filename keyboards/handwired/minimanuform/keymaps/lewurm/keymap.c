#include "kb.h"

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
#define _NUMBERS 1
#define _MISC 2

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
#define zzzz KC_TRNS
// bitwarden
#define PWD LGUI(LSFT(KC_L))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSLASH,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                         KC_LEFT, KC_LALT, KC_SPC,   KC_BSPC,              KC_ENT,  KC_LCTL, KC_DOWN, KC_UP,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                     KC_LGUI,           MO(_NUMBERS)
    //                                             └────────┘           └────────┘
    ),

   	[_NUMBERS] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TILD, KC_EXLM,  KC_AT, KC_HASH,  KC_DLR,  KC_PERC,             KC_CIRC,  KC_7,    KC_8,    KC_9,   KC_ASTR, KC_EQL,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCBR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR,             KC_PLUS,  KC_4,    KC_5,    KC_6,    KC_0,  KC_MEDIA_PLAY_PAUSE,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ┌────────┼────────┼────────┼────────┼────────┼────────┤
         zzzz,    zzzz,   KC_EQL,  KC_LEFT, KC_RIGHT, KC_GRV,            KC_MINUS,  KC_1,    KC_2,    KC_3,   KC_MUTE,  zzzz,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                           zzzz,    zzzz,    zzzz,    zzzz,              MO(_MISC), zzzz,   KC_VOLD, KC_VOLU,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                      zzzz,                zzzz
    //                                             └────────┘           └────────┘
    ),

   	[_MISC] = LAYOUT_5x6(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         zzzz,    zzzz,    zzzz,    zzzz,    RESET,   zzzz,                zzzz,    zzzz,    zzzz,    zzzz,    zzzz,    zzzz,
    //├────────┼────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┼────────┤
         zzzz,   KC_DEL, KC_HOME,KC_PGDOWN, KC_PGUP, KC_END,               zzzz,    zzzz,    zzzz,     PWD,    zzzz,    zzzz,
    //├────────┼────────┼────────┼────────┼────────┼────────┼           ┌────────┼────────┼────────┼────────┼────────┼────────┤
         zzzz,    zzzz,    zzzz,    zzzz,    zzzz,    zzzz,                zzzz,    zzzz,    zzzz,    zzzz,    zzzz,    zzzz,
    //└────────┴────────┼────────┼────────┼────────┼────────┤           ├────────┼────────┼────────┼────────┼────────┴────────┘
                           zzzz,    zzzz,    zzzz,    zzzz,                zzzz,    zzzz,    zzzz,    zzzz,
    //                  └────────┴────────┴────────┼────────┤           ├────────┼────────┴────────┴────────┘
                                                      zzzz,             zzzz
    //                                             └────────┘           └────────┘
    )

};


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

void dance_quote_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_QUOT);
  }
}

void dance_quote_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_QUOT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_QUOT);
  }
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
#if 0
 [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset), // semicolon and colon on tap/dbltap
 [TD_CP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_copypaste_fin, dance_copypaste_reset), // copy/paste/undo-copy/clipboard history
 [TD_DASH] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_dash_fin, dance_dash_reset), // - or _ for tap/dbl
 [TD_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quote_finished, dance_quote_reset), // ' or '' for tap/dbl
 [TD_NUMTERM] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_numterm_fin, dance_numterm_reset)
#endif
};
// Custom tapping terms

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
//   debug_enable=true;
//   debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
