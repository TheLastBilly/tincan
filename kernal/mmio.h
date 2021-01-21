#ifndef MMIO_H_
#define MMIO_H_

#include <kernal/types.h>

static inline void k_mmio_write(uint32_t reg, uint32_t val)
{
    *(volatile uint32_t*) reg = val;
}

static inline uint32_t k_mmio_read(uint32_t reg)
{
    return *(volatile uint32_t*)reg;
}

#endif