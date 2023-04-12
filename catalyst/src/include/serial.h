#ifndef SERIAL_H
#define SERIAL_H

#include <stddef.h>
#include <stdint.h>


int init_serial();
char serial_putc(char c);
size_t serial_puts(const char *str);

#endif