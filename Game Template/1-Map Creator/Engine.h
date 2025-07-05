#pragma once

#include "raylib.h"

#include <string>
#include <vector>
#include "AssetList.h"

using std::string;
using std::vector;

class Engine {
private:
	AssetList* assets{};
	Vector2 scroll{};
	
private:
	//Set this function in DrawScreen
    //void CheckIfOutOfBound();

public:
	Engine();
	void Start();
	void Update();
	void Draw();
};
