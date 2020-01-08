/*
 * myServer.h
 *
 *  Created on: 27.11.2019
 *      Author: ubuntu
 */

/**
 *
 * \file myServer.h
 *
 * \brief Contains Class myServer.
 *
 */

/**
 *
 * \class myServer
 *
 * \brief Implements a class that is a subclass of TCPserver
 *
 * Contains an own implementation of myResponse
 *
 */

#ifndef MYSERVER_H_
#define MYSERVER_H_
#include "SIMPLESOCKET.H"
#include "TASK3.H"

class myServer:public TCPserver {
public:

	/**
	 *
	 * \brief parameterized constructor
	 *
	 * calls the constructor of TCPserver
	 */
	myServer(int port, int maxDataSizeReciv):TCPserver(port, maxDataSizeReciv){

	}

	/**
	 *
	 * \brief Shoots the block and send back the status of the block
	 *
	 */
	string myResponse(string input);

private:
	TASK3::World *myWorld;
};



#endif /* MYSERVER_H_ */
