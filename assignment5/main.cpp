// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 5
// main.cpp

#include <iostream>
#include <string>
#include "Assignment5.cpp"
using namespace std;

int main() {
  float array1[4] = {1.2, 1.3, 1.4, 1.5};
  int array2[4] = {1, 2, 3, 4};
  int array3[4] = {2, 3, 5, 7};
  float array4[5] = {1, 2, 3, 4, 5};
  int rating[3] = {1, 2, -3};
  string text[3];

  int sampleMatrix[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  };

  cout << sumArray(array1, 4) << endl;
  cout << search(array2, 4, 3) << endl;
  cout << calculateDifference(array2, array3, 4) << endl;
  cout << findMedian(array4, 5) << endl;
  convert(rating, text, 3);
  simple2DMultiplication(2, sampleMatrix);

  for (int i = 0; i < 3; i++) {
    cout << text[i] << " ";
  }

  cout << endl;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << sampleMatrix[i][j] << " ";
    }
    cout << endl;
  }
}
