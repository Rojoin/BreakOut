#include "../header/InputSystem.h"
#include "sl.h"

void playerInput(Player& player)
{
	double test = slGetDeltaTime();
	if (slGetKey('A')&& player.pad.leftEdge > 0)
	{
		
		player.pad.x -= player.speed * test ;
	}
	if(slGetKey('D')&& player.pad.rightEdge < 900)
	{
		player.pad.x += player.speed * test;
	}

}