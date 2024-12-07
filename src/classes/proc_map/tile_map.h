#include <map>
#include <memory>
#include <fstream>
#include "chunk.h"


class TileMap {
private:
    std::map<std::pair<int, int>, Chunk*> chunkCache;
    FastNoiseLite noiseGenerator;
    std::string worldName;
    sf::Texture tile_sheet;

public:
    TileMap(int seed, std::string  name);

    Chunk* getChunk(int chunkX, int chunkY);
    void renderChunks(const sf::Vector2f& player_pos, const unsigned short& distance_of_render, sf::RenderWindow* window);

    void saveWorld(const std::string& filename, const sf::Vector2f& player_pos);
    void loadWorld(const std::string& filename, sf::Vector2f& player_pos);
};
