#include "Game.h"
#include "../EXCEPTII/Exceptii.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

Game::Game() : obstacle(10.0f, 10.0f) {
    try {
#ifdef __linux__
        XInitThreads();
#endif

        window.create(sf::VideoMode({600, 800}), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar);
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);

        player.setSize(sf::Vector2f(70.0f, 100.0f));
        player.setPosition(100.0f, 100.0f);

        playerTexture.loadFromFile(R"(C:\Users\lungu\CLionProjects\PoriectPoo_DoodleJump\ASSETS\Doodle.png)");
        if (!playerTexture.loadFromFile(R"(C:\Users\lungu\CLionProjects\PoriectPoo_DoodleJump\ASSETS\Doodle.png)")) {
            throw TextureFail();
        }
        player.setTexture(&playerTexture);

        backgroundTexture.loadFromFile(R"(C:\Users\lungu\CLionProjects\PoriectPoo_DoodleJump\ASSETS\Fundal.png)");
        if (!backgroundTexture.loadFromFile(R"(C:\Users\lungu\CLionProjects\PoriectPoo_DoodleJump\ASSETS\Fundal.png)")) {
            throw TextureFail();
        }
        background.setTexture(backgroundTexture);

    } catch (const TextureFail& e) {
        std::cerr << "Texture loading failed: " << e.what() << std::endl;

    } catch (const DoodleCollisionException& e) {
        std::cerr << "Doodle collision: " << e.what() << std::endl;

    } catch (const DoodleOutOfScreenException& e) {
        std::cerr << "Doodle out of screen: " << e.what() << std::endl;

    } catch (const GameOverException& e) {
        std::cerr << "Game over: " << e.what() << std::endl;

    }
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event e{};
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;

            default:
                break;
        }
    }
}

void Game::update() {
    try {
        doodle.update(obstacle);

        obstacle.update();


    } catch (const DoodleCollisionException& e) {
        std::cerr << "Doodle collision during update: " << e.what() << std::endl;
        handleGameOver();
    } catch (const DoodleOutOfScreenException& e) {
        std::cerr << "Doodle out of screen during update: " << e.what() << std::endl;
        handleGameOver();
    } catch (const GameOverException& e) {
        std::cerr << "Game over during update: " << e.what() << std::endl;
        handleGameOver();
    }
}


void Game::render() {
    try {
        window.clear();
        window.draw(background);
        window.draw(doodle.getSprite());
        window.draw(obstacle.getSprite());
        window.display();
    } catch (const DoodleCollisionException& e) {
        std::cerr << "Doodle collision during render: " << e.what() << std::endl;
    } catch (const DoodleOutOfScreenException& e) {
        std::cerr << "Doodle out of screen during render: " << e.what() << std::endl;
    } catch (const GameOverException& e) {
        std::cerr << "Game over during render: " << e.what() << std::endl;
    }
}
