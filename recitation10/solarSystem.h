// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Recitation 10
// solarSystem.h

#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <iostream>
#include "planet.h"
using namespace std;

class solarSystem{
	public:
		solarSystem(string);
		~solarSystem();

		string getName();			// return the name of the solar system
		int getNumPlanets();		// return the number of planets in the system
		bool addPlanet(string, float);	//Adds a single planet to solar system
        planet getPlanet(int);  	// return an object of planet at provided index
		float radiusDifference(planet, planet);

	private:
		int maxNumPlanets = 10;
		string systemName;
		int numPlanets = 0;
		planet systemPlanets[10]; // array of object planet, each obj is a planet

};
#endif // SOLAR_SYSTEM_H
