#include <iostream>
#include <string>
using namespace std;

string removeSubstring(string str, string substring) {
  while(str.find(substring) != string::npos) {
    str.replace(str.find(substring), substring.length(), "");
  }
  return str;
}

int main() {
  cout << removeSubstring("42a", "42a") << endl;
  cout << removeSubstring("42a", "z") << endl;
  cout << removeSubstring("jumped", "ed") << endl;
  cout << removeSubstring("511aa1ab", "1a") << endl;
}
