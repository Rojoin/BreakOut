
#include <iostream>

#include "../header/Functions.h"
#include "../header/GameLogic.h"
#include "../header/InputSystem.h"

int main(int args, char* argv[])
{
	
	slWindow(900, 900, "I´m in Misery", false);

	extern Ball ball;
	extern Player player;
	Vector2 pos = {100,200};
	Vector2 speed = {200,250};
	ball.radius = 5;
	ball.position = pos;
	ball.speed = speed;
	initBrick();
	player = { 450,50,100,25 };
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{

		gameLogic();

	}
	slClose();
	return 0;
}