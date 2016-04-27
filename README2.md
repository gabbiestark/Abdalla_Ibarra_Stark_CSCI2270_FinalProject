Project summary:
Our program allows a user to play hangman against a computer. We created an array of words from a third party text file, from which the code randomly chooses. The program displays to the user an arbitrary amount of underscores, based on the word picked from the array, and asks them to type in their guess. As the user inputs different letters, our program displays correct guesses in the progress bar, and incorrect guesses under the game in the “Wrong Letters Guessed:” section. Incorrect guesses also activate the DisplayHangmanPicture method. Each incorrect guess is indexed to a counter, and as the counter increases, a new body part is drawn on the gallow. If your full body is drawn, the program reveals the word and asks you if you want to exit or play again. If you win, you can also choose to play again. You can play again 299 times before a word repeats. 

How to run:
Our program is uploaded onto gitHub in a zip file. Once the zip file is downloaded, you should have a folder titled ‘Final_Project’ in your downloads folder. This will contain Hangman.cpp, Hangman.h, main.cpp, and words.txt. Create a new project in your VM. Copy and paste the words.txt document into the dropbox folder you have just created. Copy and paste our main.cpp file into the blank main.cpp file that should open as you create the new project. Create a new class and name it “Hangman.” Copy and paste our Hangman.cpp and Hangman.h into the respective .cpp and .h files that are now in the window.  Build and run the program, follow the prompted directions, and have fun! 

Dependencies:
Our program relies on a third party library that we must read in. For this project, we put 300 random words in a text file, named it words.txt, and read it in through the GenerateWord method. This word document will be downloaded when you download the zip file on gitHub. You can choose to use your own word document if you’d like, however, it would need to be formatted the same as our .txt file. 

System requirements:
Our program works for all Windows, Mac, Linux. There are no additional system requirements other than the operating system.

Group Members:
Mohammed Abdalla, Ryan Ibarra, Gabbie Stark.

Open issues/bugs 
None.
