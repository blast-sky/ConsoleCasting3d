#include <iostream>
#include "ConsoleCasting3d.h"

#include <chrono>
#include <thread>

int main()
{
	ConsoleCasting3d game;
	
	int i = 1000;
	while (--i)
	{
		game.lightDirection.x = std::sin(2 * double(i) / 100);
		game.lightDirection.y = std::sin(3 * double(i) / 100);

		game.makeStep();
		std::cout << game.field;

		std::this_thread::sleep_for(std::chrono::milliseconds(long long(1000./30)));
	}

	return 0;
}