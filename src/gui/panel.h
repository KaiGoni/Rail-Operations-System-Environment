#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H

#include <SFML/Graphics.hpp>
#include "elements.h"

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
    sf::Vector2f panelPos; // Actual pos of the panel
    Anchor anchor;
    sf::Color backgroundColor;
    sf::Color borderColor;
    Layout layout;
    Element *selected;
    int elementWidth;
    std::vector<Element *> elements;
public:
    Panel(sf::Vector2f size, sf::Vector2f pos, Anchor anchor = Anchor::None, Layout layout = Layout::Vertical,
            sf::Color backgroundColor = sf::Color(40, 40, 40), sf::Color borderColor = sf::Color(100, 100, 100)):
            size(size), pos(pos), anchor(anchor), layout(layout), backgroundColor(backgroundColor), borderColor(borderColor) {}

    void draw(sf::RenderWindow &window);
    void resize(sf::Vector2f pos, sf::Vector2f size);
    void setPos(sf::RenderWindow &window);
    void findElementWidth();
    void setElementPos();
    void addElement(Element* element);
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_ANCHOR_H