#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Game.h"

int main() {

    Game game;

    while(game.IsRunning()) {
        game.GatherInput();
        game.Update();
        game.Draw();
    }
}
