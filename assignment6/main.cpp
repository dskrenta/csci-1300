#include <iostream>
#include <string>
#include "Assignment6.cpp"
using namespace std;

int main() {
  // split test
  string array1[2];
  split("hello,world", ",", array1, 2);
  cout << array1[0] << " " << array1[1] << endl;

  cout << endl;

  // search test
  cout << search(array1, 2, "world") << endl;
  cout << search(array1, 2, "blah") << endl;

  cout << endl;

  // avgCharsPerLine test
  cout << avgCharsPerLine("part3.txt") << endl;

  cout << endl;

  // fillArray test
  float array2[3][5];
  cout << fillArray("part2.txt", array2) << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << array2[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  // arrayStats test
  float array3[5][5];
  cout << arrayStats("part3.txt", array3) << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << array3[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  // addBookRatings test
  string users[100];
  int ratings[100][50];
  addBookRatings("part4.txt", users, ratings);
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      cout << ratings[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < 15; i++) {
    cout << users[i] << endl;
  }
}
