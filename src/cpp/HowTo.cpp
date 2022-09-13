#include "../header/HowTo.h"
#include "../header/Functions.h"

Button backButton = createButton(screenSize / 4, 100, 110, 50, "BACK", RED);
void howToState(GameStates& gameStates)
{
	if (checkRecMouseCollision(backButton.rec, getMousePosition()))
	{
		backButton.isOver = true;
		if (slGetMouseButton(SL_MOUSE_BUTTON_1))
		{
			gameStates = GameStates::MainMenu;
		}
	}
	else
	{
		backButton.isOver = false;
	}
}

void drawHowTo()
{
	setColor(PINK);
	slSetFontSize(50);
	slText(screenSize / 2, screenSize - 200, "How to Play");
	slSetFontSize(10);
	setColor(WHITE);
	slText(screenSize / 2, 500, "In BREAKOUT you are a prisioner that is trying to escape from his cell");
	slText(screenSize / 2, 400, "Use the A/D or the left and right arrow keys to move your character with your pad");
	slSetFontSize(15);
	slText(screenSize / 2, 300, "Press ESCAPE to go back to the Menu");
	slSetFontSize(12);
	slText(screenSize / 2, 250, "Break the bricks hitting the ball and be free!!");


	if (backButton.isOver)
	{
		drawRectangle(backButton.rec, backButton.color);
	}
	else
	{
		drawRectangle(backButton.rec, WHITE);
	}
	slSetForeColor(0, 0, 0, 1);
	slText(backButton.rec.x, backButton.rec.y, backButton.buttonTittle.c_str());
}

