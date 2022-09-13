#pragma once
#include "Functions.h"
#include "Structs.h"

void paddleBallLogic(Player player);
void brickBallLogic(Brick& brick);
void ballLogic();
void initGame();
void initPlay();
void wallCollision();
void floorCollision();
void gameLogic(GameStates& gameStates);
void drawGame();
