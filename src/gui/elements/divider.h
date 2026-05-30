#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_DIVIDER_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_DIVIDER_H

#include "Element.h"

class Divider : public Element {
public:
    void computeSize(sf::Vector2f parentSize, Layout layout) override {
        // Size: Height/Width is full length depending on arrangement, 1px in other direction
        if (layout == Layout::Horizontal) {
            size = sf::Vector2f(1, parentSize.y - horizontalPadding); // 1px width, Full height
        } else {
            size = sf::Vector2f(parentSize.x - verticalPadding * 2, 1); // Full width, 1px height
        }
    }

    void draw(sf::RenderWindow& window, bool selected) override {
        // Placeholder: Draw a simple rectangle for the button
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(dividerColor);
        window.draw(rect);
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_DIVIDER_H