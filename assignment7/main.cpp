// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// main.cpp

#include <iostream>
#include "SpellChecker.h"
#include "WordCounts.h"

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

    WordCounts wordCounts;
    wordCounts.tallyWords("the brown fox.");
    wordCounts.tallyWords("the red fox.");
    wordCounts.tallyWords("teh blue cat.");

    cout << wordCounts.getTally("the") << endl;
    cout << wordCounts.getTally("brown") << endl;
    cout << wordCounts.getTally("fox") << endl;
    cout << wordCounts.getTally("red") << endl;
    cout << wordCounts.getTally("blue") << endl;
    cout << wordCounts.getTally("cat") << endl;
    cout << wordCounts.getTally("teh") << endl;

    string words[10];
    int counts[10];

    cout << wordCounts.mostTimes(words, counts, 5) << endl;

    for (int i = 0; i < 10; i++) {
        if (!words[i].empty()) cout << words[i] << ", " << counts[i] << endl;
    }
}
