#include "PlayerBullet.h"

#include <Novice.h>

void Bullet::Initialize(const Vector2& _pos, const Vector2& _velocity)
{
    position_ = _pos;
    radius_ = 5;
    velocity_ = _velocity;

    isAlive_ = true;
}

void Bullet::Update()
{
    Move();
}

void Bullet::Draw()
{
    if (isAlive_)
    Novice::DrawEllipse(static_cast<int>(position_.x),
                        static_cast<int>(position_.y),
                        static_cast<int>(radius_),
                        static_cast<int>(radius_),
                        0, WHITE, kFillModeSolid);
}

void Bullet::OnCollision()
{
    isAlive_ = false;
}

void Bullet::Move()
{
    position_.y += velocity_.y;
    if (position_.y < -10)
    {
        isAlive_ = false;
    }
}
