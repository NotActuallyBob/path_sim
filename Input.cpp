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
        currentFrameKeys = currentFrameKeys | (1 << (int)Key::LeftMouse);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
        currentFrameKeys = currentFrameKeys | (1 << (int)Key::MiddleMouse);
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        currentFrameKeys = currentFrameKeys | (1 << (int)Key::RightMouse);
    }
}

bool Input::IsKeyPressed(Key keycode) const
{
    bool isPressed = (((currentFrameKeys & (1 << (int)keycode)) > 0));
    return isPressed;
}

bool Input::IsKeyDown(Key keycode) const
{
    bool lastFrame = (((lastFrameKeys & (1 << (int)keycode)) > 0));
    bool thisFrame = (((currentFrameKeys & (1 << (int)keycode)) > 0));

    return thisFrame && !lastFrame;
}

bool Input::IsKeyUp(Key keycode) const
{
    bool lastFrame = (((lastFrameKeys & (1 << (int)keycode)) > 0));
    bool thisFrame = (((currentFrameKeys & (1 << (int)keycode)) > 0));

    return !thisFrame && lastFrame;
}

Input::Input() {
    currentFrameKeys = 0;
    lastFrameKeys = 0;
}
