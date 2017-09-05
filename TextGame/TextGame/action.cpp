#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "clearScreen.h"
#include "action.h"

//answer for hangman
char word[10];

void wordSelect(int diff)
{
	//random number generator to select a random word
	int rando = rand() % 10 + 1;

	//difficulty select + word selector
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

	//shows blanks for missing letters in word
	for (int i = 0; i < strlen(word); i++)
	{
		display[i] = '_';
	}

	//hangman game loop
	while (gameOn = true || tries > 0)
	{
		for (int i = 0; i < strlen(word); i++)
		{
			std::cout << display[i];
		}
		std::cout << std::endl;
		std::cout << "You have " << tries << " tries left." << std::endl;

		//sets width of input
		std::cin >> std::setw(1) >> guess;

		wrong = 0;
		//checks to see if letter is wrong
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
		//checks to see if the letter goes anywhere, else remove a try
		if (wrong == strlen(word))
		{
			tries -= 1;
		}

		std::cout << std::endl;

		//checks to see if player guessed the correct word, then returns if they won or not
		if (strcmp(display, word) == 1)
		{
			std::cout << "Congrats! You win!" << std::endl;
			return win = true;
		}
		//checks if player is out of tries, if so, returns they lose
		else if (tries <= 0)
		{
			std::cout << "I'm sorry... You lose." << std::endl;
			return win = false;
		}
		clearScreen();
	}


}

void eventCheck(int &stress, int &affection, int &hunger, int &thirst, float &money, bool &badEnd)
{
	//add events in here
	if (stress == 100)
	{
		std::cout << "Due to your high stress, you couldn't help but drink." << std::endl;
		stress = 25;
		std::cout << "Your pet lost some affection!" << std::endl;
		affection -= 5;
		std::cout << "You lost some money!" << std::endl;
		money -= 20;
		std::cout << "Your pet is now a bit hungrier and thirstier!" << std::endl;
		std::cout << std::endl;
	}

	if (hunger <= 0)
	{
		std::cout << "Due to lack of food, your pet is extremely unhappy." << std::endl;
		affection -= 25;
		std::cout << std::endl;
	}

	if (thirst <= 0)
	{
		std::cout << "Due to lack of water, your pet is extremely unhappy." << std::endl;
		affection -= 25;
		std::cout << std::endl;
	}

	if (affection <= 0)
	{
		std::cout << "Due to your neglect, your pet ran away." << std::endl;
		badEnd = true;
	}
}