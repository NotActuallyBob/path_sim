//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "Window.h"

#ifndef PATH_SIM_VERTEX_H
#define PATH_SIM_VERTEX_H

class Vertex {
public:
    Vertex(unsigned int sizeValue, unsigned int x, unsigned int y, unsigned int id);
    void Draw(Window* pWindow);
    void setColor(sf::Color color);
    void MakeWall();
    void ColorPath();
    bool IsWall() const;

    unsigned int GetDistance(Vertex& vertex) const;
    sf::Vector2u GetCoordinate() const;
    unsigned int GetId() const;
private:
    sf::Vector2u position;
    sf::Vector2u size;
    unsigned int const id;
    sf::RectangleShape rect;
    bool isWall;
};


#endif //PATH_SIM_VERTEX_H
