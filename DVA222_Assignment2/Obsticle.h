#pragma once
#include "Shape.h"
#include "Graphix.h"

class Ball;

class Obsticle : public Shape
{
protected:
	Point endPosition;
public:
	Obsticle();
	~Obsticle();
	virtual bool CheckCollision(Ball &B) = 0;
	virtual void Draw() = 0;
	virtual void CollisionAction(Ball &B) = 0;
};

