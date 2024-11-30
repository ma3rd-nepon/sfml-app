#include "./entity.h"

Entity::Entity(const sf::Vector2f &start_pos, const Direction &start_direction, const std::string &texture_filepath, const sf::Vector2i& frames_quantity, const sf::Vector2i& frame_size) {
    m_pos = start_pos;
    m_direction = start_direction;
    if (!m_sheet.loadFromFile(texture_filepath)) {
        // error
    }
    m_sprite.setTexture(m_sheet);
    m_sprite.setScale(textures::scale, textures::scale);
    m_sprite.setOrigin(m_sprite.getScale()/2.f);
    m_sprite.setPosition(m_sprite.getOrigin());
    set_textures::generate_frames(m_frames, frames_quantity, frame_size);
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

void Entity::Animate() {
    if (!m_can_animate) return;
    switch (m_state) {
        case State::RUN:
            m_animation_timer += animation::RUN;
            break;
        case State::IDLE:
        default:
            m_animation_timer += animation::IDLE;
            break;
    }
    if (m_animation_timer >= static_cast<double>(m_frames.size())) {
        m_animation_timer = 0;
    }
    switch (m_direction) {
        case Direction::LEFT:
            m_sprite.setTextureRect(set_textures::rect_flip_x(m_frames[m_state][static_cast<int>(m_animation_timer)]));
            break;
        case Direction::RIGHT:
            m_sprite.setTextureRect(m_frames[m_state][static_cast<int>(m_animation_timer)]);
            break;
    }
}

Entity::~Entity() = default;
