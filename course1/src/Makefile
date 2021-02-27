#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
#This makefile includes many make commands to get the different compiled file and its intermidiate files like .asm,.i, .o etc.FIrst intermidiate files are built from two source files named main.c and mmory .c
#
# Make file includes a compile time switch which is able to  prepare flags after differentiate between HOST and Target.
#
# A file is generated in the make file which has the information about the memory mapping and all of this info is printed on screen.
#
#After creating all types of files Clean command is used to clean all of the files accepts source files.
#
#
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.o -> It generates objects file with the same name as the target.
#      <file>.i -> Makes only preprosessed files.
#      <file>.asm-> Get the files with assembly output.
#      Compile-all -> compiles all files without linking them.
#      build -> compile all files with linking them.
#      clean -> removes all of the output file accept source files.
#
# Platform Overrides:
#      HOST = for host mechine
#      MSP432 = for Arm MSP432
#
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKR_FILE = ../msp432p401r.lds
	LDFLAGS = -WL, -Map=$(TARGET).MAP -T $(LINKER_FILE)
	# Architectures Specific Flags ARM
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	FPU = fpv4-sp-d16
	ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU)
	OBJDUMP = arm-none-eabi-objdump
	#Size Utility
	SIZE = arm-none-eabi-size
else
        	
	CC = gcc
	LD = ld
	#Size Utility
	SIZE = size
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
endif

#Compiler flages 
TARGET = c1m2
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS)
CPPFLAGS = -E
MAIN = main

OBJS = $(SOURCES:.c=.o)

PREPRO = $(SOURCES:.c=.i)

ASMS = $(SOURCES:.c=.asm)

DEPS = $(SOURCES:.c=.d)

#Had to use this because other than memory.* and main.* other files are not getting deleted.
FILES = *.asm *.i *.o *.d

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o

.PHONY: build
build: $(TARGET).out  $(TARGET).asm

$(TARGET).out: $(OBJS) $(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
.PHONY: clean
clean:
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PREPRO) $(ASMS) $(DEPS) $(OBJS)
