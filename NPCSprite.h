//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#ifndef NPCSPRITE_H
#define NPCSPRITE_H
#include "Sprite.h"
#include "System.h"
namespace gmeng {
	class NPCSprite : public Sprite {
	public:
		
		
		static NPCSprite* getInstance(const int x, int y, int w, int h, const char* p) {return new NPCSprite(x, y, w, h, p);}
		
		void setMotion(int i) {motion = i;}
		
		int getMotion() const { return motion;}
	    
		void PathAction();
		
		~NPCSprite();


protected:
		
	NPCSprite(const int x, int y, int w, int h, const char* p);
		

private:
	
	int motion = 5;
	NPCSprite(const NPCSprite&) = delete;
	const NPCSprite& operator=(const NPCSprite&) = delete;

		
	};// class

	

}//namespace
#endif
