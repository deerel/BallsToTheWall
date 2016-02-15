#include "SpeedUpBox.h"

#define SPEEDADD 1.05

SpeedUpBox::SpeedUpBox(int x, int y, int width, int height)
{
	position.X = x;
	position.Y = y;
	endPosition.X = x+width;
	endPosition.Y = y+height;
}


SpeedUpBox::~SpeedUpBox()
{
}

void SpeedUpBox::CollisionAction(Ball & B)
{
	Vector ballSpeed = B.GetSpeed();
	ballSpeed.X *= SPEEDADD;
	ballSpeed.Y *= SPEEDADD;
	B.SetSpeed(ballSpeed);
}

void SpeedUpBox::Draw()
{
	SetColor(255, 0, 0);
	Box::Draw();
}
