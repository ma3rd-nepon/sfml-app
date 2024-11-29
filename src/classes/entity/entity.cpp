#include "./entity.h"

Entity::Entity(const sf::Vector2f &start_pos, const Direction &start_direction, const std::string &texture_filepath) {
    std::string pl_path = "./assets/textures/player.png";
    m_pos = start_pos;
    m_direction = start_direction;
    m_textures = textures::def_player_anims(pl_path);
    m_sprite = m_textures[0][0];
    m_idle = m_textures[0];
    m_walk = m_textures[1];
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

void Entity::Animate(State type, bool can_animate) {
    if (can_animate) {
        m_index += 0.15;
        if (m_index >= m_textures.size()) {
            m_index = 0;
        }

        switch (type) {
            case(State::IDLE): {
                m_sprite = sf::Sprite(m_idle[int(m_index)]);
            }
            case(State::RUN): {
                m_sprite = sf::Sprite(m_walk[int(m_index)]);
            }
        }
    }
}

Entity::~Entity() = default;
