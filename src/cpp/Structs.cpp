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
	int yLine = 35 - y;
	Brick brick;
	brick.pad.width = width;
	brick.pad.height = height;
	brick.enabled = true;
	brick.score = 1;
	brick.pad.x = (x *  width)+ width/2;
	brick.pad.y = yLine * height;
	
	return brick;

}
