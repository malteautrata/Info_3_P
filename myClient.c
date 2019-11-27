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


using namespace std;

int varianteA(TCPclient *ptrC);

int main() {
	srand(time(NULL));

	TCPclient c;
	string host = "localhost";
	string msg;
	string response;

	//connect to host
	c.conn(host , 2021);
	cout << "finish after " <<  varianteA(&c) << " moves" << endl;
}

int varianteA(TCPclient *ptrC)
{
	string msg;
	string response;
	int x = 0;
	int y = 0;
	int c = 0;
	while (y < 10)
	{
		while (x < 10)
		{
			stringstream msgStream;
			msgStream << "COORD[" <<  x << ", "<< y <<"]" ;
			ptrC->sendData(msgStream.str());
			response = ptrC->receive(32);

			c++;
			x++;
			if(response.compare(0,1,"4") == 0){
				return c;
			}
		}
		y++;
		x = 0;
	}
	return c;
}

void varianteB()
{

}

