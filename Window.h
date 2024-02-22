//
// Created by Mikael on 21/02/2024.
//

#ifndef PATH_SIM_WINDOW_H
#define PATH_SIM_WINDOW_H


#include <SFML/Graphics/RenderWindow.hpp>

class Window {
public:
    Window(const std::string& windowName);
    void Update();
    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();
    bool IsOpen() const;
    sf::Vector2i GetMousePosition();
private:
    sf::RenderWindow renderWindow;
};


#endif //PATH_SIM_WINDOW_H
