#pragma once

#include "../entity/entity.h"
#include <iostream>

class Controller;

class Player : public Entity {
private:
    Controller* m_controller;
    sf::RenderWindow* m_window;
    sf::Event m_event;


public:
    Player() = delete;
    Player(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath);
    ~Player() override;

    void Update(float time) override;

    void setState(State state);

    void draw();
};