ROOT:=..

include $(ROOT)/globals.config

include make.config

all: $(BOOT_OBJS)

%.o: %.S
	$(ARM_TOOLCHAIN) $(ASM_FLAGS) $< -o $@

clean:
	-rm -f $(BOOT_OBJS)