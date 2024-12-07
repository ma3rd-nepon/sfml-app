#include <iostream>
#include <random>

#include "./game.h"

Game::Game() {
    window = new sf::RenderWindow (sf::VideoMode(window::WINDOW_WIDTH, window::WINDOW_HEIGHT), window::TITLE);
    window->setFramerateLimit(window::FPS);
    window->setVerticalSyncEnabled(true);

    camera = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(window::WINDOW_WIDTH, window::WINDOW_HEIGHT));
    player = new Player(window, sf::Vector2f(player::PLAYER_START_X, player::PLAYER_START_Y), Direction::RIGHT, player::pl_path, player::player_rows_cols, player::player_frame_size, player::player_map);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-2'147'483'648, 2'147'483'647);
    int random_seed = distrib(gen);

    world = TileMap(random_seed, "test");
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
    window->clear(sf::Color(51, 147, 255));
    window->setView(*camera);
    world.renderChunks(player->getPosition(), 2, window);
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
                linear_interpolation(settings::CAMERA_SPEED, 0.f, 1.f, static_cast<float>(camera->getCenter().x), static_cast<float>(player->getSprite().getPosition().x)),
                linear_interpolation(settings::CAMERA_SPEED, 0.f, 1.f, static_cast<float>(camera->getCenter().y), static_cast<float>(player->getSprite().getPosition().y))
                ));
        draw();
    }
}