#include "Levels.h"

map<int, Level*> Level::LevelList;
uint8_t Level::currentLevel;

Level::Level(string _name){
	levelID = LevelList.size();
	LevelList[levelID] = this;
	name = _name;
}

void Level::Start() {
	//Init all Actors here
	//Actor* pActor;
	//pActor = Actor::CreateActor("Cursor", 0, new Cursor());
	//LevelActorList[pActor->GetName()] = pActor;
}

void Level::LoadLevelbyID(int _id){
	if (LevelList.find(_id) != LevelList.end()) {
		LevelList[_id]->LoadLevel();
		UnloadLevel();
		return;
	}
	std::cout << "ERROR: Level ID could not be found.\n";
}

void Level::LoadLevelbyName(string _name) {
	for (auto const& i : LevelList) {
		if (i.second->name == _name) {
			i.second->LoadLevel();

			return;
		}
	}
	std::cout << "ERROR: Level Name could not be found.\n";
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
	cout << "Level Actors left: " << LevelActorList.size() << "\n";
}


vector<Actor*> Level::GetAllActorsInLevel()
{
	vector<Actor*> ret;
	for (auto const& i : LevelActorList) {
		ret.push_back(const_cast<Actor*>(i.second));
	}
	return ret;
}