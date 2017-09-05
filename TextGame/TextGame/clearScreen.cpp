#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <limits>
#include "clearScreen.h"

void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

int clearInput(int x)
{
	while (!(std::cin >> x))
	{
		std::cin.clear(); //Clears failbit from character
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignores bad input
		std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
	}

	std::cout << std::endl;
	return x;
}

void next()
{
	char next[80];
	std::cout << "Enter any key to continue..." << std::endl;
	std::cin >> next;
}

void clamp(int &clamp)
{
	if (clamp < 0)
	{
		clamp = 0;
	}
	else if (clamp > 100)
	{
		clamp = 100;
	}
}