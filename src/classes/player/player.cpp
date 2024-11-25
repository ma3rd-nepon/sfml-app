#include "./player.h"
#include "../controller/controller.h"

Player::Player(const sf::Texture* texture, sf::Vector2f start_pos, float health) {
    m_pos = start_pos;
    m_health = health;

    m_controller = Controller::getPlayerController();
  
    m_sprite.setTexture(*texture);
    m_size = sf::Vector2f(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height);
}

Player::~Player() {}

void Player::Update(float time) {
    m_state = State::IDLE;
    m_controller->controllPlayer(this, time);

    if (m_state == State::RUN) {

    }
    else {

    }

    m_sprite.setPosition(m_pos);
}

void Player::setState(State state) {
    m_state = state;
}