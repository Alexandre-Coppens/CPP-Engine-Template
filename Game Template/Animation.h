#pragma once

#include <string>
#include <vector>
#include <map>
#include "Raylib.h"

using std::string;
using std::vector;
using std::map;

struct Sequence {
    uint8_t length{};
};

struct Animation {
    vector<Sequence> sequences {};
    uint8_t length{};
    Vector2 size{};
};

class AnimationPlayer {
private:
    Animation* animation{};
    uint8_t currentSequence{ 0 };
    uint8_t currentFrame{ 0 };
    int8_t speed{ 24 };
    bool play{ true };

public:

private:
public:
    AnimationPlayer(Animation* animation) {
        this->animation = animation;
    }
    ~AnimationPlayer();

    void inline PlayAnimation() {
        if (!play)return;
        if (currentFrame == animation->sequences[currentSequence].length) currentFrame = 0;
        if (currentFrame < 0) currentFrame = animation->sequences[currentSequence].length - 1;
        currentFrame++;
    }

    Rectangle GetAnimationRect() {
        return Rectangle{ currentFrame * animation->size.x, currentFrame * animation->size.y, animation->size.x, animation->size.y };
    }

    void SetSequence(uint8_t index) {
        currentSequence = index;
    }

    void SetSpeed(int8_t speed) {
        this->speed = speed;
    }

    void Play() {
        play = true;
    }

    void Pause() {
        play = false;
    }
};