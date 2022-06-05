#include "MemoryMap.h"

uint_8 UsableMemoryRegionsCount;
MemoryMapEntry* UsableMemoryMapRegion[10];

void PrintMemoryMap(MemoryMapEntry* memoryMap, uint_16 position) {
	SetCursorPosition(position);

	PrintString("Memory base: "); PrintString(IntegerToString(memoryMap->BaseAddress));
	SetCursorPosition(position + 80);
	PrintString("Memory length: "); PrintString(IntegerToString(memoryMap->RegionLength));
	SetCursorPosition(position + 160);
	PrintString("Memory type: "); PrintString(IntegerToString(memoryMap->RegionType));
	SetCursorPosition(position + 240);
	PrintString("Memory attributes: "); PrintString(HexToString(memoryMap->ExtendedAttributes));
	SetCursorPosition(position + 400);
}

bool MemoryRegionsGot = false;

MemoryMapEntry** GetUsableMemoryRegions() {
	if (MemoryRegionsGot) {
		return UsableMemoryMapRegion;
	}

	uint_8 UsableRegionIndex;
	for (uint_8 i = 0; i < MemoryRegionCount; i++)
	{
		MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
		memMap += i;
		if (memMap->RegionType == 1) {
			UsableMemoryMapRegion[UsableRegionIndex] = memMap;
			UsableRegionIndex++;
		}

		UsableMemoryRegionsCount = UsableRegionIndex;
	}

	MemoryRegionsGot = true;
	return UsableMemoryMapRegion;
}