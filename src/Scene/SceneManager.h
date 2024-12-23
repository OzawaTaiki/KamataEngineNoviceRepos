#pragma once

#include "IScene.h"

#include <memory>
#include <string>
#include <map>

using CreateFunc = std::unique_ptr<IScene>(*)();

class SceneManager
{
public:

    static SceneManager* GetInstance();

    void RegisterScene(std::string _sceneName, CreateFunc _func);

    void Initialize(std::string _sceneName);
    void Update();
    void Draw();

    static void ReserveScene(std::string _sceneName);
    void ChangeScene();

private:
    std::map<std::string, CreateFunc> sceneMap_;

    std::unique_ptr<IScene> pScene_ = nullptr;

    std::string currentSceneName_;
    std::string nextSceneName_;

    SceneManager() = default;
    ~SceneManager() = default;
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

};
