#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Wulkan
#define PRODUCT         Handwired48Keys
#define DESCRIPTION     A compact ortholinear handwired keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

// top to bottom (with keyboard facing you)
#define MATRIX_ROW_PINS { A2, A1, A0, B8, B13 }
// left to right (with keyboard facing you)
#define MATRIX_COL_PINS { B15, B14, B9, B10, A6, A5, A4, B0, B4, B3, B2, B1 }

#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define FORCE_NKRO
