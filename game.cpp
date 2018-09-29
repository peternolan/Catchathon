//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"   
#include "ResourceManager.h"
#include "Color.h"
#include "Pause.h"
#include "Reciever.h"
#include "BorderL.h"
#include "BorderR.h"


//Prepares external resources for use in the game.
void loadResources() {

	//Sprites
	RM.loadSprite("sprites/border-spr.txt", "border");
	

}



// Populate world with some objects.
void populateWorld() {

	LM.writeLog("Reciever\n");

	new Reciever;
	new BorderL;
	new BorderR;

}


int main(int argc, char *argv[]) {

	// Start up game manager.
	if (GM.startUp()) {
		LM.writeLog("Error starting game manager!");
		GM.shutDown();
		return 0;
	}


	// Set flush of logfile during development (when done, make false).
	LM.setFlush(true);

	// Show splash screen.
	df::splash();

	loadResources();

	populateWorld();
	
	//Run the game after all assets are registered.
	GM.run();
	
	// Shut everything down.
	GM.shutDown();
	

}







