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
    Panel(sf::Vector2i size, sf::Vector2i pos, Anchor anchor = Anchor::None, sf::Color backgroundColor = sf::Color(50, 50, 50), sf::Color borderColor = sf::Color(255, 255, 255))
            : size(size), pos(pos), anchor(anchor), backgroundColor(backgroundColor), borderColor(borderColor) {}

    bool active = false;

    void draw(sf::RenderWindow &window);
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H