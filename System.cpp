#include "System.h"
#include <iostream>
#include <SDL.h>

using namespace std;

namespace gmeng {

	System syswindow;
	
	System::System()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Grupp 77, Mohammed Tahmid Chowdhury", 350, 30, w, h, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/Arial.ttf", 24);
		
	}//system()


	System::~System()
	{
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_Quit();
		
	}//~~System()

	
}