//
// Created by Mikael on 21/02/2024.
//

#include <valarray>
#include "Vertex.h"

sf::Vector2u Vertex::GetCoordinate() const {
    return coordinate;
}

float Vertex::GetDistance(Vertex &vertex) const {
    sf::Vector2f positionOwn = rect.getPosition();
    sf::Vector2f positionOther = vertex.rect.getPosition();
    return std::sqrt(positionOwn.x * positionOther.x + positionOwn.y * positionOther.y);
}

void Vertex::Draw(Window *pWindow) {
    pWindow->Draw(rect);
}

Vertex::Vertex(unsigned int size, float x, float y, unsigned int id)
    :id(id){
    rect = sf::RectangleShape(sf::Vector2f(size, size));
    rect.setPosition(x * size, y * size);

    coordinate = sf::Vector2u(x, y);
}

void Vertex::Color(sf::Color color) {
    rect.setFillColor(color);
}

unsigned int Vertex::GetId() const {
    return id;
}
