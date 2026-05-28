#include "panelManager.h"

void PanelManager::addPanel(Panel* panel) {
    panels.push_back(panel);
}

void PanelManager::draw(sf::RenderWindow &window) {
    for (auto& panel : panels) {
        panel->draw(window);
    }
}

void PanelManager::onWindowResized(sf::RenderWindow& window) {
    for (auto& panel : panels) {
        panel->setPos(window);
    }
}