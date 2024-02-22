//
// Created by Mikael on 21/02/2024.
//

#ifndef PATH_SIM_GAME_H
#define PATH_SIM_GAME_H

#include "Window.h"
#include "Map.h"
#include "Dijkstra.h"
#include "Input.h"

class Game {
public:
    Game();
    void GatherInput();
    void Update();
    void Draw();
    bool IsRunning() const;
private:
    Window window;
    Map map;
    Input input;

    Dijkstra dijkstra;
};


#endif //PATH_SIM_GAME_H
