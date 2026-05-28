#ifndef RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H
#define RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

class TextureManager {
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
public:
    bool createTexture(const std::string& name, const std::string& path) {
        auto tex = std::make_unique<sf::Texture>();
        if (!tex->loadFromFile(path))
            return false;
        textures[name] = std::move(tex);
        return true;
    }

    // Returns a pointer — caller must not outlive the TextureManager
    sf::Texture* get(const std::string& name) {
        return textures.at(name).get();
    }
};

#endif //RAIL_OPERATIONS_SYSTEM_ENVIRONMENT_TEXTUREMANAGER_H