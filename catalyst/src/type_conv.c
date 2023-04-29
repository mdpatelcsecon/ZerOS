#include "type_conv.h"
#include "string.h"

#include <debug.h>
#include <stdint.h>

void swap_endianness(uint8_t *bytes, size_t nbytes)
{
	uint8_t temp;
	for (size_t i = 0; i < (nbytes / 2); ++i) {
		temp = bytes[i];
		bytes[i] = bytes[nbytes - i];
		bytes[nbytes - i] = temp;
	}
}

int u64_to_bin_str(const uint64_t n, char str[66])
{
	if (str == NULL)
		return -1;
	//convert
	for (uint64_t i = 0ull; i < 64ull; ++i) {
		if ((n & (1ull << i)) != 0) {
			str[63 - i] = '1';
		} else {
			str[63 - i] = '0';
		}
	}
	//Put down the suffix and terminating null character
	memcpy(&str[64], "b", 2);
	//return success
	return 0;
}

int u64_to_hex_str(const uint64_t *const n, char str[8]);
int u64_to_dec_str(const uint64_t *const n, char str[8]);