#ifndef LEVELS_H
#define LEVELS_H

#include "Raylib.h"
#include "Actor.h"
#include "DrawScreen.h"
#include <iostream>

using std::string;
using std::vector;
using std::map;
using std::cout;

class Level {
private:
    Vector2 scroll{ 0,0 };
    map<string, Actor*> LevelActorList;
    string name;
    uint8_t levelID{};

protected:
    string GetName() { return name; }
    uint8_t GetID() { return levelID; }

    void AddNewActorToList(Actor* _actor) { LevelActorList[_actor->GetName()] = _actor; }

public:
    static map<int, Level*> LevelList;
    static uint8_t currentLevel;


private:
    void LoadLevel();
    void UnloadLevel();

protected:
public:
    Level(string _name);

    virtual void Start();

    //Unload this level and load the ID one
    void LoadLevelbyID(int id);
    void LoadLevelbyName(string name);

    vector<Actor*> GetAllActorsInLevel();
};

#endif