// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 6
// Assignment6.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
  Splits string into array based on delimiter
  Parameters: string, delimeter, array, size
*/

void split(string str, string delimiter, string array[], int size) {
  size_t pos = 0;
  int index = 0;
  while ((pos = str.find(delimiter)) != string::npos) {
    array[index] = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
    index++;
  }
  array[index] = str;
}

/*
  Searches array for target value
  Parameters: array, size, target value
  Returns: index of target value or -1 if not found
*/

int search(string array[], int size, string value) {
  for (int i = 0; i < size; i++) {
    if (array[i] == value) {
      return i;
    }
  }
  return -1;
}

/*
  Calculates the average number of characters per line from a input file
  Parameters: filename
  Returns: avgerage characters per line
*/

float avgCharsPerLine(string filename) {
  string line;
  ifstream file (filename.c_str());
  float lines = 0;
  float sum = 0;
  if (file.is_open()) {
    while (getline(file, line)) {
      sum += line.length();
      lines++;
    }
    file.close();
  }
  return sum / lines;
}

/*
  Reads a file and inserts the values separated by commmas into a 2D array
  Parameters: filename, 2D array
  Returns: sum
*/

int fillArray(string filename, float array[][5]) {
  int index = 0;
  string line;
  ifstream file (filename.c_str());
  if (file.is_open()) {
    while (getline(file, line)) {
      if (index > 0) {
        string tempArray[5];
        split(line, ",", tempArray, 5);
        for (int i = 0; i < 5; i++) {
          array[index - 1][i] = stof(tempArray[i]);
        }
      }
      index++;
    }
    file.close();
  }
  return index - 1;
}

/*
  Caclulates the summed mean for each of the odd columns and rows
  Parameters: filename, array
  Returns: the summed mean
*/

float arrayStats(string filename, float numbers[][5]) {
  int lines = fillArray(filename, numbers);
  float rowSum, colSum = 0;
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < 5; j++) {
      if (j % 2 != 0) {
        colSum += numbers[i][j];
      }
      if (i % 2 != 0) {
        rowSum += numbers[i][j];
      }
    }
  }
  rowSum /= (float)lines;
  colSum /= 5;
  cout << lines << endl;
  return rowSum + colSum;
}

/*
  Parses a file with book ratings, parses users from file, inserts users, book id, and rating into provided 2D array
  Parameters: filename, users array, ratings array
*/

void addBookRatings(string filename, string users[], int ratings[][50]) {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 50; j++) {
      ratings[i][j] = 0;
    }
  }

  int usersIndex = 0;
  string line;
  int lines = 0;
  ifstream file (filename);
  if (file.is_open()) {
    while (getline(file, line)) {
      if (lines > 0) {
        string tempArray[3];
        split(line, ",", tempArray, 3);
        int index = search(users, 100, tempArray[0]);
        int bookId = stoi(tempArray[1]);
        int rating = stoi(tempArray[2]);
        if (index == -1) {
          users[usersIndex] = tempArray[0];
          ratings[usersIndex][bookId] = rating;
          usersIndex++;
        }
        else {
          ratings[index][bookId] = rating;
        }
      }
      lines++;
    }
  }
}
