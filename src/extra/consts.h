#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace window {
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int FPS = 60;

    const std::string TITLE = "anus rvetsya ot c++";
}

namespace player {
    const float PLAYER_SPEED = 5.f;
    const float MAX_SPEED = 5.f;

    const float PLAYER_START_X = window::WINDOW_WIDTH/2;
    const float PLAYER_START_Y = window::WINDOW_HEIGHT/2;

    const float PLAYER_START_HP = 100;

    const std::string pl_path = "./src/assets/textures/player_sheet.png";
}

namespace anim {
    const double RUN = 0.15;
    const double IDLE = 0.1;
}

namespace map {
    // TODO
}

namespace entity {
    const float scaler = 5.f;
}
