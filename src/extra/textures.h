#pragma once

#include <SFML/Graphics.hpp>

namespace textures {
    static sf::Texture player_texture1;

    static void setTextures() {
        if (!player_texture1.loadFromFile("./src/assets/textures/player.png")) {
            // error
        }
    }

    sf::Sprite loadSprite(std::string filename) {
        sf::Texture texture;
        texture.loadFromFile(filename);

        return sf::Sprite(texture);
    }
}