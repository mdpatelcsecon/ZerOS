#ifndef ISA_H
#define ISA_H

#include <stdint.h>

extern volatile uint8_t inb(volatile uint16_t);
extern void outb(volatile uint16_t, volatile uint8_t);

#endif