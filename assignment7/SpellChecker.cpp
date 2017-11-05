// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// SpellChecker.cpp

#include "SpellChecker.h"

/*
    Empty constructor for SpellCheck class
*/

SpellChecker::SpellChecker() {

}

/*
    Constructor for SpellCheck class with input language specification
    Parameters: inputLanguage
*/

SpellChecker::SpellChecker(string inputLanguage) {
    language = inputLanguage;
}

/*
    Constructor for SpellCheck class with input language, correct spelling filename, and incorrect spelling filename specification
    Parameters: inputLanguage, correctSpellingFilename, incorrectSpellingFilename
*/

SpellChecker::SpellChecker(string inputLanguage, string correctSpellingFilename, string incorrectSpellingFilename) {
    language = inputLanguage;
    readValidWords(correctSpellingFilename);
    readCorrectedWords(incorrectSpellingFilename);
}

/*
    Destructor for SpellCheck class
*/

SpellChecker::~SpellChecker() {
    // letting compiler handle deconstruction of the class
}

/*
    Reads valid words into valid words array
    Parameters: filename
    Returns: boolean value based on successful file read
*/

bool SpellChecker::readValidWords(string filename) {
    ifstream file (filename);
    string line;
    int index = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            validWords[index] = line;
            index++;
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

/*
    Reads corrected words into a map
    Parameters: filename
    Returns: boolean value based on successful file read
*/

bool SpellChecker::readCorrectedWords(string filename) {
    ifstream file (filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            string parsed[2];
            split(line, '\t', parsed, 2);
            corrections.insert(pair <string, string>(parsed[0], parsed[1]));
        }
        file.close();
        return true;
    }
    else {
        return false;
    }
}

/*
    Sets start marker for SpellCheck class
    Parameters: begin
    Returns: true
*/

bool SpellChecker::setStartMarker(char begin) {
    startMarker = begin;
    return true;
}

/*
    Sets end marker for SpellCheck class
    Parameters: end
    Returns: true
*/

bool SpellChecker::setEndMarker(char end) {
    endMarker = end;
    return true;
}

/*
    Gets start marker for SpellCheck class
    Returns: start marker
*/

char SpellChecker::getStartMarker() {
    return startMarker;
}

/*
    Gets end marker for SpellCheck class
    Returns: end market
*/

char SpellChecker::getEndMarker() {
    return endMarker;
}

/*
    Repairs a normalized string given the valid words array, and corrected words map
    Parameters: sentence
    Returns: repaired sentence
*/

string SpellChecker::repair(string sentence) {
    string repaired = "";
    string normalized = lowerNoPunctuation(sentence, ".?-/,!(){}[]_:;<>");
    string token;
    stringstream ss(normalized);
    map <string, string>::iterator it;
    while (ss >> token) {
        if (search(token, validWords, 10000) != -1) {
            repaired += token;
        }
        else if ((it = corrections.find(token)) != corrections.end()) {
            repaired += it->second;
        }
        else {
            repaired += startMarker + token + endMarker;
        }
        repaired += " ";
    }
    return repaired;
}

/*
    Searches for a target value in array
    Parameters: target, array, size
    Returns: -1 if not found, positive index if found
*/

int SpellChecker::search(string target, string array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

/*
    Removes punctation from a string
    Note: Does not remove punctation inside a word
    Parameters: str, punch
    Returns: normalized string
*/

string SpellChecker::lowerNoPunctuation(string str, string punch) {
    string normalized = "";

    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            normalized += tolower(str[i]);
        }
        else {
            bool isPunch = false;
            for (int j = 0; j < punch.length(); j++) {
                if (str[i] == punch[j] && (i == 0 || i + 1 == str.length() || str[i + 1] == ' ' || str[i - 1] == ' ')) {
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

/*
    Splits string into array based on delimiter
    Parameters: str, delimiter, words array, size
*/

void SpellChecker::split(string str, char delimiter, string words[], int size) {
    size_t pos = 0;
    int index = 0;
    while ((pos = str.find(delimiter)) != string::npos) {
        words[index] = str.substr(0, pos);
        str.erase(0, pos + 1);
        index++;
    }
    words[index] = str;
}
