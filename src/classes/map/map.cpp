#include <iostream>
#include "map.h"

Level::Level(sf::RenderWindow* window) {
    // m_player_pos = player.getPosition();
    m_window = window;
    m_player_pos.x = m_player_pos.y = 0;
}

void Level::Update(float time) {
    draw();
}

std::vector<std::vector<int>> Level::read_map(const std::string& filepath) {
    std::fstream fofa(filepath);
    std::string str;
    char delimiter = ',';

    std::vector<std::vector<int>> result;

    if (!fofa.is_open()) { throw "Couldnt read file"; }

    while(getline(fofa, str)) {
        std::vector<int> row;
        for (char b : str) {
            if (b != delimiter) { row.push_back(b - '0'); }
        }
        result.push_back(row);
    }

    fofa.close();

    return result;
}

void Level::create_map() {
    read_map(map::tile_map);
    //TODO Tile class need;
}

void draw() {
    // m_window->draw(m_level);
}

sf::Vector2i Level::get_player_pos() {
    return m_player_pos;
}

Tile::Tile(int& tilesize, sf::Vector2i& pos, std::string& texture_path, int& rect_index) {
    m_texture.loadFromFile(texture_path);
    m_tilesize = tilesize;
    m_pos = {m_tilesize * pos.x, m_tilesize * pos.y};
    m_text_rect = define_rect(rect_index);

}

sf::IntRect Tile::define_rect(int& rect_index) {
    int x {0}, y {0};
    // looking for ideal tile from pygame project
    int rows = m_texture.getSize().x / m_tilesize;
    int columns = m_texture.getSize().y / m_tilesize;

    return sf::IntRect(m_tilesize * static_cast<int>(rect_index % columns), (m_tilesize * static_cast<int>(rect_index / rows)), m_tilesize, m_tilesize);

    // if (rect_index >= columns) { return sf::IntRect(m_tilesize * rect_index)}
    // {m_tilesize * rect_index, 0, m_tilesize, m_tilesize};
}