//
// Created by lungu on 10/31/2023.
//

#include "Enemies.h"
#include <iostream>

Enemy::Enemy() {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Enemy.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
}

Enemy::~Enemy() {
    std::cout << "Enemy destructor\n";
}


Enemy& Enemy::operator=(const Enemy &enemy) {
    texture = enemy.texture;
    sprite = enemy.sprite;
    velocity = enemy.velocity;
    return *this;
}


Enemy::Enemy(const Enemy& enemy) {
    texture = enemy.texture;
    sprite = enemy.sprite;
    velocity = enemy.velocity;
}

/*std::ostream& operator<<(std::ostream& out, const Doodle& doodle) {
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
}*/
void Enemy::update() {
    //handlekeys();
    //handle_gravity();
    check_collision();
    //sprite.move(velocity);
}
void Enemy::check_collision() {
    if(sprite.getPosition().y>550.0f || sprite.getPosition().y<-35.0f )  ///Aici de citit cu denis
        die();
}
/*
void Enemy::die()                                   ///aici tot cu denis
{
    hasjumped = false;
    sf::Vector2f startPosition(100.0f, 300.0f);
    sprite.setPosition(startPosition);
}
*/