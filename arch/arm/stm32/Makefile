ROOT:=../../..

include $(ROOT)/globals.config
include ./make.config

all: $(BOOT_OBJS)

%.o: %.c
	$(ARM_TOOLCHAIN) $(CFLAGS) $< -o $@

clean:
	-rm $(BOOT_OBJS)