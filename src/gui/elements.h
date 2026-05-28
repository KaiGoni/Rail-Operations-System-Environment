#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_ELEMENTS_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_ELEMENTS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include "uiConstants.h"

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

    void setPosition(sf::Vector2f pos) {position = pos;}
    void checkHovered(sf::Vector2f mousePos);
    bool detectClick(sf::Event& event);
    virtual void computeSize(sf::Vector2f parentSize, Layout layout) = 0;
    virtual void draw(sf::RenderWindow& window, bool selected) = 0;
};

class ButtonElement : public Element {
public:
    ButtonElement(sf::Sprite image) : icon(image) {
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
            rect.setFillColor(sf::Color(100, 100, 255));
        } else if (hovered) {
            rect.setFillColor(sf::Color(150, 150, 255));
        } else {
            rect.setFillColor(sf::Color(200, 200, 255));
        }
        window.draw(rect);
        window.draw(icon);
    }
};

class Divider : public Element {
public:
    void computeSize(sf::Vector2f parentSize, Layout layout) override {
        // Size: Height/Width is full length depending on arrangement, 1px in other direction
        if (layout == Layout::Horizontal) {
            size = sf::Vector2f(1, parentSize.y - horizontalPadding); // 1px width, Full height
        } else {
            size = sf::Vector2f(parentSize.x - verticalPadding, 1); // Full width, 1px height
        }
    }

    void draw(sf::RenderWindow& window, bool selected) override {
        // Placeholder: Draw a simple rectangle for the button
        sf::RectangleShape rect;
        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(sf::Color(100, 100, 100));
        window.draw(rect);
    }
};

class NavItem : public Element {
public:
    NavItem(sf::Sprite image) : icon(image) {
        interactable = true;
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
        if (selected) {
            rect.setFillColor(sf::Color(100, 100, 255));
        } else if (hovered) {
            rect.setFillColor(sf::Color(150, 150, 255));
        } else {
            rect.setFillColor(sf::Color(200, 200, 255));
        }
        window.draw(rect);
    }
};

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
        rect.setFillColor(sf::Color(100, 100, 100));
        window.draw(rect);
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_ELEMENTS_H