#include "GameScene.h"
#include "SceneManager.h"
#include <Novice.h>

Vector2 operator-(const Vector2& _vec1, const Vector2& _vec2)
{
    return Vector2(_vec1.x - _vec2.x, _vec1.y - _vec2.y);
}

float Length(const Vector2& _vec)
{
    return sqrtf(_vec.x * _vec.x + _vec.y * _vec.y);
}


std::unique_ptr<IScene> GameScene::Create()
{
    return std::make_unique<GameScene>();
}

void GameScene::Initialize()
{
    pPlayer_ = std::make_unique<Player>();
    pPlayer_->Initialize();

    pEnemy_ = std::make_unique<Enemy>();
    pEnemy_->Initialize();
}

void GameScene::Update()
{
    pPlayer_->Update();
    pEnemy_->Update();

    CheckCollision();

    if(!pEnemy_->IsAlive())
    {
        SceneManager::ReserveScene("GameClear");
    }
}

void GameScene::Draw()
{
    pPlayer_->Draw();
    pEnemy_->Draw();

    Novice::ScreenPrintf(600, 300, "Stage Scene");
}

void GameScene::CheckCollision()
{
    auto& pBullet = pPlayer_->GetBullets();

    for (auto& bullet : pBullet)
    {
        if (!bullet.IsAlive())
        {
            continue;
        }
        Vector2 bulletPos = bullet.GetPosition();
        float bulletRadius = bullet.GetRadius();
        Vector2 enemyPos = pEnemy_->GetPosition();
        float enemyRadius = pEnemy_->GetRadius();
        float distance = Length(bulletPos - enemyPos);
        if (distance < bulletRadius + enemyRadius)
        {
            bullet.OnCollision();
            pEnemy_->OnCollision();
        }
    }

}
