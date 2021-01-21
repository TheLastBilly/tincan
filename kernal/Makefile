ROOT:=..

include $(ROOT)/globals.config

include make.config

all: $(KERNAL_OBJS)

%.o: %.c
	$(ARM_TOOLCHAIN) $(C_INC_FLAGS) $(C_FLAGS) -o $@ $<

%.o: %.S
	$(ARM_TOOLCHAIN) $(ASM_FLAGS) $< -o $@

clean:
	-rm -f $(KERNAL_OBJS)