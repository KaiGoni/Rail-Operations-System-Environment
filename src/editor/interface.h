#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H

#include <SFML/Graphics.hpp>
#include "../gui/panelManager.h"
#include "../textureManager.h"

class EditorInterface {
private:
    PanelManager panelManager;
    Panel* toolbar;
    Panel* info;
    Panel* options;

    ButtonElement* buildRail;
    ButtonElement* buildSignal;
    NavItem* railLinear;
    NavItem* railLinearTangent;
public:
    EditorInterface(sf::RenderWindow &window) {
        toolbar = new Panel(sf::Vector2f(window.getSize().x, 40.f), sf::Vector2f(0.f, 0.f), Anchor::TopLeft, Layout::Horizontal);
        options = new Panel(sf::Vector2f(160.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft, Layout::Vertical);
        info    = new Panel(sf::Vector2f(160.f, 240.f), sf::Vector2f(0.f, 0.f), Anchor::Right, Layout::Vertical);

        panelManager.addPanel(toolbar);
        panelManager.addPanel(options);
        panelManager.addPanel(info);

        textureManager.createTexture("icons/BuildRail",   "../assets/icons/BuildRail.png");
        textureManager.createTexture("icons/BuildSignal", "../assets/icons/BuildSignal.png");
        textureManager.createTexture("icons/RailLinear", "../assets/icons/RailLinear.png");
        textureManager.createTexture("icons/RailLinearTangent", "../assets/icons/RailLinearTangent.png");

        sf::Sprite sprBuildRail(*textureManager.get("icons/BuildRail"));
        sf::Sprite sprBuildSignal(*textureManager.get("icons/BuildSignal"));
        sf::Sprite sprRailLinear(*textureManager.get("icons/RailLinear"));
        sf::Sprite sprRailLinearTangent(*textureManager.get("icons/RailLinearTangent"));

        buildRail   = new ButtonElement(sprBuildRail);
        buildSignal = new ButtonElement(sprBuildSignal);
        railLinear = new NavItem(sprRailLinear, "Straight Track");
        railLinearTangent = new NavItem(sprRailLinearTangent, "Tan. Straight");

        toolbar->addElement(new Divider);
        toolbar->addElement(buildRail);
        toolbar->addElement(buildSignal);
        options->addElement(railLinear);
        options->addElement(railLinearTangent);

        panelManager.onWindowResized(window);
    }

    void draw(sf::RenderWindow &window) {
        panelManager.draw(window);
    }

    void onScreenResized(sf::RenderWindow &window) {
        panelManager.onWindowResized(window);
        toolbar->resize(sf::Vector2f(0.f, 0.f), sf::Vector2f(window.getSize().x, 40.f), window);
    }
    void onMouseMoved(sf::Vector2f mousePos) {
        panelManager.checkHovered(mousePos);
    }
    void onMouseClicked(sf::Event& event) {
        panelManager.mouseClicked(event);
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H