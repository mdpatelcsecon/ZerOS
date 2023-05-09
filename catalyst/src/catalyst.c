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

#include <stdint.h>
#include <stddef.h>
#include "limine.h"

#include "cpu.h"
#include "debug.h"
#include "string.h"
#include "type_conv.h"

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.
static volatile struct limine_framebuffer_request framebuffer_request = 
{
	.id = LIMINE_FRAMEBUFFER_REQUEST,
	.revision = 0
};

static uint64_t errno = 0;

//kernel entry point
void catalyst_main(void)
{
	//initialize COM1
	if (init_serial()) {
		hcf();
	}
	log_puts("Starting Catalyst Kernel\r\n");

	// Ensure we got a framebuffer.
	if (framebuffer_request.response == NULL
		|| framebuffer_request.response->framebuffer_count < 1) {
		hcf();
	}

	log_puts("Received framebuffer from Limine\r\n");

/* 	// Fetch the first framebuffer.
	struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

	// Note: we assume the framebuffer model is RGB with 32-bit pixels.
	for (size_t i = 0; i < 1000; i++) {
		uint32_t *fb_ptr = framebuffer->address;
		fb_ptr[i * (framebuffer->pitch / 4) + i] = 0x00ffffff;
	} */
halt:
	// We're done, just hang...
	log_puts("Halting...\r\n");
	hcf();
}
