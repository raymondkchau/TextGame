#include <iostream>
#include <Windows.h>
#include "time.h"
#include "clearScreen.h"

char input;
float money = 50.0f;
int affection = 0;
int stress = 25;
int hunger = 50;
int thirst = 50;

void work()
{
	std::cout << std::endl << "You decide to go to work for a couple hours..." << std::endl;
	next();
	money += 125;
	stress += 10;
	std::cout << "You earned $125 for 4 hours of work!" << std::endl;
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
				//std::cin >> input;
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