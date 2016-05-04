#define HANGMAN_H_
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Hangman
{
    public:
        Hangman();
        virtual ~Hangman();
        void addBodyPart();
        string GenerateWord();
        int randomNumber(int maxNum);
        void letterCheck(string input);
        void StringToArray();
        bool Lost();
        bool win();
        void DisplayHangmanPicture();
        bool WIN;
        void WinMessage();
        void printProgressBar();
    private:
        vector<string> wordArray;
        vector<string> displayArray;
        vector<string> guessedLetters;
        int Tries;
        string WORD;
};
