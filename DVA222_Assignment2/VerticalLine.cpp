#include "VerticalLine.h"

VerticalLine::VerticalLine(int x, int y, int length)
{
	position.X = x;
	position.Y = y;
	endPosition.X = x;
	endPosition.Y = y+length;
}


VerticalLine::~VerticalLine()
{
}

bool VerticalLine::CheckCollision(Ball & B)
{
	Point ballPosition = B.GetPosition();
	double ballRadius = B.GetRadius();

	if (position.X < (ballPosition.X + ballRadius) && position.X >(ballPosition.X - ballRadius))
		if(position.Y < (ballPosition.Y + ballRadius) && endPosition.Y > (ballPosition.Y - ballRadius))
			return true;

	return false;
}

void VerticalLine::CollisionAction(Ball & B)
{
	Vector ballSpeed = B.GetSpeed();
	ballSpeed.X *= -1;
	B.SetSpeed(ballSpeed);
}

void VerticalLine::Draw()
{
	SetColor(255, 255, 0);
	Line::Draw();
}
