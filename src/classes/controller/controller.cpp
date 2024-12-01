#include "./controller.h"

#include "../player/player.h"

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

void Controller::controlPlayer(Player* player, const float& time) { // дизентегрировать отсюда
    sf::Vector2f updated_pos = player->getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        updated_pos.y -= player::PLAYER_SPEED * time;
        player->setState(State::RUN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        updated_pos.x -= player::PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::LEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        updated_pos.y += player::PLAYER_SPEED * time;
        player->setState(State::RUN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        updated_pos.x += player::PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::RIGHT);
    }

    player->setPosition(updated_pos);
}