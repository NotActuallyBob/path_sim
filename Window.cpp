//
// Created by Mikael on 21/02/2024.
//

#include <SFML/Window/Event.hpp>
#include "Window.h"

Window::Window(const std::string& windowName)
        :renderWindow(sf::VideoMode(1200, 900), windowName, sf::Style::Close){
    renderWindow.setFramerateLimit(144);
}


void Window::Draw(const sf::Drawable &drawable) {
    renderWindow.draw(drawable);
}

bool Window::IsOpen() const {
    return renderWindow.isOpen();
}

void Window::Update() {
    sf::Event event;

    while(renderWindow.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            renderWindow.close();
        }
    }
}

void Window::BeginDraw() {
    renderWindow.clear(sf::Color::Black);
}

void Window::EndDraw() {
    renderWindow.display();
}

sf::Vector2i Window::GetMousePosition() {
    return sf::Mouse::getPosition(renderWindow);
}
