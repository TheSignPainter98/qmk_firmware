#include "spongebob.h"

#include "keymap.h"

static uint16_t r		= 0;
static uint16_t x		= 0;
static uint16_t const a = 997;
static uint16_t const b = 757;
static uint16_t const c = 10007;

PRU_SIG_(spongebob)
{
	if (record->event.pressed && KC_S_A <= keycode && keycode <= KC_S_Z)
	{
        char kc[] = { keycode - KC_S_A + 'a', '\0' };

        if (r & 1)
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
