# required for keycode overwrite
REPEAT_KEY_ENABLE = yes

SRC += features/common.c

ifeq ($(strip $(OS_KEYS_ENABLE)), yes)
    SRC += features/os_keys.c
	OPT_DEFS += -DOS_KEYS_ENABLE
endif

ifeq ($(strip $(TAP_HOLD_ENABLE)), yes)
    SRC += features/tap_hold.c
	OPT_DEFS += -DTAP_HOLD_ENABLE
endif
