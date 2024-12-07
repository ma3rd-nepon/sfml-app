#include "tile.h"
#include "../../extra/consts.h"

Tile::Tile() {
    x = 0;
    y = 0;
}

Tile::Tile(const int& x, const int& y) : x(x), y(y), id(0) {
    sprite.setPosition(static_cast<float>(x) * map::tile_size * map::tile_scale, static_cast<float>(y) * map::tile_size * map::tile_scale);
    sprite.setScale(map::tile_scale, map::tile_scale);
}

Tile::Tile(const int& x, const int& y, sf::Texture* texture, int frame_index) : Tile(x, y) {
    sprite.setTexture(*texture);
    define_frame(texture, frame_index);
}

void Tile::define_frame(sf::Texture* texture, int frame_index) {
    if (!sprite.getTexture()) sprite.setTexture(*texture);
    id = frame_index;

    unsigned int rows = texture->getSize().x / map::tile_size;
    unsigned int columns = texture->getSize().y / map::tile_size;
    int i = 0, j = 0;
    for (int iter = 0; iter < frame_index; iter++) {
        if (i == columns - 1) {
            i = 0;
            j++;
        }
        else {
            i++;
        }
    }

    sprite.setTextureRect(sf::IntRect(
            map::tile_size * i,
            map::tile_size * j,
            map::tile_size,
            map::tile_size ));
}
