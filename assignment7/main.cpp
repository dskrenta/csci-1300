// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// main.cpp

#include <iostream>
#include "SpellChecker.h"
// #include "WordCounts.h"

using namespace std;

int main() {
    SpellChecker spellCheck("English", "VALID_WORDS_3000.txt", "MISSPELLED.txt");
    spellCheck.setStartMarker('~');
    spellCheck.setEndMarker('~');
    cout << spellCheck.repair("todayy") << endl;
    cout << spellCheck.repair("todayy, is teh day!") << endl;
    cout << spellCheck.repair("ahsjdklfha") << endl;
    cout << spellCheck.repair("tomor is another day!") << endl;
    cout << spellCheck.repair("Teh brown asdhf jumped.") << endl;
}
