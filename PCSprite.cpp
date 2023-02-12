//Mohammed Tahmid Chowdhury moch8386
//Grupp 77
#include "PCSprite.h"

namespace gmeng {
	PCSprite::PCSprite( const char* p) : Sprite(500, 900,100, 100, p)
	{
		
		
	}//PCSprite

	void PCSprite::keyAction(const SDL_Event& eve)
	{
		if (eve.type == SDL_KEYDOWN) {
			if (SDLK_RIGHT == eve.key.keysym.sym) {
				isRightDown = true;
			}//if right is clicked

			if (SDLK_LEFT == eve.key.keysym.sym) {
				isLeftDown = true;
			}//if left is clicked

			if (SDLK_SPACE == eve.key.keysym.sym) {
				shotFired = true;
			}//if space is clicked
		}

		if (eve.type == SDL_KEYUP) {
			if (SDLK_RIGHT == eve.key.keysym.sym) {
				isRightDown = false;
			}//check if right click is removed from click

			if (SDLK_LEFT == eve.key.keysym.sym) {
				isLeftDown = false;
			}//check if left clicked is removced from click

			if (SDLK_SPACE == eve.key.keysym.sym) {
				shotFired = false;
			}//check if space click is removed from click
		}

	}//Keyaction()



	void PCSprite::action(std::vector<Component*>* sprite) {
		if (bulletDelay > 0) {
			bulletDelay--;
			setFired(false);
		}//Bullet delay
		
		if (shotFired && bulletDelay == 0) {
				bulletDelay = fireDelay; 
				setFired(true);
		}//Fire bullet

		if (isRightDown && (isLeftDown == false)) {
			if (getRect().x > (syswindow.getW() - 100)) {
				rect.x += 0;
			}//stop moving if close to the right border
			else {
				rect.x += 5;
			}//else move right
		}//move right

		if ((isRightDown == false) && isLeftDown) {
			if (getRect().x < 0) {
				rect.x += 0;
			}//if close to left border stop moving
			else {
				rect.x -= 5;
			}//else move left
		}//move left
		
		
	}//action()

	PCSprite::~PCSprite()
	{
	}//~PCSprite()

}//namespace