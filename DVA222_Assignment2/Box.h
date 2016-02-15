#pragma once
#include "Obsticle.h"
#include "Ball.h"

class Box :
	public Obsticle
{
public:
	Box();
	~Box();
	bool CheckCollision(Ball &B);
	virtual void Draw();
};

