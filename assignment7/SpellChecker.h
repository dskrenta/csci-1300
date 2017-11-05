// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// SpellChecker.h

#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class SpellChecker {
    public:
        SpellChecker();
        SpellChecker(string);
        SpellChecker(string, string, string);
        ~SpellChecker();

        bool readValidWords(string);
        bool readCorrectedWords(string);
        bool setStartMarker(char);
        bool setEndMarker(char);
        char getStartMarker();
        char getEndMarker();
        string repair(string);
        void repairFile(string, string);

        string language;

    private:
        int search(string, string[], int);
        string lowerNoPunctuation(string, string);
        void split(string, char, string[], int);

        char startMarker;
        char endMarker;
        string validWords[10000];
        map <string, string> corrections;
};
#endif // SPELL_CHECKER_H
