#ifndef SPRITE_H
#define SPRITE_H
#include "Component.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

namespace gmeng {

	class Sprite : public Component
	{
	public:
		
		static Sprite* getInstance(const int x, int y, int w, int h, const char* p) { return new Sprite(x,y,w,h, p); }
		
		void draw();
		
		void action(std::vector<Component*>*);
		
		void collission(std::vector<Component*>*);
		
		~Sprite();
	protected:
		
		Sprite(int x, int y, int w, int h, const char* p);
	private:
		
		SDL_Texture* texture_sprite;
		SDL_Surface* surface_sprite;
		Sprite(const Sprite&) = delete;//Preventing it from copyg itself 
		const Sprite& operator=(const Sprite&) = delete;//Preventing it from copyg itself 
	};//class

}//NameSpace

#endif