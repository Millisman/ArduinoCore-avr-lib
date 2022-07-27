# Port where your Arduino is connected
PORT 		= -P /dev/ttyUSB0

# Please note - the arduino bootloader cannot flash FUSE bits
UPLOAD_PROTOCOL = arduino
# UPLOAD_PROTOCOL = usbtiny
BUILD_MCU 	= atmega328p
UPLOAD_SPEED 	= 115200
BUILD_F_CPU 	= 16000000L

# The compiler and build tools for ATMEGA-AVR must be installed on your system,
# or you must download it to a separate directory and write all the paths manually.
CXX 	= avr-g++
AR 	= avr-ar
SIZE 	= avr-size
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# CXX 	= /home/user/Arduino-1.8.19/hardware/tools/avr/bin/avr-g++
# AR 	= /home/user/Arduino-1.8.19/hardware/tools/avr/bin/avr-ar
# SIZE 	= /home/user/Arduino-1.8.19/hardware/tools/avr/bin/avr-size
# OBJCOPY = /home/user/Arduino-1.8.19/hardware/tools/avr/bin/avr-objcopy
# AVRDUDE = /home/user/Arduino-1.8.19/hardware/tools/avr/bin/avrdude



DUDEFLAGS = -V -p $(BUILD_MCU) $(PORT) -c $(UPLOAD_PROTOCOL) -b $(UPLOAD_SPEED)

# Please check if these parameters are suitable for your MCU
#FUSES = -U lfuse:w:0xFF:m -U hfuse:w:0xD6:m -U efuse:w:0x05:m
FUSES  = -U lfuse:w:0xFF:m -U hfuse:w:0xDF:m -U efuse:w:0xFD:m

SIZEFLAGS =


PRJCXXFLAGS = -Os -mmcu=$(BUILD_MCU) -DF_CPU=$(BUILD_F_CPU)
PRJCXXFLAGS += -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -DARDUINO=10808
PRJCXXFLAGS += -W -Wall -pedantic -fshort-enums -fpack-struct
PRJCXXFLAGS += -ffunction-sections -fdata-sections
PRJCXXFLAGS += -funsigned-bitfields
PRJCXXFLAGS += -fno-exceptions
# PRJCXXFLAGS += -fmerge-all-constants
# PRJCXXFLAGS += -funsigned-char
# PRJCXXFLAGS += -fno-inline-small-functions
# PRJCXXFLAGS += -D__AVR_ATmega328P__

# gives information for debugging
# PRJCXXFLAGS += -g

# for floating-point printf
# LDFLAGS = -Wl,-u,vfprintf -lprintf_flt -lm

# for smaller printf
# LDFLAGS = -Wl,-u,vfprintf -lprintf_min

# Relax shrinks code even more, but makes disassembly messy
LDFLAGS += -Wl,--relax
# Optional, but often ends up with smaller code
LDFLAGS += -Wl,--gc-sections

FORMAT = ihex
# or binary
