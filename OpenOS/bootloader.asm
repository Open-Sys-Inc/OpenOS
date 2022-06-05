[org 0x7c00]

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

call ReadDisk

jmp PROGRAM_SPACE

%include "DiskRead.asm"

OSBootString:
	db 'Booting OpenOS',0

times 510-($-$$) db 0

dw 0xAA55