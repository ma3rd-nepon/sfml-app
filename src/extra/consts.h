#pragma once

#include <iostream>
#include "SFML/System/Vector2.hpp"

namespace settings {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int FPS = 60;
}
namespace player {
    const float PLAYER_SPEED = 5.f;
    const float MAX_SPEED = 5.f;
    const float PLAYER_START_X = static_cast<float>(settings::WINDOW_WIDTH) / 2;
    const float PLAYER_START_Y = static_cast<float>(settings::WINDOW_HEIGHT) / 2;
    const float PLAYER_START_HP = 100;
}
namespace strings{
    const std::string TITLE = "anus hurts because of c++";
    const std::string pl_path = "./assets/textures/player.png";
}

namespace textures {
    const sf::Vector2i frame_margin {1, 1};
    const unsigned short scale = 5;

    const sf::Vector2i player_frame {11, 16};
    const sf::Vector2i player_frames {2, 3};
}

namespace animation {
    const double IDLE = 0.05;
    const double RUN = 0.15;
}