#include "NPCSprite.h"

namespace gmeng {
	NPCSprite::NPCSprite(const int x, int y, int w, int h, const char* p) :Sprite(x, y, 80, 80, p)
	{
		setNPC(true);
	}//NPCSprite()

	
	void NPCSprite::PathAction()
	{

		if (getRect().y > 500) {
			
			if (getRect().x < 50) {
				setMotion(-5);
			}// if NPC is close to left corner stop and then shift to movement to right
			if (getRect().x > (syswindow.getW() - 200)) {
				setMotion(5);
			}//if npc is close the right corner move to left corner 
			
			rect.x = rect.x - getMotion();
		}//Move to Left first then right
		
		if (getRect().y <= 500) {
			if (getRect().x < 50) {
				setMotion(5);
			}
			if (getRect().x > (syswindow.getW() - 200)) {
				setMotion(-5);
			}
			rect.x = rect.x + getMotion();
		}//Move to right to left

	}//PathAction()

	NPCSprite::~NPCSprite()
	{
	}

	

}//NameSpace