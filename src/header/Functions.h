#pragma once
#include "sl.h"
#include "../../src/header/Structs.h"

Vector2 getMousePosition();
void drawBall(Ball ball,Color color);
void drawRectangle(Rectangle rectangle, Color color);
bool checkRecBallCollision(Rectangle rectangle, Ball ball);
bool checkRecMouseCollision(Rectangle rec, Vector2 mouse);
void setColor(Color color);
