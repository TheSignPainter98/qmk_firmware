#include "cursed.h"

#include "keymap.h"

static bool cursed_active = false;

PRU_SIG_(cursed)
{
	if (record->event.pressed)
	{
		if (keycode == KC_CR_TOGGLE)
		{
			if ((cursed_active = !cursed_active))
				layer_on(L_CUSTOM);
			else
				layer_off(L_CUSTOM);
			return true;
		}
		else if (cursed_active)
			switch (keycode)
			{
				case KC_C_L:
				case KC_C_R:
                    // Useful for distracting opponents
					SEND_STRING(SS_TAP(X_W));
					return true;
                case KC_C_A...KC_C_K:
                case KC_C_M...KC_C_Q:
                case KC_C_S...KC_C_Z:
				{
					const char kc[] = { keycode - KC_C_A + 'a', '\0' };
					send_string(kc);
					return true;
				}
			}
	}
	return false;
}
