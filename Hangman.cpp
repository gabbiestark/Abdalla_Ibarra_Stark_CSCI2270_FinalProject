#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "Hangman.h"
#include "stdio.h"

Hangman::Hangman() {
	Tries = 0;
	WIN = false;
	WORD = GenerateWord();
	StringToArray();
	for(int i = 0; i < WORD.length(); i++){
        displayArray.push_back("_");
	}
}

Hangman::~Hangman() {
	// TODO Auto-generated destructor stub
}

int Hangman::randomNumber(int maxNum){
    srand(time(0));
    return (rand() % maxNum) + 1;
}

string Hangman::GenerateWord(){
	vector <vector <string> > data;
	    vector<string> record;
	    ifstream infile("words.txt");
	    while (infile)
	  {
	    string s;
	    if (!getline( infile, s )) break;

	    istringstream ss( s );

	    while (ss)
	    {
	      string s;
	      if (!getline( ss, s, '\\' )) break;
	      record.push_back( s );
	    }

	    data.push_back( record );
	  }
    int num = randomNumber(299);
    return record.at(num);
}

void Hangman::DisplayHangmanPicture() {
	if (Tries == 0) {
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
	}
	else if (Tries == 1) {
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "             O             |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
	}
	else if (Tries == 2) {
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "             O             |                " << endl;
		cout << "             |             |                " << endl;
		cout << "             |             |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
	}
	else if (Tries == 3) {
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "             O             |                " << endl;
		cout << "             |             |                " << endl;
		cout << "             |             |                " << endl;
		cout << "              \\            |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
	}
	else if (Tries == 4) {
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "             O             |                " << endl;
		cout << "             |             |                " << endl;
		cout << "             |             |                " << endl;
		cout << "            / \\            |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
	}
	else if (Tries == 5) {
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "             O             |                " << endl;
		cout << "             |-            |                " << endl;
		cout << "             |             |                " << endl;
		cout << "            / \\            |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
	}
	else if(Tries == 6){
		cout << "             ---------------                " << endl;
		cout << "             |             |                " << endl;
		cout << "             O             |                " << endl;
		cout << "            -|-            |                " << endl;
		cout << "             |             |                " << endl;
		cout << "            / \\            |                " << endl;
		cout << "                           |                " << endl;
		cout << "                           |                " << endl;
		cout << "                    ---------------         " << endl;
		cout << "" << endl;
		cout << "Sorry, you have lost! The word you were trying to guess was " << WORD << endl;
		cout << "" << endl;
	}
}

void Hangman::letterCheck(string input){
    int tmp[30];
    int counter = 0;
    if(input == WORD){
        WIN = true;
        return;
    }
    for(int i = 0; i<wordArray.size(); i++){
        if(wordArray.at(i) == input){
            tmp[counter] = i;
            counter++;
        }
    }
    if(counter == 0){
        guessedLetters.push_back(input);
        cout << "The letter you guessed was wrong!" << endl;
        Tries++;
    }else{
        for(int i = 0; i<counter; i++){
            displayArray.at(tmp[i]) = input;
        }
    }
    for(int i = 0; i < displayArray.size(); i++){
        if(displayArray.at(i) == "_"){
            break;
        }
        if(i == displayArray.size()-1){
            WIN = true;
        }
    }
}

void Hangman::printProgressBar(){
    cout << "                    ";
    for(int i = 0; i < displayArray.size(); i++){
        cout << displayArray.at(i) << " ";
    }
    cout << "      " << endl;
    cout << "" << endl;
    cout << "The word you are guessing is " << WORD.length() << " characters long!" << endl;
    cout << "Wrong Letters Guessed: ";
    for(int i = 0; i < guessedLetters.size(); i++){
        cout << guessedLetters.at(i) << ", ";
    }
    cout << " " << endl;
}

void Hangman::StringToArray(){
	string str = WORD;
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	for(int i = 0; i < str.length() + 1; i++){
		string str(1,cstr[i]);
		wordArray.push_back(str);
	}
}

bool Hangman::Lost() {
	if (Tries == 6) { return true; }
	else { return false; }
}

void Hangman::WinMessage() {
	cout << "                                             ._." << endl;
	cout << " ___.__. ____  __ __  __  _  ______   ____   | |" << endl;
	cout << "<   |  |/  _ \\|  |  \\ \\ \\/ \\/ /  _ \\ /    \\  | |" << endl;
	cout << " \\___  (  <_> )  |  /  \\     (  <_> )   |  \\  \\|" << endl;
	cout << " / ____|\\____/|____/    \\/\\_/ \\____/|___|  /  __" << endl;
	cout << " \\/                                      \\/   \\/" << endl;
	cout << "" << endl;
	cout << "You correctly guessed the word " << WORD << "!" << endl;
	cout << "" << endl;
}
