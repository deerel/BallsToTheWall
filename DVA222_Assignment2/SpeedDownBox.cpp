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

bool SpeedDownBox::CheckCollision(Ball & B)
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
	DrawRectanle(position.X, position.Y, endPosition.X - position.X, endPosition.Y - position.Y);
}
