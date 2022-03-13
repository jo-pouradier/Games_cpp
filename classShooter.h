//
// Created by Joseph Pouradier duteil on 09/03/2022.
//

#ifndef CLASSSHOOTER_H
#define CLASSSHOOTER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "classBullet.h"
#include "classEnemy.h"

class Shooter{
    struct Button {bool left= false, right= false, up= false, down= false, shoot=false;};

public:
    Shooter();
    void Play();
    void Stop();
    void Pause();
    void Running();
    void Rotation();
    void Input(sf::Event event);
    void Mouvement();
    void Drawing();
    void Shoot();
    void SpawnEnemy();
    void CollisionsEnemy();
    void CollisionsWall();
    void MouseHoverPause(sf::RectangleShape *shape);
    bool MouseHoverClick(sf::RectangleShape *shape);

private:
    float WIDTH=1600;
    float HEIGHT=1200;

    sf::RenderWindow window;
    sf::RectangleShape rect;
    sf::Color const WhiteG = sf::Color(200,200,201,255);
    sf::Color const GrayW = sf::Color(70,70,73,255);
    sf::Color const GrayD = sf::Color(24,24,26,255);
    sf::Color const WHITE=sf::Color(255,255,255,255);
    sf::Color const BlackPause = sf::Color(10,10,10,180);
    std::string fontFile= "arial.ttf";
//variables du rectangle/joueur
    float rect_width=100;
    float rect_height=50;
    float rectPosX=WIDTH/2;
    float rectPosY=HEIGHT/2;
    float dx=0;
    float dy=0;
    float newTheta=0;
    float shootTimer=0.01; //change
    float enemySpawn = 0.1; //change
    sf::Vector2f rectSize;
    sf::Vector2f rectPosition;
    std::vector<Bullet*> bullets;
    std::vector<Enemy*> enemies;
    Button button;
    Bullet *b1= nullptr;
    Enemy *e1 = nullptr;
    sf::Clock shootClock;
    sf::Clock enemyClock;

    bool play;
    bool pause;
};

#endif CLASSSHOOTER_H
