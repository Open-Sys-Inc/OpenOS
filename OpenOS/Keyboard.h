#pragma once
#include "TextPrint.h"
#include "TypeDefs.h"

extern bool LeftShiftPressed;
extern bool RightShiftPressed;
extern uint_8 LastScancode;

void KeyboardHandler(uint_8 scanCode, uint_8 chr);
void KeyboardHandler0x0E(uint_8 scanCode);
void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr);