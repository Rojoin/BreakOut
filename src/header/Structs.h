#pragma once

struct Vector2
{
	float x;
	float y;
};
struct Rectangle
{
	float x;
	float y;
	int width;
	int height;
	int rightEdge;
	int leftEdge;
	int upEdge;
	int downEdge;
};
void updatePadParts(Rectangle& rec);

struct Brick
{
	bool enabled;
	int score;
	Rectangle pad;
};
Brick createBrick(int x, int y, int width, int height);
struct Player
{
	Rectangle pad;
	int score;
	int lives;
};
struct Ball
{
	Vector2 position;
	int radius;
	Vector2 speed;
};



struct Color
{
	double r;
	double g;
	double b;
	double a;
};
const Color RED = { 1, 0, 0, 1 };
const Color BLUE = { 0, 0, 1, 1 };
const Color GREEN = { 0, 1, 0, 1 };
const Color LIGHTBLUE = { 0, 1, 1, 1 };
const Color PINK = { 1, 0, 1, 1 };
const Color ORANGE = { 1, 0.5, 0, 1 };
const Color YELLOW = { 1, 1,0 , 1 };
const Color VIOLET = { 0.5, 0,1 , 1 };
const Color WHITE = { 1, 1,1 , 1 };
const Color BLACK = { 0, 0,0 , 1 };
