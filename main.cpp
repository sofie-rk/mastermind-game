

#include "mastermindGame.h"
#include "Graph.h"
#include "Simple_window.h"


//------------------------------------------------------------------------------'

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	playMasterMind();

	Graph_lib::gui_main();

}

//------------------------------------------------------------------------------
