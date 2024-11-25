#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "consts.cpp"


class Game {
    private:
        Game(sf::RenderWindow& window) {
            sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "anus rvetsya ot c++");
            window.setFramerateLimit(FPS);

            sf::RectangleShape rect(sf::Vector2f(120, 50));
            sf::CircleShape shape(25.f);

            sf::Clock clock;
            float time{};
        }

    void eventhandler() {
        sf::Event event;
        switch (event.type) {
            case (sf::Event::Closed):
            {
                window.close();
                break;
            }
            case (sf::Event::KeyPressed):
            {
                sf::Vector2f vel;
                sf::Vector2f pos = shape.getPosition();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    vel.y += -STEP * time;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    vel.x += -STEP * time;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    vel.y += STEP * time;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    vel.x += STEP * time;
                }

                auto speed = std::sqrt(vel.x * vel.x + vel.y * vel.y);

                if (speed > MAX_SPEED) {
                    vel.x *= MAX_SPEED / speed;
                    vel.y *= MAX_SPEED / speed;
                }

                pos.x += vel.x;
                pos.y += vel.y;

                shape.setPosition(pos);
                break;
            }
            }
    }

    void draw() {
        window.clear();
        window.draw(rect);
        window.draw(shape);
        window.display();
    }

    void update() {
        eventhandler();
        time = (clock.getElapsedTime().asMicroseconds()) / 6000;
        clock.restart();
        draw();
    }

    void run() {
        while (window.isOpen()) {
            update();
        }
    }


    public:

        void start() {
            run();
        }
};