//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77
#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <vector>
#include <SDL_image.h>
namespace gmeng {

	class Component
	{
	public:
		virtual void draw() = 0;
	    SDL_Rect getRect() const { return rect; }
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		virtual void keyAction(const SDL_Event&) {}
		
		void setNPC(bool x) { isNPC = x; }
		void setBullet(bool x) { isBullet = x; }
		void setClearUp(bool x) { clearup = x; }
	    void setFired(bool x) { fired = x; }
		
		 bool getClearUp() const { return clearup; }
		 bool getShoot() const { return fired; }
		 bool getNPC() const { return isNPC; }
		 bool getBullet() const { return isBullet; }
		
		virtual void action(std::vector<Component*>*) {}
		virtual void PathAction() {}
		
		virtual ~Component();
	protected:
		Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
		SDL_Rect rect;
	private:
		
		bool clearup = false;
		bool fired = false;
		bool isNPC = false;
		bool isBullet = false;
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
	};
}
#endif