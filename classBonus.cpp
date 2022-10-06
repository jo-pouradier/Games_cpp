//
// Created by Joseph Pouradier duteil on 25/03/2022.
//

#include "header/classBonus.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "iostream"

Bonus::Bonus(int bonusIndex) {
    bonusInd = bonusIndex;
    bonusColor.emplace_back(color1);
    bonusColor.emplace_back(color2);
    bonusColor.emplace_back(color3);
    bonusColor.emplace_back(color4);
    shape.setFillColor(bonusColor[bonusInd]);
    shape.setSize(sf::Vector2f (size, size));
}

int Bonus::getBonusInd() {
    return bonusInd;
}

void Bonus::setRandPosition(int WIDTH, int HEIGHT) {
    pos = new sf::Vector2<float>;
    pos->x = rand() % WIDTH;
    pos->y = rand() % HEIGHT;
    shape.setPosition(*pos);
}

sf::RectangleShape Bonus::getShape() {
    return shape;
}

