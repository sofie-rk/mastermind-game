#pragma once

#include "mastermindVisual.h"
#include <string>


std::string randomizeString(int n, char lower, char upper);

int countChar(std::string str, char ch);

int checkCharacters(std::string code, std::string guess);
int checkCharactersAndPosition(std::string code, std::string guess);

void addGuess(MastermindWindow &mwin, const string code,const int size, const char startLetter, const int round);
void hideCode(MastermindWindow &mwin,const int size);
void addFeedback(MastermindWindow &mwin,const int correctPosition, const int correctCharacter, const int size, const int round);