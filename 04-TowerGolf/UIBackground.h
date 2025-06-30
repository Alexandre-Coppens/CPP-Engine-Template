#pragma once

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"
#include "Actor.h"

using std::string;
using std::vector;
using std::map;

class UIBackground : public Actor {
private:
public:

private:
public:
    UIBackground();
    ~UIBackground();

    void Start();
    void Update(Vector2* scroll);
    void Draw(Vector2* scroll);
};