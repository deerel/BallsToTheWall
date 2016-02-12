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
	{
		if (position.Y < (ballPosition.Y + ballRadius) && position.Y >(ballPosition.Y - ballRadius))
		{
			CollisionAction(B);
			return true;
		}
	}

	// This code does not exist..

	//I told you! Nothing here!
	// Checks if ball width extremely high speed collides.
	if (position.X < (ballPosition.X + ballRadius) && endPosition.X >(ballPosition.X - ballRadius))
	{
		if ( ( position.Y > (ballPosition.Y + ballRadius) && position.Y > (ballPosition.Y - ballRadius) &&
			position.Y < (ballPosition.Y + ballRadius + B.GetSpeed().Y) && position.Y < (ballPosition.Y - ballRadius + B.GetSpeed().Y) ) ||
			(position.Y < (ballPosition.Y + ballRadius) && position.Y < (ballPosition.Y - ballRadius) &&
			position.Y > (ballPosition.Y + ballRadius + B.GetSpeed().Y) && position.Y > (ballPosition.Y - ballRadius + B.GetSpeed().Y)))
		{
			CollisionAction(B);
			return true;
		}
	}

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
	DrawLine(position.X, position.Y, endPosition.X, endPosition.Y);
}
