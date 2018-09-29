
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

#include "BorderR.h"


BorderR::BorderR() {

	// Set object type.
	setType("BorderR");


	// Link to "ship" sprite.
	df::Sprite *p_temp_sprite;
	p_temp_sprite = RM.getSprite("border");
	//If sprite not found:
	if (!p_temp_sprite)
		LM.writeLog("Border::Border(): Warning! Sprite '%s' not found", "border");
	//If sprite found
	else {
		setSprite(p_temp_sprite);  //Set sprite
		setSpriteSlowdown(3);  // 1/3 speed animation.
		setTransparency();	   // Transparent sprite.
	}



	setAltitude(2);

	setSolidness(df::HARD);

	// Set starting location.
	df::Vector pos(74, WM.getBoundary().getVertical() / 2);
	setPosition(pos);





}

BorderR::~BorderR() {
	




}

