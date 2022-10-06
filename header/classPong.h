//
// Created by Joseph Pouradier duteil on 22/02/2022.
//

#ifndef MYPROJECT_GAME_H
#define MYPROJECT_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace  std;

class Pong {
    struct Button {bool left, right, up, down,cheat;};

public:
    Pong();
    void SetWindow();
    void Play();
    void Running();
    void Stop();
    void CheckBtn();
    void UpdateBall();
    void UpdateGame();
    void Cheat();
    void getKey(sf::Event);
    string getName();

private:
    struct Button button;

    string name="Pong";
    string fontFile="sources/arial.ttf";

    bool play=false;

    const int WIN_WIDTH = 1400;
    const int WIN_HEIGHT = 800;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text txt;

    sf::CircleShape Balle;
    sf::RectangleShape raquetteRight;
    sf::RectangleShape raquetteLeft;

    float posRLeftX=40;
    float posRRightX=WIN_WIDTH-60;
    float posRLeftY=WIN_HEIGHT/2;
    float posRRightY=posRLeftY;
    float rSpeed=8;
    float rHeight=150;
    float rWidth=20;

    float bSpeed=10;
    float posBX=WIN_HEIGHT/2;
    float posBY=WIN_WIDTH/2;
    sf::Vector2f bDir= sf::Vector2f (1.0f,1.f);

    int scoreJ1=0;
    int scoreJ2=0;
};

#endif //MYPROJECT_GAME_H
