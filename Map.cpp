//
// Created by Mikael on 22/02/2024.
//

#include <cmath>
#include "Map.h"

Map::Map(unsigned int width, unsigned int height) {
    tileSize = 10;
    dimensions = sf::Vector2i(width, height);
    for(unsigned int i = 0; i < width; ++i) {
        for(unsigned int j = 0; j < height; j++) {
            sf::Vector2u coordinate = sf::Vector2u(i, j);
            auto pVertex = new Vertex(tileSize, i, j, CoordinateToIndex(coordinate));
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

std::vector<Vertex *> Map::GetNeighbors(Vertex* vertex) {
    std::vector<Vertex*> neighbors = std::vector<Vertex*>();
    sf::Vector2u coordinate = vertex->GetCoordinate();

    AddDownNeighbor(coordinate, &neighbors);
    AddUpNeighbor(coordinate, &neighbors);
    AddLeftNeighbor(coordinate, &neighbors);
    AddRightNeighbor(coordinate, &neighbors);
    return neighbors;
}

void Map::AddUpNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.y == 0) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex - 1];
    if(pUpNeighbor->IsWall()) {
        return;
    }
    pNeighbors->push_back(pUpNeighbor);
}

void Map::AddDownNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.y == dimensions.y - 1) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex + 1];
    if(pUpNeighbor->IsWall()) {
        return;
    }
    pNeighbors->push_back(pUpNeighbor);
}

void Map::AddRightNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.x == dimensions.x - 1) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex + dimensions.y];
    if(pUpNeighbor->IsWall()) {
        return;
    }
    pNeighbors->push_back(pUpNeighbor);
}

void Map::AddLeftNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors) {
    if(vertexCoordinate.x == 0) {
        return;
    }

    int vertexIndex = CoordinateToIndex(vertexCoordinate);
    Vertex* pUpNeighbor = vertices[vertexIndex - dimensions.y];
    if(pUpNeighbor->IsWall()) {
        return;
    }
    pNeighbors->push_back(pUpNeighbor);
}

unsigned int Map::CoordinateToIndex(sf::Vector2u& coordinate) const {
    int index = coordinate.y + dimensions.y * coordinate.x;
    return index;
}

Vertex *Map::GetById(int id) {
    for(Vertex* vertex : vertices) {
        if(vertex->GetId() == id) {
            return vertex;
        }
    }
}

void Map::Clear() {
    for(auto it : vertices) {
        if(!it->IsWall()) {
            it->Color(sf::Color::White);
        }
    }
}
