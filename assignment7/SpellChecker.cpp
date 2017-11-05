// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 7
// SpellChecker.cpp

#include "SpellChecker.h"

#include <fstream>
#include <string>
#include <map>
#include <sstream>

SpellChecker::SpellChecker() {

}

SpellChecker::SpellChecker(string inputLanguage) {
    language = inputLanguage;
}

SpellChecker::SpellChecker(string inputLanguage, string correctSpellingFilename, string incorrectSpellingFilename) {
    language = inputLanguage;
    readValidWords(correctSpellingFilename);
    readCorrectedWords(incorrectSpellingFilename);
}

SpellChecker::~SpellChecker() {
    // letting compiler handle deconstruction of the class
}

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
        cout << "Could not open file: " << filename << endl;
        return false;
    }
}

bool SpellChecker::readCorrectedWords(string filename) {
    ifstream file (filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            string parsed[2];
            split(line, '\t', parsed, 2);
            corrections.insert(pair<string, string>(parsed[0], parsed[1]));
        }
        file.close();
        return true;
    }
    else {
        cout << "Could not open file: " << filename << endl;
        return false;
    }
}

bool SpellChecker::setStartMarker(char begin) {
    startMarker = begin;
    return true;
}

bool SpellChecker::setEndMarker(char end) {
    endMarker = end;
    return true;
}

char SpellChecker::getStartMarker() {
    return startMarker;
}

char SpellChecker::getEndMarker() {
    return endMarker;
}

string SpellChecker::repair(string sentence) {
    string repaired = "";
    string normalized = lowerNoPunctuation(sentence, ".?-/,!(){}[]_:;<>");
    string token;
    stringstream ss(normalized);
    map<string, string>::iterator it;
    while (ss >> token) {
        cout << "token: " << token << endl;
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

void SpellChecker::repairFile(string inputFilename, string outputFilename) {
}

int SpellChecker::search(string target, string array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

string SpellChecker::lowerNoPunctuation(string str, string punch) {
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
