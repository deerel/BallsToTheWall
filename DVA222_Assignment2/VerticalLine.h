#pragma once
#include "Obsticle.h"
#include "Ball.h"

class VerticalLine : public Obsticle
{
public:
	VerticalLine(int x, int y, int length);
	~VerticalLine();
	bool CheckCollision(Ball &B);
	void CollisionAction(Ball &B);
	void Draw();
};

