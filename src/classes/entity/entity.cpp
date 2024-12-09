#include "./entity.h"
#include <iostream>
#include <algorithm>

Entity::Entity(const sf::Vector2f &start_pos, const Direction &start_direction, const std::string &texture_filepath, const sf::Vector2i &rc, const sf::Vector2i &frame_size, const std::vector<std::pair<char, int>>& map) {
    m_pos = start_pos;
    m_direction = start_direction;

    m_sheet.loadFromFile(texture_filepath);
    m_textures = textures::cut_frame_list(rc, frame_size, map);

    m_sprite.setTexture(m_sheet);
    m_sprite.setTextureRect(m_textures['I'][0]);
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

void Entity::setState(State state) {
    m_state = state;
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

    int max_frames = static_cast<int>(m_textures[m_state].size());

    switch (m_state) {
        case State::IDLE: {
            m_index += anim::IDLE;
            break;
        }

        case State::RUN: {
            m_index += anim::RUN;
            break;
        }

        default: {
            m_index += anim::DEFAULT;
            break;
        }

    }

    if (m_index >= static_cast<double>(max_frames)) { m_index = 0; }

    // std::cout << m_textures.size() << " " << m_state << " " << m_index << std::endl;

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
}

Entity::~Entity() = default;


Neutral::Neutral(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath, const sf::Vector2i& rc, const sf::Vector2i& frame_size, const std::vector<std::pair<char, int>>& map) : Entity(start_pos, start_direction, texture_filepath, rc, frame_size, map) {
    m_schedule = {State::IDLE, State::RUN, State::RUN, State::IDLE};
    
}

Neutral::~Neutral() = default;

void Neutral::Update(float time) {
    do_schedule();
    m_sprite.setPosition(m_pos);
    Animate(m_can_animate);
}

void Neutral::draw() {
    // std::cout << "drawing " << m_sprite.getTexture() << std::endl;
    // m_window->draw(m_sprite);
    // for (auto [key, value] : m_textures) {
    //     std::cout << "key - " << key << std::endl;
    //     for (sf::IntRect i : value) {
    //         std::cout << i.getPosition().x << " " << i.getPosition().y << std::endl;
    //     }
    // }
    // std::cout << std::endl << std::endl;
}

sf::Vector2i Neutral::getNewPosition() {
    sf::Vector2i new_pos;
    new_pos.x = randoms::random_int(static_cast<int>(m_pos.x-5), static_cast<int>(m_pos.x+5));
    new_pos.y = randoms::random_int(static_cast<int>(m_pos.y-5), static_cast<int>(m_pos.y+5));

    return new_pos;
}

void Neutral::do_schedule() {
    if (m_state_index >= m_schedule.size()) {
        m_state_index = 0;
        refresh_schedule();
    }

    setState(m_schedule[m_state_index]);

    switch (m_schedule[m_state_index]) {
        case (State::IDLE): {
            m_timer += 1;

            if (m_timer >= 60) {
                m_timer = 0;
                m_state_index++;
                break;
            }
        }
        
        case (State::RUN): {
            sf::Vector2i new_pos = getNewPosition();

            if (abs(new_pos.x - m_pos.x) > 1) {
                m_pos.x += 0.15;
            }

            if (abs(new_pos.y - m_pos.y) > 1) {
                m_pos.y += 0.15;
            }

            else {
                m_state_index++;
                break;
            }
        }
    }
}

void Neutral::refresh_schedule() {
    std::shuffle(m_schedule.begin(), m_schedule.end(), randoms::gen);
}
