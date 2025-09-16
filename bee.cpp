#include <iostream>
#include "input.h"
using namespace std;

// This is a helper method for you to use.
// You can use it to see if a word contains a character.
// You should not use the find method in your program!
bool containsChar(string word, char targetChar) {
    for (char letter : word) {
        if (letter == targetChar) {
            return true;
        }
    }
    return false;
}

// Using the valid letters and the required letter,
// check to see if the guess is valid.
bool isValidGuess(string guess, string validLetters, char requiredLetter) {
if ( guess.size() < 4 ) {
    cout << "Your word must be at least 4 letters long" << endl << endl;
    return false;
}
bool hasRequiredLetter = containsChar(guess, requiredLetter);
    if(!hasRequiredLetter){
        cout << "Your word must contain the required letter: " << requiredLetter << endl << endl;
        return false;
    }

for(int i= 0; i < guess.length(); i++){
     char letter = guess.at(i);
     bool letterIsValid = containsChar(validLetters, letter);
     if(!letterIsValid){
        cout << "Your word contains an invalid character: " << letter << endl << endl;
        return false;
     }
}
     return true;
}

// Ask the user for their guess until they enter a valid guess.
// Once you have a valid guess, return that string.
string getGuess(string validLetters, char requiredLetter) {
string guess;
while (true){
     cout << "Enter a word: " ;       
      cin>> guess;

      for (int i = 0; i < guess.length(); i++) {
       guess.at(i) = toupper(guess.at(i));
    } 

    if(guess == "END"){
        return guess;
        }

    if (isValidGuess(guess, validLetters, requiredLetter)) {
    return guess;

      }
      cout << "Your letters are: ";
        printLetters(validLetters);
    }
}

// Check to see if the guess uses every letter in valid letters.
// If it does, return true.
bool isPangram(string guess, string validLetters) {
    for (int i = 0; i < validLetters.length(); i++){
        if (!containsChar(guess, validLetters.at(i))){  
            return false;
        } 
    }
    cout << "Pangram! ";
    return true;
}

// Calculate the score of a guess. This should use the
// string length and check to see if a guess gets extra
// points for being a pangram.
// Return the score for that guess.
int scoreGuess(string guess, string validLetters) {
    if (isPangram(guess, validLetters)){
        return guess.size() + 7;
    } else if(guess.size() == 4){
        return 1;
    } else{
         return guess.size();
    }
}

int main(int argc, char *argv[]) {
    ///////////////////////////
    // Do not change this code.
    string letters = GetRandomInput(argc, argv);
    cout << "Welcome to Spelling Bee! Your letters are: ";
    printLetters(letters);
    char requiredLetter = letters.at(0);
    cout << "The required letter is: " << requiredLetter << endl;
    //////////////////////////

    // Your code goes here!
    // While the user wants to play, get their guess
    // and update their score.
    string guess = "";
int totalScore = 0;
        cout << endl;
        while(true){
            cout <<  "Your letters are: ";
             printLetters(letters); 
            guess = getGuess(letters, requiredLetter);
            if (guess == "END"){
                break;
            }
        
        int score = scoreGuess(guess, letters);
        cout << "+" << score << endl;

        totalScore += score;
        cout << "New score: " << totalScore << endl << endl;
        
            
        }
    cout << "Final score: " << totalScore << endl;
    return 0;
 }

