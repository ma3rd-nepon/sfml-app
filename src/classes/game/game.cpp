#include <iostream>

#include "./game.h"


Game::Game() {
    window = new sf::RenderWindow (sf::VideoMode(window::WINDOW_WIDTH, window::WINDOW_HEIGHT), window::TITLE);
    window->setFramerateLimit(window::FPS);

    player = new Player(window, sf::Vector2f(player::PLAYER_START_X, player::PLAYER_START_Y), Direction::RIGHT, player::pl_path);
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
        // std::cout << player->getTimer();
        draw();
    }
}