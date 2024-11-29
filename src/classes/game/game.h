#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <cmath>

#include "../../extra/consts.h"
//#include "../../extra/textures.h"

#include "../player/player.h"


class Game {
public: 
    Game();
    ~Game();
    void Start();

private:
    void EventHandler(sf::Event&);
    void draw();
    void run();

    sf::RenderWindow* window;

    Player* player;

    sf::Clock clock;
    float time{};
};