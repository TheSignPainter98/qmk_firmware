#pragma once

#define PRU(n, b) PRU_SIG_(n) { switch(keycode) { b } return false; }
#define PRU_SIG(n) PRU_SIG_(n);
#define PRU_SIG_(n) bool PRU_NAME(n) (uint16_t keycode, keyrecord_t* record)
#define PRU_NAME(n) process_record_user_##n
#define PRU_SEND_STRING(c,s) case c: if (record->event.pressed) SEND_STRING(s); return true;
