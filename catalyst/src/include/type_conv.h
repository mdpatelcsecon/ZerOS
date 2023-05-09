/*
NewOS

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

#ifndef TYPE_CONV_H
#define TYPE_CONV_H

#include <stdint.h>

int u64_to_bin_str(const uint64_t n, char str[66]);
int u64_to_hex_str(const uint64_t n, char str[18]);
int u64_to_dec_str(const uint64_t n, char str[21]);

#endif