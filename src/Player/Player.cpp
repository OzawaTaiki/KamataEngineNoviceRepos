#include "Player.h"

#include "../Input/InputManager.h"
#include <Novice.h>

void Player::Initialize()
{
    pInputManager_ = InputManager::GetInstance();
    position_ = Vector2(640, 360);
    radius_ = 10;
    velocity_ = Vector2(0, 0);
    speed_ = 5;
}

void Player::Update()
{
    Move();

    if (pInputManager_->isTriggered(DIK_SPACE))
    {
        for (auto& bullet : bullets_)
        {
            if (!bullet.IsAlive())
            {
                bullet.Initialize(position_, Vector2(0, -10));
                break;
            }
        }
    }

    for (auto& bullet : bullets_)
    {
        bullet.Update();
    }


}

void Player::Draw()
{
    for (auto& bullet : bullets_)
    {
        bullet.Draw();
    }

    Novice::DrawEllipse(static_cast<int>(position_.x),
                        static_cast<int>(position_.y),
                        static_cast<int>(radius_),
                        static_cast<int>(radius_),
                        0, WHITE, kFillModeSolid);

    Novice::ScreenPrintf(0, 0, "Move :WASD Shot:Space");
}

void Player::Move()
{
    if (pInputManager_->IsPressed(DIK_A))
    {
        position_.x -= speed_;
    }
    if (pInputManager_->IsPressed(DIK_D))
    {
        position_.x += speed_;
    }
    if (pInputManager_->IsPressed(DIK_W))
    {
        position_.y -= speed_;
    }
    if (pInputManager_->IsPressed(DIK_S))
    {
        position_.y += speed_;
    }

    // クランプ
    if (position_.x < 0)
    {
        position_.x = 0;
    }
    if (position_.x > 1280)
    {
        position_.x = 1280;
    }
    if (position_.y < 0)
    {
        position_.y = 0;
    }
    if (position_.y > 720)
    {
        position_.y = 720;
    }
}
