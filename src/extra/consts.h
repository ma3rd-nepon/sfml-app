#pragma once

#include "SFML/System/Vector2.hpp"

namespace settings {
    const float CAMERA_MAX_FOLLOW_SPEED = 0.14f;
    const float CAMERA_MIN_FOLLOW_SPEED = 0.07f;
}

namespace player {
    const float PLAYER_SPEED = 1.f;
    const float MAX_SPEED = 2.f;
}

namespace strings{
    const std::string TITLE = "anus hurts because of c++";
    const std::string pl_path = "./assets/textures/player.png";
    const std::string tiles_path = "./assets/textures/ground_tiles.png";
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

namespace map {
    // TODO
}
