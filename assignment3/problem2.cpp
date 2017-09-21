#include <iostream>
#include <cmath>
using namespace std;

// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 3

/*
  Calculates the wind chill for a airtemperature and a wind velocity
  Parameters: airtemperature, wind velocity
  Returns the calculated wind chill
*/

float windChillCalculator(float t, float v) {
  return 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
}

/*
  Prints the wind chill for a range of wind speeds
  Parameters: airtemperature, low wind speed, high wind speed, wind speed step
*/

void printWindChill(float t, float lowWindSpeed, float highWindSpeed, float windSpeedStep) {
  for(float i = lowWindSpeed; i <= highWindSpeed; i += windSpeedStep) {
    cout << "The wind chill is " << windChillCalculator(t, i) << " degrees F for an airtemperature of " << t << " degrees F and a wind speed of " << i << " mph." << endl;
  }
}

int main() {
  cout << "The wind chill is " << windChillCalculator(30.0, 5.0) << " degrees F." << endl;
  printWindChill(30.0, 5.0, 8.0, 1.0);
}
