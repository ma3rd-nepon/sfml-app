#pragma once

#include "../../extra/values.h"
#include "../../extra/functions.h"

class Player;

class Controller {
private:
    // sf::Vector2f velocity;
    Controller() = default;

    static Controller* controller;

public:
    Controller(Controller const&) = delete;
    void operator=(Controller const&) = delete;
    ~Controller();

    static Controller* getPlayerController();

    void controlPlayer(Player* player, const float& time);
};