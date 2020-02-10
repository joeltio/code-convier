#include "convier.h"

//=============================================================================
// Constructor
//=============================================================================
Convier::Convier() {}

//=============================================================================
// Destructor
//=============================================================================
Convier::~Convier()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Convier::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError
	this->manager = new ECS::Manager();

	// Register systems
	for (ECS::System* systemPtr : ENABLED_SYSTEMS)
	{
		this->systemRunner.registerSystem(systemPtr);
	}

	this->systemRunner.initialize(this->manager, this->graphics, this->input);
}

//=============================================================================
// Update all game items
//=============================================================================
void Convier::update() {
	this->systemRunner.update(this->frameTime);
}

//=============================================================================
// Render game items
//=============================================================================
void Convier::render()
{
	graphics->spriteBegin();
	this->systemRunner.render();
	graphics->spriteEnd();
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Convier::releaseAll()
{
	this->systemRunner.releaseAll();
	SAFE_DELETE(this->manager);
	Game::releaseAll();
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Convier::resetAll()
{
	Game::resetAll();
	this->systemRunner.resetAll();
}