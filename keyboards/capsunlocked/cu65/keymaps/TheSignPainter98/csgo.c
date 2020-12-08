#include "csgo.h"

#include "keymap.h"

#define PRU_SEND_STRING_WITH_ESC(c, s) PRU_SEND_STRING(c, s SS_TAP(X_ESC))

PRU(csgo,
    PRU_SEND_STRING_WITH_ESC(KC_NADE_DECOY,             "b62b")
    PRU_SEND_STRING_WITH_ESC(KC_NADE_FLASH,             "b63b")
    PRU_SEND_STRING_WITH_ESC(KC_NADE_HE,                "b64b")
    PRU_SEND_STRING_WITH_ESC(KC_NADE_MOLLY,             "b61b")
    PRU_SEND_STRING_WITH_ESC(KC_ARMOUR_LIGHT,           "b51")
    PRU_SEND_STRING_WITH_ESC(KC_ARMOUR_HEAVY,           "b52")
    PRU_SEND_STRING_WITH_ESC(KC_DEFUSE_KIT,             "b54")
)

#define CSGO_WEAPON_CASE(c,s) case c: SEND_STRING(s); break;

void csgo_tap_dance_finished(qk_tap_dance_state_t* state, void* user_data)
{
    // Buy weapons and armour
    switch(state->keycode - QK_TAP_DANCE)
    {
        CSGO_WEAPON_CASE(TD_ANTI_ECO_HEAVY, "b3351")   // UMP, light
        CSGO_WEAPON_CASE(TD_ANTI_ECO_LIGHT, "b2151")   // Nova, light
        CSGO_WEAPON_CASE(TD_AWP,            "b451552") // Awp, Five-SeveN, heavy
        CSGO_WEAPON_CASE(TD_MAIN_HEAVY,     "b4452")   // AUG, heavy
        CSGO_WEAPON_CASE(TD_MAIN_LIGHT,     "b4151")   // Famas, light
        CSGO_WEAPON_CASE(TD_MAIN_MEDIUM,    "b4252")   // M4, heavy
        CSGO_WEAPON_CASE(TD_PISTOL_HEAVY,   "b1452")   // Five-SeveN, light
        CSGO_WEAPON_CASE(TD_PISTOL_LIGHT,   "b14")     // Five-SeveN
        CSGO_WEAPON_CASE(TD_PISTOL_MEDIUM,  "b1451")   // Five-SeveN, light
    }

    // Buy grenades (Press once for light, twice for medium, thrice or hold at any time for heavy)
    if (state->count == 1 && !state->pressed)
        SEND_STRING("b63");
    else if (state->count == 2 && !state->pressed)
        SEND_STRING("b635");
    else
        SEND_STRING("b61345");

    SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_MS_BTN4));
}
