#pragma once

#include <string>
#include <vector>

namespace textures {
    static std::vector<sf::IntRect> cut_frame_list(sf::Texture* sheet, int rows, int columns, int width, int height, int transparent = 255) {
        sf::Texture text;
        sf::Image base;
        std::vector<sf::IntRect> frame_vec;
        sf::Rect<int> frame;

        base.create(width, height);
        text.create(width, height);

        if ((transparent > 0) && (transparent < 256)) {
            sf::Color c = base.getPixel(0, 0);
            c.a = transparent;
            base.setPixel(0, 0, c);
        } else if ((transparent > 255) || (transparent < 0)) { transparent = 255; } 

        for (int i {0}; i < rows; i++) {
            for (int j {0}; j < columns; j++) {
                frame = sf::Rect<int>((width * j + (j * 5)), (height * i + (10 * i)), width, height);
                // text.loadFromImage(base, frame);
                frame_vec.push_back(frame);
            }
        }

        return frame_vec;
    }

    static std::vector<std::vector<sf::IntRect>> def_anims(std::string texturepath) {
        sf::Texture texture;
        std::vector<std::vector<sf::IntRect>> result;

        sf::Texture idle;
        sf::Texture walk;

        texture.loadFromFile(texturepath);
        unsigned int w {texture.getSize().x}; 
        unsigned int h {texture.getSize().y};

        idle.create(w, h); // где то здесь ебатня // дтнаху
        walk.create(w, h); // ща в д

        sf::Image idle_base;
        sf::Image walk_base;

        idle_base.create(w, h);
        walk_base.create(w, h);

        idle.loadFromImage(idle_base, sf::Rect<int>(0, 0, 250, 110));
        walk.loadFromImage(walk_base, sf::Rect<int>(0, 120, 250, 110));

        std::vector<sf::IntRect> r_idle = textures::cut_frame_list(&idle, 3, 1, 80, 110);
        std::vector<sf::IntRect> r_walk = textures::cut_frame_list(&walk, 3, 1, 80, 110);

        result.push_back(r_idle);
        result.push_back(r_walk);

        return result;
    }
}