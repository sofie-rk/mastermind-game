#pragma once

#include <string>

constexpr int codeSize = 4;
constexpr int letters = 6;
constexpr char startLetter = 'A';
constexpr int maxTries = 5;

void playMasterMind();

int checkCharacters(std::string code, std::string guess);

int checkCharactersAndPosition(std::string code, std::string guess);