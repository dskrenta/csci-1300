// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// main.h

#include <iostream>
#include "Crawler.h"

using namespace std;

int main() {
    unordered_set <string> roots;

    roots.insert("http://harvix.com");
    roots.insert("https://news.google.com");
    roots.insert("https://nytimes.com");

    // init crawler class with roots, no whitelist or blacklist, 50 urls max, and 4 threads
    Crawler crawler(roots, "", "", "data", 50, 4);
}
