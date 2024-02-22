#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Game.h"
#include "Vertex.h"

int main() {

    Game game;

    while(game.IsRunning()) {
        game.GatherInput();
        game.Update();
        game.Draw();
    }
}
