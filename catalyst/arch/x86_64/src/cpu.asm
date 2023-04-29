; Praxis
;
; Copyright (C) 2023 Mohit D. Patel
;
; This program is free software: you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.
;
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
;
; You should have received a copy of the GNU General Public License
; along with this program.  If not, see <http://www.gnu.org/licenses/>.

section .bss
global regs
regs: resq 16
global rip_val
rip_val: resq 1

section .text
global hcf
hcf:
	cli ;clear interrupts
inf_loop:
	hlt ;halt in a loop
	jmp inf_loop
extern memset
global store_regs
store_regs:
	mov [regs], rax
	mov [regs + 1 * 8], rbx
	mov [regs + 2 * 8], rcx
	mov [regs + 3 * 8], rdx
	mov [regs + 4 * 8], rsi
	mov [regs + 5 * 8], rdi
	mov [regs + 6 * 8], rsp
	mov [regs + 7 * 8], rbp
	mov [regs + 8 * 8], r8
	mov [regs + 9 * 8], r9
	mov [regs + 10 * 8], r10
	mov [regs + 11 * 8], r11
	mov [regs + 12 * 8], r12
	mov [regs + 13 * 8], r13
	mov [regs + 14 * 8], r14
	mov [regs + 15 * 8], r15
	ret
global store_rip
store_rip:
	pop rax
	mov [rip_val], rax
	push rax
	ret

