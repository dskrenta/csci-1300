#include <iostream>
#include "assignment4.cpp"

using namespace std;

int main() {
  cout << similarityScore("hahasdf", "hahafdf") << endl;
  cout << countMatches("hahahaha", "haha", 0.6) << endl;
  cout << findBestMatch("hahshf", "ha") << endl;
  cout << findBestGenome("hahc", "haha", "havr", "ha") << endl;
}
