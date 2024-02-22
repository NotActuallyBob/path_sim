//
// Created by Mikael on 20/02/2024.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Input.h"

void Input::Update()
{
    lastFrameKeys = currentFrameKeys; // 1
    currentFrameKeys = 0;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        currentFrameKeys = currentFrameKeys | 1 << (int)Key::LeftMouse;
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
        currentFrameKeys = currentFrameKeys | 1 << (int)Key::MiddleMosue;
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        currentFrameKeys = currentFrameKeys | 1 << (int)Key::RightMouse;
    }
}

bool Input::IsKeyPressed(Key keycode)
{
    return (currentFrameKeys && 1 << (int)keycode > 0);
}

bool Input::IsKeyDown(Key keycode)
{
    bool lastFrame = (lastFrameKeys && 1 << (int)keycode > 0);
    bool thisFrame = (currentFrameKeys && 1 << (int)keycode > 0);

    return thisFrame && !lastFrame;
}

bool Input::IsKeyUp(Key keycode)
{
    bool lastFrame = (lastFrameKeys && 1 << (int)keycode > 0);
    bool thisFrame = (currentFrameKeys && 1 << (int)keycode > 0);

    return !thisFrame && lastFrame;
}