// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 5
// Assignment5.cpp

#include <iostream>
#include <cmath>
using namespace std;

/*
  Sums all elements in array
  Parameters: array, array length
  Returns: sum
*/

float sumArray(float array[], int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

/*
  Seaches array for index with target value
  Parameters: array, array length, target value
  Returns: index of target value in array or -1 if not found
*/

int search(int array[], int size, int target) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      index = i;
      break;
    }
  }
  return index;
}

/*
  Calculates the summed difference of squares for two arrays
  Parameters: first array, second array, array length
  Returns: summed difference of squares
*/

float calculateDifference(int a[], int b[], int size) {
  float difference = 0;
  for (int i = 0; i < size; i++) {
    difference += pow((a[i] - b[i]), 2);
  }
  return difference;
}

/*
  Sorts an array using the bubble sort algorithm
  Parameters: array, array length
*/

void sortArray(float unsortedArray[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (unsortedArray[j] > unsortedArray[j + 1]) {
        float temp = unsortedArray[j];
        unsortedArray[j] = unsortedArray[j + 1];
        unsortedArray[j + 1] = temp;
      }
    }
  }
}

/*
  Copies a source array to a destination array
  Parameters: source array, array length, destination array
*/

void copyArray(float source[], int size, float dest[]) {
  for (int i = 0; i < size; i++) {
    dest[i] = source[i];
  }
}

/*
  Converts an array of ratings to the rating text
  Parameters: rating array, text array, array length
*/

void convert(int rating[], string text[], int size) {
  for (int i = 0; i < size; i++) {
    if (rating[i] == 0) {
      text[i] = "Not-read";
    }
    else if (rating[i] == -5) {
      text[i] = "Terrible";
    }
    else if (rating[i] == -3) {
      text[i] = "Disliked";
    }
    else if (rating[i] == 1) {
      text[i] = "Average";
    }
    else if (rating[i] == 3) {
      text[i] = "Good";
    }
    else if (rating[i] == 5) {
      text[i] = "Excellent";
    }
    else {
      text[i] = "INVALID";
    }
  }
}

/*
  Finds the median in an array
  Parameters: array, array length
  Returns: median value
*/

float findMedian(float array[], int size) {
  float median = 0;
  float arrayCopy[size];
  copyArray(array, size, arrayCopy);
  sortArray(arrayCopy, size);
  if (size % 2) {
    median = arrayCopy[(size / 2)];
  }
  else {
    median = (arrayCopy[size / 2] + arrayCopy[(size / 2) - 1]) / 2;
  }
  return median;
}

/*
  Calculates a new 2D array given an existing 2D array and a multiplier
  Parameters: multiplier, 2D array of length 10 x 10
*/

void simple2DMultiplication(int multiplier, int matrix[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = matrix[i][j] * multiplier;
    }
  }
}
