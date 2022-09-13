#include "../header/GameLogic.h"
#include "../header/InputSystem.h"
#include "../header/Functions.h"

#include <cmath>

extern Ball ball;
extern int soundHit;
Player player;
extern int screenSize;
int windowGameSize = screenSize - 100;
Brick brick[36];
std::string playerScore;
std::string playerLifes;

void paddleBallLogic(Player player)
{
	if (checkRecBallCollision(player.pad, ball))
	{
		
		ball.speed.x = abs(ball.speed.x);
		if (ball.position.x <= player.pad.leftEdge)
		{
			ball.speed.x *= -1.0f;
		}
		else if (ball.position.x > player.pad.leftEdge && ball.position.x < player.pad.x)
		{
			ball.position.y = player.pad.upEdge + ball.radius + 0.1f;
			ball.speed.x *= -(1.0f+ (ball.position.x / player.pad.x));
		}
		else if (ball.position.x > player.pad.x && ball.position.x < player.pad.rightEdge)
		{
			ball.position.y = player.pad.upEdge + ball.radius + 0.1f;
			ball.speed.x *= (1.0f + (ball.position.x / player.pad.x));
		}
		else if (ball.position.x >= player.pad.rightEdge)
		{
			ball.speed.x *= 1.0f;
		}
		ball.speed.y *= -1.0f;
		slSoundPlay(soundHit);
	}
}
void brickBallLogic(Brick& brick)
{
	if (checkRecBallCollision(brick.pad, ball) && brick.enabled)
	{
		updatePadParts(brick.pad);
		ball.speed.y = abs(ball.speed.y);
		if (ball.position.y > brick.pad.downEdge)
		{
			ball.position.y = (brick.pad.downEdge - ball.radius - 0.1f);
			ball.speed.y *= -1.1f;
		}
		else if (ball.position.y < brick.pad.upEdge)
		{
			ball.position.y = (brick.pad.upEdge + ball.radius + 0.1f);
			ball.speed.y *= -1.1f;
		}
		else
		{
			ball.speed.y *= 1.1f;
		}
		if (ball.position.x < brick.pad.leftEdge)
		{
			ball.position.x = brick.pad.leftEdge - ball.radius - 0.1f;
			ball.speed.x *= -1.1f;
		}
		else if (ball.position.x > brick.pad.rightEdge)
		{
			ball.position.x = brick.pad.rightEdge + ball.radius + 0.1f;
			ball.speed.x *= -1.1f;
		}

		else
		{
			ball.speed.x *= 1.1f;
		}

		player.score += brick.score;
		slSoundPlay(soundHit);
		brick.enabled = false;
	}
}
void ballLogic()
{

	if (ball.speed.x > maxBallSpeed)
	{
		ball.speed.x = maxBallSpeed;
	}
	if (ball.speed.y > maxBallSpeed)
	{
		ball.speed.y = maxBallSpeed;
	}
	ball.position.x += ball.speed.x * slGetDeltaTime();
	ball.position.y += ball.speed.y * slGetDeltaTime();

}
void wallCollision()
{
	if (ball.position.y >= windowGameSize - ball.radius)
	{
		ball.position.y = windowGameSize - ball.radius - 0.02f;
		ball.speed.y *= -1.0f;
	}

	if (ball.position.x < ball.radius)
	{
		ball.position.x = ball.radius + 0.02f;
		ball.speed.x *= -1.0f;
	}
	if (ball.position.x > screenSize - ball.radius)
	{
		ball.position.x = screenSize - ball.radius - 0.02f;
		ball.speed.x *= -1.0f;
	}


}
void updateScoreBoard()
{
	playerScore = "SCORE:" + std::to_string(player.score);
	playerLifes = "LIVES:" + std::to_string(player.lives);

}
bool areActiveBricks()
{
	for (int i = 0; i < 36; ++i)
	{
		if (brick[i].enabled)
		{
			return true;
		}
	}
	return false;
}
void initBall()
{
	ball.radius = 10;
	Vector2 pos = { player.pad.x,player.pad.upEdge+ball.radius+0.1f };
	Vector2 speed = { minBallSpeed,minBallSpeed };
	ball.position = pos;
	ball.speed = speed;
}
void floorCollision()
{
	if (ball.position.y < ball.radius)
	{
		player.lives--;
		initBall();
	}
}
void initPlayer()
{
	player = { 400,0,3,{(float)screenSize/2,50,100,25}};
	updatePadParts(player.pad);
}
void initPlay()
{
	int number = 0;
	while (number < 35)
	{

		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				brick[number] = createBrick(k, j, 100, 25);
				number++;
			}
		}
	}

	initPlayer();
	initBall();
}
void gameLogic(GameStates& gameStates)
{
	updatePadParts(player.pad);
	playerInput(player);
		updateScoreBoard();
	if (areActiveBricks() && player.lives >0)
	{
#if _DEBUG
		if (slGetKey('Q'))
		{

			for (int i = 0; i < 36; ++i)
			{
				brick[i].enabled = false;

			}
		}
#endif
		ballLogic();
		wallCollision();
		floorCollision();
		paddleBallLogic(player);
		for (int i = 0; i < 36; ++i)
		{
			brickBallLogic(brick[i]);

		}
	}
	else if (!areActiveBricks() || player.lives <= 0)
	{
		
		if (goBackToMenu())
		{
			gameStates = GameStates::MainMenu;
		}
		if(resetGame())
		{
			initPlay();
		}
		
	}
	




}

void drawGame()
{
	drawRectangle({ 450,900,900,200 }, WHITE);
	setColor(BLUE);
	slText(100, 850, playerScore.c_str());
	slText(800, 850, playerLifes.c_str());

	if (player.lives <= 0 && areActiveBricks())
	{
		setColor(RED);
		slText(450, 450, "YOU LOSE");
		setColor(WHITE);
		slText(450, 300, "Press space to go back to Menu");
		slText(450, 200, "Press R to restart the game");
	}
	else if (areActiveBricks())
	{
		drawBall(ball, RED);
		drawRectangle(player.pad, WHITE);

		for (int i = 0; i < 36; ++i)
		{
			if (brick[i].enabled)
			{
				if (i % 2 == 0)
				{
					drawRectangle(brick[i].pad, GREEN);
				}
				else if (i % 2 != 0)
				{
					drawRectangle(brick[i].pad, YELLOW);
				}


			}
		}
	}
	else if (!areActiveBricks() && player.lives >0)
	{
		setColor(GREEN);
		slText(450, 450, "YOU WIN");
		setColor(WHITE);
		slText(450, 300, "Press space to go back to Menu");
		slText(450, 200, "Press R to restart the game");

	}
	

	
	
}
