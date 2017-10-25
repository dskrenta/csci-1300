#include "solarSystem.h"

#include <math.h>

solarSystem::solarSystem(string name) {
    systemName = name;
    numPlanets = 0;
}

solarSystem::~solarSystem() {
    // letting compiler handle deconstruction of the class
}

string solarSystem::findLargest() {
    float max = 0;
    int maxIndex = 0;
    for (int i = 0; i < 10; i++) {
        if (planetDiameters[i] > max) {
            maxIndex = i;
            max = planetDiameters[i];
        }
    }
    return planetNames[maxIndex];
}

string solarSystem::getName() {
    return systemName;
}

float solarSystem::getDiameter() {
    float max = 0;
    for (int i = 0; i < 10; i++) {
        if (planetOrbitDist[i] > max) {
            max = planetOrbitDist[i];
        }
    }
    return max * 2;
}

int solarSystem::getNumPlanets() {
    return numPlanets;
}

bool solarSystem::addPlanet(string planetName, float planetDiameter, float planetDist) {
    planetNames[numPlanets] = planetName;
    planetDiameters[numPlanets] = planetDiameter;
    planetOrbitDist[numPlanets] = planetDist;
    numPlanets++;
}
