#pragma once
#include "Graph.h"
#include "Simple_window.h"

#include "mastermindGame.h"

constexpr int winW = 500; // window width
constexpr int winH = 500; // window height

constexpr int padX = winH/(2*(codeSize+1)+1); // rectangle width, and distance between each element in x-direction
constexpr int padY = winW/(2*(maxTries + 2)+1); // rectangle height, and distance between each element in y-direction
constexpr int radCircle = padX/8; 


constexpr int btnW = padX;
constexpr int btnH = padY;
constexpr int inBoxW = winW -3*padX-btnW;
constexpr int inBoxH = padY;
constexpr Point upperLeftCornerInBox = Point{padX,padY};
constexpr Point upperLeftCornerBtn = Point{winW-padX-btnW,padY};



class MastermindWindow:public Window{
public:
    MastermindWindow(Point xy,int w, int h, const string& title);
    static void cb_guess(Address, Address pw){
        reference_to<MastermindWindow>(pw).newGuess();
    }
    string wait_for_guess();
    Vector_ref<Rectangle> vr;
    Vector_ref<Circle> vc;
    string getGuess(unsigned int n, char lowerLimit, char upperLimit);
    void redraw(){
        Fl::wait();
        Fl::redraw();
    }
private:
    void newGuess(){button_pressed = true;}
    bool button_pressed;
    Button guessBtn;
    In_box guess;
};

