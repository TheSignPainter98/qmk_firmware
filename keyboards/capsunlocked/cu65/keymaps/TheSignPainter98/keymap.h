#pragma once

// Qmk includes
#include QMK_KEYBOARD_H

// Mandatory includes
#include "layout.h"
#include "qmk_aliases.h"
#include <stdbool.h>
#include <stdint.h>

// Optional includes
#ifdef CSGO_ENABLE
#    include "csgo.h"
#endif

enum keycodes {
    KC_CUSTOM_UNUSED = SAFE_RANGE,
#ifdef CSGO_ENABLE
    KCS_CSGO,
#endif
};

enum layers {
    L_DEFAULT,
    L_FN,
};

enum tap_dances { TD_GRAVE_ESC };

extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern qk_tap_dance_action_t tap_dance_actions[];

bool process_record_user(uint16_t keycode, keyrecord_t* record);
