#include "interface.h"

ButtonElement *EditorInterface::createToolButton(
        const std::string& name,
        const std::string& iconPath,
        ActiveTool tool,
        Panel *ownPanel,
        std::vector<Panel*> optionPanels
    ) {
    ButtonElement *thisTool = new ButtonElement(name, textureManager.makeSprite(iconPath));
    thisTool->onClick = [this, thisTool, tool, ownPanel, optionPanels]() {
        // Set everything to disabled, then check if selected
        activeTool = ActiveTool::None;
        for (Panel *panel : optionPanels) {
            panel->visible = false;
        };
        if (toolbar->selected != thisTool) {
            activeTool = tool;
            ownPanel->visible = true;
        }
    };
    return thisTool;
}

NavItem *EditorInterface::createOption(const std::string& name, const std::string& iconPath, const std::string& text, ActiveOption option, Panel *ownPanel) {
    NavItem *thisItem = new NavItem(name, textureManager.makeSprite(iconPath), text);
    thisItem->onClick = [this, thisItem, ownPanel, option]() {
        if (ownPanel->selected == thisItem) activeOption = ActiveOption::None;
        else activeOption = option;
    };
    return thisItem;
}

void EditorInterface::init(sf::RenderWindow &window) {
    // Load Textures
    textureManager.createTexture("icons/BuildRail",   "../assets/icons/BuildRail.png");
    textureManager.createTexture("icons/BuildSignal", "../assets/icons/BuildSignal.png");
    textureManager.createTexture("icons/RailLinear", "../assets/icons/RailLinear.png");
    textureManager.createTexture("icons/RailLinearTangent", "../assets/icons/RailLinearTangent.png");
    textureManager.createTexture("icons/RailCurved", "../assets/icons/RailCurve.png");
    textureManager.createTexture("icons/RailCurvedTangent", "../assets/icons/RailCurveTangent.png");

    toolbar = new Panel(sf::Vector2f(window.getSize().x, 40.f), sf::Vector2f(0.f, 0.f), Anchor::TopLeft, Layout::Horizontal, true);
    info    = new Panel(sf::Vector2f(160.f, 240.f), sf::Vector2f(0.f, 0.f), Anchor::Right, Layout::Vertical);
    buildRailOptions    = new Panel(sf::Vector2f(160.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft, Layout::Vertical);
    buildSignalOptions  = new Panel(sf::Vector2f(160.f, 500.f), sf::Vector2f(0.f, 41.f), Anchor::TopLeft, Layout::Vertical);
    std::vector<Panel*> optionPanels = {
        buildRailOptions,
        buildSignalOptions
    };
    // Toolbar
    ButtonElement *buildRail    = createToolButton("BuildRail", "icons/BuildRail", ActiveTool::BuildRail, buildRailOptions, optionPanels);
    ButtonElement *buildSignal  = createToolButton("BuildSignal", "icons/BuildSignal", ActiveTool::BuildSignal, buildSignalOptions, optionPanels);
    // Build Rail
    NavItem *railLinear         = createOption("RailLinear", "icons/RailLinear", "Straight Track", ActiveOption::RailLinear, buildRailOptions);
    NavItem *railLinearTangent  = createOption("RailLinearTangent", "icons/RailLinearTangent", "Tan. Straight", ActiveOption::RailLinearTangent, buildRailOptions);
    NavItem *railCurve          = createOption("RailCurved", "icons/RailCurved", "Curved Track", ActiveOption::RailCurve, buildRailOptions);
    NavItem *railCurveTangent   = createOption("RailCurvedTangent", "icons/RailCurvedTangent", "Tan. Curved", ActiveOption::RailCurveTangent, buildRailOptions);


    toolbar->addElement(buildRail);
    toolbar->addElement(buildSignal);
    buildRailOptions->addElement(railLinear);
    buildRailOptions->addElement(railLinearTangent);
    buildRailOptions->addElement(railCurve);
    buildRailOptions->addElement(railCurveTangent);

    // Add panels to panel manager
    panelManager.addPanel(toolbar);
    panelManager.addPanel(buildRailOptions);
    panelManager.addPanel(buildSignalOptions);
    panelManager.addPanel(info);
}