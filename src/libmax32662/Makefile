include ../build/Makefile.env

#-------------------------------------------------
# Outputs
#-------------------------------------------------
LIBNAME = libmax32662.a
TEST_ELF = libmax32662_test.elf
TEST_BIN = libmax32662_test.bin

#-------------------------------------------------
# Build files
#-------------------------------------------------
BUILD = ./build
SRC_C :=
INCLUDE :=
LDFILE = ../build/max32662_flash.ld

INCLUDE += -I.
INCLUDE += -I./include/

SRC_C += max32662_clock.c
SRC_C += max32662_adc.c
SRC_C += max32662_gpio.c
SRC_C += max32662_i2c.c
SRC_C += max32662_timer.c
SRC_C += max32662_uart.c
SRC_C += max32662_spi.c
SRC_C += max32662_dmac.c

#SRC_C_TEST = $(SRC_C) max32662_libtest.c syscall.c startup.c sla_header.c systick.c
SRC_C_TEST = $(SRC_C) max32662_libtest.c syscall.c startup.c systick.c
SRC_S_TEST = 

OBJ = $(addprefix $(BUILD)/, $(SRC_C:.c=.o)) 
OBJ_TEST = $(addprefix $(BUILD)/, $(SRC_C_TEST:.c=.o)) $(addprefix $(BUILD)/, $(SRC_S_TEST:.s=.o))

vpath %.s ../build
vpath %.c ../build

#-------------------------------------------------
# Build option
#-------------------------------------------------
COPT = -g -Og
CFLAGS_CORTEX_M4 = -mthumb -mcpu=cortex-m4 -mtune=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
AFLAGS_CORTEX_M4 = -mthumb -mcpu=cortex-m4                  -mfpu=fpv4-sp-d16 -mfloat-abi=softfp

CFLAGS = -x c $(INCLUDE) -Wall -Werror -std=c99 -nostdlib $(CFLAGS_CORTEX_M4) $(COPT)
AFLAGS =      $(INCLUDE) -Wall                            $(AFLAGS_CORTEX_M4)
LDFLAGS = -mthumb -Wl,-Map=$(BUILD)/$@.map  -Wl,--start-group -lm  -Wl,--end-group -Wl,--gc-sections -mcpu=cortex-m4 -T $(LDFILE)

all: $(BUILD) $(TEST_ELF) $(LIBNAME)
lib: $(BUILD) $(LIBNAME)
test: $(BUILD) $(TEST_ELF)

$(BUILD):
	mkdir $(BUILD) 

$(LIBNAME): $(OBJ)
	echo "LINK $@"
	$(AR) $(ARFLAGS_LIB)-r $(BUILD)/$@ $^

$(TEST_ELF): $(OBJ_TEST)
	echo "ARCHIVE $@"
	$(LD) $(LDFLAGS) $(LIB) -o $(BUILD)/$@ $^ $(LIBS)
	$(OBJCOPY) -O binary $(BUILD)/$@ $(BUILD)/$(TEST_BIN)

$(BUILD)/%.o: %.c
	$(CC) $(CFLAGS) -c -MD -o $@ $<


$(BUILD)/%.o: %.s
	$(AS) $(AFLAGS) -o $@ $<


clean:
	rm -rf $(BUILD)