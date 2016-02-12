#pragma once
#include "Obsticle.h"
#include "Ball.h"

class SpeedUpBox : public Obsticle
{
public:
	SpeedUpBox(int x, int y, int width, int height);
	~SpeedUpBox();

	bool CheckCollision(Ball &B);
	void CollisionAction(Ball &B);
	void Draw();
};

