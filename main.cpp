#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "PLAYER/Player.h"
#include "OPSTACLES/OBSTACLES.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    sf::RenderWindow window;
    window.create(sf::VideoMode({600, 1000}), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
   /* sf::RectangleShape player(sf::Vector2f(70.0f ,100.0f));
    player.setPosition(100.0f , 100.0f);
    sf::Texture playerTexture;*/

    //sf::Texture backgroundTexture;
    //backgroundTexture.loadFromFile("ASSETS/TEXTURES/Backround.png");
    //sf::Sprite background(backgroundTexture);

   Doodle doodle = Doodle();
   Obstacle obstacle = Obstacle(10.0f , 10.0f);

    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            //Am comentat pt ca nu vreau sa schimb marimea, strica jocul
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                break;
              default:
                  break;
            }
        }
       /* if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-2.0f,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(2.0f,0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0.0f,-2.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0.0f,2.0f);
        }*/

        doodle.update();
        obstacle.update();

        window.clear();

        //window.draw(background);
        window.draw(doodle.getSprite());
        window.draw(obstacle.getSprite());

    /*
        window.clear();
        //window.draw(player);
        window.display();

        window.clear();
        window.display();
        */
    }


    return 0;
}
