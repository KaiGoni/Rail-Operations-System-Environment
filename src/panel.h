#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H

#include <SFML/Graphics.hpp>

enum class Anchor {
    TopLeft,
    TopCenter,
    TopRight,
    Left,
    Center,
    Right,
    BottomLeft,
    BottomCenter,
    BottomRight,
    None
};

class Panel {
private:
    sf::Vector2f size;
    sf::Vector2f pos; // This also defines offset from anchor
    Anchor anchor;
    sf::Color backgroundColor;
    sf::Color borderColor;
public:
    Panel(sf::Vector2f size, sf::Vector2f pos, Anchor anchor = Anchor::None,
            sf::Color backgroundColor = sf::Color(50, 50, 50), sf::Color borderColor = sf::Color(255, 255, 255))
            : size(size), pos(pos), anchor(anchor), backgroundColor(backgroundColor), borderColor(borderColor) {}

    void draw(sf::RenderWindow &window);
    void setPos(sf::Vector2f pos, sf::Vector2f size);
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H