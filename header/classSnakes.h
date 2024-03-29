#ifndef CLASSSNAKE_H
#define CLASSSNAKE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

class Snakes{
public:
    Snakes();
    ~Snakes();
    void Play();
    void Stop();
    void Running();
    void Direction();
    void Collision();
    void Drawing();
    void getKey(sf::Event);
    std::string getName();


private:
    std::string name = "Snakes" ;
    std::string fontFile="sources/arial.ttf";

    bool play=false;
    //variables pour le calcul des fps
    float fps=0;
    int mfps=0;
    sf::Clock timer;
    float currentTime=0;

    sf::Text score;
    sf::Text FPS;
    sf::Text MaxFPS ;

    sf::Clock clockfct; //pour le temps de recharge de la page

    //variables pour le déplacement du serpent
    int size=20;
    int height=size*size;int width = size*size;
    sf::RectangleShape Head ;
    sf::RectangleShape Apple;
    int num=1;
    std::string dir="right";
    bool afficherFPS= false;


    struct snake{int x, y;} s[1600];
    struct apple{int x,y;} f;

    sf::RenderWindow window;
    sf::Font font;
};

#endif
