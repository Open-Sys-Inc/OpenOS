
jmp EnterProtectedMode

jmp $

%include "gdt.asm"
%include "DetectMem.asm"

EnterProtectedMode:

	call DetectMemory
	call EnableA20
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp codeseg:StartProtectedMode

EnableA20:
	in al, 0x02
	or al, 2
	out 0x92, al
	ret

[bits 32]

%include "CPUID.asm"
%include "Paging.asm"

StartProtectedMode:
	
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov [0xb8000], byte 'O'
	mov [0xb8002], byte 'p'
	mov [0xb8004], byte 'e'
	mov [0xb8006], byte 'n'
	mov [0xb8008], byte 'O'
	mov [0xb800a], byte 'S'

	call DetectCPUID
	call DetectLongMode
	call SetupIdentityPaging
	call EditGDT

	jmp codeseg:Start64Bit

[bits 64]
[extern _start]

%include "IDT.asm"

Start64Bit:
	mov edi, 0xb8000
	mov rax, 0x1f201f201f201f20
	mov ecx, 500
	rep stosq
	call ActivateSSE
	call _start
	jmp $

ActivateSSE:
	mov rax, cr0
	mov ax, 0b11111101
	or ax, 0b00000001
	mov cr0, rax

	mov rax, cr4
	or ax, 0b1100000000
	mov cr4, rax

	ret

times 2048-($-$$) db 0