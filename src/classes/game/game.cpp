#include "./game.h"

Game::Game() {
    window = new sf::RenderWindow (sf::VideoMode(settings::WINDOW_WIDTH, settings::WINDOW_HEIGHT), strings::TITLE);
    window->setFramerateLimit(settings::FPS);
    camera = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(settings::WINDOW_WIDTH, settings::WINDOW_HEIGHT));

    player = new Player(window, sf::Vector2f(0, 0), Direction::RIGHT, strings::pl_path);
    circle = new sf::CircleShape(25.f);
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