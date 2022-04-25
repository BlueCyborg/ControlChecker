#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();

	consoleInit(GFX_TOP, NULL);

	printf("\x1b[1;0H -----------------------------");
	printf("\x1b[2;0H| Welcome to ControlChecker ! |");
	printf("\x1b[3;0H -----------------------------");

	printf("\x1b[26;15HPress Start to exit.");
	printf("\x1b[30;38HBy Andromeda.");


	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		touchPosition touch;
		hidTouchRead(&touch);
		printf("\x1b[7;0HX coordinate: %i       ",touch.px);
		printf("\x1b[8;0HY coordinate: %i       ",touch.py);

		//Screen verification
		u32 kHeld = hidKeysHeld();
		if (kHeld & KEY_TOUCH)
		{
			printf("\x1b[6;0HScreen is touch: TRUE ");
		}
		else
		{
			printf("\x1b[6;0HScreen is touch: FALSE");
		}

		//Directional cross verification
		if (kHeld & KEY_DRIGHT)
		{
			printf("\x1b[10;0HDirectional cross: RIGHT");
		}
		else if (kHeld & KEY_DLEFT)
		{
			printf("\x1b[10;0HDirectional cross: LEFT");
		}
		else if (kHeld & KEY_DUP)
		{
			printf("\x1b[10;0HDirectional cross: UP");
		}
		else if (kHeld & KEY_DDOWN)
		{
			printf("\x1b[10;0HDirectional cross: DOWN");
		}
		else
		{
			printf("\x1b[10;0HDirectional cross:        ");
		}

		//C-Stick verification
		if (kHeld & KEY_CSTICK_RIGHT)
		{
			printf("\x1b[12;0HC-Stick: RIGHT");
		}
		else if (kHeld & KEY_CSTICK_LEFT)
		{
			printf("\x1b[12;0HC-Stick: LEFT");
		}
		else if (kHeld & KEY_CSTICK_UP)
		{
			printf("\x1b[12;0HC-Stick: UP");
		}
		else if (kHeld & KEY_CSTICK_DOWN)
		{
			printf("\x1b[12;0HC-Stick: DOWN");
		}
		else
		{
			printf("\x1b[12;0HC-Stick:       ");
		}

		//Button verification
		if (kHeld & KEY_A)
		{
			printf("\x1b[14;0HButton: A");
		}
		else if (kHeld & KEY_B)
		{
			printf("\x1b[14;0HButton: B");
		}
		else if (kHeld & KEY_X)
		{
			printf("\x1b[14;0HButton: X");
		}
		else if (kHeld & KEY_Y)
		{
			printf("\x1b[14;0HButton: Y");
		}
		else if (kHeld & KEY_L)
		{
			printf("\x1b[14;0HButton: L");
		}
		else if (kHeld & KEY_ZL)
		{
			printf("\x1b[14;0HButton: ZL");
		}
		else if (kHeld & KEY_R)
		{
			printf("\x1b[14;0HButton: R");
		}
		else if (kHeld & KEY_ZR)
		{
			printf("\x1b[14;0HButton: ZR");
		}
		else if (kHeld & KEY_SELECT)
		{
			printf("\x1b[14;0HButton: Select");
		}
		else if (kHeld & KEY_START)
		{
			printf("\x1b[14;0HButton: Start");
		}
		else
		{
			printf("\x1b[14;0HButton:        ");
		}

		//C-PAD verification
		if (kHeld & KEY_CPAD_RIGHT)
		{
			printf("\x1b[16;0HC-PAD: RIGHT");
		}
		else if (kHeld & KEY_CPAD_LEFT)
		{
			printf("\x1b[16;0HC-PAD: LEFT");
		}
		else if (kHeld & KEY_CPAD_UP)
		{
			printf("\x1b[16;0HC-PAD: UP");
		}
		else if (kHeld & KEY_CPAD_DOWN)
		{
			printf("\x1b[16;0HC-PAD: DOWN");
		}
		else
		{
			printf("\x1b[16;0HC-PAD:        ");
		}

		//End
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START)
		{
			break;
		}

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
//By Andromeda from www.github.com/www-andromeda/