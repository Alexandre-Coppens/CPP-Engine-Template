#include <iostream>
#include "Engine.h"
#include "Terrain.h"
#include "DrawScreen.h"

//Put here all the other includes
#include "ActorIncludes.h"

using std::cout;
using std::to_string;

Terrain terrain;

Engine::Engine() {
}

void Engine::Start(){
	assets = AssetList::GetInstance();
	terrain.tileSize = Vector2{ 50,50 };
	scroll = { GetScreenWidth() * 0.5f ,GetScreenHeight() * 0.5f };

	//Create Objects Here
	Actor::CreateActor("Cursor", 0, new Cursor());
	Actor::CreateActor("UITilesMenu", 0, new UI_TilesMenu());

}

void Engine::Update() {

	vector<Actor*> goList = Actor::GetAllActors();
	for (int i = 0; i < goList.size(); i++) {
		if (goList[i]->needToDestroy) {
			Actor::RemoveActorFromLists(goList[i]);
		}
		else if (goList[i]->enabled) goList[i]->Update(&scroll);
	}
}

void Engine::Draw() {
	BeginDrawing();
	ClearBackground(GREEN);
	DrawScreen(&scroll);
	EndDrawing();
}