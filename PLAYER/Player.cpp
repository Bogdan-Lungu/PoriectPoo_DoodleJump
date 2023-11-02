//
// Created by lungu on 10/31/2023.
//

#include "Player.h"
#include <iostream>

Doodle::Doodle() {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Doodle.png"); /////aici nu stiu daca e bine
    sprite = sf::Sprite();
    sprite.setTexture(texture);
}

    Doodle::~Doodle(){
    std::cout << "Doodle destructor\n";
    }


    Doodle& Doodle::operator=(const Doodle &doodle) {
        texture = doodle.texture;
        sprite = doodle.sprite;
        velocity = doodle.velocity;
        return *this;
    }


Doodle::Doodle(const Doodle& doodle) {
    texture = doodle.texture;
    sprite = doodle.sprite;
    velocity = doodle.velocity;
}

std::ostream& operator<<(std::ostream& out, const Doodle& doodle) {
    out << "Velocity X: " << doodle.velocity.x << "\n" << "Velocity Y: " << doodle.velocity.y;
    return out;
}

void Doodle::jump() {
    velocity.y = -JmpSpeed;
}

void Doodle::handlekeys() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        jump();
        hasjumped = true;
    }

}

void Doodle::handle_gravity() {

    if (!hasjumped) {
        velocity.y = 0.0f;
    } else {
        velocity.y += GRAVITY;
    }

    if (velocity.y > max_fall_spd){
        velocity.y = max_fall_spd;}
}
void Doodle::update() {
    handlekeys();
    handle_gravity();
    check_collision();
    sprite.move(velocity);
}
void Doodle::check_collision() {
    if(sprite.getPosition().y>550.0f || sprite.getPosition().y<-35.0f )
    die();
}

void Doodle::die()
{
    hasjumped = false;
    sf::Vector2f startPosition(100.0f, 300.0f);
    sprite.setPosition(startPosition);
}