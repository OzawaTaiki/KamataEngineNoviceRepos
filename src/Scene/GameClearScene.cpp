#include "GameClearScene.h"
#include "SceneManager.h"
#include "../Input/InputManager.h"
#include <Novice.h>

std::unique_ptr<IScene> GameClearScene::Create()
{
    return std::make_unique<GameClearScene>();
}

void GameClearScene::Initialize()
{
}

void GameClearScene::Update()
{
    if (InputManager::GetInstance()->isTriggered(DIK_SPACE))
        SceneManager::ReserveScene("Title");
}

void GameClearScene::Draw()
{
    Novice::ScreenPrintf(600, 300, "Game Clear");
    Novice::ScreenPrintf(600, 320, "Press Space Key");
}
