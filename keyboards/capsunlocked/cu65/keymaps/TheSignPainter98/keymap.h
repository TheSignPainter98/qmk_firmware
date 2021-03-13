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

#if defined(CSGO_ENABLE) || defined(MINECRAFT_ENABLE)
#	define GAME_ENABLED_
#endif

enum keycodes
{
	KC_CUSTOM_UNUSED = SAFE_RANGE,
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
};

enum layers
{
	L_DEFAULT,
	L_FN,
#ifdef GAME_ENABLED_
	L_GAME,
#endif
#ifdef SPONGEBOB_ENABLE
    L_SPONGEBOB
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
};

extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern qk_tap_dance_action_t tap_dance_actions[];

bool process_record_user(uint16_t keycode, keyrecord_t* record);
