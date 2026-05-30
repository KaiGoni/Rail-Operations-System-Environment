#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_NAVITEM_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_NAVITEM_H

#include "Element.h"

class NavItem : public Element {
public:
    NavItem(const std::string& name, const sf::Sprite& image, const std::string& text)
        : icon(image), text(text) {
        interactable = true;
        this->name = name;
    }
    sf::Sprite icon;
    std::string text;

    // Size: 20px height, full width
    void computeSize(sf::Vector2f parentSize, Layout layout) override {
        size = sf::Vector2f(parentSize.x - (verticalPadding * 2), 20); // Full width, 20px height
    }

    void draw(sf::RenderWindow& window, bool selected) override {
        // Placeholder: Draw a simple rectangle for the button
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setPosition(position);
        icon.setScale(
    size.y / icon.getLocalBounds().height,
    size.y / icon.getLocalBounds().height
        );
        icon.setPosition(position);
        sf::Text label;
        label.setFont(textureManager.getFont());
        label.setString(text);
        label.setCharacterSize(size.y - 4);
        label.setFillColor(textColor);
        label.setPosition(position + sf::Vector2f(size.y + 2, 0));
        if (selected) {
            rect.setFillColor(selectedColor);
        } else if (hovered) {
            rect.setFillColor(hoveredColor);
        } else {
            rect.setFillColor(unselectedColor);
        }
        window.draw(rect);
        window.draw(icon);
        window.draw(label);
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_NAVITEM_H