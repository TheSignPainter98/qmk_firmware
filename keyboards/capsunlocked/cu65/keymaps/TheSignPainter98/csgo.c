#include "csgo.h"

#include "keymap.h"
#include "util.h"

bool process_record_user_csgo(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        PRU_CASE_SEND_STRING(KC_ANTI_ECO_HEAVY_BUY, "b3351")
        PRU_CASE_SEND_STRING(KC_ANTI_ECO_LIGHT_BUY, "b2151")
        PRU_CASE_SEND_STRING(KC_MAIN_HEAVY_BUY,     "b4452")
        PRU_CASE_SEND_STRING(KC_MAIN_LIGHT_BUY,     "b4151")
        PRU_CASE_SEND_STRING(KC_MAIN_MEDIUM_BUY,    "b4252")
        PRU_CASE_SEND_STRING(KC_NADE_HEAVY,         "b61345b")
        PRU_CASE_SEND_STRING(KC_NADE_LIGHT,         "b63b")
        PRU_CASE_SEND_STRING(KC_NADE_MEDIUM,        "b635b")
        PRU_CASE_SEND_STRING(KC_PISTOL_HEAVY,       "b1551")
        PRU_CASE_SEND_STRING(KC_PISTOL_LIGHT,       "b1563")
        PRU_CASE_SEND_STRING(KC_AWP,                "b455261345b")
    }
    return false;
}
