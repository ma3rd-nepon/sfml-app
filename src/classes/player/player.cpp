#include "./player.h"

#include "../controller/controller.h"

Player::Player(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath, const sf::Vector2i& rc, const sf::Vector2i& frame_size) : Entity(start_pos, start_direction, texture_filepath, rc, frame_size), m_window(window) {
    m_controller = Controller::getPlayerController();
}

Player::~Player() = default;

void Player::Update(float time) {
    setState(State::IDLE);
    m_controller->controlPlayer(this, time);
    m_sprite.setPosition(m_pos);
    Animate(m_can_animate);
}

void Player::setState(State state) {
    m_state = state;
}

void Player::draw() {
    m_window->draw(m_sprite);
}