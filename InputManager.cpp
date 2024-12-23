#include "InputManager.h"
#include <Novice.h>
#include <string>


InputManager* InputManager::GetInstance()
{
    static InputManager instance;
    return &instance;
}

void InputManager::Update()
{
    memcpy(preKeys_, keys_, 256);
    Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::isTriggered(int _key) const
{
    return keys_[_key] && !preKeys_[_key];
}

bool InputManager::IsPressed(int _key) const
{
    return keys_[_key];
}

bool InputManager::isReleased(int _key) const
{
    return !keys_[_key] && preKeys_[_key];
}
