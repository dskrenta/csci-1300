#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void fullPyramid(int num) {
  for (int i=0; i <= num - 1; i++) {
    for (int j=0; j <= num; j++) {
      if (j > num-i-1) {
        cout << i + 1 << " ";
      }
      else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void StarsAndDashes(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i % 2 == 0) {
        cout << "*";
      }
      else {
        cout << "-";
      }
    }
    cout << endl;
  }
}

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int countPrimes(int array[], int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (isPrime(array[i])) {
      count++;
    }
  }
  return count;
}

void findCompositeSum(int array[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (!isPrime(array[i])) {
      sum += array[i];
    }
  }
  cout << sum << endl;
}

int multiplicationOfArrays(int x[], int size1, int y[], int size2) {
  int total = 0;
  for (int i = 0; i < size1; i++) {
    for (int j = 0; j < size2; j++) {
      total += x[i] * y[j];
    }
  }
  return total;
}

int countCharacter(string array[], int size, char ch) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < array[i].length(); j++) {
      if (array[i][j] == ch) {
        count++;
      }
    }
  }
  return count;
}

int ParseScores(string filename, int array[], int size) {
  ifstream  file (filename);
  string line;
  int lines = 0;
  if (file.is_open()) {
    while (getline(file, line)) {
      string parsed[3];
      split(line, ',', parsed, 3);
      array[lines] = stoi(parsed[0]) + stoi(parsed[1]) + stoi(parsed[2]);
      lines++;
    }
    file.close();
    return lines;
  }
  else {
    return -1;
  }
}

int CalcCost(string inputFilename, string outputFilename) {
  ifstream inputFile (inputFilename);
  ofstream outputFile (outputFilename);
  string line;
  int lines = 0;
  if (inputFile.is_open() && outputFile.is_open()) {
    while (getline(inputFile, line)) {
      string parsed[3];
      split(line, ',', parsed, 3);
      outputFile << parsed[0] << ": " << stof(parsed[1]) * stof(parsed[2]) << "\n";
      lines++;
    }
    inputFile.close();
    outputFile.close();
    return lines;
  }
  else {
    return -1;
  }
}

int main() {
  return 0;
}
