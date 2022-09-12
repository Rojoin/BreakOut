#pragma once
#include "Functions.h"
#include "Structs.h"

void paddleBallLogic(Player player);
void brickBallLogic(Brick& brick);
void ballLogic();
void blockCheck();
void initBrick();
void blockCollision();
void wallCollision();
void floorCollision();
void gameLogic();
void drawGame();
