#ifndef DEBUG_H
#define DEBUG_H

#include "isa.h"

void db_putc(char c)
{
	outb(0xE9, c);
}
void db_puts(const char *str)
{
	while(*str != '\0') {
		db_putc(*str);
		++str;
	}
}

#endif