#include "csgo.h"

#include "keymap.h"

#define PRU_SEND_STRING_CLOSE_BUY_MENU(c, s) PRU_SEND_STRING(c, s "b")

PRU(csgo,
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_NADE_DECOY,   "b62b")
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_NADE_FLASH,   "b63b")
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_NADE_HE,      "b64b")
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_NADE_MOLLY,   "b61b")
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_ARMOUR_LIGHT, "b51b")
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_ARMOUR_HEAVY, "b52b")
    PRU_SEND_STRING_CLOSE_BUY_MENU(KC_DEFUSE_KIT,   "b54b")
)

#define CSGO_WEAPON_CASE(c,s) case c: SEND_STRING(s); break;

void csgo_tap_dance_finished(qk_tap_dance_state_t* state, void* user_data)
{
    // Clear any keys being pressed
    clear_keyboard();

    // Buy weapons and armour
    switch(state->keycode - QK_TAP_DANCE)
    {
        CSGO_WEAPON_CASE(TD_ANTI_ECO_HEAVY, "b3351")   // UMP, light
        CSGO_WEAPON_CASE(TD_ANTI_ECO_LIGHT, "b2151")   // Nova, light
        CSGO_WEAPON_CASE(TD_AWP,            "b451452") // Awp, Five-SeveN, heavy
        CSGO_WEAPON_CASE(TD_MAIN_HEAVY,     "b4452")   // AUG, heavy
        CSGO_WEAPON_CASE(TD_MAIN_LIGHT,     "b4151")   // Famas, light
        CSGO_WEAPON_CASE(TD_MAIN_MEDIUM,    "b4252")   // M4, heavy
        CSGO_WEAPON_CASE(TD_PISTOL_HEAVY,   "b1452")   // Five-SeveN, heavy
        CSGO_WEAPON_CASE(TD_PISTOL_LIGHT,   "b14")     // Five-SeveN
        CSGO_WEAPON_CASE(TD_PISTOL_MEDIUM,  "b1451")   // Five-SeveN, light
    }

    // Buy grenades (Press once for light, twice for medium, thrice or hold at any time for heavy)
    if (state->count == 1 && !state->pressed)
        SEND_STRING("b63b");
    else if (state->count == 2 && !state->pressed)
        SEND_STRING("b635b");
    else
        SEND_STRING("b61345b");

    SEND_STRING("b" SS_TAP(X_MS_BTN4)); // Close buy menu, equip knife
}
