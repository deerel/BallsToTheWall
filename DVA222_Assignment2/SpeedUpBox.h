#pragma once
#include "Box.h"

class SpeedUpBox : public Box
{
public:
	SpeedUpBox(int x, int y, int width, int height);
	~SpeedUpBox();

	void CollisionAction(Ball &B);
	void Draw();
};

