#include "panel.h"

void Panel::setPos(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();
    panelPos = pos;
    switch (anchor) {
    case Anchor::TopCenter:
        panelPos.x = windowSize.x / 2.f - size.x / 2.f + pos.x;
        break;
    case Anchor::TopRight:
        panelPos.x = windowSize.x - size.x + pos.x;
        break;
    case Anchor::Left:
        panelPos.y = windowSize.y / 2.f - size.y / 2.f + pos.y;
        break;
    case Anchor::Center:
        panelPos.x = windowSize.x / 2.f - size.x / 2.f + pos.x;
        panelPos.y = windowSize.y / 2.f - size.y / 2.f + pos.y;
        break;
    case Anchor::Right:
        panelPos.x = windowSize.x - size.x + pos.x;
        panelPos.y = windowSize.y / 2.f - size.y / 2.f + pos.y;
        break;
    case Anchor::BottomLeft:
        panelPos.y = windowSize.y - size.y + pos.y;
        break;
    case Anchor::BottomCenter:
        panelPos.x = windowSize.x / 2.f - size.x / 2.f + pos.x;
        panelPos.y = windowSize.y - size.y + pos.y;
        break;
    case Anchor::BottomRight:
        panelPos.x = windowSize.x - size.x + pos.x;
        panelPos.y = windowSize.y - size.y + pos.y;
        break;
    }

    setElementPos();
}

void Panel::draw(sf::RenderWindow &window) {
    if (!visible)return;
    sf::RectangleShape rect;
    rect.setSize(size);
    rect.setPosition(panelPos);
    rect.setFillColor(backgroundColor);
    rect.setOutlineColor(borderColor);
    rect.setOutlineThickness(1.f);
    window.draw(rect);

    // Draw elements
    for (auto& element : elements) {
        bool isSelected = selected == element;
        element->draw(window, isSelected);
    }
}

void Panel::resize(sf::Vector2f pos, sf::Vector2f size, sf::RenderWindow &window) {
    this->size = size;
    this->pos = pos;
    setPos(window);
}

void Panel::findElementWidth() {
    // We only care about Horizontal, we don't need to worry about vertical condition since that will not happen
    elementWidth = 0;
    for (auto& element : elements) {
        element->computeSize(size, layout);
        elementWidth += element->size.x;
    }
    elementWidth += horizontalPadding;
}

void Panel::setElementPos() {
    if (layout == Layout::Vertical) {
        float current = panelPos.y + verticalPadding;

        for (auto& element : elements) {
            element->computeSize(size, layout);
            element->setPosition(sf::Vector2f(panelPos.x + verticalPadding, current));
            current += element->size.y + verticalPadding;
        }
    } else {
        // Center align by getting center x value, then offset by half of the element width
        findElementWidth();
        float current = panelPos.x + (size.x - elementWidth) / 2;

        for (auto& element : elements) {
            element->setPosition(sf::Vector2f(current, panelPos.y + (horizontalPadding/2)));
            current += element->size.x + horizontalPadding;
        }
    }
}

void Panel::addElement(Element* element) {
    elements.push_back(element);
}

void Panel::checkHovered(sf::Vector2f mousePos) {
    for (auto& element : elements) {
        element->checkHovered(mousePos);
    }
}

bool Panel::checkClicked(sf::Event& event) {
    for (auto* element : elements) {
        if (element->detectClick(event)) { // If an element had successful click
            if (selected == element) selected = nullptr;
            else selected = element;
            return true;
        }
    }
    // If click on panel, also return true
    if (sf::FloatRect(pos.x, pos.y, size.x, size.y).contains(event.mouseButton.x, event.mouseButton.y)) return true;
    return false;
}