#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <SFML/Graphics.hpp>
#include "../OBSTACLES/OBSTACLES.h"

class Doodle{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
    const float GRAVITY = 5.0f;
    const float JmpSpeed = 8.0f;
    const float max_fall_spd = 4.0f;
    bool hasjumped = false;
public:
    Doodle();
    ~Doodle();
    Doodle& operator = (const Doodle& doodle);

    [[maybe_unused]] Doodle(const Doodle& doodle);
    friend std::ostream& operator <<(std::ostream& out, const Doodle& doodle);

    void handlekeys();
    void handle_gravity();
    void jump();
    void die();
    sf::Sprite getSprite() {return sprite;}

    void move(float deltaX, float deltaY);


    void check_collision(Obstacle obstacle);

    void update(const Obstacle& obstacles);
};


#endif //OOP_PLAYER_H
