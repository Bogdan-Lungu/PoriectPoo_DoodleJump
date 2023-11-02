//
// Created by lungu on 10/31/2023.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include <SFML/Graphics.hpp>



class Doodle{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
    const float GRAVITY = 1.0f;  //  DE STERS VALORI DACA NU FUNCTIONEAZA
    const float JmpSpeed = 8.0f;
    const float max_fall_spd = 4.0f;
    bool hasjumped = false;
public:
    Doodle();
    ~Doodle();
    Doodle& operator = (const Doodle& doodle);
    Doodle(const Doodle& doodle);
    friend std::ostream& operator <<(std::ostream& out, const Doodle& doodle);

    void update();
    void handlekeys();
    void handle_gravity();
    void jump();
    void die();
    void check_collision();
    sf::Sprite getSprite() {return sprite;}
};


#endif //OOP_PLAYER_H
