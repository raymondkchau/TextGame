#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "time.h"
#include "clearScreen.h"

char input;
float money = 50.0f;
int affection = 0;
int stress = 25;
int hunger = 50;
int thirst = 50;
char word[10];

void wordSelect(int diff)
{
	int rando = rand() % 10 + 1;

	if (diff == 1)
	{
		std::cout << "Difficulty selected: Easy" << std::endl;

		if (rando == 1)
		{
			strcpy_s(word, "fort");
		}
		else if (rando == 2)
		{
			strcpy_s(word, "nuts");
		}
		else if (rando == 3)
		{
			strcpy_s(word, "doll");
		}
		else if (rando == 4)
		{
			strcpy_s(word, "soap");
		}
		else if (rando == 5)
		{
			strcpy_s(word, "spin");
		}
		else if (rando == 6)
		{
			strcpy_s(word, "zoo");
		}
		else if (rando == 7)
		{
			strcpy_s(word, "wolf");
		}
		else if (rando == 8)
		{
			strcpy_s(word, "tale");
		}
		else if (rando == 9)
		{
			strcpy_s(word, "rush");
		}
		else if (rando == 10)
		{
			strcpy_s(word, "sale");
		}
	}
	else if (diff == 2)
	{
		std::cout << "Difficulty selected: Medium" << std::endl;

		if (rando == 1)
		{
			strcpy_s(word, "shake");
		}
		else if (rando == 2)
		{
			strcpy_s(word, "shout");
		}
		else if (rando == 3)
		{
			strcpy_s(word, "habit");
		}
		else if (rando == 4)
		{
			strcpy_s(word, "pride");
		}
		else if (rando == 5)
		{
			strcpy_s(word, "lungs");
		}
		else if (rando == 6)
		{
			strcpy_s(word, "canal");
		}
		else if (rando == 7)
		{
			strcpy_s(word, "brick");
		}
		else if (rando == 8)
		{
			strcpy_s(word, "adult");
		}
		else if (rando == 9)
		{
			strcpy_s(word, "border");
		}
		else if (rando == 10)
		{
			strcpy_s(word, "chose");
		}
	}
	else if (diff == 3)
	{
		std::cout << "Difficulty selected: Hard" << std::endl;

		if (rando == 1)
		{
			strcpy_s(word, "mission");
		}
		else if (rando == 2)
		{
			strcpy_s(word, "mountain");
		}
		else if (rando == 3)
		{
			strcpy_s(word, "shallow");
		}
		else if (rando == 4)
		{
			strcpy_s(word, "tobacco");
		}
		else if (rando == 5)
		{
			strcpy_s(word, "huntress");
		}
		else if (rando == 6)
		{
			strcpy_s(word, "cookies");
		}
		else if (rando == 7)
		{
			strcpy_s(word, "instant");
		}
		else if (rando == 8)
		{
			strcpy_s(word, "wealthy");
		}
		else if (rando == 9)
		{
			strcpy_s(word, "robbery");
		}
		else if (rando == 10)
		{
			strcpy_s(word, "promised");
		}
	}

	Sleep(1500);
}

bool hangman()
{
	clearScreen();
	bool gameOn = true;
	char display[10];
	int diff;
	char guess;
	int tries = 10;
	bool win;
	int wrong;

	std::cout << "You're playing Hangman!" << std::endl;
	std::cout << std::endl;
	std::cout << "Select a difficulty!" << std::endl;
	std::cout << "1) Easy (3-4 letters)" << std::endl;
	std::cout << "2) Medium (5-6 letters)" << std::endl;
	std::cout << "3) Hard (7-8 letters)" << std::endl;
	std::cin >> diff;
	
	if (diff <= 0)
	{
		diff = 1;
	}
	else if (diff >= 4)
	{
		diff = 3;
	}

	wordSelect(diff);
	clearScreen();

	for (int i = 0; i < strlen(word); i++)
	{
		display[i] = '_';
	}

	while (gameOn = true || tries > 0)
	{
		for (int i = 0; i < strlen(word); i++)
		{
			std::cout << display[i];
		}
		std::cout << std::endl;
		std::cout << "You have " << tries << " tries left." << std::endl;

		std::cin >> std::setw(1) >> guess;

		wrong = 0;
		for (int i = 0; i < strlen(word); i++)
		{
			if (guess == word[i])
			{
				display[i] = guess;
			}
			else
			{
				wrong += 1;
			}
		}
		if (wrong == strlen(word))
		{
			tries -= 1;
		}

		std::cout << std::endl;

		if (strcmp(display, word) == 1)
		{
			std::cout << "Congrats! You win!" << std::endl;
			return win = true;
		}
		else if (tries <= 0)
		{
			std::cout << "I'm sorry... You lose." << std::endl;
			return win = false;
		}
		clearScreen();
	}


}

void work()
{
	std::cout << std::endl << "You decide to go to work for a couple hours..." << std::endl;
	next();
	bool pay = hangman();


	if (pay == true)
	{
		money += 50;
		stress += 10;
		std::cout << "You earned $50 for 4 hours of work!" << std::endl;
	}
	else if (pay == false)
	{
		money += 10;
		stress += 25;
		std::cout << "You did subpar at work and only got $10." << std::endl;
	}
	next();
}

void time()
{
	for (int week = 1; week >= 0; week--)
	{
		for (int day = 6; day >= 0; day--)
		{
			for (int time = 3; time > 0; time--)
			{
				clearScreen();

				if (week == 0 && day == 0)
				{
					std::cout << "Today is your final day." << std::endl;
				}
				else if (week > 0 && day == 0)
				{
					std::cout << "You have " << week << " week left." << std::endl;
				}
				else
				{
					std::cout << "You have " << week << " week, " << day << " days left." << std::endl;
				}

				if (time == 3)
				{
					std::cout << "It is morning." << std::endl;
				}
				else if (time == 2)
				{
					std::cout << "It is noon." << std::endl;
				}
				else
				{
					std::cout << "It is afternoon." << std::endl;
				}
				std::cout << std::endl;

				//Maybe add functions in here to do events?? Check for input and what to do?

				std::cout << "You have $" << money << " left." << std::endl;
				std::cout << "Your stress: " << stress << std::endl;
				std::cout << "Affection: " << affection << std::endl;
				std::cout << "Hunger: " << hunger << std::endl;
				std::cout << "Thirst: " << thirst << std::endl;

				std::cout << std::endl << "What would you like to do?" << std::endl;
				std::cout << "1) Work" << std::endl;
				std::cout << "2) Do nothing" << std::endl;
				input = clearInput(input);

				switch (input)
				{
				case 1:
					work();
					break;

				case 2:
					std::cout << "You did nothing." << std::endl;
					next();
				}
			}
		}
	}
	std::cout << std::endl << "You're out of time!" << std::endl;
}