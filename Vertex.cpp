//
// Created by Mikael on 21/02/2024.
//

#include <valarray>
#include "Vertex.h"

sf::Vector2u Vertex::GetPosition() const {
    return cordinates;
}

float Vertex::GetDistance(Vertex &vertex) const {
    sf::Vector2f positionOwn = rect.getPosition();
    sf::Vector2f positionOther = vertex.rect.getPosition();
    return std::sqrt(positionOwn.x * positionOther.x + positionOwn.y * positionOther.y);
}

void Vertex::Draw(Window *pWindow) {
    pWindow->Draw(rect);
}

Vertex::Vertex(unsigned int size, float x, float y) {
    rect = sf::RectangleShape(sf::Vector2f(size, size));
    rect.setPosition(x * size, y * size);

    cordinates = sf::Vector2u(x, y);
}

void Vertex::Color(sf::Color color) {
    rect.setFillColor(color);
}
