
// These are the header files that we need for the code.
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>

// The line below "using namespace std" statement makes
//it unnecessary to prefix the standard library functions with "std::".
using namespace std;

// function prototypes
string chooseWord();
string hideWord(string word);
bool checkGuess(char guess, string word, string& hiddenWord);
void intro();
int main()
{
    // set up random number generator
    srand(time(0));

    // choose a random word from a list
    string word = chooseWord();

    // initialize hidden word with underscores
    string hiddenWord = hideWord(word);

    // set up variables for tracking game progress
    int numGuesses = 0;
    const int maxGuesses = 7;
    bool gameWon = false;

    // loop until the game is over
    while (numGuesses < maxGuesses && !gameWon) {
        // print current state of game
        cout << "Current word: " << hiddenWord << endl;
        cout << "Guesses remaining: " << maxGuesses - numGuesses << endl;

        // get guess from user
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        // check if guess is correct
        if (checkGuess(guess, word, hiddenWord)) {
            cout << "Correct!" << endl;
            // check if all letters have been guessed
            if (word == hiddenWord) {
                gameWon = true;
            }
        } else {
            cout << "Incorrect." << endl;
            numGuesses++;
        }
    }

    // print final state of game
    cout << "Final word: " << word << endl;
    if (gameWon) {
        cout << "Congratulations, you won!" << endl;
    } else {
        cout << "Sorry, you lost." << endl;
    }

    return 0;
}

// function definitions

// chooses a random word from a list
string chooseWord() {
    const int numWords = 5;
    string words[numWords] = {"apple", "banana", "cherry", "orange", "pear"};
    int index = rand() % numWords;
    return words[index];
}

// returns a string of underscores of the same length as the word
string hideWord(string word) {
    string hiddenWord(word.length(), '_');
    return hiddenWord;
}

// checks if the guess is correct, updates the hidden word if necessary, and returns true if the guess was correct
bool checkGuess(char guess, string word, string& hiddenWord) {
    bool correctGuess = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess) {
            hiddenWord[i] = guess;
            correctGuess = true;
        }
    }
    return correctGuess;
}
        // Introduction section 
void intro(){
    cout << "\n\n\n\t     TOPIC HANGMAN GAME";
    cout << "\n\n\n\n\t     MADE BY: SALAKO RAHMON OLUWASEUN";
    cout << "\n\n\n\n\t     MATRIC NO: H/CTE/22/0689";
    cout << "\n\n\n\n\t     SUPERVISOR : ENGR NZUBE";
    cout << "\n\n\n\n\t     SCHOOL : THE FEDERAL POLYTECHNIC ILARO";
    cin.get();
}