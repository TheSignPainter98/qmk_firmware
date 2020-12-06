#include "git.h"

#include "keymap.h"

PRU(git,
    PRU_SEND_STRING(KC_GIT_ADD,            "git add ")
    PRU_SEND_STRING(KC_GIT_COMMIT,         "git commit\n")
    PRU_SEND_STRING(KC_GIT_COMMIT_A,       "git commit -a\n")
    PRU_SEND_STRING(KC_GIT_COMMIT_AMEND,   "git commit --amend\n")
    PRU_SEND_STRING(KC_GIT_COMMIT_A_AMEND, "git commit -a --amend\n")
    PRU_SEND_STRING(KC_GIT_DIFF,           "git diff \n")
    PRU_SEND_STRING(KC_GIT_DIFF_CACHED,    "git diff --cached ")
    PRU_SEND_STRING(KC_GIT_PULL,           "git pull\n")
    PRU_SEND_STRING(KC_GIT_PUSH,           "git push\n")
    PRU_SEND_STRING(KC_GIT_STASH,          "git stash\n")
    PRU_SEND_STRING(KC_GIT_STASH_POP,      "git stash pop\n")
    PRU_SEND_STRING(KC_GIT_STATUS,         "git status\n")
)
