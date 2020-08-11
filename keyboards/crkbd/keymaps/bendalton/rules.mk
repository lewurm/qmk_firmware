
RGBLIGHT_ENABLE=yes

TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
LINK_TIME_OPTIMIZATION_ENABLE = yes
BOOTLOADER = qmk-dfu
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/logo_reader.c \
        # ./lib/rgb_state_reader.c \
        # ./lib/host_led_state_reader.c \
		# ./lib/layer_state_reader.c \
        # ./lib/keylogger.c \
		# ./lib/layer_state_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/timelogger.c \
