#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0002
#define MANUFACTURER    lewurm
#define PRODUCT         DactylIUAB
#define DESCRIPTION     Dactyl Manuform I am using Arch btw

/* mouse config */
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, F5, F6, F7, B1, B2 }

#define MATRIX_COL_PINS { D3, D2, D1, D0, D4, C6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#if 1
#define DIODE_DIRECTION COL2ROW
#else
#define DIODE_DIRECTION ROW2COL
#endif

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCING_DELAY 5

#define RETRO_TAPPING

// #define ENCODERS_PAD_A { B1 }
// #define ENCODERS_PAD_B { B3 }

#define ENCODER_RESOLUTION 2

#if 0
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D1
#define USE_SERIAL
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

#define COMBO_COUNT 16
// #define COMBO_ALLOW_ACTION_KEYS
#define COMBO_TERM 150

#define RGB_DI_PIN E6
#define RGBLED_NUM 30
// #define RGBLED_SPLIT

#define RGBLIGHT_LAYERS

#define RGBLIGHT_HUE_STEP 25

#endif
