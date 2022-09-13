#include "../header/InputSystem.h"
#include "sl.h"

extern int screenSize;
void playerInput(Player& player)
{
	double delta = slGetDeltaTime();
	if ((slGetKey('A')&& player.pad.leftEdge > 0)|| (slGetKey(SL_KEY_LEFT) && player.pad.leftEdge > 0))
	{
		
		player.pad.x -= player.speed * delta;
	}
	if((slGetKey('D')&& player.pad.rightEdge < screenSize)|| (slGetKey(SL_KEY_RIGHT) && player.pad.rightEdge < screenSize))
	{
		player.pad.x += player.speed * delta;
	}

}
bool goBackToMenu()
{
	if (slGetKey(' '))
	{
		return true;
	}
	return false;
}
bool resetGame()
{
	if (slGetKey('R'))
	{
		return true;
	}
	return false;
}