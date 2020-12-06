#pragma once

#include <stdbool.h>
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "tsp-util.h"

#define KCS_GIT \
    KC_GIT_ADD,\
    KC_GIT_COMMIT,\
    KC_GIT_COMMIT_A,\
    KC_GIT_COMMIT_AMEND,\
    KC_GIT_COMMIT_A_AMEND,\
    KC_GIT_DIFF,\
    KC_GIT_DIFF_CACHED,\
    KC_GIT_PULL,\
    KC_GIT_PUSH,\
    KC_GIT_STASH,\
    KC_GIT_STASH_POP,\
    KC_GIT_STATUS,\

PRU_SIG(git)
