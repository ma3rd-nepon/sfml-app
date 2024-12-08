#include <iostream>

#include "./game.h"

Game::Game() {
    window = new sf::RenderWindow (sf::VideoMode(window::WINDOW_WIDTH, window::WINDOW_HEIGHT), window::TITLE);
    window->setFramerateLimit(window::FPS);
    window->setVerticalSyncEnabled(true);

    map_texture.loadFromFile("./assets/textures/map.png");
    map_sprite.setTexture(map_texture);
    map_sprite.move(-500, -500);
    map_sprite.setOrigin(500, 500);
    map_sprite.setScale(3, 3);

    camera = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(window::WINDOW_WIDTH, window::WINDOW_HEIGHT));
    player = new Player(window, sf::Vector2f(0, 0), Direction::RIGHT, player::pl_path, player::player_rows_cols, player::player_frame_size, player::player_map);
    skeleton = new Neutral(window, sf::Vector2f(0, 0), Direction::RIGHT, entity::skeleton_path, entity::skeleton_rc, entity::skeleton_frame_size, entity::skeleton_map);
    circle = new sf::CircleShape(5.f);
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
    window->draw(map_sprite);
    window->draw(*circle);
    player->draw();
    skeleton->draw();
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
        skeleton->Update(time);
        camera->setCenter(sf::Vector2f(
                linear_interpolation(settings::CAMERA_SPEED, 0.f, 1.f, static_cast<float>(camera->getCenter().x), static_cast<float>(player->getSprite().getPosition().x)),
                linear_interpolation(settings::CAMERA_SPEED, 0.f, 1.f, static_cast<float>(camera->getCenter().y), static_cast<float>(player->getSprite().getPosition().y))
                ));
        draw();
    }
}