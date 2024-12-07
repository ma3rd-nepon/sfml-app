#include "chunk.h"
#include "../../extra/consts.h"
#include "tile_map.h"

Chunk::Chunk(int chunkX, int chunkY, FastNoiseLite& noiseGenerator, sf::Texture* tile_sheet) : x(chunkX), y(chunkY), tile_sheet(tile_sheet) {
    generateTiles(noiseGenerator);
}

void Chunk::generateTiles(FastNoiseLite& noiseGenerator) {
    tiles.resize(16, std::vector<Tile>(16));

    for (int localY = 0; localY < 16; ++localY) {
        for (int localX = 0; localX < 16; ++localX) {
            // Мировые координаты тайла
            int worldX = x * 16 + localX;
            int worldY = y * 16 + localY;

            // Получение значения шума Перлина
            float noiseValue = noiseGenerator.GetNoise(static_cast<float>(worldX), static_cast<float>(worldY));
            tiles[localX][localY] = Tile(worldX, worldY);

            // Преобразование шума в тип биома
            if (noiseValue < -0.3f) {
                tiles[localX][localY].define_frame(tile_sheet, tile_id::WATER);
            } else if (noiseValue < 0.0f) {
                tiles[localX][localY].define_frame(tile_sheet, tile_id::SAND);
            } else if (noiseValue < 0.5f) {
                tiles[localX][localY].define_frame(tile_sheet, tile_id::GRASS);
            } else {
                tiles[localX][localY].define_frame(tile_sheet, tile_id::SNOW);
            }
        }
    }
}
