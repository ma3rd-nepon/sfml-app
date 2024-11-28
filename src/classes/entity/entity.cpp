#include "./entity.h"

Entity::Entity(const sf::Vector2f &start_pos, const Direction &start_direction, const std::string &texture_filepath) {
    m_pos = start_pos;
    m_direction = start_direction;
    m_texture.loadFromFile(texture_filepath);
    m_sprite.setTexture(m_texture);
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

Entity::~Entity() = default;
