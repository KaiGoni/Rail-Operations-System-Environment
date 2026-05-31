#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

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
        if (!tex->loadFromFile(path)) {
            std::cerr << "Failed to load texture: " << path << std::endl;
            textures[name] = std::move(tex);
            return false;
        }
        textures[name] = std::move(tex);
        return true;
    }

    sf::Sprite makeSprite(const std::string& name) {
        sf::Sprite sprite;
        auto it = textures.find(name);
        if (it == textures.end()) {
            std::cerr << "makeSprite: texture not found: " << name << std::endl;
            return sprite; // return empty sprite instead of crashing
        }
        sprite.setTexture(*it->second);
        return sprite;
    }
};

extern TextureManager textureManager;

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H