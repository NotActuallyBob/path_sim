//
// Created by Mikael on 21/02/2024.
//

#include <valarray>
#include "Vertex.h"

sf::Vector2f Vertex::GetPosition() const {
    return rect.getPosition();
}

float Vertex::GetDistance(Vertex &vertex) const {
    sf::Vector2f positionOwn = rect.getPosition();
    sf::Vector2f positionOther = vertex.rect.getPosition();
    return std::sqrt(positionOwn.x * positionOther.x + positionOwn.y * positionOther.y);
}

void Vertex::Draw(Window *pWindow) {
    pWindow->Draw(rect);
}
