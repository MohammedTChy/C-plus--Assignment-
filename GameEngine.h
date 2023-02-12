//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#ifndef SESSION_H
#define SESSION_H
#include "Component.h"
#include <vector>

#define FPS 60

namespace gmeng {

	class GameEngine
	{
	public:
		
		void addToGame(Component*);
		void run();
		void setQuit(bool x) { quit = x;}
		
		~GameEngine();
	
	private:
		
		bool quit = false;
		std::vector<Component*> comps;
		std::vector<Component*> bulletspawn;
		std::vector<Component*> remove;
		int delay;
		const int tickInterval = 1000/FPS;
		Uint32 nextTick;
	};//class

}//NameSpace
#endif