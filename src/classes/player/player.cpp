#include "./player.h"

#include "../controller/controller.h"

Player::Player(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath) : Entity(start_pos, start_direction, texture_filepath, textures::player_frames, textures::player_frame), m_window(window) {
    m_controller = Controller::getPlayerController();
}

Player::~Player() = default;

void Player::Update(float time) {
    m_state = State::IDLE;
    m_controller->controlPlayer(this, time);
    Animate();

    switch (m_direction) {
        case Direction::LEFT:
            break;
        case Direction::RIGHT:
            break;
    }

    m_sprite.setPosition(m_pos);
}

void Player::setState(State state) {
    m_state = state;
}

void Player::draw() {
    m_window->draw(m_sprite);
}