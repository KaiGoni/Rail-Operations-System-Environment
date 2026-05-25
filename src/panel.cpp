#include "panel.h"

void Panel::draw(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f panelPos = pos;
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

    sf::RectangleShape rect;
    rect.setSize(size);
    rect.setPosition(panelPos);
    rect.setFillColor(backgroundColor);
    rect.setOutlineColor(borderColor);
    rect.setOutlineThickness(1.f);
    window.draw(rect);
}

void Panel::setPos(sf::Vector2f pos, sf::Vector2f size) {
    this->size = size;
    this->pos = pos;
}