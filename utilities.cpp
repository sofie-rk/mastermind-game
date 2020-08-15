#include "utilities.h"

#include <vector>
#include <iostream>
#include <string>
#include <set>

std::string randomizeString(int n, char lowerLimit, char upperLimit) {

    std::string resultString;
    for (int i = 0; i < n; i++){
        resultString += lowerLimit + (rand() % ((upperLimit+1)-lowerLimit));
    }

    return resultString;
}

int countChar(std::string str, char ch) {
    int count = 0;

    for (char character : str){
        if (character == ch){
            count += 1;
        }
    }
    return count;
}

int checkCharacters(std::string code, std::string guess) {

    int count = 0;

    std::set<char> guessSet;
    for (char ch : guess){
        guessSet.insert(ch);
    }

    for (char ch : guessSet) {
        int guessCount = countChar(guess, ch);
        int codeCount = countChar(code, ch);
        count += std::min(guessCount, codeCount);
    }

    return count;
}

int checkCharactersAndPosition(std::string code, std::string guess) {
    
    int count = 0;

    for (int i=0; i<code.size(); i++){
        if (code[i] == guess[i]){
            ++count;
        }
    }
    return count;
}


void addGuess(MastermindWindow& mwin,const string code,const int size, const char startLetter, const int round){
	int xPos = padX;
    const int yPos = 3*padY + 2*padY*round;

    for (int i = 0; i < size; i++){
        mwin.vr.push_back(new Rectangle{Point{xPos,yPos}, padX, padY});
        mwin.vr[mwin.vr.size()-1].set_fill_color(Color{code[i]-startLetter+1});
        mwin.attach(mwin.vr[mwin.vr.size()-1]);

		xPos += 2*padX;
    }	
}

void addFeedback(MastermindWindow &mwin,const int correctPosition, const int correctCharacter, const int size, const int round){
    int xPos = 2*padX*size + padX;
	const int yPos = 3*padY + 2*padY*round;

	for (int i = 0; i < size; i++){
		mwin.vc.push_back(new Circle{Point{xPos,yPos}, radCircle});

		if (i < correctPosition) {
			mwin.vc[mwin.vc.size()-1].set_fill_color(Color::black);
		} else if (i < (correctPosition + max(0, correctCharacter - correctPosition))) {
			mwin.vc[mwin.vc.size()-1].set_fill_color(Color::white);
		}

		mwin.attach(mwin.vc[mwin.vc.size() - 1]);

		xPos += 2*radCircle;
	}


}

void hideCode(MastermindWindow &mwin,const int size){

	int xPos = padX;
    const int yPos = 3*padY;

    for (int i = 0; i < size; i++){
        mwin.vr.push_back(new Rectangle{Point{xPos,yPos}, padX, padY});
        mwin.vr[mwin.vr.size()-1].set_fill_color(Color::black);
        mwin.attach(mwin.vr[mwin.vr.size()-1]);

		xPos += 2*padX;
    }
}


