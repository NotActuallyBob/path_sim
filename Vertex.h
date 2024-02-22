//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "Window.h"

#ifndef PATH_SIM_VERTEX_H
#define PATH_SIM_VERTEX_H

class Vertex {
public:
    Vertex(unsigned int size, float x, float y);
    void Draw(Window* pWindow);
    void Color(sf::Color color);
    float GetDistance(Vertex& vertex) const;
    sf::Vector2u GetPosition() const;
private:
    sf::Vector2u cordinates;
    sf::RectangleShape rect;
};


#endif //PATH_SIM_VERTEX_H
