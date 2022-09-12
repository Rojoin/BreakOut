#include "../header/GameLogic.h"
#include "../header/InputSystem.h"
#include "../header/Functions.h"

#include <cmath>

extern Ball ball;
Player player;

Brick brick[36];


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



		brick.enabled = false;
	}
}
void ballLogic()
{

	if (ball.speed.x > maxSpeed)
	{
		ball.speed.x = maxSpeed;
	}
	if (ball.speed.y > maxSpeed)
	{
		ball.speed.y = maxSpeed;
	}
	ball.position.x += ball.speed.x * slGetDeltaTime();
	ball.position.y += ball.speed.y * slGetDeltaTime();

}

void blockCheck()
{
}

void blockCollision()
{
}

void wallCollision()
{
	if (ball.position.y >= 900 - ball.radius)
	{
		ball.position.y = 900 - ball.radius - 0.02f;
		ball.speed.y *= -1.0f;
	}

	if (ball.position.x < ball.radius)
	{
		ball.position.x = ball.radius + 0.02f;
		ball.speed.x *= -1.0f;
	}
	if (ball.position.x > 900 - ball.radius)
	{
		ball.position.x = 900 - ball.radius - 0.02f;
		ball.speed.x *= -1.0f;
	}


}

void floorCollision()
{
	if (ball.position.y < ball.radius)
	{
		player.lives--;
	}
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
	Vector2 speed = { minSpeed,minSpeed };
	ball.isMoving = false;
	ball.position = pos;
	ball.speed = speed;
}
void initBrick()
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


	initBall();
	player = { 400,0,3,{450,50,100,25} };
}
void gameLogic()
{
	updatePadParts(player.pad);
	playerInput(player);
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
		paddleBallLogic(player);
		for (int i = 0; i < 36; ++i)
		{
			brickBallLogic(brick[i]);

		}
	}




}

void drawGame()
{
	if (areActiveBricks())
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
	slRender();
}
