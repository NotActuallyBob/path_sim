//
// Created by Mikael on 21/02/2024.
//

#include <valarray>
#include "Vertex.h"

sf::Vector2u Vertex::GetCoordinate() const {
    return position;
}

unsigned int Vertex::GetDistance(Vertex &vertex) const {
    int diff = position.x - vertex.position.x + position.y - vertex.position.y;
    if(diff < 0) {
        return -1 * diff;
    }
    return diff;
}

void Vertex::Draw(Window *pWindow) {
    pWindow->Draw(rect);
}

Vertex::Vertex(unsigned int sizeValue, unsigned int x, unsigned int y, unsigned int id)
    : id(id), position(sf::Vector2u(x, y)), size(sf::Vector2u(sizeValue, sizeValue)) {
    rect = sf::RectangleShape();

    rect.setPosition(sf::Vector2f(position.x * size.x, position.y * size.y));
    rect.setSize(sf::Vector2f(size.x, size.y));
    isWall = false;
}

void Vertex::setColor(sf::Color color) {
    rect.setFillColor(color);
}

unsigned int Vertex::GetId() const {
    return id;
}

void Vertex::MakeWall() {
    isWall = true;
    setColor(sf::Color::Black);
}

bool Vertex::IsWall() const {
    return isWall;
}

void Vertex::ColorPath() {
    if(rect.getFillColor() != sf::Color::Green && rect.getFillColor() != sf::Color::Red) {
        setColor(sf::Color::Yellow);
    }
}
