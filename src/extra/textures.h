#pragma once

#include <string>
#include <vector>

namespace textures {
    static std::vector<sf::Sprite> cut_frame_list(sf::Texture* sheet, int rows, int columns, int width, int height, int transparent = 255) {
        sf::Texture text;
        sf::Image base;
        std::vector<sf::Sprite> frame_vec;
        sf::IntRect frame;

        if ((transparent > 0) && (transparent < 256)) {
            sf::Color c = base.getPixel(0, 0);
            c.a = transparent;
            base.setPixel(0, 0, c);
        } else if ((transparent > 255) || (transparent < 0)) { transparent = 255; } 

        base.create(width, height);
        text.create(width, height);

        for (int i {0}; i < rows; i++) {
            for (int j {0}; j < columns; j++) {
                frame = sf::IntRect(width * j + (j * 5), height * i + (10 * i), width, height);
                text.loadFromImage(base, frame);
                frame_vec.push_back(sf::Sprite(text));
            }
        }

        return frame_vec;
    }

    static std::vector<std::vector<sf::Sprite>> def_player_anims(std::string player_texturepath) {
        sf::Texture player_texture;
        std::vector<std::vector<sf::Sprite>> result;

        sf::Texture pl_idle;
        sf::Texture pl_walk;

        pl_idle.create(250, 110); // где то здесь ебатня // дтнаху
        pl_walk.create(250, 110); // ща в д

        sf::Image idle_base;
        sf::Image walk_base;

        idle_base.create(250, 110);
        walk_base.create(250, 110);

        player_texture.loadFromFile(player_texturepath);

        pl_idle.loadFromImage(idle_base, sf::Rect<int>(0, 0, 250, 110));
        pl_walk.loadFromImage(walk_base, sf::Rect<int>(0, 120, 250, 110));

        std::vector<sf::Sprite> player_idle = textures::cut_frame_list(&pl_idle, 3, 1, 80, 110);
        std::vector<sf::Sprite> player_walk = textures::cut_frame_list(&pl_walk, 3, 1, 80, 110);

        result.push_back(player_idle);
        result.push_back(player_walk);

        return result;
    }
}