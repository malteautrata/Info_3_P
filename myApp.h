/*
 * myApp.h
 *
 *  Created on: 19.11.2019
 *      Author: ubuntu
 */

#ifndef MYAPP_H_
#define MYAPP_H_
#include "TASK3.H"

/**
 *
 * \namespace std
 *
 * \brief Namesapce für Lösungen des Praktikums
 *
 */
namespace std {

/**
 *
 * \class myApp
 *
 * \brief Zwei unterschiedliche Algorithmen um alle Schiffe zu versenken
 */
class myApp {
public:

	//Festlegung der Parameter für die zu erzeugende Welt

	// Länge des Spielfeldes
	int xMax = 10;

	//Höhe des Spielfeldes
	int yMax = 10;

	// Anzhal der fünfer Schiffe
	int fiver = 1;

	// Anzahl der vierer Schiffe
	int fourer = 1;

	// Anzhal der dreier Schiffe
	int threer = 1;

	// Anzahl der zweier Schiffe
	int twoer = 1;


	// Erzeugung eines Objektes der Klasse World aus Task 3
	TASK3::World myWorld = TASK3::World(xMax, yMax, fiver, fourer, threer, twoer);


	// Erster Algorithmus um alle Schiffe zu versenken, bei dem jedes Feld nacheinander beschossen wird
	void varianteA(){
		int x = 0;
		int y = 0;
		myWorld.printBoard();

		cout << endl;

		while(y <= yMax)
		{
			while(x <= xMax)
			{
				myWorld.shoot(x, y);
				x++;
			}
			x = 0;
			y++;
		}

		cout << "alle Schiffe versenkt:" << endl;
		myWorld.printBoard();
	}

	// Zweiter Algorithmus um alle Schiffe zu versenken
	void VarianteB()
	{

	}
};

} /* namespace std */
#endif /* MYAPP_H_ */

