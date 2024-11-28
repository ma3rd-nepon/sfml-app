#include "./game.h"


Game::Game() {
    window = new sf::RenderWindow (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE);
    window->setFramerateLimit(FPS);

    player = new Player(window, sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), Direction::RIGHT, textures::player_texture);
}

Game::~Game() {
    delete player;
}

void Game::Start() {
    run();
}

void Game::EventHandler(sf::Event& event) {
    switch (event.type) {
        case (sf::Event::Closed):
            window->close();
            break;
    }
}

void Game::draw() {
    window->clear(sf::Color(64, 64, 64));
    player->draw();
    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        time = (clock.getElapsedTime().asMicroseconds()) / 6000;
        clock.restart();

        sf::Event event;
        while (window->pollEvent(event)) {
            EventHandler(event);
        }

        player->Update(time);
        draw();
    }
}