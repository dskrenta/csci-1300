// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 5
// main.cpp

#include <iostream>
#include "Assignment5.cpp"
using namespace std;

int main() {
  float array1[4] = {1.2, 1.3, 1.4, 1.5};
  int array2[4] = {1, 2, 3, 4};
  int array3[4] = {2, 3, 5, 7};

  cout << sumArray(array1, 4) << endl;
  cout << search(array2, 4, 3) << endl;
  cout << calculateDifference(array2, array3, 4) << endl;
  cout << findMedian(array1, 4) << endl;
}
