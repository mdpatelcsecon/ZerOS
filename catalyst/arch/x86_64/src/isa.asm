global inb
inb:
	mov dx, di
	in al, dx
	ret

global outb
outb:
	mov dx, di
	mov al, sil
	out dx, al
	ret

global write
write:
	mov dx, 0xe9
	mov al, 65
	out dx, al
	ret
