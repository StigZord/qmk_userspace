OLED_ENABLE = yes
# OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no     # Enable keyboard RGB matrix, do not use together with RGBLIGHT_ENABLE

# Bootloader selection
LEADER_ENABLE = yes # https://docs.qmk.fm/#/feature_leader_key
# TODO Refactor combos and re-enable
COMBO_ENABLE = no # https://docs.qmk.fm/#/feature_combo
# TAP_DANCE_ENABLE = yes # https://docs.qmk.fm/#/feature_tap_dance
CAPS_WORD_ENABLE = yes
CONSOLE_ENABLE = no       # Console for debug

EXTRAFLAGS += -flto
MOUSEKEY_ENABLE = no
MUSIC_ENABLE = no
UNICODE_ENABLE = no

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += encoders.c
endif

