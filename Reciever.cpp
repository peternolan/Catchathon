
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"

#include "Reciever.h"

#include "atlstr.h"

#include "EventOut.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventView.h"



Reciever::Reciever() {


	// Player controls hero, so register with keyboard and mouse.
	registerInterest(df::KEYBOARD_EVENT);


	// Need to update fire rate control each step.
	registerInterest(df::STEP_EVENT);

	// Set object type.
	setType("Reciever");

	setAltitude(2);

	setSolidness(df::HARD);

	// Set starting location.
	df::Vector pos(WM.getBoundary().getHorizontal()/2, 20.0f);
	setPosition(pos);

}



// Handle event.
// Return 0 if ignored, else 1.
int Reciever::eventHandler(const df::Event *p_e) {

	CString stringType = p_e->getType().c_str();
	LM.writeLog("%p\n", p_e);
	LM.writeLog("EVENT THAT WE ARE LOOKING AT: %s\n", stringType);

	if (p_e->getType() == df::COLLISION_EVENT) {

		LM.writeLog("COLLISION OCCURED\n");

	}

	if (p_e->getType() == df::KEYBOARD_EVENT) {
		//TEST THIS
		const df::EventKeyboard *p_keyboard_event = (df::EventKeyboard *) (p_e);
		LM.writeLog("%p\n", p_keyboard_event);
		LM.writeLog("GET KEY IN HERO\n");
		kbd(p_keyboard_event);
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}



Reciever::~Reciever() {


}

//ADDED THIS FOR POWERUP
//This function determins behaviour after collision event.
void Reciever::hit(const df::EventCollision *p_c) {

	// If it hits the power up, destroy the PowerUp, reduce the fire delay to 7 frames, and set the PowerUp time limit to 100 frames.
	if ((p_c->getObject1()->getType() == "PowerUp") ||
		(p_c->getObject2()->getType() == "PowerUp"))
		//Delete only the PowerUp object.
		if (p_c->getObject1()->getType() == "PowerUp") {

			WM.markForDelete(p_c->getObject1());

		}
		else {
			WM.markForDelete(p_c->getObject2());
		}


	return;

}

//  Custom draw.
void Reciever::draw() {
	DM.drawCh(getPosition(), '0', df::BLUE);
}


// Take appropriate action according to key pressed.
void Reciever::kbd(const df::EventKeyboard *p_keyboard_event) {

	LM.writeLog("IN KBD\n");
	LM.writeLog("%p\n", p_keyboard_event);
	switch (p_keyboard_event->getKey()) {
	case df::Keyboard::Key::W:			// up
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			LM.writeLog("IN KBD W\n");
		move(-1);
		break;
	case df::Keyboard::Key::S:			// down
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			LM.writeLog("IN KBD S\n");
		move(+1);
		break;
	case df::Keyboard::Key::Q:			// quit
		if (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED)
			WM.markForDelete(this);
		break;
	};

	return;
}


// Move up or down.
void Reciever::move(int dx) {
	df::Vector new_pos(getPosition().getX() + dx, getPosition().getY());
	LM.writeLog("MOVE IN HERO");
	// If stays on screen, allow move.
	if ((new_pos.getX() >= 0) &&
		(new_pos.getX() < DM.getHorizontal()))
		WM.moveObject(this, new_pos);

}



