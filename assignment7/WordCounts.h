// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// WordCounts.h

#ifndef WORD_COUNTS_H
#define WORD_COUNTS_H

#include <iostream>
#include <string>

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
        string words[10000];
        int counts[10000];
        int index = 0;
};
#endif // WORD_COUNTS_H
