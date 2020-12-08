/*
Copyright 2020 CapsUnlocked, Ed Jones

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

#include "keymap.h"

// kcza's changes from the default ISO layout
// -----------------------------------------------------------------------------
// [x] ANSI enter
// [x] Key above ANSI enter is ISO #~
// [x] Mod+# for RESET (bootloader)
// [x] Add FN + top row for F#
// [x] Use FN + top left for escape
// [x] Use top left for ¬/`
// [x] Use left of <- as the fn key
// [x] FN+Pg+ is volume up
// [x] FN+Pg- is volume down
// [x] FN+del is mute
// [x] Ins is F14
// [x] Fn+down is media_play
// [x] Fn+left is next track
// [x] Fn+right is previous track
// [n] Swap caps <-> lctrl
// [ ] Shift+left/right is home/end
// [ ] Shift+up/down is pgup/pgdn
// [ ] Git commands
//      - [ ] git status
//      - [ ] git pull
//      - [ ] git push
//      - [ ] git add
//      - [ ] git commit
//      - [ ] git commit -a
//      - [ ] git commit --amend
//      - [ ] git commit -a --amend
//      - [ ] git stash
//      - [ ] git stash pop
//      - [ ] git diff
//      - [ ] git diff --cached
// [x] CS:GO buys
//      - [x] famas+light               b4151
//      - [x] A4+heavy                  b4252
//      - [x] AUG+heavy                 b4452
//      - [x] nova+light                b2151
//      - [x] ump+light                 b3351
//      - [x] Five-SeveN+light          b1451
//      - [x] flash                     b5145+ESC
//      - [x] flash+smoke               b5145+ESC
//      - [x] flash+smoke+molly+frag    b5145+ESC

#ifdef GAME_ENABLED_
#   define MO_L_GAME MO(L_GAME)
#else
#   define MO_L_GAME KC_RALT
#endif

// Tap dance setup
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GRAVE_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESC),
#if defined(CSGO_ENABLE) && defined(TDS_CSGO)
    TDS_CSGO
#endif
#if defined(GIT_ENABLE) && defined(TDS_GIT)
    TDS_GIT
#endif
#if defined(MINECRAFT_ENABLE) && defined(TDS_MINECRAFT)
    TDS_MINECRAFT
#endif
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_DEFAULT] = LAYOUT_65_franken(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │`/X│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│F14│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │Del│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │Pg+│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │Pg-│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │Ctrl│LGUI│LAlt│         Space          │ L1 │RAlt│ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
        TD(TD_GRAVE_ESC), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_MINS, KC_EQL,  KC_BSPC, KC_F14,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_LBRC, KC_RBRC, KC_OTHP, KC_DEL,
        KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_QUOT, KC_NUHS, KC_ENT,  KC_PGUP,
        KC_LSFT,          KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,    KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC,                             MO(L_FN), MO_L_GAME,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [L_FN] = LAYOUT_65_franken(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │   │ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│       │F13│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │ RST │MUT│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │VUP│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │    │   │   │   │   │   │   │   │   │   │   │   │      │   │VDN│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │                        │    │    │ │PTK│PSE│NTK│
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   KC_AUMU,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUVU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUVD,
        _______, _______, _______,                   _______,                            _______, KC_RALT,          KC_MEPT, KC_MEPA, KC_MENT
    ),
#ifdef GAME_ENABLED_
    [L_GAME] = LAYOUT_65_franken(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │   │NH │NM │NL │   │   │   │   │   │   │   │   │   │       │   │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │MH │MM │ML │AWP│   │   │   │   │   │   │   │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │AEH│AEL│PH │PL │   │   │   │   │   │   │   │        │   │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │    │   │   │   │   │   │   │   │   │   │   │   │      │   │   │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │                        │    │    │ │   │   │   │
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
        _______, CSGO(KC_NADE_DECOY),       CSGO(KC_NADE_FLASH),       CSGO(KC_NADE_HE),            CSGO(KC_NADE_MOLLY),         _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, CSGO(TD(TD_MAIN_LIGHT)),   CSGO(TD(TD_MAIN_MEDIUM)),  CSGO(TD(TD_MAIN_HEAVY)),     CSGO(TD(TD_AWP)),            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, CSGO(TD(TD_PISTOL_LIGHT)), CSGO(TD(TD_PISTOL_HEAVY)), CSGO(TD(TD_ANTI_ECO_LIGHT)), CSGO(TD(TD_ANTI_ECO_HEAVY)), _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______,                   CSGO(KC_ARMOUR_LIGHT),     CSGO(KC_ARMOUR_HEAVY),       CSGO(KC_DEFUSE_KIT),         _______, _______, _______, _______, _______, _______, MC(KC_TWCL), _______, _______, _______,
        _______, _______,                   _______,                                                                             _______,                            _______, _______,              _______, _______, _______
    ),
#endif
};

func_arr(bool, (uint16_t, keyrecord_t*), custom_keycode_funcs) = {
#ifdef GIT_ENABLE
    PRU_NAME(git),
#endif
#ifdef CSGO_ENABLE
    PRU_NAME(csgo),
#endif
#ifdef MINECRAFT_ENABLE
    PRU_NAME(minecraft),
#endif
};
const int num_custom_keycode_funcs = sizeof(custom_keycode_funcs) / sizeof(*custom_keycode_funcs);

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    for (uint16_t i = 0; i < num_custom_keycode_funcs; i++)
    {
        if (custom_keycode_funcs[i] && custom_keycode_funcs[i](keycode, record))
            return true;
    }
    return true;
}
