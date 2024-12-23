#pragma once

#include "IScene.h"

#include <memory>

class TitleScene : public IScene
{
public:
    static std::unique_ptr<IScene> Create();
    void Initialize() override;
    void Update() override;
    void Draw() override;

private:
};