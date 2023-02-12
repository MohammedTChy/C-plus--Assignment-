//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#ifndef BULLET_H
#define BULLET_H
#include "Sprite.h"

namespace gmeng {
	class Bullet : public Sprite
	{
	public:
		
		static Bullet* getInstance(const int x,  const char* p) { return new Bullet(x, p); }
		
		void action(std::vector<Component*>*);
		
		~Bullet();
	protected:
		Bullet(const int x,  const char* p);

	private:
		
		int bulletSpeed = 5;
		Bullet(const Bullet&) = delete;//Preventing it from copyg itself 
		const Bullet& operator=(const Bullet&) = delete;//Preventing it from copyg itself 
	};//class
}//Namspace
#endif