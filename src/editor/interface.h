#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H

#include <SFML/Graphics.hpp>
#include "../gui/panelManager.h"

class EditorInterface {
private:
    PanelManager panelManager;
    Panel* toolbar;
    Panel* info;
    Panel* options;
public:
    EditorInterface(sf::RenderWindow &window) {
        toolbar = new Panel(sf::Vector2f(window.getSize().x, 40.f), sf::Vector2f(0.f, 0.f), Anchor::TopLeft, Layout::Horizontal);
        options = new Panel(sf::Vector2f(80.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft, Layout::Vertical);
        info    = new Panel(sf::Vector2f(160.f, 240.f), sf::Vector2f(0.f, 0.f), Anchor::Right, Layout::Vertical);

        panelManager.addPanel(toolbar);
        panelManager.addPanel(options);
        panelManager.addPanel(info);

        panelManager.onWindowResized(window);
    }

    void draw(sf::RenderWindow &window) {
        panelManager.draw(window);
    }

    void onScreenResized(sf::RenderWindow &window) {
        panelManager.onWindowResized(window);
        toolbar->resize(sf::Vector2f(0.f, 0.f), sf::Vector2f(window.getSize().x, 40.f));
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H