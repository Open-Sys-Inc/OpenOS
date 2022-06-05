
PROGRAM_SPACE equ 0x8000

ReadDisk:
	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 32
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02

	int 0x13

	jc DiskReadFailed

	ret

BOOT_DISK:
	db 0

DiskReadErrorString:
	db 'Error while reading disk.',0

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString

	jmp $

PrintString:
	mov ah, 0x0e
	.Loop:
	cmp [bx], byte 0
	je .Ext
		mov al, [bx]
		int 0x10
		inc bx,
		jmp .Loop
	.Ext:
	ret