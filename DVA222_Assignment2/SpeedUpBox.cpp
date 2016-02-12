#include "SpeedUpBox.h"

#define SPEEDADD 1.25

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

bool SpeedUpBox::CheckCollision(Ball & B)
{

	Point ballPosition = B.GetPosition();
	double ballRadius = B.GetRadius();

	if (position.X < (ballPosition.X + ballRadius) && endPosition.X >(ballPosition.X - ballRadius))
	{
		if (position.Y < (ballPosition.Y + ballRadius) && endPosition.Y >(ballPosition.Y - ballRadius))
		{
			CollisionAction(B);
			return true;
		}
	}


	return false;
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
	DrawRectanle(position.X, position.Y, endPosition.X - position.X, endPosition.Y - position.Y);

}
