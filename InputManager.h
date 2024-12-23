#pragma once

#include <input/Input.h>

class InputManager
{
public:
    static InputManager* GetInstance();
    void Update();

    bool isTriggered(int _key)const;
    bool IsPressed(int _key)const;
    bool isReleased(int _key)const;


private:
    char keys_[256] = { 0 };
    char preKeys_[256] = { 0 };

    InputManager() = default;
    ~InputManager() = default;
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
};