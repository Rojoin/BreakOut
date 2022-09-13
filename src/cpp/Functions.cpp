#include "../../src/header/Functions.h"
#include <cmath>
#include "sl.h"

 Ball ball;
Vector2 getMousePosition()
{
	float x = slGetMouseX();
	float y = slGetMouseY();

	return { x,y };
}

void drawBall(Ball ball,Color color)
{
	
	slSetForeColor(color.r, color.g, color.b, color.a);
	slCircleFill(ball.position.x, ball.position.y, ball.radius, 100);
}
void drawRectangle(Rectangle rectangle, Color color)
{
	slSetForeColor(color.r, color.g, color.b, color.a);
	slRectangleFill(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
}
bool checkRecBallCollision(Rectangle rectangle, Ball ball)
{
	updatePadParts(rectangle); 
	float testX = ball.position.x;
	float testY = ball.position.y;

	if (ball.position.x < rectangle.leftEdge)
	{
		testX = rectangle.leftEdge;
	}
	else if (ball.position.x > rectangle.rightEdge)
	{
		testX = rectangle.rightEdge;
	}
	if (ball.position.y < rectangle.downEdge)
	{
		testY = rectangle.upEdge;
	}
	else if (ball.position.y > rectangle.upEdge)
	{
		testY = rectangle.downEdge;
	}

	float distanceX = ball.position.x - testX;
	float distanceY = ball.position.y - testY;
	float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

	if (distance <= ball.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkRecMouseCollision(Rectangle rec, Vector2 mouse)
{
	int rightEdge = rec.x + rec.width / 2;
	int leftEdge  = rec.x - rec.width / 2;
	int upEdge    = rec.y + rec.height/ 2;
	int downEdge  = rec.y - rec.height/ 2;

	if (mouse.x >= leftEdge && mouse.x <= rightEdge && mouse.y <= upEdge && mouse.y >= downEdge)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void setColor(Color color)
{
	slSetForeColor(color.r, color.g, color.b, color.a);
}







