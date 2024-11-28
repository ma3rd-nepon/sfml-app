#pragma once

#include "../entity/entity.h"
#include "../../extra/textures.h"
#include <iostream>
#include <filesystem>

class Controller;

enum class State {
    IDLE,
    RUN
};

class Player : public Entity {
private:
    State m_state;
    Controller* m_controller;
    sf::RenderWindow* m_window;

public:
    Player() = delete;
    Player(sf::RenderWindow* window, sf::Vector2f start_pos, float health);
    ~Player();

    void Update(float time) override;

    void setState(State state);

    void draw();
};