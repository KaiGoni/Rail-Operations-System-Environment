#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_ELEMENT_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_ELEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include <functional>
#include "../../textureManager.h"
#include "../uiConstants.h"

enum class Layout {
    Horizontal,
    Vertical
};

class Element {
public:
    bool hovered = false;
    bool interactable = false;
    sf::Vector2f position;
    sf::Vector2f size = sf::Vector2f(0,0);
    std::string name;

    void setPosition(sf::Vector2f pos) {position = pos;}
    void checkHovered(sf::Vector2f mousePos);
    bool detectClick(sf::Event& event);
    std::function<void()> onClick;
    virtual void computeSize(sf::Vector2f parentSize, Layout layout) = 0;
    virtual void draw(sf::RenderWindow& window, bool selected) = 0;
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_ELEMENT_H