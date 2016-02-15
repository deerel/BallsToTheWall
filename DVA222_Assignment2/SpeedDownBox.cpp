#include "SpeedDownBox.h"

#define SPEEDADD 0.99

SpeedDownBox::SpeedDownBox(int x, int y, int width, int height)
{
	position.X = x;
	position.Y = y;
	endPosition.X = x + width;
	endPosition.Y = y + height;
}


SpeedDownBox::~SpeedDownBox()
{
}


void SpeedDownBox::CollisionAction(Ball & B)
{
	Vector ballSpeed = B.GetSpeed();
	ballSpeed.X *= SPEEDADD;
	ballSpeed.Y *= SPEEDADD;
	B.SetSpeed(ballSpeed);
}

void SpeedDownBox::Draw()
{
	SetColor(0, 0, 255);
	Box::Draw();
}
