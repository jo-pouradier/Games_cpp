#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include "classSnake.h"


Snakes::Snakes(){
    Head.setSize(sf::Vector2f(size,size));
    Apple.setSize(sf::Vector2f(size,size));

    score.setString(std::to_string(num));
    score.setFont(font);
    score.setCharacterSize(50);

    FPS.setString(std::to_string(fps));
    FPS.setFont(font);
    FPS.setCharacterSize(20);

    FPS.setString("MAX FPS: "+std::to_string(mfps));
    FPS.setFont(font);
    FPS.setCharacterSize(20);

    Head.setFillColor(sf::Color::Green);
    Apple.setFillColor(sf::Color::Red);
    font.loadFromFile("/Users/jopouradierduteil/CLionProjects/untitled/arial.ttf"); //il peut y avoir erreur
    score.setPosition(width/2,10);
    FPS.setPosition(width-150,10);
    MaxFPS.setPosition(width-150,30);

    //on initialise une pomme avec des coordonnées random
    f.x=rand()%size;
    f.y=rand()%size;
}

void Snakes::Play(){
    play=true;
    window.create(sf::VideoMode(width,height,32),"SFML Snakes",sf::Style::None);
    window.setFramerateLimit(80);
    while (play) Running();
}

void Snakes::Running(){
    sf::Event event;
    //prise en compte des touches
    while (window.pollEvent(event)) getKey (event);

    if (clockfct.getElapsedTime().asMilliseconds()>100){
        Direction();
        Collision();
        clockfct.restart();
    }

    //modification des différents labels
    Apple.setPosition(f.x*size,f.y*size);
    score.setString(std::to_string(num));
    currentTime = timer.restart().asSeconds();
    fps = 1.0f / currentTime; // the asSeconds returns a float
    int floorfps=floor(fps);
    if (floorfps>mfps) mfps=floorfps;
    FPS.setString("FPS: "+std::to_string(floorfps));
    MaxFPS.setString(("MAX FPS: "+std::to_string(mfps)));

    Drawing();
}

void Snakes::Direction(){
    //chaque case prend la place de la suivante (on garde en mémoire le virage)
    for (int i=num;i>0;i--){
        s[i].x=s[i-1].x;
        s[i].y=s[i-1].y;
    }
    // changement de direction en fct des touches
    if (dir=="up") s[0].y--;
    if (dir=="down") s[0].y++;
    if (dir=="right") s[0].x++;
    if (dir=="left") s[0].x--;
}

void Snakes::Collision(){
    //collision avec lui meme
    for (int i=1;i<num;i++){
        if (s[0].x==s[i].x && s[0].y==s[i].y) num=0;
    }
    //collision avec les murs (on passe de l'autre côté)
    if (s[0].x>size) s[0].x=0;
    if (s[0].x<0) s[0].x=size;
    if (s[0].y>size) s[0].y=0;
    if (s[0].y<0) s[0].y=size;
    //collision avec la pomme
    if (s[0].x==f.x && s[0].y==f.y){
        num++;
        f.x=rand()%size;
        f.y=rand()%size;
    }
}

void Snakes::Drawing() {
    //on affiche le tout
    window.clear();
    //on draw chaque partie du serpent
    for (int i=0;i<num;i++){
        Head.setPosition(s[i].x*size,s[i].y*size);
        window.draw(Head);
    }
    if(afficherFPS) {
        window.draw(FPS);
        window.draw(MaxFPS);
    }
    window.draw(Apple);
    window.draw(score);
    window.display();
}

void Snakes::getKey(sf::Event event){
    switch (event.type){
        case (sf::Event::KeyReleased):
            if (event.key.code==sf::Keyboard::Escape){
                Stop();
            }
            break;
        case (sf::Event::KeyPressed):
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir="up";
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir="down";
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dir="right";
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir="left";
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { //pour afficher les FPS
                if (!afficherFPS) afficherFPS=true;
                else afficherFPS= false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && num ==0) num=1; //pour rejouer

            break;
        default:
            break;
    }
}


void Snakes::Stop(){
    play= false;
    window.close();
}

std::string Snakes::getName() {
    return name;
}