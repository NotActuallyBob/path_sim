//
// Created by Mikael on 22/02/2024.
//

#ifndef PATH_SIM_MAP_H
#define PATH_SIM_MAP_H


#include "Vertex.h"

class Map {
public:
    Map(unsigned int width, unsigned int height);
    Vertex* GetVertexAtPosition(sf::Vector2i position);
    void Draw(Window* window);
private:
    std::vector<Vertex*> vertices;
    unsigned int tileSize;
    sf::Vector2i dimensions;
};


#endif //PATH_SIM_MAP_H
