#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

class planet {
	public:
		planet(string, float, float);
		planet();
		~planet();

		void setName(string);
		string getName();

		void setRadius(float);
		float getDiameter();

		void setDist(float);
		float getDist();

		float getOrbitPeriod();

	private:
		string name;
		float radius;
	 	float distance;
};
#endif // PLANET_H
