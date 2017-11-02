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
    return systemPlanets[planetNum - 1];
}

float solarSystem::radiusDifference(planet planet1, planet planet2) {
    return fabs(planet1.getRadius()) - fabs(planet2.getRadius());
}
