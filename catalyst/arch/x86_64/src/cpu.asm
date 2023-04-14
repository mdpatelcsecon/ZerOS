; Aster
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
regs: resq 15
global rip
rip_val: resq 1

section .text
global hcf
hcf:
	cli ;clear interrupts
loop:
	hlt ;halt in a loop
	jmp loop

global store_regs
store_regs:
	mov [regs + 0], rax
	mov [regs + 1], rbx
	mov [regs + 2], rcx
	mov [regs + 3], rdx
	mov [regs + 4], rsi
	mov [regs + 5], rdi
	mov [regs + 6], rsp
	mov [regs + 7], rbp
	mov [regs + 8], r8
	mov [regs + 9], r9
	mov [regs + 10], r10
	mov [regs + 11], r11
	mov [regs + 12], r12
	mov [regs + 13], r13
	mov [regs + 14], r14
	mov [regs + 15], r15
	ret
global store_rip
store_rip:
	pop rax
	mov [rip_val], rax
	ret
