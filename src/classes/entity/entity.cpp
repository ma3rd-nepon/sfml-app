#include "./entity.h"
#include <iostream>

Entity::Entity(const sf::Vector2f &start_pos, const Direction &start_direction, const std::string &texture_filepath, const sf::Vector2i &rc, const sf::Vector2i &frame_size) {
    m_pos = start_pos;
    m_direction = start_direction;

    m_sheet.loadFromFile(texture_filepath);
    m_textures = textures::cut_frame_list(rc, frame_size);

    m_sprite.setTexture(m_sheet);
    m_sprite.setTextureRect(m_textures[0][0]);
    m_sprite.setScale(entity::scaler, entity::scaler);
    m_sprite.setOrigin(m_sprite.getScale() / 2.0f);

    m_size = sf::Vector2f(static_cast<float>(m_sprite.getTextureRect().width), static_cast<float>(m_sprite.getTextureRect().height));
}

void Entity::setPosition(sf::Vector2f& pos) {
    m_pos = pos;
}

void Entity::setDirection(Direction direction) {
    m_direction = direction;
}

sf::Vector2f Entity::getSize() const {
    return m_size;
}

sf::Vector2f Entity::getPosition() const {
    return m_pos;
}

sf::Sprite Entity::getSprite() const {
    return m_sprite;
}

Direction Entity::getDirection() const {
    return m_direction;
}

double Entity::getTimer() const {
    return m_index;
}

void Entity::Animate(bool can_animate) {
    if (!can_animate) { return; }

    sf::IntRect frame;

    int max_frames = m_textures[m_state].size();

    if (m_index >= static_cast<double>(max_frames)) { m_index = 0; }

    switch (m_state) {
        case State::IDLE: {
            m_index += anim::IDLE;
            break;
        }

        case State::RUN: {
            m_index += anim::RUN;
            break;
        }

    }

    frame = m_textures[m_state][static_cast<int>(m_index)];

    switch (m_direction) {
        case Direction::RIGHT: {
            m_sprite.setTextureRect(frame);
            break;
        }
        case Direction::LEFT: {
            m_sprite.setTextureRect(textures::flip_x(frame));
            break;
        }
    }

    // std::cout << "index is " << m_index << std::endl;
    // std::cout << m_idle[0].getSize().x << " " << m_idle[0].getSize().y << std::endl;
}

Entity::~Entity() = default;
