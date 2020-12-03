/*
Copyright 2020 CapsUnlocked

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

#include QMK_KEYBOARD_H

// Ed's changes from the default ISO layout
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
// [ ] Swap caps <-> lctrl
// [ ] Shift+left/right is home/end
// [ ] Shift+up/down is home/end

/**
 * @brief Layout definition for the CU65 ANSISO frankenlayout
 *
 * @return
 */
#define LAYOUT_65_franken( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, \
	K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, \
	K300, K301,       K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, \
	K400, K401, K402,                         K407,             K410,       K412, K413, K414, K415  \
) { \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, KC_NO,K014, K015 }, \
	{ K100, KC_NO,K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115 }, \
	{ K200, KC_NO,K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215 }, \
	{ K300, K301, KC_NO,K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315 }, \
	{ K400, K401, K402, KC_NO,KC_NO,KC_NO,KC_NO,K407, KC_NO,KC_NO,K410, KC_NO,K412, K413, K414, K415 }  \
}

// Aliases for long keycode names
#define KC_OTHP KC_NONUS_HASH
#define KC_AUMU KC_AUDIO_MUTE
#define KC_AUVD KC_AUDIO_VOL_DOWN
#define KC_AUVU KC_AUDIO_VOL_UP
#define KC_MENT KC_MEDIA_NEXT_TRACK
#define KC_MEPA KC_MEDIA_PLAY_PAUSE
#define KC_MEPT KC_MEDIA_PREV_TRACK

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_franken(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│F14│
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
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_F14,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_OTHP, KC_DEL,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGUP,
        KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LGUI, KC_LALT,                   KC_SPC,                             MO(1),   KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_franken(
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │ESC│ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│       │F13│
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
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_F13,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   KC_AUMU,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUVU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUVD,
        _______, _______, _______,                   _______,                            _______, _______,          KC_MEPT, KC_MEPA, KC_MENT
    ),
};
