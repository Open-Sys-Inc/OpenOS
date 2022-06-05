#include "Keyboard.h"

bool LeftShiftPressed = false;
bool RightShiftPressed = false;
uint_8 LastScancode = 0;

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr) {
	if (chr != 0)
		if (LeftShiftPressed || RightShiftPressed)
			PrintChar(chr - 32);
		else
			PrintChar(chr);
	else
		switch (scanCode) {
		case 0x8E:  // Backspace
			SetCursorPosition(CursorPosition - 1);
			PrintChar(' ');
			SetCursorPosition(CursorPosition - 1);
			break;
		case 0x2A: // Left Shift Enter
			LeftShiftPressed = true;
			break;
		case 0xAA: // Left Shift Release
			LeftShiftPressed = false;
			break;
		case 0x36: // Right Shift Enter
			RightShiftPressed = true;
			break;
		case 0xB6: // Right Shift Release
			RightShiftPressed = false;
			break;
		case 0x9C: // Enter
			PrintString("\n\r");
			break;
		}
}

void KeyboardHandler0x0E(uint_8 scanCode) {
	switch (scanCode) {
	case 0x50:
		SetCursorPosition(CursorPosition + VGA_WIDTH);
		break;
	case 0x48:
		SetCursorPosition(CursorPosition - VGA_WIDTH);
		break;
	default:
		break;
	}
}

void KeyboardHandler(uint_8 scanCode, uint_8 chr) {

	switch (LastScancode) {
	case 0xE0:
		KeyboardHandler0x0E(scanCode);
		break;
	default:
		StandardKeyboardHandler(scanCode, chr);
	}

	LastScancode = scanCode;
}