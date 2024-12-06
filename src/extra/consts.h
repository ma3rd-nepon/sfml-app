#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace window {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int FPS = 60;

    const std::string TITLE = "wtf c++";
}

namespace player {
    const float PLAYER_SPEED = 1.5f;
    const float MAX_SPEED = 2.4f;

    const float PLAYER_START_X = window::WINDOW_WIDTH/2;
    const float PLAYER_START_Y = window::WINDOW_HEIGHT/2;

    const float PLAYER_START_HP = 100;

    const std::string pl_path = "./assets/textures/player_sheet.png";

    const sf::Vector2i player_rows_cols = {2, 3};
    const sf::Vector2i player_frame_size = {11, 16};

    // const std::vector<std::vector<std::vector<int>>> player_frame_size = {{{1, 3}, {11, 16}, {0, 0}}, {{1, 3}, {11, 16}, {0, 17}}};
}

namespace anim {
    const double RUN = 0.15;
    const double IDLE = 0.1;
}

namespace camera {
    const float CAMERA_MAX_SPEED = 0.14f;
    const float CAMERA_MIN_SPEED = 0.07f;
}

namespace map {
    // TODO
}

namespace entity {
    const float scaler = 5.f;
}
