// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Recitation 10
// SolarSystem_main.cpp

#include <iostream>
#include "planet.h"
#include "solarSystem.h"
#include <math.h>

using namespace std;


/*
    This function implements the logic to find the difference between the radius
    of all the planets in the system.

    Notes:
        * having more or less outputs means that your logic is not quite correct.
        * do not hard code the cout statements; use a smart logic instead.
        * use fabs() to compute the absolute value of the difference (do it either in your impementation of
          radiusDifference(planet,planet) or use it after you return the function call to radiusDifference(planet,planet)
        * your output should have the following structure:
            cout<<"Radius difference between planet " <<  <<" and planet "<< <<
                    " is => "<< <<endl;
        * for 5 planets you should have 10 outputs.

*/
void compareRadii(solarSystem mySolarSystem, int num_of_planets) {
        // Logic for 2 goes here
        for (int i = 0; i < num_of_planets; i++) {
            for (int j = i + 1; j < num_of_planets; j++) {
                planet planet1 = mySolarSystem.getPlanet(i);
                planet planet2 = mySolarSystem.getPlanet(j);
                cout << "Radius difference between planet " << planet1.getName() << " and planet "
                << planet2.getName() << " is => " << mySolarSystem.radiusDifference(planet1, planet2) << endl;
            }
        }
}


int main(){

    /* 1) Ask the user to create a solar system by promting him for 5 instances
     of type Planet. You will ask the user for name and radius of each
     Planet. Each object will have to have a unique name.

     Notes and hints:
        * you can use getline() to make the process faster
        * if you use getline use a smart delimeter to process name and radius in one user input
        * make sure to check if name already exists. If it does, ask the user to enter another name.
     */

    int i;
    int j = 5;
    bool unique;
    string name;
    string radius;
    solarSystem testSystem ("test solar system");

    // Logic for 1 goes here

    for (i = 0; i < j; i++) {
        cout << "Enter the (name, radius) for the next planet:" << endl;
        getline(cin, name, ',');
        getline(cin, radius);
        unique = testSystem.addPlanet(name, stof(radius));
        if (!unique) {
            cout << "Name already exists, please try again" << endl;
            j++;
        }
        else {
            cout << "Added new planet: (name: " << name << ", radius: " << radius << ")" << endl;
        }
    }

    // Use the following snipped of code to test that you filled your system correctly
    // !!NOTE: here "<obj_of_type_solarSystem>" is a placeholder you should use the name
    //  of your solarSystem instance created (hopefully) above.

    i = 0;
    int num_of_planets = testSystem.getNumPlanets();

    if (num_of_planets < 5) {

        cout << "Your system has less than 5 planets!" << endl;
    }

    while (i < num_of_planets) {
        cout << "This is planet " << i << " with name: " << testSystem.getPlanet(i).getName() <<
        " and radius: "<< testSystem.getPlanet(i).getRadius() << endl;
        i++;
    }

    /* 2) Add the method radiusDifference(...) to the SolarSytem class. This method
     takes two objects of type Planet and returns the difference of their
     radius. Develop a logic to return the difference among all the planets in a
     function called compareRadii(...) that takes two params, a solarSystem and the
     number of planets in the system. You can find the function definition above
     the main. Once you are done implementing it call it.

     */


    // !!NOTE: here "<obj_of_type_solarSystem>" and "<num_of_planets> are placeholders
    // you should use the name of your solarSystem instance created (hopefully) above
    // and the number of planets currently in the solarSystem

    compareRadii(testSystem, 5);

    return 0;
}
