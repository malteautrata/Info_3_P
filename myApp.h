/*
 * myApp.h
 *
 *  Created on: 19.11.2019
 *      Author: ubuntu
 */

#ifndef MYAPP_H_
#define MYAPP_H_
#include "TASK3.H"

namespace std {

class myApp {
public:
	int xMax = 10;
	int yMax = 10;
	int fiver = 1;
	int fourer = 1;
	int threer = 1;
	int twoer = 1;

	TASK3::World myWorld = TASK3::World(xMax, yMax, fiver, fourer, threer, twoer);

	void varianteA(){
		int x = 0;
		int y = 0;
		myWorld.printBoard();
		while(y <= yMax)
		{
			while(x <= xMax)
			{
				myWorld.shoot(x, y);
				x++;
			}
			y++;
		}
		myWorld.printBoard();

	}

	void VarianteB()
	{

	}
};

} /* namespace std */
#endif /* MYAPP_H_ */

