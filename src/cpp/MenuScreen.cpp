#include "../header/MenuScreen.h"
#include "../header/Functions.h"

Button playButton = createButton(450,800,100,50,"PLAY",GREEN);
Button howToButton = createButton(450, 500, 100, 50, "PLAY", GREEN);
Button exitButton = createButton(450, 300, 100, 50, "PLAY", RED);


void menuState(GameStates& gameStates)
{
	if (checkRecMouseCollision(playButton.rec,getMousePosition()))
	{
		playButton.isOver = true;
		if (slGetMouseButton(SL_MOUSE_BUTTON_1))
		{
			slClose();
		}
	}
}

void menuDraw()
{
	if (playButton.isOver)
	{
		drawRectangle(playButton.rec, playButton.color);
	}
	else
	{
		drawRectangle(playButton.rec, WHITE);
	}
}
