/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REV2_CONFIG_H
#define REV2_CONFIG_H
//#define CATERINA_BOOTLOADER
#include "../config.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    CH boxMods
#define PRODUCT         Dactyl
#define DESCRIPTION     A split ergonomic keyboard for the adventerous makers

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 14
#define MATRIX_COLS 6

// wiring of each half

//#define MATRIX_COL_PINS { B5,B4,E6,D7,C6,D4}
//#define MATRIX_ROW_PINS { B6,B2, B3, B1,F7, F6,F5 }

//QMK DFU related stuff
#define QMK_ESC_OUTPUT B4 // usually COL
#define QMK_ESC_INPUT B2 // usually ROW
#define QMK_LED B0
#define QMK_SPEAKER C6

// wiring of each half

//#define MATRIX_COL_PINS { B5,B4,E6,D7,C6,D4}
//#define MATRIX_ROW_PINS { B6,B2, B3, B1,F7, F6,F5 }

//#define MATRIX_COL_PINS { B4,E6,D7,D4,D2,D3}
//#define MATRIX_ROW_PINS { B2,B3,B1,F7,F6,F5,F4 }

#define MATRIX_COL_PINS { B4,E6,D7,D4,D2,D3 }
#define MATRIX_ROW_PINS { B2,B3,B1,F7,F6,F5 }


/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLIGHT_TIMER
#define RGBLED_NUM 12    // Number of LEDs
#define ws2812_PORTREG  PORTD
#define ws2812_DDRREG   DDRD



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION


#endif
