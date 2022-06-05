#include "TextPrint.h"
#include "TypeDefs.h"
#include "IDT.h"
#include "Keyboard.h"
#include "MemoryMap.h"

extern const char Test[];

extern "C" void _start() {
	SetCursorPosition(PositionFromCoords(0, 0));
	ClearScreen();
	PrintString("Booting OpenOS...\n\r");
	InitializeIDT();

	MainKeyBoardHandler = KeyboardHandler;

	MemoryMapEntry** UsableMemoryMaps = GetUsableMemoryRegions();

	for (uint_8 i = 0; i < UsableMemoryRegionsCount; i++)
	{
		MemoryMapEntry* memMap = UsableMemoryMaps[i];
		PrintMemoryMap(memMap, CursorPosition);
	}

	return;
}