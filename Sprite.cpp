//Mohammed Tahmid Chowdhury moch8386
//Grupp 77
#include "Sprite.h"
#include <SDL_image.h>
#include "System.h"
#include <iostream>
#include <string>
using namespace std;
namespace gmeng {
	Sprite::Sprite(int x, int y, int w, int h, const char* p) : Component(x,  y, w,  h)
	{
		surface_sprite = IMG_Load(p);
		if (surface_sprite == nullptr) {
			throw invalid_argument("fanns ingen bild där");
		}
		
		texture_sprite = SDL_CreateTextureFromSurface(syswindow.getRen(), surface_sprite);
		SDL_FreeSurface(surface_sprite);

		

	}//Sprite()
	
	
	void Sprite::draw() {
		
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(syswindow.getRen(), texture_sprite, NULL, &rect);
		
	}//draw()

	void Sprite::action(std::vector<Component*>* sprite) {
		PathAction();
		collission(sprite);
	}//action()


	void Sprite::collission(std::vector<Component*>* sprite) {
		const SDL_Rect& rect = getRect();
		const SDL_Rect* tempRect = &rect;
		for (Component* bullet : *sprite) {
			if ((bullet->getBullet() == true) && (getNPC() == true)) {
				const SDL_Rect& rectC = bullet->getRect();
				const SDL_Rect* temprectC = &rectC;
				if (SDL_HasIntersection(tempRect, temprectC) == SDL_TRUE) {

					if ((bullet->getBullet())) {
						bullet->setClearUp(true);
						setClearUp(true);

					}//if bullet, extra check, probably unnecessary, but set to clear them up true for both the object and the bullet 

				}//check if the the npc and bullet is contacted on that postion 
				

			}//check if the object is bullet and the that was attacked is npc 

		}//for to loop over
		
	}//collision()		
						
				
			



	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture_sprite);

	}//~sprite()

}//NameSpace