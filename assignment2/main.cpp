#include <iostream>
using namespace std;

// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 2

/*
  Algorithm to calulate the US population in one year based on the current population
  Parameter: current population
  Returns the calculated population
*/

int howMany(int population) {
  int secondsPerYear = 31536000;
  population += secondsPerYear / 8;
  population -= secondsPerYear / 12;
  population += secondsPerYear / 33;
  return population;
}

/*
  Calculates days, hours, minutes, and seconds from seconds
  Parameter: seconds
  Prints result, returns nothing
*/

void howLong(int seconds) {
  if (seconds < 0) {
    seconds = 0;
  }
  int days = seconds / (24*60*60);
  seconds = seconds % (24*60*60);
  int hours = seconds / (60*60);
  seconds = seconds % (60*60);
  int minutes = seconds / 60;
  seconds = seconds % 60;
  cout << "Time is " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
}

/*
  Converts celsius to farenheight
  Parameter: Celsius number
  Returns final farenheight number
*/

int howHot(int celsius) {
  return (celsius * 1.8) + 32;
}

int main() {
  cout << howMany(1000000) << endl;
  howLong(70000);
  cout << howHot(20) << endl;
}
