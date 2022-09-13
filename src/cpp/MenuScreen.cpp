#include "../header/MenuScreen.h"
#include "../header/Functions.h"
#include "../header/GameLogic.h"


Button playButton = createButton(450,700,110,50,"PLAY",GREEN);
Button howToButton = createButton(450, 500, 110, 50, "HOWTO", GREEN);
Button exitButton = createButton(450, 300, 110, 50, "EXIT", RED);


void menuState(GameStates& gameStates)
{
	if (checkRecMouseCollision(playButton.rec,getMousePosition()))
	{
		playButton.isOver = true;
		if (slGetMouseButton(SL_MOUSE_BUTTON_1))
		{
			gameStates = GameStates::Game;
			initPlay();
		}
	}
	else
	{
		playButton.isOver = false;
	}
	if (checkRecMouseCollision(howToButton.rec, getMousePosition()))
	{
		howToButton.isOver = true;
		if (slGetMouseButton(SL_MOUSE_BUTTON_1))
		{
			gameStates = GameStates::HowTo;
		}
	}
	else
	{
		howToButton.isOver = false;
	}

	if (checkRecMouseCollision(exitButton.rec, getMousePosition()))
	{
		exitButton.isOver = true;
		if (slGetMouseButton(SL_MOUSE_BUTTON_1))
		{
			gameStates = GameStates::Exit;
		}
	}
	else
	{
		exitButton.isOver = false;
	}
}

void drawMenu()
{

	if (playButton.isOver)
	{
		drawRectangle(playButton.rec, playButton.color);
	}
	else
	{
		drawRectangle(playButton.rec, WHITE);
	}
	slSetForeColor(0, 0, 0, 1);
	slText(playButton.rec.x, playButton.rec.y, playButton.buttonTittle.c_str());
	if (howToButton.isOver)
	{
		drawRectangle(howToButton.rec, howToButton.color);
	}
	else
	{
		drawRectangle(howToButton.rec, WHITE);
	}
	slSetForeColor(0, 0, 0, 1);
	slText(howToButton.rec.x, howToButton.rec.y, howToButton.buttonTittle.c_str());
	if (exitButton.isOver)
	{
		drawRectangle(exitButton.rec, exitButton.color);
	}
	else
	{
		drawRectangle(exitButton.rec, WHITE);
	}
	slSetForeColor(0, 0, 0, 1);
	slText(exitButton.rec.x, exitButton.rec.y, exitButton.buttonTittle.c_str());
}
