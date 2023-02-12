//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#include <SDL.h>
#include "System.h"
#include <iostream>
#include "Bullet.h"
#include "GameEngine.h"
using namespace std;


namespace gmeng {
	

	void GameEngine::addToGame(Component* sprite) {
		comps.push_back(sprite);
	}//addTogGame()
	
	
	void GameEngine::run() {
		
		while (!quit) {
			nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT: 
					setQuit(true);
					break;
				case SDL_KEYDOWN:
					for (Component* sprite : comps)
						sprite->keyAction(eve);
					break;
				case SDL_KEYUP:
					for (Component* sprite : comps)
						sprite->keyAction(eve);
					break;
				
				}//switch
			}//while eve action

			
			SDL_SetRenderDrawColor(syswindow.getRen(), 255, 255, 255, 0); // background
			SDL_RenderClear(syswindow.getRen()); //clear it
			
			for (Component* sprite : comps) {
				sprite->draw();
			}//for over comp to draw everything 


			
			
			
			for (Component* sprite : comps) {
				sprite->action(&comps);
				if (sprite->getShoot() == true) {
					Bullet* bullet = Bullet::getInstance(sprite->getRect().x , "Bilder/bullet.bmp");
					bulletspawn.push_back(bullet); //this was needed if I wanted to create and do action with the bullet at the same time save it somewhere to be cleared later on for a temp hold
				}	//check if comp now is a bullet if it's set on fire, then create it and shoot					
				
			}//for over comp to see if any of the comps has a action event to handle
			
			
			for (Component* sprite : bulletspawn) {
				addToGame(sprite);
			}//take everything in bulletspawn and add it to comps
			
			bulletspawn.clear(); //clear bulletspawn after everything been added to comps

			
			SDL_RenderPresent(syswindow.getRen());

					
			
			
			for (std::vector<Component*>::iterator it = comps.begin(); it != comps.end(); ++it) {
				if ((*it)->getClearUp()) {
					Component* temp = *it;
					remove.push_back(temp);
					delete temp;
				}//if it's clear up true

			}//for iteration over comp



			for (Component* sprite : remove) {
				for (vector<Component*>::iterator i = comps.begin();
					i != comps.end();)
					if (*i == sprite) {
						i = comps.erase(i);
					}//if remove has the same as comp
					else
						i++;
			}//for over remove to erase from comp

			remove.clear();//clear remove after it's done with what remove and comp has incommon
			
			delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}//Delay in the window 
			
		}//while
	}//run

	
	GameEngine ::~GameEngine()
	{
		
		
		for (Component* sprite : comps) {
			delete sprite;
		}//delte comps elements

		for (Component* sprite : bulletspawn) {
			delete sprite;
		}//delete bulletspawn elemetns if it's any been left 

		for (Component* sprite : remove) {
			delete sprite;
		}//delete remove elements if it's any left
		
		

	}//~GameEngine

}//nameSpace