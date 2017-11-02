#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>
using namespace std;

class planet {
	public:
        planet();
        planet(string, float);
		~planet();

        void setName(string planetName);
        string getName();
        void setRadius(float planetRadius);
        float getRadius();

	private:
        string name;
        float radius;
};
#endif // PLANET_H
