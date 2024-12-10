#include <iostream>
#include <SFML/Graphics.hpp>

#include "entity.h"

class Neutral : public Entity {
private:
	State			 	m_schedule;
	double				m_timer = 0;
	int					m_speed;
	std::pair<int, int>	m_movement_direction = {0, 0};

	sf::Vector2i 		getNewPosition(int recoil);

public:
	Neutral() = delete;
	Neutral(const sf::Vector2f& start_pos, const Direction& start_direction, const std::string& texture_filepath, const sf::Vector2i& rc, const sf::Vector2i& frame_size, const std::vector<std::pair<char, int>>& map);
	~Neutral() override;

	void do_schedule();

	void refresh_schedule();

	void Update(float time) override;
};