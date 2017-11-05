// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// WordCounts.cpp

#include "WordCounts.h"

/*
    Empty constructor for WordCounts class
*/

WordCounts::WordCounts() {

}

/*
    Destructor for WordCounts class
*/

WordCounts::~WordCounts() {
    // letting compiler handle deconstruction of the class
}

/*
    Counts words in sentence and adds them to the wordCounts map
    If words exists in map, increments count
    Parameters: sentence
*/

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

/*
    Gets tally for given word from wordCounts map
    Parameters: word
    Returns: tally or 0 if word does not exist in map
*/

int WordCounts::getTally(string word) {
    map <string, int>::iterator it;
    it = wordCounts.find(word);
    if (it != wordCounts.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}

/*
    Resets all word counts to 0
*/

void WordCounts::resetTally() {
    map <string, int>::iterator it;
    for (it = wordCounts.begin(); it != wordCounts.end(); it++) {
        it->second = 0;
    }
}

/*
    Populates words and counts array with the highest n counts
    Parameters: words array, counts array, n
    Returns: max frequency
*/

int WordCounts::mostTimes(string words[], int counts[], int n) {
    int maxFrequency = 0;
    vector <pair<string, int>> tempWords(wordCounts.begin(), wordCounts.end());
    sort(tempWords.begin(), tempWords.end(), WordCounts::sortByFrequency);
    for (int i = 0; i < tempWords.size(); i++) {
        pair <string, int> wordCountPair = tempWords.at(i);
        words[i] = wordCountPair.first;
        counts[i] = wordCountPair.second;
        if (i == 0) maxFrequency = wordCountPair.second;
    }
    return maxFrequency;
}

/*
    Sorts a vector of pairs <string, int> based on the second value in the pair (int)
    Parameters: reference to pair a, reference to pair b
    Returns: boolean based on which int is higher
*/

bool WordCounts::sortByFrequency(const pair <string, int> &a, const pair <string, int> &b) {
    return (a.second > b.second);
}

/*
    Converts string to lowercase equivalent and removes punctation
    Parameters: str, punch
    Returns: normalized string
*/

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
