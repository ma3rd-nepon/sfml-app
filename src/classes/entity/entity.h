#pragma once

#include <SFML/Graphics.hpp>
#include "../../extra/textures.h"

enum class Direction : bool {
	LEFT = false,
	RIGHT = true
};

enum class State {
    IDLE,
    RUN
};

class Entity {
protected:
	sf::Vector2f m_size;
	sf::Vector2f m_pos;
	sf::Sprite   m_sprite;
    sf::Texture  m_texture;
	Direction    m_direction = Direction::RIGHT;
    State        m_state = State::IDLE;

public:
    Entity(const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath);
	virtual ~Entity();

	virtual void Update(float time) = 0;

	void setPosition(sf::Vector2f& pos);
	void setDirection(Direction direction);

	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	sf::Sprite getSprite() const;
	Direction getDirection() const;
};