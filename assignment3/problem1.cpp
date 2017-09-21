#include <iostream>
#include <string>
using namespace std;

// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 3

/*
  Prints the template for story1 with the user inputs
  User inputs: plural noun, occupation, animal name, place
*/

void story1(void) {
  string pluralNoun;
  string occupation;
  string animalName;
  string place;

  cout << "Enter a plural noun: " << endl;
  cin >> pluralNoun;
  cout << "Enter an occupation: " << endl;
  cin >> occupation;
  cout << "Enter an animal name: " << endl;
  cin >> animalName;
  cout << "Enter a place: " << endl;
  cin >> place;

  cout << "In the book War of the " << pluralNoun << ", the main character is an anonymous " << occupation << " who records the arrival of the " << animalName << "s in " << place << endl;
}

/*
  Prints the template for story2 with the user inputs
  User inputs: name, state / country
*/

void story2(void) {
  string name;
  string area;

  cout << "Enter a name: " << endl;
  cin >> name;
  cout << "Enter a state/country: " << endl;
  cin >> area;

  cout << name << ", I;ve got a feeling we're not in " << area << " anymore." << endl;
}

/*
  Prints the template for story3 with the user inputs
  User inputs: first name, relative, verb
*/

void story3(void) {
  string firstName;
  string relative;
  string verb;

  cout << "Enter a first name: " << endl;
  cin >> firstName;
  cout << "Enter a relative: " << endl;
  cin >> relative;
  cout << "Enter a verb: " << endl;
  cin >> verb;

  cout << "Hello. My name is " << firstName << ". You killed my " << relative << ". Prepare to " << verb << endl;
}

/*
  Core game loop that allows users to switch between stories and or exit the program
  User input: story index input or quit
*/

void menu(void) {
  string input;
  while(input != "q") {
    cout << "Which story would you like to play? Enter the number of the story​ ​(1,​ 2,​ or​ 3)​ or​ type​ ​q to​ quit:​ " << endl;
    cin >> input;

    if(input == "1") {
      story1();
    }
    else if(input == "2") {
      story2();
    }
    else if(input == "3") {
      story3();
    }
    else if(input == "q") {
      break;
    }
    else {
      cout << "Valid choice not selected" << endl;
    }
  }
  cout << "good bye" << endl;
}

int main() {
  menu();
}
