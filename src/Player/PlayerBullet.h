#pragma once

#include <math/Vector2.h>

using namespace KamataEngine;

class Bullet
{
public:
    Bullet() = default;
    ~Bullet() = default;
    void Initialize(const Vector2& _pos, const Vector2& velocity_);
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

    bool isAlive_ = false;

};

