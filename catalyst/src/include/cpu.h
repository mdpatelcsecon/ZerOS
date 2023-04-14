/*
Catalyst

Copyright (C) 2023 Mohit D. Patel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CPU_H
#define CPU_H

#include <stdint.h>

extern volatile uint64_t regs[15];
extern volatile uint64_t rip_val;

extern void hcf(void);
extern void store_regs(void);
extern void store_rip(void);

#endif