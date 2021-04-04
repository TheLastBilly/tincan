ENTRY(bmain)
MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .vector_table :
    {
        . = ALIGN(4);
        KEEP(*(.vector_table))
        . = ALIGN(4);
    } > FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
    } > FLASH

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    /* The AT is because the data section will also go to ram, so the variables */
    /* will be pointing to the RAM's VMA space. Tp put it simply, .data represent */
    /* globals (and/or static variables) that have been initialized with a value */
    /* thus, they can't stay in read only memory (FLASH) and should also go to RAM. */
    /* However, we need to keep the values they were initialized with, so, we first */
    /* need to write them to ROM, and then, at boot time, we move them to ram. The */
    /* linker will make sure to make the pointers to them in the code, point to their */
    /* RAM addresses (and that's were the Virtual Memory Address (VMA) part comes in) */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;     /* _sdata and _edata represent the RAM locations of data    */
        *(.data)
        *(.data*)
        _edata = .;
        . = ALIGN(4);
    } > RAM AT > FLASH
    /* _ldata will be used to know where in the FLASH .data is located*/
    _ldata = LOADADDR(.data);

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)		/* Used for uninitialied variables */
        _ebss = .;
        . = ALIGN(4);
    } > RAM

    _stack_size = 1024;
    _estack = ORIGIN(RAM)+LENGTH(RAM);
    _sstack = _estack - _stack_size;
    . = _sstack;
    ._stack :
    {
    . = . + _stack_size;
    } > RAM
}