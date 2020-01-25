#pragma once
#define WIN32_LEAN_AND_MEAN
#include <string.h>
#include "game.h"

//=============================================================================
// Create game class
//=============================================================================
class Convier : public Game {
private:

public:
	// Constructor
	Convier();

	// Destructor
	virtual ~Convier();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void render();
	void releaseAll();
	void resetAll();
};
