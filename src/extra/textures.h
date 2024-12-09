#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace textures {
    static std::map<char, std::vector<sf::IntRect>> cut_frame_list(const sf::Vector2i &rc, const sf::Vector2i &frame_size, const std::vector<std::pair<char, int>>& animations) {
        int rows = rc.x;
        int columns = rc.y;

        int width = frame_size.x;
        int height = frame_size.y;

        std::cout << rows << " " << columns << std::endl;

        std::map<char, std::vector<sf::IntRect>> frame_map;
        sf::Rect<int> frame;
        
        int temp_i = 0;
        int temp_j = 0;
        for (auto& [key, value] : animations) {
            std::vector<sf::IntRect> animation;
            for (int i {temp_i}; i < rows; i++) {

                if (animation.size() >= value) {
                    temp_i = i;
                    break;
                }
                for (int j {temp_j}; j < columns; j++) {
                    std::cout << i << " " << j << std::endl;
                    frame = sf::Rect<int>((width * j + j), (height * i + i), width, height);
                    animation.push_back(frame);

                    if (animation.size() >= value) {
                        temp_j = (j == columns) ? j : 0; // почему оно работает
                        break;
                    }
                }
                std::cout << std::endl;
            }
            frame_map[key] = animation;
        }
        std::cout << std::endl;

        return frame_map;
    }

    static sf::IntRect flip_x(sf::IntRect& rect) {
        return sf::IntRect(rect.left + rect.width, rect.top, -rect.width, rect.height);
    }
}