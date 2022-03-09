//
// Created by Joseph Pouradier duteil on 09/03/2022.
//

#ifndef CLASSBULLET_H
#define CLASSBULLET_H

#include <SFML/Graphics.hpp>
#include "classBullet.h"

class Bullet{
public:
    Bullet();
    void setDir(sf::Vector2f direction);
    sf::CircleShape getShape();
    sf::Vector2f getVel();

private:
    sf::Color Red=sf::Color::Red;
    sf::Vector2f dir;
    sf::Vector2f directionNorme;
    sf::CircleShape shape;
    int size=8;
    float speed=4;
};


#endif CLASSBULLET_H
