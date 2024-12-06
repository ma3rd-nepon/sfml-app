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
    window->setView(*camera);
    window->draw(*circle);
    player->draw();
    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        time = static_cast<float>(clock.getElapsedTime().asMicroseconds()) / 6000;
        clock.restart();

        sf::Event event;
        while (window->pollEvent(event)) {
            EventHandler(event);
        }

        player->Update(time);
        camera->setCenter(sf::Vector2f(
                linear_interpolation(settings::CAMERA_FOLLOW_SPEED, 0.f, 1.f, static_cast<float>(camera->getCenter().x), static_cast<float>(player->getSprite().getPosition().x)),
                linear_interpolation(settings::CAMERA_FOLLOW_SPEED, 0.f, 1.f, static_cast<float>(camera->getCenter().y), static_cast<float>(player->getSprite().getPosition().y))
                ));
        draw();
    }
}