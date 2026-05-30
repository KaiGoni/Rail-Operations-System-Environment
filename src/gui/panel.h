#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_H

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
    Element *selected = nullptr;
    int elementWidth;
    std::vector<Element *> elements;

    void findElementWidth();
public:
    Panel(sf::Vector2f size, sf::Vector2f pos, Anchor anchor = Anchor::None, Layout layout = Layout::Vertical,
            bool visible = false, std::vector<Element*> elements = {},
            sf::Color backgroundColor = sf::Color(40, 40, 40), sf::Color borderColor = sf::Color(100, 100, 100))
          : size(size), pos(pos), anchor(anchor), layout(layout),
            backgroundColor(backgroundColor), borderColor(borderColor),
            elements(elements), visible(visible) {}

    bool visible;

    void draw(sf::RenderWindow &window);
    void resize(sf::Vector2f pos, sf::Vector2f size, sf::RenderWindow &window);
    void setPos(sf::RenderWindow &window);
    void setElementPos();
    void addElement(Element* element);
    void checkHovered(sf::Vector2f mousePos);
    bool checkClicked(sf::Event& event);
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANEL_H