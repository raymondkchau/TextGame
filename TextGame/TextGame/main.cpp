#include <iostream>
#include "time.h"

void main()
{
	char end;
	int phase = 0;

	switch (phase)
	{
	case 0:
	{
		std::cout << "Your good ol' friend Gary has decided to take a 2 week vacation. You offered to watch his pet." << std::endl;
		std::cout << "\"Make sure you take care of it\" he says, \"its my whole world. I don't know what I'd do if I lost it.\"" << std::endl;
		std::cout << "Now that Gary has gone and the two of you are at home," << std::endl;
	}

	case 1:
	{
		time();
	}

	case 2:
	{
		std::cout << "Let's see how you did..." << std::endl;
	}
	}

	std::cout << "Enter any key to continue..." << std::endl;
	std::cin >> end;
}