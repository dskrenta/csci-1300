// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// WordCounts.h

#ifndef WORD_COUNTS_H
#define WORD_COUNTS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class WordCounts {
    public:
        WordCounts();
        ~WordCounts();

        void tallyWords(string);
        int getTally(string word);
        void resetTally();
        int mostTimes(string[], int[], int);

    private:
        string lowerNoPunctuation(string, string);
        static bool sortByFrequency(const pair <string, int> &a, const pair <string, int> &b);

        map <string, int> wordCounts;
};
#endif // WORD_COUNTS_H
