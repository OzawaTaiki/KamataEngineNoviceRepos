#include "TitleScene.h"
#include "SceneManager.h"
#include "InputManager.h"
#include <Novice.h>

std::unique_ptr<IScene> TitleScene::Create()
{
    return std::make_unique<TitleScene>();
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
    if (InputManager::GetInstance()->isTriggered(DIK_SPACE))
        SceneManager::ReserveScene("Game");
}

void TitleScene::Draw()
{
    Novice::ScreenPrintf(600, 300, "Title Scene");
    Novice::ScreenPrintf(600, 320, "Press Space Key");
}
