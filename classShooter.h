//
// Created by Joseph Pouradier duteil on 09/03/2022.
//

#ifndef CLASSSHOOTER_H
#define CLASSSHOOTER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "classBullet.h"

class Shooter{
    struct Button {bool left= false, right= false, up= false, down= false, shoot=false;};

public:
    Shooter();
    void Play();
    void Stop();
    void Running();
    void Rotation();
    void Input(sf::Event event);
    void Mouvement();
    void Drawing();
    void Shoot();
    void moveBullet();

private:
//variables du rectangle/joueur
    float rect_width=100;
    float rect_height=50;
    float rectPosX=WIDTH/2;
    float rectPosY=HEIGHT/2;
    float dx=0;
    float dy=0;
    float newTheta=0;
    float shootTimer=0.1;

    sf::Vector2f rectSize;
    sf::Vector2f rectPosition;
    std::vector<Bullet> bullets;

    Button button;
    Bullet b1;

    bool play;

    float WIDTH=1600;
    float HEIGHT=1200;

    sf::RenderWindow window;
    sf::RectangleShape rect;
    sf::Clock shootClock;

    sf::Color WHITE=sf::Color(255,255,255,255);
    sf::Color GRAY=sf::Color(24,24,26,255);
};

#endif CLASSSHOOTER_H
