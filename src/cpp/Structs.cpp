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
	int yLine = 32 - y;
	Brick brick;
	brick.pad.width = width;
	brick.pad.height = height;
	brick.enabled = true;
	brick.score = 100;
	brick.pad.x = (x *  width)+ width/2;
	brick.pad.y = yLine * height;
	
	return brick;

}


Button createButton(float x, float y, int width, int height, std::string buttonTitle, Color color)
{
	Button button;
	button.isOver = false;
	button.rec ={ x,y, width, height };
	button.buttonTittle = buttonTitle;
	button.color = color;
	return button;
}
