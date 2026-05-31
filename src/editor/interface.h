#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_INTERFACE_H

#include <SFML/Graphics.hpp>
#include "../gui/panelManager.h"

class EditorInterface {
private:
    PanelManager panelManager;
    Panel* toolbar;
    Panel* buildRailOptions;
    Panel* buildSignalOptions;
    Panel* info;

    ButtonElement* buildRail;
    ButtonElement* buildSignal;
    NavItem* railLinear;
    NavItem* railLinearTangent;

    enum class ActiveTool {
        None,
        BuildRail,
        BuildSignal,
    };

    enum class ActiveOption {
        None,
        // BuildRail
        RailLinear,
        RailLinearTangent,
        RailCurve,
        RailCurveTangent,
        // BuildSignal
        // TBD
    };

    ActiveTool activeTool = ActiveTool::None;
    ActiveOption activeOption = ActiveOption::None;

    void init(sf::RenderWindow &window);

    ButtonElement *createToolButton(const std::string& name, const std::string& iconPath, ActiveTool tool, Panel *ownPanel, std::vector<Panel*> optionPanels);
    NavItem *createOption(const std::string& name, const std::string& iconPath, const std::string& text, ActiveOption option, Panel *ownPanel);
public:
    EditorInterface(sf::RenderWindow &window) {
        init(window);
        panelManager.onWindowResized(window);
    }

    void draw(sf::RenderWindow &window) {
        panelManager.draw(window);
    }

    // Event Behavior
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