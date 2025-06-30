#pragma once

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"
#include "Actor.h"

using std::string;
using std::vector;
using std::map;

class UI_TilesMenu : public Actor {
private:
    bool open{ false };
    float mouseScroll = 0;
    float mouseScrollSpeed = 20;
    float mouseScrollMax = 0;

public:

private:
public:
    UI_TilesMenu();
    ~UI_TilesMenu();

    void Update(Vector2* scroll);
    void Draw(Vector2* scroll);
    void Clicked();

    void OpenTilesTab();
};