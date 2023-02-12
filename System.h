//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>

namespace gmeng {

	class System
	{
	public:
		System();
		
		SDL_Renderer* getRen() { return ren; }
		TTF_Font* getFont() { return font; }
		SDL_Window* getWin() { return win; }
		
		int getH() const { return h; }
		int getW() const { return w; }
		
		~System();
	protected:
		
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
	
	private:
		
		int w = 1350;
		int h = 1000;
	};//class

	extern System syswindow;
}//NameSpace
#endif