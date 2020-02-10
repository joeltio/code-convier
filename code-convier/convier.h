#pragma once
#define WIN32_LEAN_AND_MEAN
#include <string.h>
#include "game.h"
#include "Manager.h"
#include "SystemRunner.h"
#include "ecsConstants.h"

//=============================================================================
// Create game class
//=============================================================================
class Convier : public Game {
private:
	ECS::Manager* manager = NULL;
	ECS::SystemRunner systemRunner;
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
