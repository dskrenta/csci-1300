#include <iostream>
#include <string>
using namespace std;

int Split(string str, char delimeter, string words[], int size) {
    size_t pos = 0;
    int index = 0;
    while ((pos = str.find(delimeter)) != string::npos) {
        words[index] = str.substr(0, pos);
        str.erase(0, pos + 1);
        index++;
    }
    if (str.length() > 0 && index < size) {
        if (index < size) index++;
        words[index] = str;
    }
    return index;
}

int main() {
  string testcase = "ABCD EFG";
  char separator = ' ';
  string my_array[2];
  int tc4 = Split(testcase, separator, my_array, sizeof(my_array)/sizeof(string));
  for (int i=0 ; i < 10 && i < tc4 ; i++) {
   cout << my_array[i] << endl;
  }
  cout << "Function returned value: " << tc4 << endl;
}


int GetAmounts(string str, float values[], int max_values) {
  int index = 0;
  while (str.length() > 0) {
    if (str.find(" ") != string::npos) {
      values[index] = stof(str.substr(0, str.find(" ")));
      str.erase(0, str.find(" ") + 1);
      index++;
    }
    else {
      values[index] = stof(str);
    }
  }
  return index;
}
