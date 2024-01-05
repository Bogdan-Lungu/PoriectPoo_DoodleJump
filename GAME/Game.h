#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "../PLAYER/Player.h"
#include "../OBSTACLES/OBSTACLES.h"


#ifdef __linux__
#include <X11/Xlib.h>
#endif

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleGameOver() {

        std::cerr << "Game Over!" << std::endl;
        window.close();
    }
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::Texture playerTexture;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    Doodle doodle;
    Obstacle obstacle;
};

#endif //OOP_GAME_H
