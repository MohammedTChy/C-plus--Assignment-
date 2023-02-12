//Mohammed Tahmid Chowdhury Moch8386
//Grupp 77


#include <crtdbg.h>
#include "System.h"
#include <SDL.h>
#include <iostream>
#include "GameEngine.h"
#include "Sprite.h"
#include "NPCSprite.h"
#include "PCSprite.h"


using namespace gmeng;
using namespace std;


int main(int argc, char** argv) {

	
	GameEngine  ge;
	
	PCSprite* pcs = PCSprite::getInstance( "Bilder/spaceship.bmp");
	
	
	
	NPCSprite* NPC1 = NPCSprite::getInstance( 600,200, 80, 80, "Bilder/enemy.bmp");
	NPCSprite* NPC2 = NPCSprite::getInstance( 800,500,80, 80, "Bilder/enemy.bmp");
	NPCSprite* NPC3 = NPCSprite::getInstance(200, 450, 80, 80, "Bilder/enemy.bmp");
	NPCSprite* NPC4 = NPCSprite::getInstance(400, 550, 80, 80, "Bilder/enemy.bmp");
	NPCSprite* NPC5 = NPCSprite::getInstance(300, 600, 80, 80, "Bilder/enemy.bmp");

	
	ge.addToGame(pcs);
	
	ge.addToGame(NPC1);
	ge.addToGame(NPC2);
	ge.addToGame(NPC3);
	ge.addToGame(NPC4);
	ge.addToGame(NPC5);

	
	
	ge.run();
	
	return 0;
}//Main