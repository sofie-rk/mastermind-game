#include "utilities.h"
#include "mastermindGame.h"
#include "mastermindVisual.h"

#include <iostream>
#include <string>
#include <set>

void playMasterMind() {

    bool playAgain = true;
    
    while (playAgain) {

        MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    
        const string code = randomizeString(codeSize, startLetter, startLetter + (letters -1));
        std::cout << "Code: " << code << endl;
        string guess;
        std::cout << "\n*** MASTER MIND ***\n";

        int currentGuess = 0;

        hideCode(mwin, codeSize);
        
        while (guess != code && currentGuess != maxTries){

            guess = mwin.getGuess(codeSize, startLetter, startLetter + (letters - 1));
            ++currentGuess;
            
            int correctCharAndPos = checkCharactersAndPosition(code, guess);
            int correctChar = checkCharacters(code, guess);

            addGuess(mwin, guess, codeSize, startLetter, currentGuess);
            addFeedback(mwin, correctCharAndPos, correctChar, codeSize, currentGuess);

            if (correctCharAndPos == codeSize) {
                break;
            }

            cout << "Correct characters: " << correctChar
                << "\nCorrect position: " << correctCharAndPos
                << "\nYou have " << maxTries - currentGuess << " tries left. \n";
        
        }

        if (guess == code){
            std::cout << "Correct code!!! \n";
        } else {
            std::cout << "Wrong code...\n";
            addGuess(mwin, code, codeSize, startLetter, 0);
        }

        mwin.redraw();

        char c;
        std::cout << "Do you want to play again? (y/n) \n";
        std::cin>>c;
        if (c == 'y'){
            playAgain = true;
        } else {
            playAgain = false;
        }

    }
    
}




