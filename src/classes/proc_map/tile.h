#pragma once
#include "SFML/Graphics.hpp"

enum tile_id {
    GRASS,
    SAND,
    SNOW,
    WATER
};

struct Tile {
    int x, y;
    int id;
    sf::Sprite sprite;

    Tile();
    Tile(const int& x, const int& y);
    Tile(const int &x, const int &y, sf::Texture* texture, int frame_index);

    void define_frame(sf::Texture* texture, int frame_index);
};
