#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <deque>
#include <unordered_map>

#include "../../extra/textures.h"
#include "../../extra/consts.h"
#include "../../extra/functions.h"

enum Direction : bool {
	LEFT = false,
	RIGHT = true
};

enum State : char {
    IDLE = 'I',
    RUN = 'R',
	SPAWN = 'S'
};

class Entity {
protected:
	sf::Vector2f m_size;
	sf::Vector2f m_pos;
	sf::Sprite   m_sprite;
	Direction    m_direction = Direction::RIGHT;
    State        m_state = State::IDLE;
	sf::Texture  m_sheet;
	bool 		 m_can_animate = true;
	double 		 m_index = 0;

	std::map<char, std::vector<sf::IntRect>> m_textures;
	std::vector<sf::IntRect> m_idle;
	std::vector<sf::IntRect> m_walk;

public:
    Entity(const sf::Vector2f &start_pos, const Direction &start_direction, const std::string &texture_filepath, const sf::Vector2i &rc, const sf::Vector2i &frame_size, const std::vector<std::pair<char, int>>& map);
	virtual ~Entity();

	virtual void Update(float time) = 0;

	void setPosition(sf::Vector2f& pos);
	void setDirection(Direction direction);
	void Animate(bool can_animate);
	void setState(State state);

	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	sf::Sprite getSprite() const;
	Direction getDirection() const;
	double getTimer() const;
};


class Neutral : public Entity {
private:
	sf::RenderWindow* 	m_window;
	std::deque<State> 	m_schedule;
	int					m_timer = 0;
	int 				m_state_index = 0;

	sf::Vector2i 		getNewPosition();

public:
	Neutral() = delete;
	Neutral(sf::RenderWindow* window, const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath, const sf::Vector2i& rc, const sf::Vector2i& frame_size, const std::vector<std::pair<char, int>>& map);
	~Neutral() override;

	void do_schedule();

	void refresh_schedule();

	void Update(float time) override;

	void draw();
};