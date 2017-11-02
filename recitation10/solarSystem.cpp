// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Recitation 10
// solarSystem.cpp

#include "planet.h"
#include "solarSystem.h"
#include "math.h"

solarSystem::solarSystem(string name) {
    systemName = name;
}

solarSystem::~solarSystem() {
    // letting compiler handle deconstruction of this class
}

string solarSystem::getName() {
    return systemName;
}

int solarSystem::getNumPlanets() {
    return numPlanets;
}

bool solarSystem::addPlanet(string name, float radius) {
    for (int i = 0; i < numPlanets; i++) {
        if (systemPlanets[i].getName() == name) {
            return false;
        }
    }
    systemPlanets[numPlanets] = planet(name, radius);
    numPlanets++;
    return true;
}

planet solarSystem::getPlanet(int planetNum) {
    return systemPlanets[planetNum];
}

float solarSystem::radiusDifference(planet planet1, planet planet2) {
    return fabs(planet1.getRadius() - planet2.getRadius());
}
