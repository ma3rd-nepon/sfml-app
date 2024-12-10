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

        std::map<char, std::vector<sf::IntRect>> frame_map;
        sf::Rect<int> frame;
        
        std::vector<sf::IntRect> all_frames;
        for (int i {0}; i < rows; i++) {
            for (int j {0}; j < columns; j++) {
                frame = sf::Rect<int>((width * j + j), (height * i + i), width, height);
                all_frames.push_back(frame);
            }
        }

        int index = 0;
        for (auto& [key, value] : animations) {
            std::vector<sf::IntRect> bbb;
            for (int i{index}; i < all_frames.size(); i++) {
                bbb.push_back(all_frames[i]);
                if (bbb.size() == value) {
                    frame_map[key] = bbb;
                    index = i+1;
                    break;
                }
            }
        }
        return frame_map;
    }

    static sf::IntRect flip_x(sf::IntRect& rect) {
        return sf::IntRect(rect.left + rect.width, rect.top, -rect.width, rect.height);
    }
}