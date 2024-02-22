//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "Window.h"

#ifndef PATH_SIM_VERTEX_H
#define PATH_SIM_VERTEX_H

class Vertex {
public:
    Vertex(unsigned int size, float x, float y, unsigned int id);
    void Draw(Window* pWindow);
    void Color(sf::Color color);
    void MakeWall();
    void ColorPath();
    bool IsWall() const;

    unsigned int GetDistance(Vertex& vertex) const;
    sf::Vector2u GetCoordinate() const;
    unsigned int GetId() const;
private:
    sf::Vector2u coordinate;
    sf::RectangleShape rect;
    unsigned int id;
    bool isWall;
};


#endif //PATH_SIM_VERTEX_H
