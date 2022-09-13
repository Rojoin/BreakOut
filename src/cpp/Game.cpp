
#include "sl.h"
#include "../header/MenuScreen.h"
#include "../header/HowTo.h"
#include "../header/GameLogic.h"
int soundHit;
int soundDead;
int soundWin;
int soundLose;
int soundMenu;
void initGame()
{
	GameStates gameStates = GameStates::MainMenu;

	slWindow(900, 900, "Pong", false);

     soundHit  = slLoadWAV("../Assets/hit.wav");
	 soundDead = slLoadWAV("../Assets/dead.wav");
	 soundWin  = slLoadWAV("../Assets/win.wav");
	 soundLose = slLoadWAV("../Assets/lose.wav");
	 soundMenu = slLoadWAV("../Assets/breakOut.wav");

	slSetFont(slLoadFont("../Assets/PressStart2P.ttf"), 20);
	slSetTextAlign(SL_ALIGN_CENTER);
	bool activeWindow = true;
	slSoundLoop(soundMenu);
	while (activeWindow && !slShouldClose())
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
			howToState(gameStates);
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
			drawHowTo();
			break;
		case GameStates::Exit:
			break;

		}
		slRender();
	}
	slClose();


}