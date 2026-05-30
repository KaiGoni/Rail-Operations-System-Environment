#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXT_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXT_H

#include "Element.h"

class Text : public Element {
public:
    std::string text;
    std::vector<sf::Text> subtexts;

    // Size: 20px height, full width
    void computeSize(sf::Vector2f parentSize, Layout layout) override {
        size = sf::Vector2f(parentSize.x - (verticalPadding * 2), 20); // Full width, 20px height
    }

    void draw(sf::RenderWindow& window, bool selected) override {
        // Placeholder: Draw a simple rectangle for the button
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(textColor);
        window.draw(rect);
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXT_H