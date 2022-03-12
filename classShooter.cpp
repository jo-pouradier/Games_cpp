//
// Created by Joseph Pouradier duteil on 09/03/2022.
//

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "classShooter.h"
#include "classBullet.h"
#include "classEnemy.h"

Shooter::Shooter(){
    rectSize.x= rect_width;
    rectSize.y= rect_height;
    rectPosition.x= rectPosX;
    rectPosition.y= rectPosY;
    rect.setSize(rectSize);
    rect.setFillColor(WHITE);
    rect.setPosition(rectPosition);
    rect.setOrigin(rect_width/2, rect_height/2);
    play=false;
    pause=false;
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

void Shooter::Pause() {
    sf::Text *textPause, *textQuit;
    sf::Font *font;
    sf::RectangleShape *buttonPause, *buttonQuit, *background;
    sf::Vector2f *buttonPauseSize, *buttonQuitSize, *buttonPausePos, *buttonQuitPos;

    textPause = new sf::Text;
    textQuit= new sf::Text;
    font = new sf::Font;
    buttonPause = new sf::RectangleShape;
    buttonQuit = new sf::RectangleShape;
    background = new sf::RectangleShape;
    buttonPauseSize = new sf::Vector2f;
    buttonQuitSize = new sf::Vector2f;
    buttonPausePos = new sf::Vector2f;
    buttonQuitPos = new sf::Vector2f;

    textPause->setString("Play");
    textQuit->setString("Quit");
    font->loadFromFile(fontFile);
    textPause->setFont(*font);
    textQuit->setFont(*font);
    textPause->setPosition(WIDTH/5, HEIGHT/2);
    textQuit->setPosition(WIDTH*3/5, HEIGHT/2);
    textPause->setFillColor(WhiteG);
    textQuit->setFillColor(WhiteG);
    textPause->setCharacterSize(100);
    textQuit->setCharacterSize(100);

    *buttonPauseSize = sf::Vector2f (WIDTH/5, textPause->getCharacterSize());
    *buttonQuitSize = sf::Vector2f (WIDTH/5, textQuit->getCharacterSize());
    *buttonPausePos = sf::Vector2f (textPause->getPosition().x, textPause->getPosition().y);
    *buttonQuitPos = sf::Vector2f (textQuit->getPosition().x, textQuit->getPosition().y);
    buttonPause->setSize(*buttonPauseSize);
    buttonQuit->setSize(*buttonQuitSize);
    buttonPause->setPosition(*buttonPausePos);
    buttonQuit->setPosition(*buttonQuitPos);
    buttonPause->setFillColor(GrayW);
    buttonQuit->setFillColor(GrayW);
    background->setFillColor(GrayPause);

    Drawing();

    window.draw(*background);
    window.draw(*buttonQuit);
    window.draw(*buttonPause);
    window.draw(*textQuit);
    window.draw(*textPause);
    window.display();
}

void Shooter::Running(){
    sf::Event event{};
    while (window.pollEvent(event)) Input(event);
    if (not pause) {
        Mouvement();
        Shoot();
        Rotation();
        SpawnEnemy();
        CollisionsEnemy();
        CollisionsWall();
        Drawing();
        window.display();
    }
    else{
        Pause();
    }
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

    for (auto & bullet : bullets) {
        bullet->Moving();
    }

    for (auto & enemy : enemies){
        enemy->enemyMoving(sf::Vector2f (rect.getPosition()));
    }
}

void Shooter::Drawing(){
    window.clear(GrayD);

    for (auto & bullet : bullets){
        window.draw(bullet->getShape());
    }
    for (auto & enemy : enemies){
        window.draw(enemy->getShape());
    }
    window.draw(rect);
}

void Shooter::Rotation() {
    if (sf::Event::MouseMoved) {
        float newPosX(rect.getPosition().x);
        float newPosY(rect.getPosition().y);
        float mousePosX(sf::Mouse::getPosition(window).x);
        float mousePosY(sf::Mouse::getPosition(window).y);
        //On met Mouse et rect dans les memes "axes" de rotation d'où le +90 et +360
        if (mousePosX > newPosX) newTheta = 90.f + atan2(mousePosY - newPosY, mousePosX - newPosX) * (180 / 3.14);
        if (mousePosX <= newPosX) newTheta = 360.0 - atan2(newPosX - mousePosX, newPosY - mousePosY) * (180 / 3.14);

        rect.rotate(newTheta - rect.getRotation());
    }
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
            if (touche==sf::Keyboard::P)
                if (!pause)
                    pause = true;
                else{
                    pause = false;
                }
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
        b1 = new Bullet;
        b1->Positioning(rect.getPosition());
        sf::Vector2f mousePosNow = sf::Vector2f(sf::Mouse::getPosition(window));
        b1->setDir(sf::Vector2f(mousePosNow-rect.getPosition()));
        bullets.emplace_back(b1);
        shootClock.restart();
    }
}

void Shooter::SpawnEnemy() {
    if (enemyClock.getElapsedTime().asSeconds()>enemySpawn) {
        e1 = new Enemy;
        e1->setDir(float(WIDTH), float(HEIGHT));
        enemies.emplace_back(e1);
        enemyClock.restart();
    }
}

void Shooter::CollisionsEnemy() {
    for (int i = 0; i < bullets.size(); i++) {
        for (int k = 0; k < enemies.size(); k++) {
            if (bullets[i]->getShape().getGlobalBounds().intersects(enemies[k]->getShape().getGlobalBounds())) {
                delete bullets[i];
                delete enemies[k];
                bullets[i] = nullptr;
                enemies[k] = nullptr;
                bullets.erase(bullets.begin() + i);
                enemies.erase(enemies.begin() + k);
                break;    //NE PAS OUBLIER CE FOUTUE BREAK !!!! la balle peut avoir plusieurs collisions...
            }
        }
    }
}

void Shooter::CollisionsWall(){
    for (int i = 0; i < bullets.size(); i++){
        if (bullets[i]->getShape().getPosition().x < 0 || bullets[i]->getShape().getPosition().x > WIDTH
            || bullets[i]->getShape().getPosition().y < 0 || bullets[i]->getShape().getPosition().y > HEIGHT){
            delete bullets[i];
            bullets[i] = nullptr;
            bullets.erase(bullets.begin()+i);
        }
    }
}
