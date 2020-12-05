#pragma once

#define PRU_CASE_SEND_STRING(c,s) case c: if (record->event.pressed) SEND_STRING(s); return true;
