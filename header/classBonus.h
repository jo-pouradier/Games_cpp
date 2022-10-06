//
// Created by Joseph Pouradier duteil on 25/03/2022.
//

#ifndef CLASSPONG_CPP_CLASSBONUS_H
#define CLASSPONG_CPP_CLASSBONUS_H

#include <SFML/Graphics.hpp>

class Bonus{
public:
    Bonus(int bonusInd);
    void setRandPosition(int WIDTH, int HEIGHT);
    sf::RectangleShape getShape();
    int getBonusInd();

private:
    sf::RectangleShape shape;
    sf::Vector2<float> *pos = nullptr;
    std::vector<sf::Color> bonusColor;
    sf::Color const color1 = sf::Color(0,255,0,255);
    sf::Color const color2 = sf::Color(0,200,50,255);
    sf::Color const color3 = sf::Color(0,150,100,255);
    sf::Color const color4 = sf::Color(0,100,150,255);
    float size = 20;
    int bonusInd;
};

#endif //CLASSPONG_CPP_CLASSBONUS_H
