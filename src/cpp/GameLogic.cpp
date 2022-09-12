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
		ball.position.y = player.pad.upEdge + ball.radius + 0.1f;
		ball.speed.x = abs(ball.speed.x);
		if (ball.position.x <= player.pad.leftEdge)
		{
			ball.speed.x *= -1.0f;
		}
		else if (ball.position.x > player.pad.leftEdge && ball.position.x < player.pad.x)
		{
			ball.speed.x *= -(ball.position.x / player.pad.x);
		}
		else if (ball.position.x > player.pad.x && ball.position.x < player.pad.rightEdge)
		{
			ball.speed.x *= (ball.position.x / player.pad.rightEdge);
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
		if (ball.position.y <= brick.pad.downEdge)
		{
			ball.position.y = (brick.pad.downEdge - ball.radius - 0.1f);
		}
		if (ball.position.y > brick.pad.upEdge)
		{
			ball.position.y = (brick.pad.upEdge + ball.radius + 0.1f);
		}
		ball.speed.x = abs(ball.speed.x);
		if (ball.position.x <= brick.pad.leftEdge)
		{
			ball.speed.x *= -1.0f;
		}
		else if (ball.position.x > brick.pad.leftEdge && ball.position.x < brick.pad.x)
		{
			ball.speed.x *= -1.0f;
		}
		else if (ball.position.x > brick.pad.x && ball.position.x < brick.pad.rightEdge)
		{
			ball.speed.x *= 1.0f;
		}
		else if (ball.position.x >= brick.pad.rightEdge)
		{
			ball.speed.x *= 1.0f;
		}
		ball.speed.x += 1.0f;
		ball.speed.y *= -1.0f;
		brick.enabled = false;
	}
}
void ballLogic()
{
	
	if (ball.speed.x >maxSpeed)
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
		ball.position.y = ball.radius + 0.02f;
		ball.speed.y *= -1.0f;
	}
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

	Vector2 pos = { 100,200 };
	Vector2 speed = { minSpeed,minSpeed };
	ball.radius = 10;
	ball.position = pos;
	ball.speed = speed;
	player = { 450,50,100,25 };
}
void gameLogic()
{
	updatePadParts(player.pad);
	playerInput(player);
	ballLogic();
	wallCollision();
	paddleBallLogic(player);
	for (int i = 0; i < 36; ++i)
	{
		brickBallLogic(brick[i]);
	}



}

void drawGame()
{
	drawBall(ball, RED);
	drawRectangle(player.pad, WHITE);
	
	for (int i = 0; i < 36; ++i)
	{
		if (brick[i].enabled)
		{
			if (i %2 == 0)
			{
				drawRectangle(brick[i].pad, GREEN);
			}
			else if (i % 2 != 0)
			{
				drawRectangle(brick[i].pad, YELLOW);
			}
			
			
		}
	}

	slRender();
}
