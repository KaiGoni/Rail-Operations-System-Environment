#include "interface.h"
#include "../panel.h"

void displayEditorInterface(sf::RenderWindow &window) {
    sf::Vector2u windowSize = window.getSize();

    Panel toolbar(sf::Vector2f(windowSize.x, 40.f), sf::Vector2f(0.f, 0.f), Anchor::TopLeft);
    Panel options(sf::Vector2f(80.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft);
    Panel info(sf::Vector2f(160.f, 240.f), sf::Vector2f(0.f, 0.f), Anchor::Right);

    toolbar.draw(window);
    options.draw(window);
    info.draw(window);
}