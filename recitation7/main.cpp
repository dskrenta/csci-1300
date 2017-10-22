#include <iostream>
#include <string>
using namespace std;

int Split(string str, char delimiter, string words[], int size) {
  size_t pos = 0;
  int index = 0;
  while ((pos = str.find(delimiter)) != string::npos) {
    words[index] = str.substr(0, pos);
    str.erase(0, pos + 1);
    index++;
  }
  words[index] = str;
  return str.length() > 0 ? index + 1 : 0;
}

int SplitString(string str, string delimiter, string words[], int size) {
  size_t pos = 0;
  int index = 0;
  while ((pos = str.find(delimiter)) != string::npos) {
    words[index] = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
    index++;
  }
  words[index] = str;
  return str.length() > 0 ? index + 1 : 0;
}

int GetTimes(string str, int values[], int max_values) {
  int numTimes = 0;
  string times[max_values];
  SplitString(str, " ", times, max_values);
  for (int i = 0; i < max_values; i++) {
      string parsed[2];
      SplitString(times[i], ":", parsed, 2);
      if (parsed[0].length() == 0 && parsed[1].length() == 0) break;
      values[i] = (stoi(parsed[0]) * 60) + stoi(parsed[1]);
      numTimes++;
  }
  return numTimes;
}

void parseMatrix(string strArray[], int size, int matrix[][3], int maxRows) {
    for (int i = 0; i < size; i++) {
        string tempArray[3];
        SplitString(strArray[i], "-", tempArray, 3);
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = stoi(tempArray[j]);
        }
    }
}

int main() {
  /*
  string testcase = "ABCD,EFG";
  char separator = ' ';
  string my_array[1];
  int tc5 = Split(testcase, separator, my_array, sizeof(my_array)/sizeof(string));
  for (int i=0 ; i < 10 && i < tc5 ; i++)
     cout << my_array[i] << endl;
  cout << "Function returned value: " << tc5 << endl;
  */

  int values[3];

  GetTimes("12:13 42:35 23:23", values, 3);

  for (int i = 0; i < 3; i++) {
    cout << values[i] << endl;
  }
}
