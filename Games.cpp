#include <SFML/Graphics.hpp>
#include <iostream>
#include "classSnake.h"
#include "classPong.h"
#include "classShooter.h"

Pong GamePong;
Snakes GameSnake;
Shooter GameShooter;

int const WIN_WIDTH=200, WIN_HEIGHT=200;
sf::Color const WhiteG(200,200,201,255);
sf::Color const GrayW(70,70,73,255);
sf::Color const GrayD (24,24,26,255);

sf::RenderWindow window;
sf::Text textPong,textSnake,textShooter;
sf::Font font;
sf::RectangleShape RectPong,RectSnake,RectShooter;
sf::Vector2f RectSize;
sf::Mouse mouse;
sf::Vector2i mPosition;
sf::Vector2f textPongPosition,textSnakePosition,textShooterPosition;

std::string fontFile("arial.ttf");


void mouseHover(sf::Vector2i mPosition){
    if (textSnakePosition.y<mPosition.y && mPosition.y<textSnakePosition.y+40){
        RectSnake.setFillColor(WhiteG);
        textSnake.setFillColor(GrayW);
    }
    else {
        RectSnake.setFillColor(GrayW);
        textSnake.setFillColor(WhiteG);
    }
    if ((textPongPosition.y)<mPosition.y && mPosition.y<(textPongPosition.y+40)){
        RectPong.setFillColor(WhiteG);
        textPong.setFillColor(GrayW);
    }
    else{
        RectPong.setFillColor(GrayW);
        textPong.setFillColor(WhiteG);
    }
    if ((textShooterPosition.y)<mPosition.y && mPosition.y<(textShooterPosition.y+40)){
        RectShooter.setFillColor(WhiteG);
        textShooter.setFillColor(GrayW);
    }
    else{
        RectShooter.setFillColor(GrayW);
        textShooter.setFillColor(WhiteG);
    }
}

int main(){

    window.create (VideoMode(WIN_WIDTH,WIN_HEIGHT,32),"Games");
    window.setFramerateLimit(30);

    font.loadFromFile(fontFile);

    textPong.setString(GamePong.getName());
    textPongPosition.x=(40),textPongPosition.y=50;
    textPong.setPosition(textPongPosition);
    textPong.setFont(font);
    textPong.setFillColor(WhiteG);

    textSnakePosition.x=(40),textSnakePosition.y=100;
    textSnake.setString(GameSnake.getName());
    textSnake.setPosition(textSnakePosition);
    textSnake.setFont(font);
    textSnake.setFillColor(WhiteG);

    textShooterPosition.x=(40),textShooterPosition.y=150;
    textShooter.setString(GameShooter.getName());
    textShooter.setPosition(textShooterPosition);
    textShooter.setFont(font);
    textShooter.setFillColor(WhiteG);

    RectSize.x=WIN_WIDTH;
    RectSize.y=40;

    RectPong.setSize(RectSize);
    RectPong.setFillColor(GrayW);
    RectPong.setPosition(0,textPongPosition.y);

    RectSnake.setSize(RectSize);
    RectSnake.setFillColor(GrayW);
    RectSnake.setPosition(0,textSnakePosition.y);

    RectShooter.setSize(RectSize);
    RectShooter.setFillColor(GrayW);
    RectShooter.setPosition(0,textShooterPosition.y);

    while(window.isOpen()){
        sf::Event event{};
        mPosition = sf::Mouse::getPosition(window);
        mouseHover(mPosition);
        while (window.pollEvent(event)){
            switch (event.type) {
                case (sf::Event::Closed):
                    window.close();
                    break;
                case (sf::Event::KeyReleased):
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
                case (sf::Event::MouseButtonPressed):
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        if (textSnakePosition.y<mPosition.y && mPosition.y<textSnakePosition.y+40){
                            GameSnake.Play();
                        }
                        if ((textPongPosition.y)<mPosition.y && mPosition.y<(textPongPosition.y+40)){
                            GamePong.Play();
                        }
                        if ((textShooterPosition.y)<mPosition.y && mPosition.y<(textShooterPosition.y+40)){
                            GameShooter.Play();
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        window.clear(GrayD);
        window.draw(RectSnake);
        window.draw(textSnake);

        window.draw(RectPong);
        window.draw(textPong);

        window.draw(RectShooter);
        window.draw(textShooter);

        window.display();
    }
}
