//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"

Game::Game()
    : window("Path Simulator"), map(100, 50), dijkstra(map){

}

bool Game::IsRunning() const {
    return window.IsOpen();
}

void Game::Update() {
    Vertex* pVertexStart = nullptr;
    Vertex* pVertexNewWall = nullptr;
    Vertex* pVertexEnd = nullptr;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        pVertexStart = map.GetVertexAtPosition(window.GetMousePosition());
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        pVertexEnd = map.GetVertexAtPosition(window.GetMousePosition());
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
        pVertexNewWall = map.GetVertexAtPosition(window.GetMousePosition());
    }

    if(pVertexStart != nullptr) {
        dijkstra.SetStart(pVertexStart);
        dijkstra.MarkPath();
    }
    if(pVertexEnd != nullptr) {
        dijkstra.SetEnd(pVertexEnd);
        dijkstra.MarkPath();
    }
    if(pVertexNewWall != nullptr) {
        pVertexNewWall->MakeWall();
        dijkstra.CalculatePath();
        dijkstra.MarkPath();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        dijkstra.CalculatePath();
        dijkstra.MarkPath();
    }

    window.Update();
}

void Game::Draw() {
    window.BeginDraw();

    map.Draw(&window);

    window.EndDraw();
}

void Game::GatherInput() {

}
