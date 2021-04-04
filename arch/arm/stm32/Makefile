ROOT:=../../..

include $(ROOT)/globals.config
include ./make.config

all: $(BOOT_OBJS)

%.o: %.c
	$(ARM_TOOLCHAIN) $(C_FLAGS) $< -o $@

clean:
	-rm $(BOOT_OBJS)