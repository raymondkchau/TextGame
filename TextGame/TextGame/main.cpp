#include <iostream>
#include "time.h"
#include "clearScreen.h"
//#include <Windows.h>
//#include <thread>
//#include <chrono>
using namespace std;

void main()
{
	char end;
	int phase = 0;

	switch (phase)
	{
	case 0:
	{
		std::cout << "Your good ol' friend Gary has decided to take a 2 week vacation. You offered to watch his pet." << std::endl;
		std::cout << "\"Make sure you take care of it,\" he says, \"its my whole world. I don't know what I'd do if I lost it.\"" << std::endl;
		std::cout << "Now that Gary has gone, the two of you are alone at home," << std::endl;
		next();
	}

	case 1:
	{
		time();
	}

	case 2:
	{
		ending();
		std::cout << "Let's see how you did..." << std::endl;
		stats();
	}
	}

	next();
}

//color changer and text delayer tutorial
/*
void colorPicker(int color)
{
	//changes text color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void delayText(int millisec, char word[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		int rando = rand() % 15 + 1;
		colorPicker(rando);
		cout << word[i];
		this_thread::sleep_for(chrono::milliseconds(millisec));
	}
}

void toot()
{
	//number changes color. use before each cout to change the color till otherwise specified.
	colorPicker(5);
	std::cout << std::endl;
	std::cout << "LOL" << std::endl;
	delayText(300, "SLLLLLOOOOOOWWWWW MOOOOOOOTTTTTTIIIIOOOONNN");

	while (true)
	{

	}
}
*/