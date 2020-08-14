//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "test.h"
#include "utilities.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	testString();

	string resultString = readInputToString(8, 'A', 'F');

	cout << resultString << endl;
}

//------------------------------------------------------------------------------
