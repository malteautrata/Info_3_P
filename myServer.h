/*
 * myServer.h
 *
 *  Created on: 27.11.2019
 *      Author: ubuntu
 */

#ifndef MYSERVER_H_
#define MYSERVER_H_
#include "SIMPLESOCKET.H"
#include "TASK3.H"

class myServer:public TCPserver {
public:

	myServer(int port, int maxDataSizeReciv):TCPserver(port, maxDataSizeReciv){
		myWorld = new TASK3::World;
	}

	string myResponse(string input);

private:
	TASK3::World *myWorld;
};



#endif /* MYSERVER_H_ */
