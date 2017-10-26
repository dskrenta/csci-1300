// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// SpellChecker.h

#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class SpellChecker {
    public:
        SpellChecker();
        SpellChecker(string inputLanguage);
        SpellChecker(string inputLanguage, string correctSpellingFilename, string incorrectSpellingFilename);
        ~SpellChecker();

        bool readValidWords(string filename);
        bool readCorrectedWords(string filename);
        bool setStartMarker(char begin);
        bool setEndMarker(char end);
        char getStartMarker();
        char getEndMarker();
        string repair(string sentence);
        void repairFile(string inputFilename, string outputFilename);

        string language;

    private:
        int search(string word, string array[], int size);
        string lowerNoPunctuation(string str, string punch);
        void split(string str, char delimiter, string words[], int size);

        char startMarker;
        char endMarker;
        string validWords[10000];
        map <string, string> corrections;
};
#endif // SPELL_CHECKER_H
