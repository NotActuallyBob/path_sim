//
// Created by Mikael on 21/02/2024.
//

#include "Game.h"

Game::Game()
    : window("Path Simulator"){

}

bool Game::IsRunning() const {
    return window.IsOpen();
}

void Game::Update() {
    window.Update();
}

void Game::Draw() {
    window.BeginDraw();

    //Draw

    window.EndDraw();
}

void Game::GatherInput() {

}
