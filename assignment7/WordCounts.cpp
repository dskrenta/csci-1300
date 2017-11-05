// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// WordCounts.cpp

#include "WordCounts.h"

WordCounts::WordCounts() {

}

WordCounts::~WordCounts() {
    // letting compiler handle deconstruction of the class
}

void WordCounts::tallyWords(string sentence) {
    string normalized = lowerNoPunctuation(sentence, ".?-/,!(){}[]_:;<>");
    string token;
    stringstream ss(normalized);
    map <string, int>::iterator it;
    while (ss >> token) {
        if ((it = wordCounts.find(token)) != wordCounts.end()) {
            it->second = it->second + 1;
        }
        else {
            wordCounts.insert(pair <string, int>(token, 1));
        }
    }
}

int WordCounts::getTally(string word) {
    return wordCounts.at(word);
}

void WordCounts::resetTally() {
    map <string, int>::iterator it;
    for (it = wordCounts.begin(); it != wordCounts.end(); it++) {
        it->second = 0;
    }
}

int WordCounts::mostTimes(string words[], int counts[], int n) {
    int maxFrequency = 0;
    vector <pair<string, int>> tempWords(wordCounts.begin(), wordCounts.end());
    sort(tempWords.begin(), tempWords.end(), WordCounts::sortByFrequency);
    for (int i = 0; i < n; i++) {
        pair <string, int> wordCountPair = tempWords.at(i);
        cout << wordCountPair.first << ", " << wordCountPair.second << endl;
        words[i] = wordCountPair.first;
        counts[i] = wordCountPair.second;
        if (i == 0) maxFrequency = wordCountPair.second;
    }
    return maxFrequency;
}

bool WordCounts::sortByFrequency(const pair <string, int> &a, const pair <string, int> &b) {
    return (a.second > b.second);
}

string WordCounts::lowerNoPunctuation(string str, string punch) {
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
                    break;
                }
            }
            if (!isPunch) {
                normalized += str[i];
            }
        }
    }

    return normalized;
}
