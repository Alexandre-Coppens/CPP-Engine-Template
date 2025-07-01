#pragma once

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"
#include "Actor.h"

using std::string;
using std::vector;
using std::map;

class Cursor : public Actor{
private:
    Vector2 scrollSpeed{ 150, 150 };
    string currentTextureName = "";

public:

private:
public:
    Cursor();
    ~Cursor();

    void Update(Vector2* scroll);
    void Draw(Vector2* scroll);
};