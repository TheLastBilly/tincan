ROOT:=.
PROJECT_NAME:=tincan

include $(ROOT)/globals.config

include $(ROOT)/boot/make.config
include $(ROOT)/kernal/make.config
include $(ROOT)/libc/make.config

ELF:=$(PROJECT_NAME).elf
BIN:=$(PROJECT_NAME).bin

LD:=$(PROJECT_NAME).ld

rebuild: clean all

all: make-kernal make-libc make-bootloader link #binary

# Build
make-bootloader:
	$(MAKE) -C $(BOOT_ROOT)

make-libc:
	$(MAKE) -C $(LIBC_ROOT)
	
make-kernal:
	$(MAKE) -C $(KERNAL_ROOT)

# Linking
link:
	$(ARM_TOOLCHAIN) $(LINKER_FLAGS) -T $(LD) $(BOOT_OBJS) $(KERNAL_OBJS) $(LIBC_OBJS) -o $(ELF)

# binary:
# 	$(OBJCOPY) $(OBJ_FLAGS) $(ELF) $(BIN)

#Cleanning
clean: clean-root clean-bootloader clean-kernal clean-libc

clean-bootloader:
	$(MAKE) -C $(BOOT_ROOT) clean

clean-kernal:
	$(MAKE) -C $(KERNAL_ROOT) clean

clean-libc:
	$(MAKE) -C $(LIBC_ROOT) clean

clean-root:
	-rm -f *.elf
	-rm -f $(BIN)

run:
	$(QEMU) $(QEMU_FLAGS) $(ELF)
