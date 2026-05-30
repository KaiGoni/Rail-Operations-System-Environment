#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_BUTTONELEMENT_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_BUTTONELEMENT_H

#include "Element.h"

class ButtonElement : public Element {
public:
    ButtonElement(const std::string& name, sf::Sprite image) : icon(image) {
        this->name = name;
        interactable = true;
    }
    sf::Sprite icon;

    // Size: Square Ratio, takes up as much space in panel as needed
    void computeSize(sf::Vector2f parentSize, Layout layout) override{
        // Set both width and height to parent height
        size = sf::Vector2f(parentSize.y - horizontalPadding, parentSize.y - horizontalPadding);
    }

    void draw(sf::RenderWindow& window, bool selected) override {
        // Placeholder: Draw a simple rectangle for the button
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setPosition(position);
        icon.setScale(
            size.x / icon.getLocalBounds().width,
            size.y / icon.getLocalBounds().height
        );
        icon.setPosition(position);
        if (selected) {
            rect.setFillColor(selectedColor);
        } else if (hovered) {
            rect.setFillColor(hoveredColor);
        } else {
            rect.setFillColor(unselectedColor);
        }
        window.draw(rect);
        window.draw(icon);
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_BUTTONELEMENT_H