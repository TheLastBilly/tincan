#ifndef DELAY_H_
#define DELAY_H_

#include <kernal/types.h>

static inline void k_delay_np(int32_t count)
{
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
            : "=r"(count): [count]"0"(count) : "cc");
}

#endif