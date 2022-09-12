#include "../header/GameLogic.h"
#include "../header/InputSystem.h"
#include "../header/Functions.h"

#include <cmath>

extern Ball ball;
Player player;
Brick brick;
void paddleBallLogic(Player player)
{
	if (checkRecBallCollision(player.pad,ball))
	{
		ball.position.y = player.pad.upEdge + ball.radius + 0.1f;
		ball.speed.x = abs(ball.speed.x);
		if (ball.position.x <= player.pad.leftEdge)
		{
			ball.speed.x  *= -1.0f;
		}
		else if (ball.position.x>player.pad.leftEdge && ball.position.x < player.pad.x)
		{
			ball.speed.x *= -(ball.position.x / player.pad.x);
		}
		else if (ball.position.x>player.pad.x && ball.position.x < player.pad.rightEdge)
		{
			ball.speed.x *= -(ball.position.x / player.pad.rightEdge);
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
	if (checkRecBallCollision(brick.pad, ball)&& brick.enabled)
	{
		updatePadParts(brick.pad);
		if (ball.position.y <= brick.pad.downEdge)
		{
			ball.position.y = (brick.pad.downEdge - ball.radius - 0.1f);
		}
		if (ball.position.y > brick.pad.upEdge)
		{
			ball.position.y = (brick.pad.upEdge + ball.radius+0.1f);
		}
		ball.speed.x = abs(ball.speed.x);
		if (ball.position.x <= brick.pad.leftEdge)
		{
			ball.speed.x *= -1.0f;
		}
		else if (ball.position.x > brick.pad.leftEdge && ball.position.x < brick.pad.x)
		{
			ball.speed.x *= -(ball.position.x / brick.pad.x);
		}
		else if (ball.position.x > brick.pad.x && ball.position.x < brick.pad.rightEdge)
		{
			ball.speed.x *= -(ball.position.x / brick.pad.rightEdge);
		}
		else if (ball.position.x >= brick.pad.rightEdge)
		{
			ball.speed.x *= 1.0f;
		}
		
		ball.speed.y *= -1.0f;
		brick.enabled = false;
	}
}
void ballLogic()
{
	ball.position.x += ball.speed.x* slGetDeltaTime();
	ball.position.y += ball.speed.y* slGetDeltaTime();
}

void blockCheck()
{
}

void blockCollision()
{
}

void wallCollision()
{
	if (ball.position.y >=900- ball.radius)
	{
		ball.position.y = 900 - ball.radius - 0.02f;
		ball.speed.y *= -1.0f;
	}
	if (ball.position.y < ball.radius)
	{
		ball.position.y =  ball.radius +0.02f;
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
		ball.speed.x  *= -1.0f;
	}


}

void floorCollision()
{

}
void initBrick()
{
	brick = createBrick(1,1,50,25);
	Player player = { 450,50,100,25 };
}
void gameLogic()
{
	updatePadParts(player.pad);
	playerInput(player);
	ballLogic();
	wallCollision();
	paddleBallLogic(player);
	drawBall(ball, RED);
	drawRectangle(player.pad, WHITE);
	brickBallLogic(brick);
	
	if (brick.enabled)
	{

		drawRectangle(brick.pad, BLUE);
	}
	slRender();
}

void drawGame()
{
}
