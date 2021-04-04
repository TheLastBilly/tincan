#define BINT_T unsigned int
#define BOOT_VTABLE_SIZE 2

#define BRAM_START          0x20000000
#define BRAM_STACK_BEG      (1024 * 20) + BRAM_START

// Get access to linker variables
extern BINT_T _ldata;
extern BINT_T _sdata;
extern BINT_T _edata;
extern BINT_T _sbss;
extern BINT_T _ebss;
extern BINT_T _estack;

void bmain();
void kmain();

// This is to make sure, vector_table is related to the linker script's
// ".vector_table"
volatile BINT_T * vector_table[BOOT_VTABLE_SIZE] __attribute__((section(".vector_table"))) =
{
    (BINT_T *) (BRAM_STACK_BEG),
    (BINT_T *) bmain
};

// Entrypoint for the bootloader
void bmain()
{
    // Copy .data section into ram
    volatile BINT_T *src, *dest;
    for(src = &_ldata, dest = &_sdata; dest < &_edata; src++, dest++) *dest = *src;

    // Clear the .bss section
    for(dest = &_sbss; dest < _ebss; dest++) *dest = 0;

    // Move on to the kernel
    kmain();

    // Got to an infitite loop
    while(1);
}