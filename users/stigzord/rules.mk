SRC += stigzord.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C += combos.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
	SRC += caps_words.c
endif
