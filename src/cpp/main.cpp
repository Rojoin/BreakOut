
#include <iostream>

#include "../header/Functions.h"
#include "../header/GameLogic.h"
#include "../header/InputSystem.h"

int main(int args, char* argv[])
{
	
	slWindow(900, 900, "I´m in Misery", false);

	bool first = true;
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		if (first)
		{
			initBrick();
			first = false;
		}
		gameLogic();
		drawGame();

	}
	slClose();
	return 0;
}