//
// Created by Joseph Pouradier duteil on 22/02/2022.
//
#include "classPong.h"

Pong::Pong(){
    //creation des raquettes
    raquetteRight.setSize(Vector2f(rWidth,rHeight));
    raquetteRight.setPosition(posRRightX,posRRightY);
    raquetteLeft.setSize(Vector2f(rWidth,rHeight));
    raquetteLeft.setPosition(posRLeftX,posRLeftY);
    //creation de la balle
    Balle.setRadius(15);
    Balle.setPosition(posBX,posBY);
    //creation du text
    font.loadFromFile("/Users/jopouradierduteil/CLionProjects/untitled/arial.ttf");
    txt.setString(to_string(scoreJ1)+ " | " + to_string(scoreJ2));
    txt.setFont(font);
    txt.setCharacterSize(35);
    txt.setFillColor(Color::White);
    txt.setPosition((WIN_WIDTH/2)-40,10);
}

void Pong::Play(){
    SetWindow();
    play=true;
    while(play) Running();
}

void Pong::Running(){
    sf::Event event; //variables des evenements

    while (window.pollEvent(event)) input.InputHandler(event, window);

    //gestion du clavier
    CheckBtn();
    //on repositionne les raquettes
    raquetteLeft.setPosition(posRLeftX,posRLeftY);
    raquetteRight.setPosition(posRRightX,posRRightY);

    UpdateBall();
    Balle.setPosition(posBX,posBY);

    UpdateGame();
}

void Pong::SetWindow() {
    window.create(VideoMode(WIN_WIDTH,WIN_HEIGHT,32),"Pong SFML");
    window.setFramerateLimit(80);
}

void Pong::UpdateBall(){
    posBX+=bDir.x*bSpeed;
    posBY+=bDir.y*bSpeed;

    //collision avec la raquette droite ou gauche, prendre en compte la hauteur de la balle
    if (posBX < posRLeftX+rWidth && posBX > posRLeftX &&
        posBY+15 > posRLeftY  && posBY+15 < posRLeftY+rHeight ||
        posBX+15 > posRRightX && posBX+15 < posRRightX+rWidth &&
        posBY >posRRightY  && posBY+15 < posRRightY+rHeight){
        bDir.x*=-1; //symétrie par rapport a Y
    }
    //collision mur gauche
    if (posBX<0){
        scoreJ2++;
        posBX=WIN_WIDTH/2;
        posBY=WIN_HEIGHT/2;
        //on redirige la balle vers le gagnant
        bDir.x*=-1;
        bDir.y*=-1;
    }
    //collision mur droite
    if (posBX+15>WIN_WIDTH){
        scoreJ1++;
        posBX=WIN_WIDTH/2 -8;
        posBY=WIN_HEIGHT/2 -8;
        //on redirige la balle vers le gagnant
        bDir.x*=-1;
        bDir.y*=-1;
    }
    //collision mur du haut ou bas
    if (posBY>WIN_HEIGHT || posBY<0){
        bDir.y*=-1; //symetrie par rapport a X
    }
}

void Pong::CheckBtn(){
    //la position de la raquette est faite par rapport au coin supp gauche, axe y de haut en bas !
    //raquette de gauche
    if (input.GetButton().up){
        posRLeftY-=rSpeed;
        if (posRLeftY<0){
            posRLeftY=0;
        }
    }
    if (input.GetButton().down){
        posRLeftY+=rSpeed;
        if (posRLeftY>WIN_HEIGHT-rHeight){
            posRLeftY=WIN_HEIGHT-rHeight ;
        }
    }
    //raquette de droite
    if (input.GetButton().left){
        posRRightY-=rSpeed;
        if (posRRightY<0){
            posRRightY=0;
        }
    }
    if (input.GetButton().right){
        posRRightY+=rSpeed;
        if (posRRightY>WIN_HEIGHT-rHeight){
            posRRightY=WIN_HEIGHT-rHeight ;
        }
    }
    if (input.GetButton().escape){
        Stop();
    }
    if (input.GetButton().cheat){
        Cheat();
    }
}

void Pong::UpdateGame(){
    //on dessine enfin nos element
    txt.setString(to_string(scoreJ1)+ " | " + to_string(scoreJ2));
    window.clear(Color::Black);
    window.draw(txt);
    window.draw(raquetteRight);
    window.draw(raquetteLeft);
    window.draw(Balle);
    //On affiche le tout
    window.display();
}

void Pong::Cheat() {
    posRLeftY=posBY-50;
}

void Pong::Stop(){
    play=false;
    window.close();
}