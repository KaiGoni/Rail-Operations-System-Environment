#include "interface.h"

void EditorInterface::init(sf::RenderWindow &window) {
    // Load Textures
    textureManager.createTexture("icons/BuildRail",   "../assets/icons/BuildRail.png");
    textureManager.createTexture("icons/BuildSignal", "../assets/icons/BuildSignal.png");
    textureManager.createTexture("icons/RailLinear", "../assets/icons/RailLinear.png");
    textureManager.createTexture("icons/RailLinearTangent", "../assets/icons/RailLinearTangent.png");
    textureManager.createTexture("icons/RailCurved", "../assets/icons/RailCurve.png");
    textureManager.createTexture("icons/RailCurvedTangent", "../assets/icons/RailCurveTangent.png");

    // Create elements and behavior
    ButtonElement *buildRail = new ButtonElement("BuildRail", textureManager.makeSprite("icons/BuildRail"));
    buildRail->onClick = [this]() {
        activeTool = ActiveTool::BuildRail;
        activeOption = ActiveOption::None;
        buildRailOptions->visible   = true;
        buildSignalOptions->visible = false;
    };
    ButtonElement *buildSignal = new ButtonElement("BuildSignal", textureManager.makeSprite("icons/BuildSignal"));
    buildSignal->onClick = [this]() {
        activeTool = ActiveTool::BuildSignal;
        activeOption = ActiveOption::None;
        buildSignalOptions->visible = false;
        buildSignalOptions->visible = true;
    };

    // Create Panels
    toolbar = new Panel(
            sf::Vector2f(window.getSize().x, 40.f), sf::Vector2f(0.f, 0.f),
            Anchor::TopLeft, Layout::Horizontal, true,
        {
            new Divider(),
            buildRail,
            buildSignal
        }
    );

    buildRailOptions = new Panel(
        sf::Vector2f(160.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft, Layout::Vertical, false,
            {
                new NavItem("RailLinear", textureManager.makeSprite("icons/RailLinear"), "Straight Track"),
                new NavItem("RailLinearTangent", textureManager.makeSprite("icons/RailLinearTangent"), "Tan. Straight"),
                new NavItem("RailCurved", textureManager.makeSprite("icons/RailCurved"), "Curved Track"),
                new NavItem("RailCurvedTangent", textureManager.makeSprite("icons/RailCurvedTangent"), "Tan. Curved")
            }
        );
    buildSignalOptions = new Panel(sf::Vector2f(160.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft, Layout::Vertical);

    info    = new Panel(sf::Vector2f(160.f, 240.f), sf::Vector2f(0.f, 0.f), Anchor::Right, Layout::Vertical);

    // Add panels to panel manager
    panelManager.addPanel(toolbar);
    panelManager.addPanel(buildRailOptions);
    panelManager.addPanel(buildSignalOptions);
    panelManager.addPanel(info);
}