//
// Created by Joseph Pouradier duteil on 11/03/2022.
//

#ifndef CLASSENEMY_H
#define CLASSENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy{
public:
    Enemy();
    void setDir(int WIDTH, int HEIGHT);
    void enemyMoving(sf::Vector2f rectPos);
    sf::RectangleShape getShape();

private:
    sf::RectangleShape shape;
    sf::Color BLUE=sf::Color(0,0,255,255);
    sf::Vector2f dir;
    sf::Vector2f newDir;
    sf::Vector2f Size;
    float size = 20;
    float speed = 2;
};

#endif CLASSENEMY_H
