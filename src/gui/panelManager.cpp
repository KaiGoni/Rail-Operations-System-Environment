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
void PanelManager::checkHovered(sf::Vector2f mousePos) {
    for (auto& panel : panels) {
        panel->checkHovered(mousePos);
    }
}

bool PanelManager::mouseClicked(sf::Event& event) {
    for (auto& panel : panels) {
        if (panel->checkClicked(event))return true;
    }
    return false;
}