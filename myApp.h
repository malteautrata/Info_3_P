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
	int xMax = 10;
	int yMax = 10;
	int fiver = 1;
	int fourer = 2;
	int threer = 5;
	int twoer = 6;
	TASK3::World myWorld = TASK3::World(xMax, yMax, fiver, fourer, threer, twoer);

	void varianteA();
	virtual void VarianteB() = 0;
};

} /* namespace std */
#endif /* MYAPP_H_ */

