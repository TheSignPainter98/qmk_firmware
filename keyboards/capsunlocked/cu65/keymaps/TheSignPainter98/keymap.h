#pragma once

// Qmk includes
#include QMK_KEYBOARD_H

// Options
#undef TAPPING_TERM
#define TAPPING_TERM 100

// Mandatory includes
#include "func-sig.h"
#include "layout.h"
#include "qmk-aliases.h"
#include <stdbool.h>
#include <stdint.h>

// Optional includes
#ifdef CSGO_ENABLE
#	include "csgo.h"
#	define CSGO(n) n
#else
#	define CSGO(n) _______
#endif

#ifdef GIT_ENABLE
#	include "git.h"
#	define GIT(n) n
#else
#	define GIT(n) _______
#endif

#ifdef MINECRAFT_ENABLE
#	include "minecraft.h"
#	define MC(n) n
#else
#	define MC(n) _______
#endif

#ifdef SPONGEBOB_ENABLE
#   include "spongebob.h"
#endif

#ifdef AUTOCAPS_ENABLE
#   include "autocaps.h"
#endif

#ifdef CURSED_ENABLE
#   include "cursed.h"
#endif

#if defined(CSGO_ENABLE) || defined(MINECRAFT_ENABLE)
#	define GAME_ENABLED_
#endif

#define KCS_CUSTOM \
    KC_C_A,\
    KC_C_B,\
    KC_C_C,\
    KC_C_D,\
    KC_C_E,\
    KC_C_F,\
    KC_C_G,\
    KC_C_H,\
    KC_C_I,\
    KC_C_J,\
    KC_C_K,\
    KC_C_L,\
    KC_C_M,\
    KC_C_N,\
    KC_C_O,\
    KC_C_P,\
    KC_C_Q,\
    KC_C_R,\
    KC_C_S,\
    KC_C_T,\
    KC_C_U,\
    KC_C_V,\
    KC_C_W,\
    KC_C_X,\
    KC_C_Y,\
    KC_C_Z,\
    KC_C_SPC,\
    KC_C_DOT,\
    KC_C_1,\
    KC_C_SLSH,\

enum keycodes
{
	KC_CUSTOM_UNUSED = SAFE_RANGE,
    KCS_CUSTOM
#if defined(CSGO_ENABLE) && defined(KCS_CSGO)
	KCS_CSGO
#endif
#if defined(GIT_ENABLE) && defined(KCS_GIT)
	KCS_GIT
#endif
#if defined(MINECRAFT_ENABLE) && defined(KCS_MINECRAFT)
	KCS_MINECRAFT
#endif
#if defined(SPONGEBOB_ENABLE) && defined(KCS_SPONGEBOB)
	KCS_SPONGEBOB
#endif
#if defined(AUTOCAPS_ENABLE) && defined(KCS_AUTOCAPS)
	KCS_AUTOCAPS
#endif
#if defined(CURSED_ENABLE) && defined(KCS_CURSED)
	KCS_CURSED
#endif
};

enum layers
{
	L_DEFAULT,
	L_FN,
	L_CUSTOM,
#ifdef GAME_ENABLED_
	L_GAME,
#endif
};

enum tap_dances
{
	TD_GRAVE_ESC,
	TD_F14_MUTE,
    TD_HOME_MEPT,
    TD_END_MENT,
#if defined(CSGO_ENABLE) && defined(TDNS_CSGO)
	TDNS_CSGO
#endif
#if defined(GIT_ENABLE) && defined(TDNS_GIT)
	TDNS_GIT
#endif
#if defined(MINECRAFT_ENABLE) && defined(TDNS_MINECRAFT)
	TDNS_MINECRAFT
#endif
#if defined(SPONGEBOB_ENABLE) && defined(TDNS_SPONGEBOB)
	TDNS_SPONGEBOB
#endif
#if defined(AUTOCAPS_ENABLE) && defined(TDNS_AUTOCAPS)
	TDNS_AUTOCAPS
#endif
#if defined(CURSED_ENABLE) && defined(TDNS_CURSED)
	TDNS_CURSED
#endif
};

extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern qk_tap_dance_action_t tap_dance_actions[];

bool process_record_user(uint16_t keycode, keyrecord_t* record);
