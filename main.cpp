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
        cout << "Type exit to exit or start to begin" << endl;
        getline(cin,choice);
        if (choice == "exit") { ProgramRunning = false; break; }
        cout << "You have started a new game!" << endl;
        cout << "Don't forget: only use lowercase letters!" << endl;
        Hangman Game;
        while (GameRunning) {
        	Game.DisplayHangmanPicture();
        	Game.printProgressBar();
        	cout << "Guess a letter or the whole word!" << endl;
        	getline(cin,guess);
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
