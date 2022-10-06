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
    ~Bullet();
    void setDir(sf::Vector2f direction);
    sf::CircleShape getShape();
    sf::Vector2f getVel();
    void Positioning(sf::Vector2f pos);
    void Moving();

private:
    sf::Color Red=sf::Color::Red;
    sf::Vector2f dir;
    sf::CircleShape shape;
    int size=8;
    float speed=20;

};


#endif 
