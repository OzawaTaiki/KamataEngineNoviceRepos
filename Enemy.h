#pragma once

#include "InputManager.h"

#include <math/Vector2.h>
#include <memory>

using namespace KamataEngine;

class Enemy
{
public:
    Enemy() = default;
    ~Enemy() = default;
    void Initialize();
    void Update();
    void Draw();

    void OnCollision();

    bool IsAlive() const { return isAlive_; }
    Vector2 GetPosition() const { return position_; }
    float GetRadius() const { return radius_; }

private:

    void Move();

    Vector2 position_;
    float radius_;
    Vector2 velocity_;
    float speed_;

    int hp_ = 3;

    bool isAlive_ = true;
};
 