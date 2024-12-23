#pragma once

#include "../Input/InputManager.h"
#include <math/Vector2.h>

#include "PlayerBullet.h"
#include <array>

using namespace KamataEngine;

class Player
{
public:
    Player() = default;
    ~Player() = default;

    void Initialize();
    void Update();
    void Draw();

    std::array<Bullet, 5>& GetBullets() { return bullets_; }

private:

    void Move();

    std::array<Bullet, 5> bullets_;

    InputManager* pInputManager_;

    Vector2 position_;
    float radius_;

    Vector2 velocity_;
    float speed_;



};