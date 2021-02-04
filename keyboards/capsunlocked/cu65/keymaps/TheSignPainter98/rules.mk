# MCU name
MCU = atmega32u4

# Bootloader
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
TAP_DANCE_ENABLE = yes		# Enable tap-dance

# My configuration
CSGO_ENABLE = yes
GIT_ENABLE = yes
MINECRAFT_ENABLE = yes
SPONGEBOB_ENABLE = yes

LAYOUTS = 65_ansi 65_iso

# Sources
ifeq ($(strip $(CSGO_ENABLE)),yes)
	SRC += csgo.c
	CFLAGS += -DCSGO_ENABLE
endif

ifeq ($(strip $(GIT_ENABLE)),yes)
	SRC += git.c
	CFLAGS += -DGIT_ENABLE
endif

ifeq ($(strip $(MINECRAFT_ENABLE)),yes)
	SRC += minecraft.c
	CFLAGS += -DMINECRAFT_ENABLE
endif

ifeq ($(strip $(SPONGEBOB_ENABLE)),yes)
	SRC += spongebob.c
	CFLAGS += -DSPONGEBOB_ENABLE
endif
