ROOT:=..

include $(ROOT)/globals.config

include make.config

all:	$(LIBC_OBJS)

%.o: %.c
	$(ARM_TOOLCHAIN) $(C_INC_FLAGS) $(CFLAGS) -o $@ $<

%.o: %.S
	$(ARM_TOOLCHAIN) $(ASM_FLAGS) $< -o $@

clean:
	-rm -f $(LIBC_OBJS)