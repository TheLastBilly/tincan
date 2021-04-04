ROOT:=.
PROJECT_NAME:=tincan

include $(ROOT)/globals.config

include $(ARCH_ROOT)/make.config
include $(KERNAL_ROOT)/make.config
include $(LIBC_ROOT)/make.config

ELF:=$(PROJECT_NAME).elf
BIN:=$(PROJECT_NAME).bin

LD:=$(PROJECT_NAME).ld

all: make-kernal make-libc make-bootloader link binary

rebuild: clean all

# Build
make-bootloader:
	$(MAKE) -C $(ARCH_ROOT)

make-libc:
	$(MAKE) -C $(LIBC_ROOT)
	
make-kernal:
	$(MAKE) -C $(KERNAL_ROOT)

# Linking
link:
	$(ARM_TOOLCHAIN) $(LINKER_FLAGS) -T $(LD) $(BOOT_OBJS) $(KERNAL_OBJS) $(LIBC_OBJS) -o $(ELF)

binary:
	$(OBJCOPY) $(OBJ_FLAGS) $(ELF) $(BIN)

#Cleanning
clean: clean-root clean-arch clean-kernal clean-libc

clean-arch:
	$(MAKE) -C $(ARCH_ROOT) clean

clean-kernal:
	$(MAKE) -C $(KERNAL_ROOT) clean

clean-libc:
	$(MAKE) -C $(LIBC_ROOT) clean

clean-root:
	-rm -f *.elf
	-rm -f $(BIN)

run:
	$(QEMU) $(QEMU_FLAGS) $(ELF)

flash:
	$(STFLASH) --reset write $(BIN) 0x8000000

debug:
	$(GDB) $(GDB_FLAGS)