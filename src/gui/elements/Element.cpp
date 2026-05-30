#include <iostream>
#include "Element.h"

void Element::checkHovered(sf::Vector2f mousePos) {
    if (!interactable) return;
    hovered = sf::FloatRect(position.x, position.y, size.x, size.y).contains(mousePos);
}

bool Element::detectClick(sf::Event& event) {
    if (hovered && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (onClick) onClick();
        else std::cerr << "elements.cpp: Element \"" << name << "\" onClick detected but no behavior defined" << std::endl;
        return true;
    }
    return false;
}