//
// Created by Mikael on 21/02/2024.
//

#include <valarray>
#include "Vertex.h"

sf::Vector2u Vertex::GetCoordinate() const {
    return coordinate;
}

unsigned int Vertex::GetDistance(Vertex &vertex) const {
    int diff = coordinate.x - vertex.coordinate.x + coordinate.y - vertex.coordinate.y;
    if(diff < 0) {
        return -1 * diff;
    }
    return diff;
}

void Vertex::Draw(Window *pWindow) {
    pWindow->Draw(rect);
}

Vertex::Vertex(unsigned int size, float x, float y, unsigned int id)
    :id(id){
    rect = sf::RectangleShape(sf::Vector2f(size, size));
    rect.setPosition(x * size, y * size);

    coordinate = sf::Vector2u(x, y);
    isWall = false;
}

void Vertex::Color(sf::Color color) {
    rect.setFillColor(color);
}

unsigned int Vertex::GetId() const {
    return id;
}

void Vertex::MakeWall() {
    isWall = true;
    Color(sf::Color::Black);
}

bool Vertex::IsWall() const {
    return isWall;
}

void Vertex::ColorPath() {
    if(rect.getFillColor() != sf::Color::Green && rect.getFillColor() != sf::Color::Red) {
        Color(sf::Color::Yellow);
    }
}
