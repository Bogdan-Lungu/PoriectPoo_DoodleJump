#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <SFML/Graphics.hpp>


class Enemy{
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
public:
    Enemy();
    ~Enemy();
    Enemy& operator = (const Enemy& enemy);
    Enemy(const Enemy& enemy);
    friend std::ostream& operator <<(std::ostream& out, const Enemy& enemy);

    void update();
    void die();
    void check_collision();
    sf::Sprite getSprite() {return sprite;}
};




#endif //OOP_PLAYER_H




