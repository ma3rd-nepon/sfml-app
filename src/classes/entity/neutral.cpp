#include "neutral.h"

Entity::~Entity() = default;


Neutral::Neutral(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath, const sf::Vector2i& rc, const sf::Vector2i& frame_size, const std::vector<std::pair<char, int>>& map) : Entity(window, start_pos, start_direction, texture_filepath, rc, frame_size, map) {
    m_schedule = State::IDLE;
    
}

Neutral::~Neutral() = default;

void Neutral::Update(float time) {
    do_schedule();
    m_sprite.setPosition(m_pos);
    Animate(m_can_animate);
}

void Neutral::do_schedule() {

    if (m_timer >= 40) {
        m_timer = 0;
        refresh_schedule();
        setState(m_schedule);
        return;
    }

    switch (m_schedule) {
        case (State::IDLE): {
            m_timer += 0.15;
        }

        case (State::RUN): {
            m_speed = randoms::random_int(2, 4);
            m_timer += 0.2;

            m_direction = m_movement_direction.first > 0 ? Direction::RIGHT : Direction::LEFT;

            if (40 - m_timer > 5) {
                m_pos.x += m_speed * m_movement_direction.first;
                m_pos.y += m_speed * m_movement_direction.second;
            }
        }
    }
}

void Neutral::refresh_schedule() {
    std::vector<State> choice = {State::IDLE, State::RUN};
    int idx = randoms::random_int(0, 1);
    m_schedule = choice[idx];

    if (choice[idx] == State::RUN) {
        m_movement_direction = {randoms::random_int(-1, 1), randoms::random_int(-1, 1)};
    }

}
