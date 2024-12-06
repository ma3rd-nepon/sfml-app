#include "values.h"
#include "consts.h"

int settings::WINDOW_WIDTH = 800;
int settings::WINDOW_HEIGHT = 600;


int settings::FPS = 60;
float settings::CAMERA_SPEED = camera::CAMERA_MAX_SPEED;


sf::Keyboard::Key binds::move_up = sf::Keyboard::W;
sf::Keyboard::Key binds::move_down = sf::Keyboard::S;
sf::Keyboard::Key binds::move_left = sf::Keyboard::A;
sf::Keyboard::Key binds::move_right = sf::Keyboard::D;

sf::Keyboard::Key binds::run = sf::Keyboard::LShift;