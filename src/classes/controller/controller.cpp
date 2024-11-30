#include "./controller.h"
#include "../player/player.h"
#include <cmath>

Controller* Controller::controller = nullptr;

Controller::~Controller() {
    delete controller;
}

Controller* Controller::getPlayerController() {
    if (!controller) {
        controller = new Controller();
    }
    return controller;
}

void Controller::controlPlayer(Player* player, const float& time) {
    velocity = {0, 0};
    float speed = sf::Keyboard::isKeyPressed(binds::run) ? player::MAX_SPEED : player::PLAYER_SPEED;
    if (sf::Keyboard::isKeyPressed(binds::run)) {
        speed = player::MAX_SPEED;
        settings::CAMERA_FOLLOW_SPEED = settings::CAMERA_MIN_FOLLOW_SPEED;
    } else {
        speed = player::PLAYER_SPEED;
        settings::CAMERA_FOLLOW_SPEED = settings::CAMERA_MAX_FOLLOW_SPEED;
    }

    if (sf::Keyboard::isKeyPressed(binds::move_up)) {
        velocity.y -= speed * time;
        player->setState(State::RUN);
    }
    if (sf::Keyboard::isKeyPressed(binds::move_left)) {
        velocity.x -= speed * time;
        player->setState(State::RUN);
        player->setDirection(Direction::LEFT);
    }
    if (sf::Keyboard::isKeyPressed(binds::move_down)) {
        velocity.y += speed * time;
        player->setState(State::RUN);
    }
    if (sf::Keyboard::isKeyPressed(binds::move_right)) {
        velocity.x += speed * time;
        player->setState(State::RUN);
        player->setDirection(Direction::RIGHT);
    }

    sf::Vector2f borders = {
            static_cast<float>(sqrt(pow(speed, 2) - pow(velocity.x, 2))),
            static_cast<float>(sqrt(pow(speed, 2) - pow(velocity.y, 2)))

    };
    velocity = {
            clamp(velocity.x, -borders.x, borders.x),
            clamp(velocity.y, -borders.y, borders.y)
    };

    sf::Vector2f updated_pos = player->getPosition() + velocity;
    player->setPosition(updated_pos);
}