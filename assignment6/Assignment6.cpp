#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

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

int search(string array[], int size, string value) {
  for (int i = 0; i < size; i++) {
    if (array[i] == value) {
      return i;
    }
  }
  return -1;
}

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
  return index;
}

float arrayStats(string filename, float numbers[][5]) {
  fillArray(filename, numbers);
  float sumRow1, sumRow3, sumCol1, sumCol3 = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == 1) {
        sumRow1 += numbers[i][j];
      }
      else if (i == 3) {
        sumRow3 += numbers[i][j];
      }
      if (j == 1) {
        sumCol1 += numbers[i][j];
      }
      else if (j == 3) {
        sumCol3 += numbers[i][j];
      }
    }
  }
  sumRow1 /= 5;
  sumRow3 /= 5;
  sumCol1 /= 5;
  sumCol3 /= 5;
  return sumRow1 + sumRow3 + sumCol1 + sumCol3;
}

void addBookRatings(string filename, string users[], int ratings[][50]) {
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
          ratings[usersIndex][bookId] = rating;
        }
      }
      lines++;
    }
  }
}
