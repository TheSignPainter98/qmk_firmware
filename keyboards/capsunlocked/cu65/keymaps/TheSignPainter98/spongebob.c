#include "spongebob.h"

#include "keymap.h"

#define R_INITIAL_VALUE 2

static uint16_t r		= R_INITIAL_VALUE;
static uint16_t x		= R_INITIAL_VALUE;
static uint16_t const a = 997;
static uint16_t const b = 757;
static uint16_t const c = 10007;

static int spongebob_active = 0;

PRU_SIG_(spongebob)
{
	if (record->event.pressed)
		switch (keycode)
		{
			case KC_S_TOGGLE:
				if ((spongebob_active = !spongebob_active))
					layer_move(L_CUSTOM);
				else
					layer_move(L_DEFAULT);
				return true;
			case KC_C_A ... KC_C_Z:
				if (!spongebob_active)
					return false;

				const char kc[] = { keycode - KC_C_A + 'a', '\0' };

				if ((r & 1 && keycode != KC_L) || keycode == KC_I)
					send_string(kc);
				else
				{
					SEND_STRING(SS_DOWN(X_LSFT));
					send_string(kc);
					SEND_STRING(SS_UP(X_LSFT));
				}

				if (r)
					r >>= 1;
				else
				{
					x = (a * x + b) % c;
					r = x;
				}
				return true;
		}
	return false;
}
