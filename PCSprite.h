//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#ifndef PCSPRITE_H
#define PCSPRITE_H

#include "Sprite.h"
#include"System.h"
#include "Bullet.h"


namespace gmeng {

	
	class PCSprite : public Sprite
	{
	public:
		
		static PCSprite* getInstance( const char* p) { return new PCSprite( p); }
		int getYPC() const { return y; }
		int getWPC() const { return w; }
		int getHPC() const { return h; }
		
		void keyAction(const SDL_Event&);
		
		void action(std::vector<Component*>*);
		
		~PCSprite();
	protected:
		PCSprite(const char* p);
		
	private:
		int y = 800;
		int w = 100;
		int h = 100;
		bool shotFired = false;
		bool isRightDown = false;
		bool isLeftDown = false;
 		int bulletDelay = 0;
	    int fireDelay = 30;
		PCSprite(const PCSprite&) = delete;//Preventing it from copyg itself 
		const PCSprite& operator=(const PCSprite&) = delete;//Preventing it from copyg itself 
	};//class

}//NameSpace

#endif