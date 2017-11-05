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
    SpellChecker spellCheck1("English");
    SpellChecker spellCheck2;

    spellCheck1.readValidWords("VALID_WORDS_3000.txt");
    spellCheck1.readCorrectedWords("MISSPELLED.txt");

    spellCheck2.readValidWords("VALID_WORDS_3000.txt");
    spellCheck2.readCorrectedWords("MISSPELLED.txt");

    spellCheck.setStartMarker('~');
    spellCheck.setEndMarker('~');

    spellCheck1.setStartMarker('$');
    spellCheck1.setEndMarker('$');

    spellCheck2.setStartMarker('*');
    spellCheck2.setEndMarker('*');

    cout << spellCheck.repair("todayy") << endl;
    cout << spellCheck.repair("todayy, is teh day!") << endl;
    cout << spellCheck.repair("ahsjdklfha") << endl;
    cout << spellCheck.repair("tomor is another day!") << endl;
    cout << spellCheck.repair("Teh brown asdhf jumped.") << endl;
    cout << spellCheck.repair("Hel'lo, my na!me is dav!i.d") << endl;

    cout << spellCheck1.repair("todayy") << endl;
    cout << spellCheck1.repair("todayy, is teh day!") << endl;
    cout << spellCheck1.repair("ahsjdklfha") << endl;
    cout << spellCheck1.repair("tomor is another day!") << endl;
    cout << spellCheck1.repair("Teh brown asdhf jumped.") << endl;
    cout << spellCheck1.repair("Hel'lo, my na!me is dav!i.d") << endl;

    cout << spellCheck2.repair("todayy") << endl;
    cout << spellCheck2.repair("todayy, is teh day!") << endl;
    cout << spellCheck2.repair("ahsjdklfha") << endl;
    cout << spellCheck2.repair("tomor is another day!") << endl;
    cout << spellCheck2.repair("Teh brown asdhf jumped.") << endl;
    cout << spellCheck2.repair("Hel'lo, my na!me is dav!i.d") << endl;

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

    wordCounts.resetTally();

    cout << wordCounts.getTally("fox") << endl;
}
