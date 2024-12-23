#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize()
{
    position_ = Vector2(640, 100);
    radius_ = 20;
    speed_ = 3;
    velocity_ = Vector2(0, 0);
}

void Enemy::Update()
{
    Move();
}

void Enemy::Draw()
{
    Novice::DrawEllipse(static_cast<int>(position_.x),
                        static_cast<int>(position_.y),
                        static_cast<int>(radius_),
                        static_cast<int>(radius_),
                        0, RED, kFillModeSolid);

    Novice::ScreenPrintf(0, 20, "Enemy HP : %d", hp_);
}

void Enemy::OnCollision()
{
    hp_--;
    if (hp_ <= 0)
        isAlive_ = false;
}

void Enemy::Move()
{
    position_.x += speed_;

    if (position_.x - radius_ < 0)
    {
        position_.x = 0 + radius_;
        speed_ *= -1;
    }
    else if (position_.x + radius_ > 1280)
    {
        position_.x = 1280 - radius_;
        speed_ *= -1;
    }
}
