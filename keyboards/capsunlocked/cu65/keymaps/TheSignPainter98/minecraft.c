#include "minecraft.h"

#include "keymap.h"

#define MC_INPUT_DELAY SS_DELAY(100)

PRU(minecraft, PRU_SEND_STRING(KC_TWCL, "/" MC_INPUT_DELAY "time set day\n" MC_INPUT_DELAY "/" MC_INPUT_DELAY "weather clear\n"))
