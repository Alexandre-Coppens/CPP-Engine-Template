#pragma once

#include "raylib.h"

#include <string>
#include <vector>
#include "AssetsList.h"

using std::string;
using std::vector;

class Engine {
private:
	AssetList* assets{};
	Vector2 scroll{};
	
private:
    void CheckIfOutOfBound();

public:
	Engine();
	void Start();
	void Update();
	void Draw();
};
