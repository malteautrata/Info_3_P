/*
 * myServer.c
 *
 *  Created on: 27.11.2019
 *      Author: ubuntu
 */

#include <iostream>
#include <sstream>
#include <string>
#include "myServer.h"
#include "TASK3.H"

using namespace std;


string myServer::myResponse(string input) {
	stringstream ss;
	int x, y;
	TASK3::ShootResult result;

	if(input.compare(0,6, "COORD[") == 0) {
		if(2!=sscanf(input.c_str(), "COORD[%d, %d]", &x, &y)) {
			return string("RES[-1]");
		}

		if( (x<1) || (y<1)) {
			return string("RES[-2]");
		}

		cout << "shoot(" << x << "," << y << ")";
		result = myWorld->shoot(x,y);
		ss << "RES[" << result << "]";
		return ss.str();
	}

	if(input.compare(0,7,"NEWGAME") == 0)
	{
		delete myWorld;
		myWorld = new TASK3::World;
		myWorld->printBoard();
		return string("OK");
	}
	return "UNKNOWN COMMAND";
}



