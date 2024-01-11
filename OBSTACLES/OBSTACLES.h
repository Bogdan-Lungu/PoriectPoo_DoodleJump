/*
Obstacolele reprezinta platformele care se spawneaza de sus in jos.
Si care dispar atunci cand trec de partea de jos a ecranului.
*/
#include <SFML/Graphics.hpp>
#ifndef OOP_OPSTACLES_H
#define OOP_OPSTACLES_H

// Clasa "Obstacle" reprezinta platforma standard a jocului lipsita de functionalitate
class Obstacle {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    float gapY{};
    float gapHeight{};
public:
    sf::FloatRect getLowerBounds() const {
        sf::FloatRect upperBounds = sprite.getGlobalBounds();
        float spacing = 70.0f;  // Adjust the spacing based on your requirements

        sf::FloatRect lowerBounds = upperBounds;
        lowerBounds.top += upperBounds.height / 2 + spacing;

        return lowerBounds;
    }

    Obstacle([[maybe_unused]] float upperHeight, [[maybe_unused]] float playerSpace);
    ~Obstacle();
    Obstacle& operator=(const Obstacle& obstacle);
    Obstacle([[maybe_unused]] const Obstacle& opstacle);
    friend std::ostream& operator<<(std::ostream & out, const Obstacle& opstacle);

    void update();
    void die();

    sf::Sprite getSprite() { return sprite; }
};


// Clasa "BreakingPlatforms" reprezinta o derivare a clasei "Obstacle",
// singura diferenta fiind faptul ca aceste platforme nu vor avea colision si vor disparea dupa interactiune
class BreakingPlatform : public Obstacle {
public:
    [[maybe_unused]] BreakingPlatform(float upperHeight, float playerSpace);
    ~BreakingPlatform();
    BreakingPlatform& operator=(const BreakingPlatform& breakingPlatform);

    [[maybe_unused]] BreakingPlatform(const BreakingPlatform& breakingPlatform);

    [[maybe_unused]] void jumpOnPlatform(); // Add method for jumping behavior
};

// Clasa "JumpAndBreakPlatform" reprezint tot o derivare a clasei "Obstacle"
// Singura diferenta fata de BreakingPlatforms fiind faptul ca acestea vor avea o singura interactiune iar dupa acea vor disparea
class JumpAndBreakPlatform : public Obstacle {
private:
    bool hasBeenJumpedOn;
public:
    [[maybe_unused]] JumpAndBreakPlatform(float upperHeight, float playerSpace);
    ~JumpAndBreakPlatform();
    JumpAndBreakPlatform& operator=(const JumpAndBreakPlatform& jumpAndBreakPlatform);

    [[maybe_unused]] JumpAndBreakPlatform(const JumpAndBreakPlatform& jumpAndBreakPlatform);

    void update();

    [[maybe_unused]] void jumpOnPlatform(); // De adaugat caracteristici "jump"
};

// La fel ca si clasele de sus, doar ca misccarea este doar pe axa X
class MovingPlatform : public Obstacle {
public:
    [[maybe_unused]] MovingPlatform(float upperHeight, float playerSpace);
    ~MovingPlatform();
    MovingPlatform& operator=(const MovingPlatform& movingPlatform);

    [[maybe_unused]] MovingPlatform(const MovingPlatform& movingPlatform);

    void update();
    void movingPlatform(); // De adaugat caracteristici "moving stml"

};

#endif