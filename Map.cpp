//
// Created by Mikael on 22/02/2024.
//

#include <cmath>
#include "Map.h"

Map::Map(unsigned int width, unsigned int height) {
    tileSize = 10;
    dimensions = sf::Vector2i(width, height);
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; j++) {
            auto pVertex = new Vertex(tileSize, tileSize * i, tileSize * j);
            vertices.push_back(pVertex);
        }
    }
}

void Map::Draw(Window* window) {
    for(auto & vertex : vertices) {
        vertex->Draw(window);
    }
}

Vertex *Map::GetVertexAtPosition(sf::Vector2i position) {
    int x = static_cast <int> (std::floor(position.x / tileSize));
    int y = static_cast <int> (std::floor(position.y / tileSize));

    if(x < 0 || x > dimensions.x || y < 0 || y > dimensions.y) {
        return nullptr;
    }


    return vertices[y + dimensions.y * x];
}
