#include "OBSTACLES.h"
#include <iostream>

Obstacle::Obstacle([[maybe_unused]] float upperHeight, [[maybe_unused]] float playerSpace) {
    velocity = {-0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile(R"(C:\Users\lungu\CLionProjects\PoriectPoo_DoodleJump\ASSETS\Verde.png)");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({300.0f, 300.0f});
}

Obstacle::~Obstacle() {
    std::cout << "Obstacle destructor\n";
}

Obstacle& Obstacle::operator=(const Obstacle& obstacle) {
    if (this != &obstacle) {
        texture = obstacle.texture;
        sprite = obstacle.sprite;
        velocity = obstacle.velocity;
    }
    return *this;
}

Obstacle::Obstacle(const Obstacle& obstacle) {
    texture = obstacle.texture;
    sprite = obstacle.sprite;
    velocity = obstacle.velocity;
}

std::ostream& operator<<(std::ostream& out, const Obstacle& obstacle) {
    out << "Obstacle position: " << obstacle.sprite.getPosition().x << ", " << obstacle.sprite.getPosition().y;
    return out;
}

void Obstacle::update() {
    sprite.move(velocity);

    if (sprite.getPosition().x < -1.0f)
        die();
}

void Obstacle::die() {
    sf::Vector2f startPosition(700.0f, -100.0f);
    sprite.setPosition(startPosition);
}

BreakingPlatform::BreakingPlatform(float upperHeight, float playerSpace) : Obstacle(upperHeight, playerSpace) {}

BreakingPlatform::~BreakingPlatform() {
    std::cout << "BreakingPlatform destructor\n";
}

BreakingPlatform& BreakingPlatform::operator=(const BreakingPlatform& breakingPlatform) {
    if (this != &breakingPlatform) {
        Obstacle::operator=(breakingPlatform);
    }
    return *this;
}

BreakingPlatform::BreakingPlatform(const BreakingPlatform& breakingPlatform) : Obstacle(breakingPlatform) {}

void BreakingPlatform::jumpOnPlatform() {
    // Add logic for jumping behavior
    // ...
    die();  // For example, breaking platforms disappear after interaction
}

JumpAndBreakPlatform::JumpAndBreakPlatform(float upperHeight, float playerSpace) : Obstacle(upperHeight, playerSpace) {
    hasBeenJumpedOn = false;
}

JumpAndBreakPlatform::~JumpAndBreakPlatform() {
    std::cout << "JumpAndBreakPlatform destructor\n";
}

JumpAndBreakPlatform& JumpAndBreakPlatform::operator=(const JumpAndBreakPlatform& jumpAndBreakPlatform) {
    if (this != &jumpAndBreakPlatform) {
        Obstacle::operator=(jumpAndBreakPlatform);
        hasBeenJumpedOn = jumpAndBreakPlatform.hasBeenJumpedOn;
    }
    return *this;
}

JumpAndBreakPlatform::JumpAndBreakPlatform(const JumpAndBreakPlatform& jumpAndBreakPlatform) : Obstacle(jumpAndBreakPlatform) {
    hasBeenJumpedOn = jumpAndBreakPlatform.hasBeenJumpedOn;
}

void JumpAndBreakPlatform::update() {
    if (hasBeenJumpedOn) {
        // Add logic for disappearing after interaction
        // ...
        die();
    }
}

void JumpAndBreakPlatform::jumpOnPlatform() {
    // Add logic for jumping behavior
    // ...
    hasBeenJumpedOn = true;
}

MovingPlatform::MovingPlatform(float upperHeight, float playerSpace) : Obstacle(upperHeight, playerSpace) {}

MovingPlatform::~MovingPlatform() {
    std::cout << "MovingPlatform destructor\n";
}

MovingPlatform& MovingPlatform::operator=(const MovingPlatform& movingPlatform) {
    if (this != &movingPlatform) {
        Obstacle::operator=(movingPlatform);
    }
    return *this;
}

MovingPlatform::MovingPlatform(const MovingPlatform& movingPlatform) : Obstacle(movingPlatform) {}

void MovingPlatform::update() {
    movingPlatform();  // Assuming you have a function for moving behavior
}

void MovingPlatform::movingPlatform() {
    // Add logic for moving behavior
    // ...
}
