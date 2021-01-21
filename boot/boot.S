.section ".text.boot"

.global _start

_start:
    mrc p15, #0, r1, c0, c0, #5         @ Get the CPU ID for the current core
    and r1, r1, #3                      @ Make sure that the core ID (r1) is no bigger than 3
    cmp r1, #0                          @ Check if this is being run by core 0
    bne halt                            @ If this is not core 0, halt

    mov sp, #0x8000                     @ Move stack pointer to start of program memory    

    ldr r4, =__bss_start                @ Initialize bss, I still need to do some research into why this is done
    ldr r9, =__bss_end                  @ in this matter, but it should do just fine for now

    mov r5, #0
    mov r6, #0
    mov r7, #0
    mov r8, #0
    b       2f

1:
    stmia r4!, {r5-r8}

2:
    cmp r4, r9
    blo 1b

    ldr r3, =kmain
    blx r3

halt:
    wfe
    b halt