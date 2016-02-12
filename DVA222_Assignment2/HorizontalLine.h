#pragma once
#include "Obsticle.h"
#include "Ball.h"

class HorizontalLine : public Obsticle
{
public:
	HorizontalLine(int x, int y, int length);
	~HorizontalLine();

	bool CheckCollision(Ball &B);
	void CollisionAction(Ball &B);
	void Draw();
};

