//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#include "Bullet.h"


namespace gmeng {
	Bullet::Bullet(const int x, const char* p) :Sprite(x + 40, 870, 20, 20, p)
	{
		setBullet(true);
	}//Bullet()

	void Bullet::action(std::vector<Component*>* sprite) {
		rect.y -= bulletSpeed;
		if (rect.y < -bulletSpeed) {
			setClearUp(true);
		}		
	}//action()
	
	
	Bullet::~Bullet()
	{
	}//~~bullet()
	
}//NameSpace