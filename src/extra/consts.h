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
    const float PLAYER_SPEED = 1.7f;
    const float RUN_SPEED = 2.8f;
    const float MAX_SPEED = 6.f;

    const float PLAYER_START_X = window::WINDOW_WIDTH/2;
    const float PLAYER_START_Y = window::WINDOW_HEIGHT/2;

    const float PLAYER_START_HP = 100;

    const std::string pl_path = "./assets/textures/player_sheet.png";

    const sf::Vector2i player_rows_cols = {2, 3};
    const sf::Vector2i player_frame_size = {11, 16};
    const std::vector<std::pair<char, int>> player_map = {{'I', 3}, {'R', 3}};

    // const std::vector<std::vector<std::vector<int>>> player_frame_size = {{{1, 3}, {11, 16}, {0, 0}}, {{1, 3}, {11, 16}, {0, 17}}};
}

namespace anim {
    const double RUN = 0.15;
    const double SHIFT_RUN = 0.30;
    const double IDLE = 0.1;
    const double DEFAULT = 0.1;
}

namespace camera {
    const float CAMERA_MAX_SPEED = 0.14f;
    const float CAMERA_MIN_SPEED = 0.07f;
}

namespace map {
    const int tile_size = 80;
    const std::string tile_map = "./assets/test_map.csv";

    const int tile_rows = 16;
    const int tile_columns = 22;
}

namespace tiles {
    const int tile_size = 16;
    const int chunk_size = 8;
}

namespace entity {
    const float scaler = 5.f;

    const std::string skeleton_path = "./assets/textures/skeleton.png";
    const sf::Vector2i skeleton_rc = {4, 6};
    const sf::Vector2i skeleton_frame_size = {14, 17};
    const std::vector<std::pair<char, int>> skeleton_map = {{'S', 10}, {'I', 6}, {'R', 6}};
}
