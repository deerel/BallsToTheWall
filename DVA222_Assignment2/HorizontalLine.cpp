#include "HorizontalLine.h"

HorizontalLine::HorizontalLine(int x, int y, int length)
{
	position.X = x;
	position.Y = y;
	endPosition.X = x+length;
	endPosition.Y = y;
}

HorizontalLine::~HorizontalLine()
{
}

bool HorizontalLine::CheckCollision(Ball & B)
{
	Point ballPosition = B.GetPosition();
	double ballRadius = B.GetRadius();

	if (position.X < (ballPosition.X + ballRadius) && endPosition.X >(ballPosition.X - ballRadius))
		if (position.Y < (ballPosition.Y + ballRadius) && position.Y >(ballPosition.Y - ballRadius))
			return true;

	return false;
}

void HorizontalLine::CollisionAction(Ball & B)
{
	Vector ballSpeed = B.GetSpeed();
	ballSpeed.Y *= -1;
	B.SetSpeed(ballSpeed);
}

void HorizontalLine::Draw()
{
	SetColor(0, 255, 0);
	Line::Draw();
}
