// DVA222_Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "Graphix.h"

#include "Ball.h"
#include "VerticalLine.h"
#include "HorizontalLine.h"
#include "SpeedUpBox.h"
#include "SpeedDownBox.h"
#include "Obsticle.h"

int ballCount = 20;
int obsticleCount = 13;

Ball **balls = new Ball*[ballCount];
Obsticle **obsticles = new Obsticle*[obsticleCount];

		 
int _tmain(int argc, char** argv)
{
	//NOTE:
	//----------------------------------------------------------------------
	//Create your objects in the global namespace
	//Initialize your object here, like what we do for the balls
	//----------------------------------------------------------------------
	srand(time(0));
	for(int i = 0; i < ballCount; i++)
	{
		balls[i] = new Ball(400, 300, 10);
		balls[i]->SetSpeed(Vector(10 * rand() / RAND_MAX -5 , 10 * rand() / RAND_MAX -5));
	}

	obsticles[0] = new SpeedUpBox(180, 180, 80, 80);
	obsticles[1] = new SpeedUpBox(650, 310, 50, 110);
	obsticles[2] = new SpeedDownBox(70, 480, 290, 50);
	obsticles[3] = new SpeedDownBox(520, 80, 80, 80);
	obsticles[4] = new VerticalLine(20, 90, 510);
	obsticles[5] = new VerticalLine(110, 80, 180);
	obsticles[6] = new VerticalLine(750, 40, 510);
	obsticles[7] = new HorizontalLine(70, 40, 240);
	obsticles[8] = new HorizontalLine(400, 40, 280);
	obsticles[9] = new HorizontalLine(130, 130, 230);
	obsticles[10] = new HorizontalLine(200, 420, 400);
	obsticles[11] = new HorizontalLine(500, 480, 230);
	obsticles[12] = new HorizontalLine(10, 580, 670);

	
	//NOTE:
	//----------------------------------------------------------------------
	//Below this line control of your main is passed to graphix library
	//Don't touch this line, Don't write anything after it
	//Simply just don't do anything after this point ==> . 
	//----------------------------------------------------------------------
    InitGraphix(argc, argv);
    return 0;
}


//NOTE:
//------------------------------------------------------------------------------
//This is the function which is called by the graphix library to draw the objects
//Write all your drawing code here and not in main. 
//If you want to ReDraw stuff, call the ReDraw function at the end.
////------------------------------------------------------------------------------
void Draw()
{
	SetColor(255, 255, 255);

	for (int i = 0; i < ballCount; i++)
	{
		balls[i]->Update();
		balls[i]->Draw();
		for (int j = 0;j < obsticleCount;j++)
		{
			obsticles[j]->CheckCollision(*balls[i]);
			obsticles[j]->Draw();
		}
	}

	Redraw();
}