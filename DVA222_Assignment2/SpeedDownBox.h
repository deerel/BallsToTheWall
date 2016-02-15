#pragma once
#include "Box.h"

class SpeedDownBox : public Box
{
public:
	SpeedDownBox(int x, int y, int width, int height);
	~SpeedDownBox();

	void CollisionAction(Ball &B);
	void Draw();
};

