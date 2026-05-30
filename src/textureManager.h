#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

class TextureManager {
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
    sf::Font defaultFont;

    // Redundant function now
    sf::Texture* get(const std::string& name) {
        return textures.at(name).get();
    }
public:
    TextureManager() {
        if (!defaultFont.loadFromFile("../assets/Inconsolata-Medium.ttf"))
            throw std::runtime_error("Failed to load default font");
    }

    sf::Font& getFont() {
        return defaultFont;
    }

    bool createTexture(const std::string& name, const std::string& path) {
        auto tex = std::make_unique<sf::Texture>();
        if (!tex->loadFromFile(path))
            return false;
        textures[name] = std::move(tex);
        return true;
    }

    sf::Sprite makeSprite(const std::string& name) {
        sf::Sprite sprite;
        sprite.setTexture(*textures.at(name));
        return sprite;
    }
};

extern TextureManager textureManager;

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H