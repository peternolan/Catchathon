#pragma once
#include "Object.h"
#include "EventKeyboard.h"
#include "EventCollision.h"
#include "EventMouse.h"

class Reciever : public df::Object {

private:
	void kbd(const df::EventKeyboard *p_keyboard_event);
	void move(int dy);
	//void step();
	void hit(const df::EventCollision *p_c);
	
	int move_slowdown;
	int move_countdown;
	

	



public:
	Reciever();
	~Reciever();
	int eventHandler(const df::Event *p_e);
	void draw();
};