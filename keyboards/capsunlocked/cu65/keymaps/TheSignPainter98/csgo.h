#pragma once

#include <stdbool.h>
#include <stdint.h>
#include QMK_KEYBOARD_H

#define KCS_CSGO \
    KC_ANTI_ECO_HEAVY_BUY,\
    KC_ANTI_ECO_LIGHT_BUY,\
    KC_AWP,\
    KC_MAIN_HEAVY_BUY,\
    KC_MAIN_LIGHT_BUY,\
    KC_MAIN_MEDIUM_BUY,\
    KC_NADE_HEAVY,\
    KC_NADE_LIGHT,\
    KC_NADE_MEDIUM,\
    KC_PISTOL_HEAVY,\
    KC_PISTOL_LIGHT,\

bool process_record_user_csgo(uint16_t keycode, keyrecord_t* record);
