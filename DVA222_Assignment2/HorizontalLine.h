#pragma once
#include "Line.h"
#include "Ball.h"

class HorizontalLine : public Line
{
public:
	HorizontalLine(int x, int y, int length);
	~HorizontalLine();
	void CollisionAction(Ball &B);
	bool CheckCollision(Ball &B);
	void Draw();
};

