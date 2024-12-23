#pragma once

#include "IScene.h"

#include "Player.h"
#include "Enemy.h"
#include <memory>

class GameScene : public IScene
{
public:

    static std::unique_ptr<IScene> Create();

    void Initialize() override;
    void Update() override;
    void Draw() override;

private:

    void CheckCollision();

    std::unique_ptr<Player> pPlayer_ = nullptr;
    std::unique_ptr<Enemy> pEnemy_ = nullptr;


};
