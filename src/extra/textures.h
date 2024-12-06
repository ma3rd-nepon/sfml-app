#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace textures {
    static std::vector<sf::IntRect> cut_frame_list(sf::Texture* sheet, int rows, int columns, int width, int height, int transparent = 255, int start_x=0, int start_y=0) {
        sf::Texture text;
        sf::Image base;
        std::vector<sf::IntRect> frame_vec;
        sf::Rect<int> frame;

        base.create(width, height);
        text.create(width, height);

        if ((transparent > 0) && (transparent < 256)) {
            sf::Color c = base.getPixel(0, 0);
            c.a = transparent;
            base.setPixel(0, 0, c);
        } else if ((transparent > 255) || (transparent < 0)) { transparent = 255; } 

        for (int i {0}; i < rows; i++) {
            for (int j {0}; j < columns; j++) {
                frame = sf::Rect<int>((start_x + width * j + j), (start_y + height * i + i), width, height);
                // text.loadFromImage(base, frame);
                frame_vec.push_back(frame);
            }
        }

        return frame_vec;
    }

    static std::vector<std::vector<sf::IntRect>> def_anims(std::string texturepath) {
        sf::Texture texture;
        std::vector<std::vector<sf::IntRect>> result;

        sf::Texture idle;
        sf::Texture walk;

        texture.loadFromFile(texturepath);

        std::vector<sf::IntRect> r_idle = textures::cut_frame_list(&texture, 1, 3, 11, 16, 255, 0, 0);
        std::vector<sf::IntRect> r_walk = textures::cut_frame_list(&texture, 1, 3, 11, 16, 255, 0, 17);

        result.push_back(r_idle);
        result.push_back(r_walk);

        return result;
    }

    static sf::IntRect flip_x(sf::IntRect& rect) {
        return sf::IntRect(rect.left + rect.width, rect.top, -rect.width, rect.height);
    }
}