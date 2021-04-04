#ifndef _STM32F4_UTIL_H_
#define _STM32F4_UTIL_H_

// Taken from https://github.com/al95/STM32-Bare-Metal/blob/master/common.h
#define BIT_SET(REG, BITSET)     ( (REG) |= (BITSET) )
#define BIT_CLR(REG, BITCLR)     ( (REG) &= (~(BITCLR)) )
#define BIT_CLR_SET(REG, BITCLR, BITSET) ( (REG) = ( ( (REG) & (~(BITCLR)) ) | (BITSET) ) )

#define BIT_0   0x00000001
#define BIT_1   0x00000002
#define BIT_2   0x00000004
#define BIT_3   0x00000008
#define BIT_4   0x00000010
#define BIT_5   0x00000020
#define BIT_6   0x00000040
#define BIT_7   0x00000080
#define BIT_8   0x00000100
#define BIT_9   0x00000200
#define BIT_10  0x00000400
#define BIT_11  0x00000800
#define BIT_12  0x00001000
#define BIT_13  0x00002000
#define BIT_14  0x00004000
#define BIT_15  0x00008000
#define BIT_16  0x00010000
#define BIT_17  0x00020000
#define BIT_18  0x00040000
#define BIT_19  0x00080000
#define BIT_20  0x00100000
#define BIT_21  0x00200000
#define BIT_22  0x00400000
#define BIT_23  0x00800000
#define BIT_24  0x01000000
#define BIT_25  0x02000000
#define BIT_26  0x04000000
#define BIT_27  0x08000000
#define BIT_28  0x10000000
#define BIT_29  0x20000000
#define BIT_30  0x40000000
#define BIT_31  0x80000000

#define MASK_0  0xFFFFFFFE
#define MASK_1  0xFFFFFFFD
#define MASK_2  0xFFFFFFFB
#define MASK_3  0xFFFFFFF7
#define MASK_4  0xFFFFFFEF
#define MASK_5  0xFFFFFFDF
#define MASK_6  0xFFFFFFBF
#define MASK_7  0xFFFFFF7F
#define MASK_8  0xFFFFFEFF
#define MASK_9  0xFFFFFDFF
#define MASK_10 0xFFFFFBFF
#define MASK_11 0xFFFFF7FF
#define MASK_12 0xFFFFEFFF
#define MASK_13 0xFFFFDFFF
#define MASK_14 0xFFFFBFFF
#define MASK_15 0xFFFF7FFF
#define MASK_16 0xFFFEFFFF
#define MASK_17 0xFFFDFFFF
#define MASK_18 0xFFFBFFFF
#define MASK_19 0xFFF7FFFF
#define MASK_20 0xFFEFFFFF
#define MASK_21 0xFFDFFFFF
#define MASK_22 0xFFBFFFFF
#define MASK_23 0xFF7FFFFF
#define MASK_24 0xFEFFFFFF
#define MASK_25 0xFDFFFFFF
#define MASK_26 0xFBFFFFFF
#define MASK_27 0xF7FFFFFF
#define MASK_28 0xEFFFFFFF
#define MASK_29 0xDFFFFFFF
#define MASK_30 0xBFFFFFFF
#define MASK_31 0x7FFFFFFF

#endif