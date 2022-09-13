
#include "sl.h"
#include "../header/MenuScreen.h"
#include "../header/Functions.h"
#include "../header/GameLogic.h"
#include "../header/InputSystem.h"

void initGame()
{
	GameStates gameStates = GameStates::MainMenu;

	slWindow(900, 900, "Pong", false);

	slLoadWAV("../Assets/hit.wav");
	slSetFont(slLoadFont("../Assets/PressStart2P.ttf"), 20);
	slSetTextAlign(SL_ALIGN_CENTER);
	bool activeWindow = true;
	while (activeWindow && !slGetKey(SL_KEY_ESCAPE)&& !slShouldClose())
	{
		switch (gameStates)
		{
		case GameStates::MainMenu:
			menuState(gameStates);

			break;
		case GameStates::Game:
			gameLogic(gameStates);
			break;
		case GameStates::HowTo:
			break;
		case GameStates::Exit:
			activeWindow = false;
			break;

		}
		switch (gameStates)
		{
		case GameStates::MainMenu:
			drawMenu();

			break;
		case GameStates::Game:
			drawGame();
			break;
		case GameStates::HowTo:
			break;
		case GameStates::Exit:
			break;

		}
		slRender();
	}
	slClose();


}