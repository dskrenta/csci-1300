// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Recitation 5
// recitation5pattern.cpp

#include <iostream>
using namespace std;

int main() {
  int rows;
  cout << "Enter number of rows: ";
  cin >> rows;

  for (int row = 0; row < rows; row++) {
    for (int asteriks = 0; asteriks < row; asteriks++) {
      cout << "* ";
    }
    cout << endl;
  }
}
