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
#define MATRIX_ROWS 2
#define MATRIX_COLS 1

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B1 } // , C6, D7, E6 }

#define MATRIX_COL_PINS { B2 } // , C1, B2, B6, B5, B4 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#if 0
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

#define RGB_DI_PIN B6
#define RGBLED_NUM 2
// #define RGBLED_SPLIT

#define RGBLIGHT_LAYERS

#define RGBLIGHT_HUE_STEP 25

#endif
