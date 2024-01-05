#include "Enemies.h"
#include <iostream>

Enemy::Enemy() {
    //velocity = {0.0f, 0.0f};
    //texture.loadFromFile("ASSETS/TEXTURES/Enemy.png");
    //sprite.setTexture(texture);
}

Enemy::~Enemy() {
    std::cout << "Enemy destructor\n";
}
/*
Enemy& Enemy::operator=(const Enemy &enemy) {
    //texture = enemy.texture;
    //sprite = enemy.sprite;
    //velocity = enemy.velocity;
    return *this;
}

Enemy::Enemy(const Enemy& enemy) {
    //texture = enemy.texture;
    //sprite = enemy.sprite;
    //velocity = enemy.velocity;
}

void Enemy::update() {
    check_collision();
}

void Enemy::check_collision() {
    if (sprite.getPosition().y > 600) { //aici sa verifici cu valoare data de ecran in main
        die();
    }
}

void Enemy::die() {
    //hasjumped = false;
    sf::Vector2f startPosition(100.0f, 300.0f);
    sprite.setPosition(startPosition);
}
*/
