#pragma once

// Options
#define CSGO_ENABLE
#define TAPPING_TERM 100

// Qmk includes
#include QMK_KEYBOARD_H

// Mandatory includes
#include "layout.h"
#include "qmk-aliases.h"
#include "func-sig.h"
#include <stdbool.h>
#include <stdint.h>

// Optional includes
#include "csgo.h"

enum keycodes { KC_CUSTOM_UNUSED = SAFE_RANGE, KCS_CSGO };

enum layers {
    L_DEFAULT,
    L_FN,
    L_CSGO,
};

enum tap_dances { TD_GRAVE_ESC };

extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern qk_tap_dance_action_t  tap_dance_actions[];

bool process_record_user(uint16_t keycode, keyrecord_t* record);
