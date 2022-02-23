#ifndef CLASSSNAKE_H
#define CLASSSNAKE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

class Snakes{
public:
    Snakes();
    void Direction();
    void Collision();


private:
    //variables pour le calcul des fps
    float fps=0;
    int mfps=0;
    sf::Clock timer;
    float currentTime=0;

    sf::Clock clockfct; //pour le temps de recharge de la page

    //variables pour le déplacement du serpent
    int size=40;
    int height=size*size;int width=size*size;
    int num=1;
    std::string dir="right";
    bool afficherFPS= false;


    struct snake{int x, y;} s[1600];
    struct apple{int x,y;} f;

    sf::RenderWindow window;
    sf::Font font;


};

#endif
