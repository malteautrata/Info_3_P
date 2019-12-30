/*
 * myClient.H
 *
 *  Created on: 27.11.2019
 *      Author: ubuntu
 */

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h> //contains various constants
#include "SIMPLESOCKET.H"
#include <time.h>
#include <stdlib.h>

using namespace std;

int varianteA(TCPclient *ptrC);
int varianteB(TCPclient *ptrC);


int main() {
	srand(time(NULL));

	TCPclient c;
	string host = "localhost";
	string msg;
	string response;
	int avgCounter = 0;
	//connect to host
	c.conn(host , 2021);

	int stepsCount = 5;
	for (int i = 0; i < stepsCount; i++)
	{
		int steps = varianteA(&c);
		cout << "finished after " <<  steps << " moves" << endl;
		avgCounter += steps;
	}
	avgCounter = avgCounter/stepsCount;
	cout << "average Steps A:" << avgCounter << endl;

	avgCounter = 0;

	for (int i = 0; i < stepsCount; i++)
	{
			int steps = varianteB(&c);
			cout << "finished after " <<  steps << " moves" << endl;
			avgCounter += steps;
	}
	avgCounter = avgCounter/stepsCount;
	cout << "average Steps B:" << avgCounter << endl;

}

int varianteA(TCPclient *ptrC)
{
	ptrC->sendData("NEWGAME");
	string msg;
	string response;
	int x = 1;
	int y = 1;
	int c = 0;
	while (y <= 10 && response.compare(0,5,"RES[4") != 0)
	{
		while (x <= 10 && response.compare(0,5,"RES[4") != 0)
		{
			stringstream msgStream;
			msgStream << "COORD[" <<  x << ", "<< y <<"]" ;
			ptrC->sendData(msgStream.str());
			response = ptrC->receive(32);
			//cout << "shoot: " << "X: " << x << " " << "Y: " << y << endl;
			c++;
			x++;
		}
		y++;
		x = 1;
	}
	return c;
}

int varianteB(TCPclient *ptrC)
{
	//ptrC->sendData("NEWGAME");

	return 0;
}

