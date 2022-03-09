//
// Created by Joseph Pouradier duteil on 09/03/2022.
//
#include <SFML/Graphics.hpp>
#include "classBullet.h"
#include <cmath>

Bullet::Bullet(){
    shape.setFillColor(Red);
    shape.setRadius(size);
}

void Bullet::setDir(sf::Vector2f direction) {
    //normalisation du vecteur direction
    dir=direction/float(sqrt(pow(direction.x,2)+pow(direction.y,2)));
}

sf::CircleShape Bullet::getShape(){
    return shape;
}

sf::Vector2f Bullet::getVel() {
    return dir*speed;
}