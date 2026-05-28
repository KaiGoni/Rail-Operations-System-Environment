#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANELMANAGER_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANELMANAGER_H

#include <vector>
#include "panel.h"

class PanelManager {
private:
    std::vector<Panel *> panels;
public:
    PanelManager() {}
    void addPanel(Panel *panel);
    void draw(sf::RenderWindow &window);
    void onWindowResized(sf::RenderWindow &window);
    void checkHovered(sf::Vector2f mousePos);
    void mouseClicked(sf::Event& event);
};


#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_PANELMANAGER_H