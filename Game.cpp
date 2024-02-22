//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"

Game::Game()
    : window("Path Simulator"), map(100, 50), dijkstra(map), input(){

}

bool Game::IsRunning() const {
    return window.IsOpen();
}

void Game::Update() {
    if(dijkstra.IsSolving()) {
        dijkstra.IterateCalculation();
        if(dijkstra.IsCalculated()) {
            dijkstra.MarkPath();
        } else {
            return;
        }
    }

    Vertex* pVertexStart = nullptr;
    Vertex* pVertexNewWall = nullptr;
    Vertex* pVertexEnd = nullptr;

    if(input.IsKeyPressed(Input::Key::LeftMouse)) {
        pVertexStart = map.GetVertexAtPosition(window.GetMousePosition());
        dijkstra.InitCalculation();
        if(dijkstra.IsCalculated()) {
            dijkstra.MarkPath();
        }
    }

    if(input.IsKeyPressed(Input::Key::RightMouse)) {
        pVertexEnd = map.GetVertexAtPosition(window.GetMousePosition());
        dijkstra.InitCalculation();
        if(dijkstra.IsCalculated()) {
            dijkstra.MarkPath();
        }
    }

    if(input.IsKeyPressed(Input::Key::MiddleMouse)) {
        pVertexNewWall = map.GetVertexAtPosition(window.GetMousePosition());
    }

    if(pVertexStart != nullptr && !pVertexStart->IsWall()) {
        dijkstra.SetStart(pVertexStart);
        dijkstra.InitCalculation();
    }

    if(pVertexEnd != nullptr && !pVertexEnd->IsWall()) {
        dijkstra.SetEnd(pVertexEnd);
        dijkstra.InitCalculation();
    }

    if(pVertexNewWall != nullptr) {
        pVertexNewWall->MakeWall();
        dijkstra.SetNotCalculated();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        map.Clear();
        dijkstra.Reset();
    }

    if(input.IsKeyUp(Input::Key::MiddleMouse)) {
        dijkstra.InitCalculation();
    }

    window.Update();
}

void Game::Draw() {
    window.BeginDraw();

    map.Draw(&window);

    window.EndDraw();
}

void Game::GatherInput() {
    input.Update();
}
