#pragma once

#include "SFML/Window.hpp"

namespace settings {
    extern int WINDOW_WIDTH;
    extern int WINDOW_HEIGHT;

    extern int FPS;
    extern float CAMERA_SPEED;
}

namespace binds {
    extern sf::Keyboard::Key move_up;
    extern sf::Keyboard::Key move_down;
    extern sf::Keyboard::Key move_left;
    extern sf::Keyboard::Key move_right;

    extern sf::Keyboard::Key run;
}
