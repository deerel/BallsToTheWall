#pragma once
#include "Obsticle.h"
#include "Ball.h"

class SpeedDownBox : public Obsticle
{
public:
	SpeedDownBox(int x, int y, int width, int height);
	~SpeedDownBox();

	bool CheckCollision(Ball &B);
	void CollisionAction(Ball &B);
	void Draw();
};

