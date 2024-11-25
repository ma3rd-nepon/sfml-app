#include "./game.h"


Game::Game() {
    window = new sf::RenderWindow (sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "anus rvetsya ot c++");
    window->setFramerateLimit(FPS);

    //textures::setTextures();
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Green);
    player = new Player(shape.getTexture(), sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), PLAYER_START_HP);
}

Game::~Game() {
    delete player;
}

void Game::Initialize() {
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
    window->clear();
    window->draw(player->getSprite());
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