#pragma once

#include "../entity/entity.h"
#include <iostream>

class Controller;

class Player : public Entity {
private:
    Controller* m_controller;
    sf::RenderWindow* m_window;

public:
    Player() = delete;
    Player(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath, const sf::Vector2i& rc, const sf::Vector2i& frame_size, const std::vector<std::pair<char, int>>& map);
    ~Player() override;

    void Update(float time) override;

    void draw();
};