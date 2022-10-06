//
// Created by Joseph Pouradier duteil on 09/03/2022.
//

#ifndef CLASSSHOOTER_H
#define CLASSSHOOTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "classBullet.h"
#include "classEnemy.h"
#include "classBonus.h"

class Shooter{
    struct Button {bool left = false, right= false, up= false, down= false, shoot=false;};

public:
    Shooter();
    void Play();
    void Stop();
    void Pause();
    void Running();
    void Rotation();
    void Input();
    void Mouvement();
    void Drawing();
    void UpdateText();
    void Shoot();
    void SpawnEnemy();
    void SpawnBonus();
    void CollisionsEnemy();
    void CollisionsWall();
    void CollisionsBonus();
    void MouseHoverPause(sf::RectangleShape *shape);
    bool MouseHoverClick(sf::RectangleShape *shape);
    void PauseMusic();
    std::string getName();
    //TODO fonction SpawnBonus

private:
    float WIDTH = 1600;
    float HEIGHT = 1200;
    std::string name = "Shooter";

    sf::RenderWindow window;
    sf::Event event; //event{}
    sf::RectangleShape rect;

    sf::Color const WhiteG = sf::Color(200,200,201,255);
    sf::Color const GrayW = sf::Color(70,70,73,255);
    sf::Color const GrayD = sf::Color(24,24,26,255);
    sf::Color const WHITE=sf::Color(255,255,255,255);
    sf::Color const BlackPause = sf::Color(10,10,10,180);

    sf::Font font;
    sf::Text scoreTxt;
    sf::Text nbrEnemyTxt;
    sf::Music music;
    std::string musicFile = "sources/tetris-gameboy-02.wav";
    std::string fontFile= "sources/arial.ttf";
//variables du rectangle/joueur
    float rect_width=100;
    float rect_height=50;
    float rectPosX=WIDTH/2;
    float rectPosY=HEIGHT/2;
    float dx=0;
    float dy=0;
    float newTheta=0;
    float shootTimer=0.1; //change
    float enemyTimer = 0.1; //change
    float bonusTimer = 0.1;
    int playerSpeed = 3;
    int score = 0;

    sf::Vector2f rectSize;
    sf::Vector2f rectPosition;

    std::vector<Bullet*> bullets;
    std::vector<Enemy*> enemies;
    std::vector<Bonus*> bonuses;

    Button button;
    Bullet *b1= nullptr;
    Enemy *e1 = nullptr;
    Bonus *bo1 = nullptr;

    sf::Clock shootClock;
    sf::Clock enemyClock;
    sf::Clock bonusClock;

    bool play;
    bool pause;
};

#endif 
