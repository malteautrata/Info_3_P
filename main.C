//============================================================================
// Name        : INF3_Prak.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <string>
#include <iostream>

#include <cstdio>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

#include "SHA256.H"
#include "TASK1.H"
#include "TASK2.H"
#include "TASK3.H"
#include "TASK4.H"
#include "TASK5.H"
#include "TASK6.H"
#include "myApp.h"

using namespace std;


int main(){
	srand(time(nullptr));

	// Erzeugung eines Objektes der Klasse myApp
	TASK5::demoOB01();

	// Aufrufen des ersten Algorithmus um alle Schiffe zu versenken
	//variante1.demo0B00();
}





