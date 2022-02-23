//
// Created by Joseph Pouradier duteil on 22/02/2022.
//

#ifndef MYPROJECT_GAME_H
#define MYPROJECT_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "input.h"

using namespace sf;
using namespace  std;

class Pong {
    struct Button {bool left, right, up, down,escape,cheat;};

public:
    Pong();
    void getKey(Event);
    void Play();
    void Running();
    void Stop();
    void SetWindow();
    void SetText(Text &txt, String str);
    void CheckBtn();
    void UpdateBall();
    void UpdateGame();
    void Cheat();
    string getName();

private:
    Button button;

    string name="Pong";

    bool play=false;

    const int WIN_WIDTH = 800;
    const int WIN_HEIGHT = 600;

    RenderWindow window;
    //Input input;
    Font font;
    Text txt;

    CircleShape Balle;
    RectangleShape raquetteRight;
    RectangleShape raquetteLeft;

    float posRLeftX=40;
    float posRRightX=WIN_WIDTH-60;
    float posRLeftY=WIN_HEIGHT/2;
    float posRRightY=posRLeftY;
    float rSpeed=5;
    float rHeight=150;
    float rWidth=20;

    float bSpeed=2;
    float posBX=WIN_HEIGHT/2;
    float posBY=WIN_WIDTH/2;
    Vector2f bDir= Vector2f (1.0f,2);

    int scoreJ1=0;
    int scoreJ2=0;
};

#endif //MYPROJECT_GAME_H
