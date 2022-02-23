#include <iostream>
#include <string>
#include "classSnake.h"
#include "classPong.h"

string inputJeu;
string game;
Pong GamePong;
Snakes GameSnake;

string lower(string str){
    for (int i=0;i<str.length();i++){
        str[i]= tolower(str[i]);
    }
    return str;
}


int main(){
    std::cout<<"A quelle jeu voulez vous jouer? ('pong' ou 'snake' ) : ";
    std::cin>>inputJeu;
    game=lower(inputJeu);
    switch (game){
        case "pong":
            GamePong.Play();
            break;
        case "snake":
            GameSnake.Play();
            break;
        default:
            break;
    }

}
