#ifndef DEBUG_H
#define DEBUG_H

#include "isa.h"
#include "serial.h"

void db_putc(char c)
{
	outb(0xE9, c);
}

void db_puts(const char *str)
{
	while (*str != '\0') {
		db_putc(*str);
		++str;
	}
}

void log_putc(char c)
{
	db_putc(c);
	serial_putc(c);
}

void log_puts(const char *str)
{
	while (*str != '\0') {
		log_putc(*str);
		++str;
	}
}

#endif