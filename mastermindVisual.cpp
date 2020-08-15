#include "mastermindVisual.h"


MastermindWindow::MastermindWindow(Point xy,int w, int h, const string& title):Window(xy,w,h,title),
    button_pressed{false},
	guessBtn{upperLeftCornerBtn,btnW,btnH,"Add",cb_guess},
    guess{upperLeftCornerInBox,inBoxW,inBoxH,"Guess"}
    {
        attach(guess);
        attach(guessBtn);
};

 string MastermindWindow::wait_for_guess(){
		while (!button_pressed)
			Fl::wait();
		button_pressed = false;
		Fl::redraw();
        string newGuess = guess.get_string();
        guess.clear_value();
        return newGuess;
}


string MastermindWindow::getGuess(unsigned int n, char lowerLimit, char upperLimit){
	bool validInput = false;
	string guess;
	while(!validInput){
		guess.clear();
		string newGuess = wait_for_guess();
		if(newGuess.size() == n){
			for(unsigned int i = 0; i < n; i++){
				char ch = newGuess[i];
                ch = toupper(ch);
				if(isalpha(ch) && ch <= upperLimit && lowerLimit <= ch){
					guess += ch;
				} 
				else 
				break;
			}
		}
		if(guess.size() == n) validInput=true;
		else cout<<"Invalid input guess again\n";
	}
	return guess;
}