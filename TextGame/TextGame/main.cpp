#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//Attempt at making a turn-based rpg
int enemyHP;
int playerHP = 100;
int playerMP = 100;
int playerInventory[3] = { 1, 5, 3 }; //1. Sword 2. Potion 3. Mana Potion
string enemy;
string playerCommand;

void ClearScreen()
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

void battlePhase()
{
	//system("Color 1A");

	bool turnEnd = false;

	while (enemyHP > 0 || playerHP > 0)
	{
		if (playerHP <= 0)
		{
			break;
		}
		cout << "Enemy " << enemy << " would like to fight!" << endl;
		cout << "You currently have " << playerHP << " HP." << endl;
		cout << "\nWhat would you like to do?\nFight\nInventory\nRun\n" << endl;
		cin >> playerCommand;
		ClearScreen();

		if (playerCommand == "fight")
		{
			if (playerInventory[0] == 1)
			{
				cout << "You attack the enemy with your sword, dealing 15 damage.\n" << endl;
				enemyHP -= 15;
				cout << "The enemy now has " << enemyHP << " HP!" << endl;
				turnEnd = true;
			}
			if (playerInventory[1] == 0)
			{
				cout << "You attack the enemy with your bare fists, dealing 5 damage.\n" << endl;
				enemyHP -= 5;
				cout << "The enemy now has " << enemyHP << " HP!" << endl;
				turnEnd = true;
			}
		}
		if (playerCommand == "inventory")
		{
			cout << "In your bag, you have " << playerInventory[1] << " Health Potions and " << playerInventory[2] << " Mana Potions. Do you wan to drink a HP or MP?" << endl;
			cout << "(Available Commands: HP, MP, back" << endl;
			cin >> playerCommand;
			ClearScreen();

			if (playerCommand == "HP" || playerCommand == "hp")
			{
				cout << "You regained 50 HP!" << endl;
				playerInventory[1] -= 1;
				playerHP += 50;
				cout << "You now have " << playerHP << "!\n" << endl;
				turnEnd = true;
			}
			if (playerCommand == "back")
			{
				ClearScreen();
			}
		}

		if (turnEnd)
		{
			if (enemyHP <= 0)
			{
				break;
			}

			cout << "Enemy " << enemy << " attacks you for 10 HP!\n" << endl;
			playerHP -= 10;
			cout << "You now have " << playerHP << " HP!" << endl;
		}
	}

	if (enemyHP <= 0)
	{
		cout << "You won the battle!" << endl;
	}
	else if (playerHP <= 0)
	{
		cout << "You lost the battle... GAME OVER" << endl;
	}
}

int main()
{
	cout << "While walking around the forest, you ran into a wild Goblin!\n" << endl;
	enemy = "goblin";
	enemyHP = 15;

	battlePhase();

	system("pause");
}