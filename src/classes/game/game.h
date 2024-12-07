#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <cmath>

#include "../../extra/values.h"
#include "../../extra/functions.h"
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
    sf::View* camera;
    Player* player;
    sf::CircleShape* circle;

    sf::Texture map_texture;
    sf::Sprite map_sprite;

    sf::Clock clock;
    float time{};
};