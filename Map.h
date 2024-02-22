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

    std::vector<Vertex*> GetVertices();
    std::vector<Vertex*> GetNeighbors(Vertex vertex);
    int CoordinateToIndex(sf::Vector2u& coordinate);
private:
    std::vector<Vertex*> vertices;
    unsigned int tileSize;
    sf::Vector2i dimensions;

    void AddUpNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex*>* pNeighbors);

    void AddDownNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors);

    void AddRightNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors);

    void AddLeftNeighbor(sf::Vector2u vertexCoordinate, std::vector<Vertex *> *pNeighbors);
};


#endif //PATH_SIM_MAP_H
