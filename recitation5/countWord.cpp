#include <iostream>
using namespace std;

string lowerNoPunctuation(string str, string punch) {
    string normalized = "";

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            normalized += tolower(str[i]);
        }
        else {
            bool isPunch = false;
            for (int j = 0; j < punch.length(); j++) {
                if (str[i] == punch[j]) {
                    isPunch = true;
                }
            }
            if (!isPunch) {
                normalized += str[i];
            }
        }
    }

    return normalized;
}

int countWord(string sentence, string matchWord) {
    int count = 0;
    string punctuation = ".,!$*&^%${}:-";
    string normalizedSentence = lowerNoPunctuation(sentence, punctuation);

    string currentWord = "";
    int lastPosition = 0;

    /*
    while(normalizedSentence.find(matchWord) != string::npos) {
        normalizedSentence.replace(normalizedSentence.find(matchWord), matchWord.length(), "");
        count++;
    }
    */

    cout << "normalizedSentence: " << normalizedSentence << endl;

    /*
    for (int i = 0; i < normalizedSentence.length(); i++) {
        if (normalizedSentence[i] == 32) {
            currentWord = normalizedSentence.substr(lastPosition, i);
            lastPosition = i;
            cout << "currentWord: " << currentWord << " lastPosition: " << lastPosition << " i: " << i << endl;
            if (currentWord == matchWord) {
                count++;
            }
        }
    }
    */

    // a sample sentence
    // start = 0
    // length = start - last space position

    for (int i = 0; i < normalizedSentence.length(); i++) {
      if (normalizedSentence[i] == 32) {
        // cout << i - 1 << endl;
        int start = i == 0 ? lastPosition : lastPosition - 1;
        string currentWord = normalizedSentence.substr(lastPosition, i - lastPosition);
        // string currentWord = normalizedSentence.substr(start, i - lastPosition);
        cout << currentWord << endl;
        lastPosition = i + 1;
        if (currentWord == matchWord) {
          count++;
        }
      }
    }

    return count;
}

int main() {
  // cout << countWord( "She sells sea-shells on the sea-shore. The shells she sells are sea-shells, I'm sure.", "shells") << endl;
  cout << countWord("WOLF", "wolf") << endl;
}
