#pragma once

#include "../../extra/consts.cpp"

class Player;

class Controller {
private:
    Controller() = default;

    static Controller* controller;
  
public:

    Controller(Controller const&) = delete;
    void operator=(Controller const&) = delete;
    ~Controller();

    static Controller* getPlayerController();

    void controllPlayer(Player* player, float time);
};