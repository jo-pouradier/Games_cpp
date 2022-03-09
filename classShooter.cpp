//
// Created by Joseph Pouradier duteil on 09/03/2022.
//

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "classShooter.h"
#include "classBullet.h"

Shooter::Shooter(){
    rectSize.x= rect_width;
    rectSize.y= rect_height;
    rectPosition.x= rectPosX;
    rectPosition.y= rectPosY;
    rect.setSize(rectSize);
    rect.setFillColor(WHITE);
    rect.setPosition(rectPosition);
    rect.setOrigin(rect_width/2, rect_height/2);
}

void Shooter::Play(){
    play=true;
    window.create(sf::VideoMode(WIDTH,HEIGHT,32),"SFML Snakes");
    window.setFramerateLimit(80);
    while (play) Running();
}

void Shooter::Stop(){
    play=false;
    window.close();
}

void Shooter::Running(){
    sf::Event event{};
    while (window.pollEvent(event)) Input(event);
    Mouvement();
    Shoot();
    if (sf::Event::MouseMoved) Rotation();
    moveBullet();
    Drawing();
}

void Shooter::Mouvement(){
    if (button.right) dx=3;
    if (button.left) dx=-3;
    if (button.up) dy=-3;
    if (button.down) dy=3;
    if (not button.right && not button.left) dx=0;
    if (not button.up && not button.down) dy=0;
    //Collisions avec les bords de la fenêtre
    if (rect.getPosition().x>WIDTH-50 || rect.getPosition().x< 50) dx=0;
    if (rect.getPosition().y>=HEIGHT-25 || rect.getPosition().y< 25) dy=0;

    rect.move(dx,dy);
}

void Shooter::Drawing(){
    window.clear(GRAY);
    window.draw(rect);
    for (auto & bullet : bullets){
        window.draw(bullet.getShape());
    }
    window.display();
}

void Shooter::Rotation() {
    float newPosX(rect.getPosition().x);
    float newPosY(rect.getPosition().y);
    float mousePosX(sf::Mouse::getPosition(window).x);
    float mousePosY(sf::Mouse::getPosition(window).y);
    //On met Mouse et rect dans les memes "axes" de rotation d'où le +90 et +360
    if (mousePosX > newPosX) newTheta = 90.f + atan2(mousePosY - newPosY, mousePosX - newPosX) * (180 / 3.14);
    if (mousePosX <= newPosX) newTheta = 360.0 - atan2(newPosX - mousePosX, newPosY - mousePosY) * (180 / 3.14);

    rect.rotate( newTheta-rect.getRotation());
}

void Shooter::Input(sf::Event event) {
    char touche(event.key.code);
    switch (event.type) {
        case (sf::Event::Closed):
            Stop();
            break;
        case sf::Event::KeyPressed:
            if (touche == sf::Keyboard::Z)
                button.up=true;
            if (touche == sf::Keyboard::S)
                button.down=true;
            if (touche == sf::Keyboard::D)
                button.right=true;
            if (touche == sf::Keyboard::Q)
                button.left=true;
            break;
        case sf::Event::KeyReleased:
            if (touche==sf::Keyboard::Escape)
                Stop();
            if (touche == sf::Keyboard::Z)
                button.up=false;
            if (touche == sf::Keyboard::S)
                button.down=false;
            if (touche == sf::Keyboard::D)
                button.right=false;
            if (touche == sf::Keyboard::Q)
                button.left=false;
            break;
        case sf::Event::MouseButtonPressed:
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) button.shoot=true;
            break;
        case sf::Event::MouseButtonReleased:
            if (not sf::Mouse::isButtonPressed(sf::Mouse::Left)) button.shoot=false;
            break;
    }
}

void Shooter::Shoot(){
    if (button.shoot && shootClock.getElapsedTime().asSeconds()>shootTimer){
        b1.Positioning(rect.getPosition());
        sf::Vector2f mousePosNow=sf::Vector2f(sf::Mouse::getPosition(window));
        b1.setDir(sf::Vector2f(mousePosNow-rectPosition));
        bullets.push_back(Bullet(b1));
        shootClock.restart();
    }
}

void Shooter::moveBullet(){
    for (int i=0; i<bullets.size();i++){
        bullets[i].Moving();
        //collisions avec les bords
        if (bullets[i].getShape().getPosition().x < 0 || bullets[i].getShape().getPosition().x > WIDTH
        || bullets[i].getShape().getPosition().y < 0 || bullets[i].getShape().getPosition().y > HEIGHT){
            bullets.erase(bullets.begin()+i);
        }
    }
}
