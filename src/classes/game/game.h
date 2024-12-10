#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <cmath>

#include "../../extra/values.h"
#include "../../extra/functions.h"
#include "../player/player.h"
#include "../entity/neutral.h"


class Game {
public: 
    Game();
    ~Game();
    void Start();
    void AddNeutralEntity(const sf::Vector2f& start_pos, const Direction direction, const std::string& path, const sf::Vector2i& rc, const sf::Vector2i& frame_size, const std::vector<std::pair<char, int>>& map);

private:
    void EventHandler(sf::Event&);
    void draw();
    void run();

    sf::RenderWindow* window;
    sf::View* camera;
    Player* player;
    Neutral* skeleton;

    std::vector<Entity*> m_entities;
    sf::CircleShape* circle;

    sf::Texture map_texture;
    sf::Sprite map_sprite;

    sf::Clock clock;
    float time{};
};