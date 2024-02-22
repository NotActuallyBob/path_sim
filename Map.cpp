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
            auto pVertex = new Vertex(tileSize, i, j);
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

std::vector<Vertex *> Map::GetVertices() {
    return vertices;
}

std::vector<Vertex *> Map::GetNeighbors(Vertex vertex) {
    std::vector<Vertex*> neighbors = std::vector<Vertex*>();
    sf::Vector2u cordinate = vertex.GetPosition();
    int x = cordinate.x;
    int y = cordinate.y;

    AddDownNeighbor(cordinate, &neighbors);
    AddUpNeighbor(cordinate, &neighbors);
    AddLeftNeighbor(cordinate, &neighbors);
    AddRightNeighbor(cordinate, &neighbors);
    return neighbors;
}

void Map::AddUpNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.y == 0) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex - 1];
    pNeighbors->push_back(pUpNeighbor);
}

void Map::AddDownNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.y == dimensions.y - 1) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex + 1];
    pNeighbors->push_back(pUpNeighbor);
}

void Map::AddRightNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.x == dimensions.x - 1) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex + dimensions.y];
    pNeighbors->push_back(pUpNeighbor);
}

void Map::AddLeftNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.x == 0) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex - dimensions.y];
    pNeighbors->push_back(pUpNeighbor);
}

int Map::CoordinateToIndex(sf::Vector2u& coordinate) {
    int index = coordinate.y + dimensions.y * coordinate.x;
    return index;
}
