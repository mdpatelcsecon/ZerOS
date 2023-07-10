#ifndef CPU_H
#define CPU_H

#include <stdint.h>

extern volatile uint64_t regs[16];
extern volatile uint64_t rip_val;

extern void hcf(void);
extern void store_regs(void);
extern void store_rip(void);

#endif
