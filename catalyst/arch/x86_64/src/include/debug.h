#ifndef DEBUG_H
#define DEBUG_H

#include "isa.h"
#include "serial.h"

void db_putc(char c);
void db_puts(const char *str);
void log_putc(char c);
void log_puts(const char *str);

#endif