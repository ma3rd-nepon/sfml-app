#pragma once

#include <SFML/Graphics.hpp>

namespace textures {
    static sf::Texture player_texture;

    static void setTextures() {
        if (!player_texture.loadFromFile("./assets/textures/player.png")) {
            //error
        }
    }
}