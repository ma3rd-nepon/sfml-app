#include "tile_map.h"

#include <iostream>
#include <fstream>
#include <utility>

#include "../../extra/consts.h"

TileMap::TileMap(int seed, std::string  name) : worldName(std::move(name)) {
    tile_sheet.loadFromFile(map::tile_sheet);
    // Инициализация генератора шума с использованием сида
    noiseGenerator.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noiseGenerator.SetFrequency(map::noise_frequency);
    noiseGenerator.SetSeed(seed);
}

Chunk* TileMap::getChunk(int chunkX, int chunkY) {
    auto chunkKey = std::make_pair(chunkX, chunkY);
    if (chunkCache.find(chunkKey) != chunkCache.end()) {
        return chunkCache[chunkKey];
    }

    auto newChunk = new Chunk(chunkX, chunkY, noiseGenerator, &tile_sheet);
    chunkCache[chunkKey] = newChunk;
    return newChunk;
}

void TileMap::renderChunks(const sf::Vector2f& player_pos, const unsigned short& distance_of_render, sf::RenderWindow* window) {
    // Рендер карты вокруг игрока
    for (int y = static_cast<int>(player_pos.x) / map::tile_size / map::tile_scale / 16 - distance_of_render; y < static_cast<int>(player_pos.x) / map::tile_size / map::tile_scale / 16 + distance_of_render; y++) {
        for (int x = static_cast<int>(player_pos.x) / map::tile_size / map::tile_scale / 16 - distance_of_render; x < static_cast<int>(player_pos.x) / map::tile_size / map::tile_scale / 16 + distance_of_render; x++) {
            auto chunk = getChunk(x, y);
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    window->draw(chunk->tiles[i][j].sprite);
                }
            }
        }
    }
}

// Сохранение мира в бинарный файл
void TileMap::saveWorld(const std::string& filename, const sf::Vector2f& player_pos) {
    std::ofstream outFile(filename, std::ios::binary);

    // Сохраняем имя мира
    size_t nameLength = worldName.length();
    outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    outFile.write(worldName.c_str(), nameLength);

    float playerX = player_pos.x;
    float playerY = player_pos.y;

    // Сохраняем позицию игрока
    outFile.write(reinterpret_cast<char*>(&playerX), sizeof(player_pos.x));
    outFile.write(reinterpret_cast<char*>(&playerY), sizeof(player_pos.y));

    // Сохраняем чанки
    for (const auto& chunkPair : chunkCache) {
        auto chunk = chunkPair.second;

        // Сохраняем координаты чанка
        outFile.write(reinterpret_cast<char*>(&chunk->x), sizeof(chunk->x));
        outFile.write(reinterpret_cast<char*>(&chunk->y), sizeof(chunk->y));

        // Сохраняем тайлы
        for (int y = 0; y < 16; ++y) {
            for (int x = 0; x < 16; ++x) {
                int id = chunk->tiles[y][x].id;
                outFile.write(reinterpret_cast<char*>(&id), sizeof(id));
            }
        }
    }

    outFile.close();
}

// Загрузка мира из бинарного файла
void TileMap::loadWorld(const std::string& filename, sf::Vector2f& player_pos) {
    std::ifstream inFile(filename, std::ios::binary);

    // Загружаем имя мира
    size_t nameLength;
    inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    worldName.resize(nameLength);
    inFile.read(&worldName[0], nameLength);

    float playerX = 0;
    float playerY = 0;

    // Загружаем позицию игрока
    inFile.read(reinterpret_cast<char*>(&playerX), sizeof(playerX));
    inFile.read(reinterpret_cast<char*>(&playerY), sizeof(playerY));

    player_pos = {playerX, playerY};

    // Загружаем чанки
    while (inFile.peek() != EOF) {
        int chunkX, chunkY;
        inFile.read(reinterpret_cast<char*>(&chunkX), sizeof(chunkX));
        inFile.read(reinterpret_cast<char*>(&chunkY), sizeof(chunkY));

        auto chunk = new Chunk(chunkX, chunkY, noiseGenerator, &tile_sheet);

        // Загружаем тайлы
        for (int y = 0; y < 16; ++y) {
            for (int x = 0; x < 16; ++x) {
                int id;
                inFile.read(reinterpret_cast<char*>(&id), sizeof(id));

                // Присваиваем символ тайлу
                chunk->tiles[y][x].id = id;
            }
        }

        // Добавляем чанк в кеш
        chunkCache[std::make_pair(chunkX, chunkY)] = chunk;
    }

    inFile.close();
}
