#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>


#include "../../extra/textures.h"
#include "../../extra/consts.h"

class Level {
protected:
    sf::Vector2i        m_player_pos;
    int                 m_tilesize;
    sf::RenderWindow*   m_window;

public:
    Level(sf::RenderWindow* window);
    virtual ~Level();

    virtual void Update(float time) = 0;

    void create_map();
    void draw();

    std::vector<std::vector<int>> read_map(const std::string& filepath);
    sf::Vector2i get_player_pos();
};

class Tile {
protected:
    int             m_tilesize;
    sf::Vector2i    m_pos;
    sf::Texture     m_texture;
    sf::IntRect     m_text_rect;
    sf::Sprite      m_sprite;

    sf::IntRect define_rect(int& rect_index);

public:
    Tile(int& tilesize, sf::Vector2i& pos, std::string& texture_path, int& rect_index);
};