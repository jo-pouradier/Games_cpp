//
// Created by Joseph Pouradier duteil on 11/03/2022.
//

#include "header/classEnemy.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>

Enemy::Enemy() {
    shape.setFillColor(BLUE);
    Size.x=size;
    Size.y=size;
    shape.setSize(Size);
}

void Enemy::setDir(int WIDTH, int HEIGHT) {
    float height, width;
    int RLHL= rand() % 4;
    height = (float) rand()/RAND_MAX;
    width = (float) rand()/RAND_MAX;
    switch (RLHL) {
        case 0:
            shape.setPosition(float(WIDTH)-20, (float(HEIGHT)-20) * height); //coté droit
            break;
        case 1:
            shape.setPosition(0, (float(HEIGHT)-20) * height); // coté gauche
            break;
        case 2:
            shape.setPosition((float(WIDTH)-20) * width, float(HEIGHT)-20); // en bas
            break;
        case 3:
            shape.setPosition((float(WIDTH)-20) * width, 0); // en haut
    }
}

void Enemy::enemyMoving(sf::Vector2f rectPos) {
    dir = sf::Vector2f(rectPos-shape.getPosition());
    newDir = dir/float(sqrt(pow(dir.x,2)+pow(dir.y,2)));
    shape.move(newDir*speed);
}

sf::RectangleShape Enemy::getShape() {
    return shape;
}
