#pragma once

#include <string>
#include <vector>
#include "consts.h"

class set_textures {
    typedef unsigned short length;
    typedef std::vector<std::vector<sf::IntRect>> frames;
};

// public:
//     static void generate_frames(frames& vec, const sf::Vector2i frames_quantity, const sf::Vector2i& frame) {
//         length current_x = 0;
//         length current_y = 0;
//         for (int i = 0; i < frames_quantity.x; i++) {
//             vec.emplace_back();
//             for (int j = 0; j < frames_quantity.y; j++) {
//                 vec[i].emplace_back(current_x, current_y, frame.x, frame.y);
//                 current_x += textures::frame_margin.x + frame.x;
//             }
//             current_x = 0;
//             current_y += textures::frame_margin.y + frame.y;
//         }
//     }

//     static sf::IntRect rect_flip_x(const sf::IntRect& rect) {
//         return {rect.left + rect.width, rect.top, -rect.width, rect.height};
//     }
// };