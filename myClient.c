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

int stepByStep(TCPclient *ptrC);
int random(TCPclient *ptrC);
void startNewGame(TCPclient *ptrC);

stringstream msgStream;
string response = "";

int main() {
	srand(time(NULL));

	TCPclient c;
	string host = "localhost";
	int avgCounterA = 0;
	int avgCounterB = 0;

	//connect to host
	c.conn(host , 2021);

	int stepsCount = 100;

	for (int i = 0; i < stepsCount; i++)
	{
		int steps = stepByStep(&c);
		cout << "finished after " <<  steps << " moves" << endl;
		avgCounterA += steps;
		sleep(0.1);
	}
	avgCounterA = avgCounterA/stepsCount;


	for (int i = 0; i < stepsCount; i++)
	{
			int steps = random(&c);
			cout << "finished after " <<  steps << " moves" << endl;
			avgCounterB += steps;
			sleep(0.1);
	}
	avgCounterB = avgCounterB/stepsCount;

	cout << endl;
	cout << "average Steps Step by Step:" << avgCounterA << endl;
	cout << "average Steps Random:" << avgCounterB << endl;

}

int stepByStep(TCPclient *ptrC)
{
	startNewGame(ptrC);
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

int random(TCPclient *ptrC)
{
	startNewGame(ptrC);
	/*
	int c = 0;
	int x [10];
	int y [10];

	for(int i = 0; i < 100; i++)
	{
		x[i] = i;
		y[i] = i;
	}
*/
	int c = 0;

	while (response.compare(0,5,"RES[4") != 0)
	{
		c++;
		int x = (rand() % 10)+1;


		int y = (rand() % 10)+1;

		msgStream << "COORD[" <<  x << ", "<< y <<"]" ;
		ptrC->sendData(msgStream.str());
		msgStream.str("");
		response = ptrC->receive(32);
	}
	return c;
}

void startNewGame(TCPclient *ptrC)
{
	msgStream << "NEWGAME";
	response = "";
	ptrC->sendData(msgStream.str());
	msgStream.str("");
	response = ptrC->receive(32);
}
