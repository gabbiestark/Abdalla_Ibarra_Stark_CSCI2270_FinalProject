#include <iostream>
#include <string>
#include <vector>
#include "Hangman.h"

using namespace std;

int main()
{
	cout << "Hello and welcome to Hangman 1.0!" << endl;
	cout << "Created by the minds of Moe, Gabbie, and Ryan" << endl;
	string choice;
	string guess;
    bool ProgramRunning = true;
    while (ProgramRunning) {
        bool GameRunning = true;
        cout << "Type (1) to start or (2) to exit." << endl;        //Altered menu for easier navigation
        getline(cin,choice);
        if (choice == "2") { ProgramRunning = false; break; }       //Change what program looks for in order to begin/quit
        cout << "You have started a new game!" << endl;
        //cout << "Don't forget: only use lowercase letters!" << endl;      //Program now makes all letters lowercase by default
        Hangman Game;
        while (GameRunning) {
        	Game.DisplayHangmanPicture();
        	Game.printProgressBar();
        	cout << "Guess a letter or the whole word!" << endl;
        	getline(cin,guess);
            for(int i=0;i<guess.length();++i)      //From the beginning to the end of guess variable
            {
                guess[i]=tolower(guess[i]);         //Make each letter lower case
        	}
        	Game.letterCheck(guess);
        	if (Game.Lost()) {
        		Game.DisplayHangmanPicture();
        		GameRunning = false;
        	}
        	if (Game.WIN == true) {
        		Game.WinMessage();
        		GameRunning = false;
        	}
        }
    }
    cout << "Goodbye and play again!" << endl;
    return 0;
}
