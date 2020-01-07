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
		sleep(1);
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
	stringstream msgStream;
	string response = "";
	msgStream << "NEWGAME";

	ptrC->sendData(msgStream.str());
	msgStream.str("");

	int x = 1;
	int y = 1;
	int c = 0;

	while (y <= 10)
	{
		while (x <= 10)
		{
			msgStream << "COORD[" <<  x << ", "<< y <<"]" ;
			ptrC->sendData(msgStream.str());
			msgStream.str("");
			response = ptrC->receive(32);
			c++;
			x++;

			if (response.compare(0,5,"RES[4") == 0)
			{
				return c;
			}
		}
		y++;
		x = 1;
	}
	return c;
}

int varianteB(TCPclient *ptrC)
{

	return 0;
}

