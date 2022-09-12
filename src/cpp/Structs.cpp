#include "../../src/header/Structs.h"

void updatePadParts(Rectangle& rec)
{
	rec.rightEdge= rec.x + rec.width / 2;
	rec.leftEdge = rec.x - rec.width / 2;
	rec.upEdge   = rec.y + rec.height / 2;
	rec.downEdge = rec.y - rec.height / 2;
}

Brick createBrick(int x,int y,int width,int height)
{
	Brick brick;
	brick.enabled = true;
	brick.pad.x = x * 50;
	brick.pad.x = y * 25;
	brick.pad.width = width;
	brick.pad.height = height;
	return brick;

}
