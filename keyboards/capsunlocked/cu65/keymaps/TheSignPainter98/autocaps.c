#include "autocaps.h"

#include "keymap.h"

static bool autocaps_active	   = false;
static bool capitalise		   = false;
static bool shift_down		   = false;
static bool maybe_capitalise_i = false;

static void handle_capitalised_i(void);

PRU_SIG_(autocaps)
{
	/* if (autocaps_active) */
	/* { */
	/* send_string(shift_down ? "S" : "s"); */
	/* send_string(capitalise ? "Q" : "q"); */
	/* } */
	if (keycode == KC_LSFT || keycode == KC_RSFT)
		shift_down = record->event.pressed;
	else if (record->event.pressed)
	{
		if (keycode == KC_AC_TOGGLE)
		{
			if ((autocaps_active = !autocaps_active))
			{
				layer_move(L_CUSTOM);
				capitalise		   = true;
				maybe_capitalise_i = true;
			}
			else
				layer_move(L_DEFAULT);
			return true;
		}
		else if (autocaps_active)
			switch (keycode)
			{
				case KC_C_I:
					SEND_STRING(SS_TAP(X_I));
					capitalise		   = false;
					maybe_capitalise_i = true;
					return true;
                case KC_C_A ... KC_C_H:
                case KC_C_J ... KC_C_Z:
				{
					const char kc[] = { keycode - KC_C_A + 'a', '\0' };
					if (capitalise)
					{
						SEND_STRING(SS_DOWN(X_LSFT));
						send_string(kc);
						SEND_STRING(SS_UP(X_LSFT));
					}
					else
						send_string(kc);
					capitalise		   = false;
					maybe_capitalise_i = false;
					return true;
				}
				case KC_DOT:
					capitalise = true;
					handle_capitalised_i();
					return false;
				case KC_1:
					if (shift_down)
						capitalise = true;
					handle_capitalised_i();
					return false;
				case KC_SLSH:
					if (shift_down)
						capitalise = true;
					handle_capitalised_i();
					return false;
				case KC_SPC:
					handle_capitalised_i();
					return false;
				default:
					handle_capitalised_i();
					capitalise = false;
					return false;
			}
	}
	return false;
}

static void handle_capitalised_i(void)
{
	if (!maybe_capitalise_i)
		return;
	SEND_STRING(SS_TAP(X_BSPC) SS_DOWN(X_LSFT) "I" SS_UP(X_LSFT));
	maybe_capitalise_i = false;
}
