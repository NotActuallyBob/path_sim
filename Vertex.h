//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "Window.h"

#ifndef PATH_SIM_VERTEX_H
#define PATH_SIM_VERTEX_H

class Vertex {
public:
    void Draw(Window* pWindow);
    float GetDistance(Vertex& vertex) const;
    sf::Vector2f GetPosition() const;
private:
    sf::RectangleShape rect;
};


#endif //PATH_SIM_VERTEX_H
