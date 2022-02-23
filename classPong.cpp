//
// Created by Joseph Pouradier duteil on 22/02/2022.
//
#include "classPong.h"

Pong
::Pong
(){

    //initialisation des raquettes, de la balle et du score
    //creation des raquettes
    RectangleShape raquetteRight(Vector2f(rWidth,rHeight));
    raquetteRight.setPosition(posRRightX,posRRightY);
    RectangleShape raquetteLeft(Vector2f(rWidth,rHeight));
    raquetteLeft.setPosition(posRLeftX,posRLeftY);
    //creation de la balle
    CircleShape Balle(15);
    Balle.setPosition(posBX,posBY);
    //creation du text
    font.loadFromFile("/Users/jopouradierduteil/CLionProjects/untitled/arial.ttf");
    SetText(txt,to_string(scoreJ1)+ " | " + to_string(scoreJ2));

    SetWindow();

    while (window.isOpen()){

        Event event; //variables des evenements

        while (window.pollEvent(event)) {
            //changement des inputs
            input.InputHandler(event, window);
        }

        //gestion du clavier
        CheckBtn();
        //on repositionne les raquettes
        raquetteLeft.setPosition(posRLeftX,posRLeftY);
        raquetteRight.setPosition(posRRightX,posRRightY);

        UpdateBall();
        Balle.setPosition(posBX,posBY);

        UpdateGame(raquetteRight,raquetteLeft,Balle);


    }

}

void Pong
::SetWindow() {
    window.create(VideoMode(WIN_WIDTH,WIN_HEIGHT,32),"Pong SFML");
    window.setFramerateLimit(80);
}

void Pong
::UpdateBall(){
    posBX+=bDir.x*bSpeed;
    posBY+=bDir.y*bSpeed;

    //collision avec la raquette droite ou gauche, prendre en compte la hauteur de la balle
    if (posBX < posRLeftX+rWidth && posBX > posRLeftX &&
        posBY+15 < posRLeftY+rHeight && posBY > posRLeftY ||
        posBX+15 > posRRightX && posBX+15 < posRRightX+rWidth &&
        posBY+15 < posRRightY+rHeight && posBY >posRRightY){
        bDir.x*=-1; //symétrie par rapport a Y
    }
    //collision mur gauche
    if (posBX<0){
        scoreJ2++;
        SetText(txt,to_string(scoreJ1)+ " | " + to_string(scoreJ2));
        posBX=WIN_WIDTH/2;
        posBY=WIN_HEIGHT/2;
        //on redirige la balle vers le gagnant
        bDir.x*=-1;
        bDir.y*=-1;
    }
    //collision mur droite
    if (posBX+15>WIN_WIDTH){
        scoreJ1++;
        SetText(txt,to_string(scoreJ1)+ " | " + to_string(scoreJ2));
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

void Pong
::SetText(Text& txt, String str){
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(35);
    txt.setFillColor(Color::White);
    txt.setPosition((WIN_WIDTH/2)-40,10);
}

void Pong
::CheckBtn(){
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
        window.close();
    }
    if (input.GetButton().cheat){
        Cheat();
    }
}

void Pong
::UpdateGame(RectangleShape R1,RectangleShape R2,CircleShape B){
    //on dessine enfin nos element
    window.clear(Color::Black);
    window.draw(txt);
    window.draw(R1);
    window.draw(R2);
    window.draw(B);
    //On affiche le tout
    window.display();
}

void Pong
::Cheat() {
    posRLeftY=posBY-50;
}