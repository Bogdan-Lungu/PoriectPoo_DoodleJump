#include "Player.h"
#include "../EXCEPTII/Exceptii.h"
#include "../OBSTACLES/OBSTACLES.h"
#include <iostream>


Doodle::Doodle()
        : sprite(),
          texture(),
          velocity(0.0f, 0.0f) {
    texture.loadFromFile(R"(C:\Users\lungu\CLionProjects\PoriectPoo_DoodleJump\ASSETS\Doodle.png)");
    sprite.setPosition({250.0f, 550.0f});
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


[[maybe_unused]] Doodle::Doodle(const Doodle& doodle) {
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        move(-6.0f, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        move(6.0f, 0.0f);
    }
}

void Doodle::move(float deltaX, float deltaY) {

    sprite.move(deltaX, deltaY);


    if (sprite.getPosition().x < 0) {
        sprite.setPosition({600.0f, sprite.getPosition().y});
    }


    if (sprite.getPosition().x > 600.0f) {
        sprite.setPosition({0.0f, sprite.getPosition().y});
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
void Doodle::update(const Obstacle& obstacles) {
    handlekeys();
    handle_gravity();


    check_collision(obstacles);

    sprite.move(velocity);
}

void Doodle::check_collision(Obstacle obstacle) {

    if (sprite.getPosition().y > 550.0f || sprite.getPosition().y < -35.0f) {
        die();
        throw DoodleOutOfScreenException();
    }

    sf::FloatRect doodleBounds = sprite.getGlobalBounds();
    sf::FloatRect upperObstacleBounds = obstacle.getSprite().getGlobalBounds();
    sf::FloatRect lowerObstacleBounds = obstacle.getLowerBounds();


    if (doodleBounds.intersects(upperObstacleBounds) || doodleBounds.intersects(lowerObstacleBounds)) {
        die();
        throw DoodleCollisionException();
    }
}



void Doodle::die()
{
    hasjumped = false;
    sf::Vector2f startPosition(250.0f, 550.0f);
    sprite.setPosition(startPosition);
}