#pragma once

#include <stdbool.h>
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "tsp-util.h"

#define KCS_CSGO \
    KC_NADE_DECOY,\
    KC_NADE_FLASH,\
    KC_NADE_HE,\
    KC_NADE_MOLLY,\
    KC_ARMOUR_LIGHT,\
    KC_ARMOUR_HEAVY,\
    KC_DEFUSE_KIT,\

#define TDNS_CSGO \
    TD_ANTI_ECO_HEAVY,\
    TD_ANTI_ECO_LIGHT,\
    TD_AWP,\
    TD_MAIN_HEAVY,\
    TD_MAIN_LIGHT,\
    TD_MAIN_MEDIUM,\
    TD_PISTOL_HEAVY,\
    TD_PISTOL_LIGHT,\
    TD_PISTOL_MEDIUM,\

#define CSGO_BUY_TDA(n) [TD_##n] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, csgo_tap_dance_finished, NULL)
#define TDS_CSGO \
    CSGO_BUY_TDA(ANTI_ECO_HEAVY),\
    CSGO_BUY_TDA(ANTI_ECO_LIGHT),\
    CSGO_BUY_TDA(AWP),\
    CSGO_BUY_TDA(MAIN_HEAVY),\
    CSGO_BUY_TDA(MAIN_LIGHT),\
    CSGO_BUY_TDA(MAIN_MEDIUM),\
    CSGO_BUY_TDA(PISTOL_HEAVY),\
    CSGO_BUY_TDA(PISTOL_LIGHT),\
    CSGO_BUY_TDA(PISTOL_MEDIUM),

PRU_SIG(csgo)

void csgo_tap_dance_finished(qk_tap_dance_state_t* state, void* user_data);
