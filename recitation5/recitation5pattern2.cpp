// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Recitation 5
// recitation5pattern2.cpp

#include <iostream>
using namespace std;

int main() {
  int rows;
  cout << "Enter number of rows: ";
  cin >> rows;

  for (int row = rows; row > 0; row--) {
    for (int asteriks = row; asteriks > 0; asteriks--) {
      cout << "* ";
    }
    cout << endl;
  }

}
