#pragma once
#include "Line.h"
#include "Ball.h"

class VerticalLine : public Line
{
public:
	VerticalLine(int x, int y, int length);
	~VerticalLine();
	bool CheckCollision(Ball &B);
	void CollisionAction(Ball &B);
	void Draw();
};

