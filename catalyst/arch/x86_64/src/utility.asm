global hcf
hcf:
	cli ;clear interrupts
l:
	hlt ;halt in a loop
	jmp l