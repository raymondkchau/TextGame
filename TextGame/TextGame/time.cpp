#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "time.h"
#include "clearScreen.h"
#include "action.h"

//initializing variables
char input;
bool timeConsume;
bool badEnd = false;

float money = 50.0f;
int affection = 1;
int stress = 25;
int hunger = 50;
int thirst = 50;

int waterBottle = 5;
int petFood = 5;

void feedPet()
{
	clearScreen();
	bool feeding = true;

	while (feeding == true && (waterBottle > 0 || petFood > 0))
	{
		std::cout << "You have " << petFood << " Pet Food and " << waterBottle << " Bottled Water left." << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1) Feed Pet Food" << std::endl;
		std::cout << "2) Give Pet Water" << std::endl;
		std::cout << "3) Leave" << std::endl;
		input = clearInput(input);

		switch (input)
		{
		case 1:
			std::cout << "You fed your pet some food." << std::endl;
			Sleep(500);
			hunger -= 20;
			std::cout << "It looks a bit happier!" << std::endl;
			Sleep(500);
			affection += 2;
			break;

		case 2:
			std::cout << "You gave your pet some water." << std::endl;
			Sleep(500);
			thirst -= 10;
			std::cout << "It looks a bit happier!" << std::endl;
			Sleep(500);
			affection += 2;
			break;

		case 3:
			std::cout << "You decided to leave." << std::endl;
			feeding = false;
			break;
		}
		
		clearScreen();
	}
}

void playPet()
{
	clearScreen();
	std::cout << "You decided to play with your pet." << std::endl;
	std::cout << "You visit the park and play catch with you pet." << std::endl;
	next();
	std::cout << "It looks extremely happy!" << std::endl;
	affection += 10;
	stress -= 10;
	std::cout << "It gained 15 affection!" << std::endl;
	std::cout << "You also released some stress." << std::endl;
	next();
}

void work()
{
	clearScreen();
	//sends player to hangman minigame
	std::cout << std::endl << "You decide to go to work for a couple hours..." << std::endl;
	next();
	bool pay = hangman();

	//if player wins, pay, if they lose, gain more stress and less pay
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

void shop()
{
	clearScreen();
	bool quit = false;
	std::cout << "You walk to the shop by your house." << std::endl;
	std::cout << "The shop keeper greets you warmly. \"Welcome to the convenience store!\"" << std::endl;
	std::cout << std::endl;
	if (money > 0)
	{
		while (quit == false)
		{
			std::cout << "\"What would you like to buy?\"" << std::endl;
			std::cout << "You currently have $" << money << "." << std::endl;
			std::cout << "1) 5x Pet Food - $15" << std::endl;
			std::cout << "2) 5x Bottled Water - $5" << std::endl;
			std::cout << "3) Leave" << std::endl;
			input = clearInput(input);

			if (money > 0)
			{
				switch (input)
				{
				case 1:
				{
					if (money >= 15)
					{
						std::cout << "You bought 5 Pet Food." << std::endl;
						money -= 15;
						petFood += 5;
						next();
						break;
					}
					else
					{
						std::cout << "You don't have enough money." << std::endl;
						break;
					}
				}
				case 2:
				{
					if (money >= 5)
					{
						std::cout << "You bought 5 Bottled Waters." << std::endl;
						money -= 5;
						waterBottle += 5;
						next();
						break;
					}
					else
					{
						std::cout << "You don't have enough money." << std::endl;
						break;
					}
				}
				case 3:
				{
					std::cout << "You decide to return home." << std::endl;
					quit = true;
					next();
					break;
				}
				default:
				{
					std::cout << "Invalid input." << std::endl;
					next();
					break;
				}
				}
			}
			else
			{
				std::cout << "You're out of money!" << std::endl;
				quit == true;
			}

			clearScreen();
		}
		std::cout << "\"Thank you for shopping with us! Hope to see you again soon.\" The" << std::endl;
		std::cout << "shopkeeper says as you leave the store." << std::endl;
		next();
	}
	else
	{
		std::cout << "\"It doesn't look like you have any money! Please come back when you do, thank you.\"" << std::endl;
		std::cout << "The shop keep says. You decide to take your leave." << std::endl;
	}
}

void checkInventory()
{
	clearScreen();
	std::cout << "You decided to check you inventory." << std::endl;
	std::cout << "You currently have..." << std::endl;
	std::cout << "$" << money << std::endl;
	std::cout << petFood << " Pet Food" << std::endl;
	std::cout << waterBottle << " Bottled Water" << std::endl;
	next();
}

void time()
{
	//game loop, checks for how much time the player has left
	for (int week = 1; week >= 0; week--)
	{
		if (badEnd == true)
		{
			break;
		}

		for (int day = 6; day >= 0; day--)
		{
			if (badEnd == true)
			{
				break;
			}

			hunger -= 10;
			thirst -= 10;

			for (int time = 3; time > 0; time--)
			{
				clearScreen();
				timeConsume = false;

				eventCheck(stress, affection, hunger, thirst, money, badEnd);

				clamp(affection);
				clamp(hunger);
				clamp(thirst);
				clamp(stress);

				if (badEnd == true)
				{
					break;
				}

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

				while (timeConsume == false)
				{
					std::cout << "You have $" << money << " left." << std::endl;
					std::cout << "Your stress: " << stress << std::endl;
					std::cout << "Affection: " << affection << std::endl;
					std::cout << "Hunger: " << hunger << std::endl;
					std::cout << "Thirst: " << thirst << std::endl;

					std::cout << std::endl << "What would you like to do?" << std::endl;
					std::cout << "1) Feed Pet" << std::endl;
					std::cout << "2) Play With Your Pet" << std::endl;
					std::cout << "3) Work" << std::endl;
					std::cout << "4) Shop" << std::endl;
					std::cout << "5) Check Inventory" << std::endl;
					input = clearInput(input);

					switch (input)
					{
					case 1:
						feedPet();
						timeConsume = false;
						break;

					case 2:
						playPet();
						timeConsume = true;
						break;

					case 3:
						work();
						timeConsume = true;
						break;

					case 4:
						shop();
						timeConsume = true;
						break;

					case 5:
						checkInventory();
						timeConsume = false;
						break;
					}
				}
			}
		}
	}
	std::cout << std::endl << "You're out of time!" << std::endl;
}

void ending()
{
	if (affection <= 100 && money > 50)
	{
		//great end
		std::cout << "In the two weeks you had together, you and your pet have bonded extremely well." << std::endl;
	}
	
	if (affection <= 100 && money <= 50)
	{
		//good end, through sacrifice
		std::cout << "Although you are not poorer than you started, you cared for your pet moreso than yourself." << std::endl;
	}

	if (badEnd = true)
	{
		//bad end
		std::cout << "Not willing to stay any longer, your pet has left you." << std::endl;
	}
}

void stats()
{

}