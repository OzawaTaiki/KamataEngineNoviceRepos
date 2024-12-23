#include "SceneManager.h"

#include <cassert>

SceneManager* SceneManager::GetInstance()
{
    static SceneManager instance;
    return &instance;
}

void SceneManager::RegisterScene(std::string _sceneName, CreateFunc _func)
{
    sceneMap_[_sceneName] = _func;
}


void SceneManager::Initialize(std::string _sceneName)
{
    assert(sceneMap_.find(_sceneName) != sceneMap_.end());

    pScene_ = sceneMap_[_sceneName]();
    pScene_->Initialize();

    currentSceneName_ = _sceneName;
    nextSceneName_ = "";
}

void SceneManager::Update()
{
    pScene_->Update();
}

void SceneManager::Draw()
{
    pScene_->Draw();
}

void SceneManager::ReserveScene(std::string _sceneName)
{
    auto instance = GetInstance();
    assert(instance->sceneMap_.find(_sceneName) != instance->sceneMap_.end());
    instance->nextSceneName_ = _sceneName;

}

void SceneManager::ChangeScene()
{
    auto instance = GetInstance();

    if (instance->nextSceneName_ == "" ||
        instance->currentSceneName_ == instance->nextSceneName_)
    {
        return;
    }

    instance->pScene_ = instance->sceneMap_[instance->nextSceneName_]();
    instance->pScene_->Initialize();
    instance->currentSceneName_ = instance->nextSceneName_;
    instance->nextSceneName_ = "";
}
