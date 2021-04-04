ROOT:=../../..

include $(ROOT)/globals.config
include ./make.config

all: $(BOOT_OBJS)

%.o: %.c
	$(ARM_TOOLCHAIN) $(C_INC_FLAGS) $(CFLAGS) $< -o $@

clean:
	-rm $(BOOT_OBJS)