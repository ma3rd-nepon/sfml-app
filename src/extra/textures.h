#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace textures {
    static std::vector<std::vector<sf::IntRect>> cut_frame_list(const sf::Vector2i &rc, const sf::Vector2i &frame_size) {
        int rows = rc.x;
        int columns = rc.y;

        int width = frame_size.x;
        int height = frame_size.y;

        std::vector<std::vector<sf::IntRect>> frame_vec;
        sf::Rect<int> frame;

        for (int i {0}; i < rows; i++) {
            frame_vec.emplace_back();
            for (int j {0}; j < columns; j++) {
                frame = sf::Rect<int>((width * j + j), (height * i + i), width, height);
                frame_vec[i].push_back(frame);
            }
        }

        return frame_vec;
    }

    // static std::vector<std::vector<sf::IntRect>> def_anims(std::string texturepath, int rows, int columns, int width, int height, int start_x=0, int start_y=0) {
    //     sf::Texture texture;
    //     std::vector<std::vector<sf::IntRect>> result;

    //     sf::Texture idle;
    //     sf::Texture walk;

    //     texture.loadFromFile(texturepath);

    //     std::vector<sf::IntRect> r_idle = textures::cut_frame_list(1, 3, 11, 16, 0, 0);
    //     std::vector<sf::IntRect> r_walk = textures::cut_frame_list(1, 3, 11, 16, 0, 17);

    //     result.push_back(r_idle);
    //     result.push_back(r_walk);

    //     return result;
    // }

    static sf::IntRect flip_x(sf::IntRect& rect) {
        return sf::IntRect(rect.left + rect.width, rect.top, -rect.width, rect.height);
    }
}