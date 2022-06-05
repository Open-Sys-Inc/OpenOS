nasm bootloader.asm -f bin -o bootloader.bin

nasm ExtendedProgram.asm -f elf64 -o extprog.o

nasm Binaries.asm -f elf64 -o bins.o

wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel.cpp" -o "kernel.o"

wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "IDT.cpp" -o "IDT.o"

wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "IO.cpp" -o "io.o"

wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Keyboard.cpp" -o "kboard.o"

wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "MemoryMap.cpp" -o "memmap.o"

wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "TextPrint.cpp" -o "txprint.o"

wsl $WSLENV/x86_64-elf-ld -T"link.ld"

copy /b bootloader.bin+kernel.bin OpenOS.flp

pause