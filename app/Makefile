PROJECT = cps_app
BUILD_DIR = bin

SHARED_DIR = ../common-code
CFILES = main.c
CFILES += api.c \
	  module_uart.c \
	  buffer.c \
	  tools.c
AFILES += api-asm.S

# TODO - you will need to edit these two lines!
DEVICE=stm32f401re
#OOCD_FILE = board/stm32f4discovery.cfg
# Flash the firmware by st-link
OOCD_INTERFACE = stlink-v2
OOCD_TARGET = stm32f4x

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR= ../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
