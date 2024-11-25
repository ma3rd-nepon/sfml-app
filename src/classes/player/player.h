#pragma once

#include "../entity/entity.h"

class Controller;

enum class State {
    IDLE,
    RUN
};

class Player : public Entity {
private:
    State m_state;
    Controller* m_controller;

public:
    Player() = delete;
    Player(const sf::Texture* texture, sf::Vector2f start_pos, float health);
    ~Player();

    void Update(float time) override;

    void setState(State state);
};