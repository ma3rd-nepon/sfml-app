#pragma once

#include "tile.h"
#include "FastNoiseLite.h"

class Chunk {
public:
    int x, y; // Координаты чанка
    std::vector<std::vector<Tile>> tiles; // Двумерный массив тайлов
    sf::Texture* tile_sheet;

    Chunk(int chunkX, int chunkY, FastNoiseLite& noiseGenerator, sf::Texture* tile_sheet);

    void generateTiles(FastNoiseLite& noiseGenerator);
};