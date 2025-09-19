#include "Levels.h"

map<string, Level*> Level::LevelList;

Level::Level(string name){
	levelID = LevelList.size();
	LevelList[name] = this;
}

void Level::Start() {
	//Init all Actors here
	//Actor* pActor;
	//pActor = Actor::CreateActor("Cursor", 0, new Cursor());
	//LevelActorList[pActor->GetName()] = pActor;
}

void Level::Update() {
	vector<Actor*> actorList = GetAllActorsInLevel();
	for (int i = 0; i < actorList.size(); i++) {
		if (actorList[i]->GetOnDestroyList()) {
			Actor::RemoveActorFromLists(actorList[i]);
		}
		else if (actorList[i]->GetEnabled()) actorList[i]->Update(&scroll);
	}
}

void Level::Draw() {
}

void Level::LoadLevelbyID(int _id){
	int i = 0;
	for(auto level : LevelList){
		if (i == _id) {
			level.second->LoadLevel();
			UnloadLevel();
			return;
		}
		i++;
	}
	std::cout << "ERROR: Level ID could not be found.\n";
}

void Level::LoadLevelbyName(string _name) {
	for (auto const& i : LevelList) {
		if (i.first == _name) {
			i.second->LoadLevel();

			return;
		}
	}
	std::cout << "ERROR: Level Name could not be found.\n";
}

vector<Actor*> Level::GetAllActorsInLevel()
{
	vector<Actor*> ret;
	for (auto const& i : LevelActorList) {
		ret.push_back(const_cast<Actor*>(i.second));
	}
	return ret;
}

void Level::LoadLevel(){
	Start();
}

void Level::UnloadLevel(){
	vector<Actor*> actorList = GetAllActorsInLevel();
	for (int i = 0; i < actorList.size(); i++) {
		actorList[i]->SetOnDestroyList(true);
		LevelActorList.erase(actorList[i]->GetName());
	}
}
