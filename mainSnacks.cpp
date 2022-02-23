#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

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
sf::RectangleShape Head (sf::Vector2f(size,size));
sf::RectangleShape Apple (sf::Vector2f(size,size));
sf::Font font;
sf::Text score(std::to_string(num), font, 50);
sf::Text FPS("FPS: "+std::to_string(fps),font,20);
sf::Text MaxFPS ("MAX FPS: "+std::to_string(mfps),font,20);

void Direction(){
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

void Collision(){
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

int main(){
    window.create(sf::VideoMode(width,height,32),"SFML Snakes");
    window.setFramerateLimit(80);
    Head.setFillColor(sf::Color::Green);
    Apple.setFillColor(sf::Color::Red);
    if (!font.loadFromFile("/Users/jopouradierduteil/CLionProjects/untitled/arial.ttf"))
        return EXIT_FAILURE;
    score.setPosition(width/2,10);
    FPS.setPosition(width-150,10);
    MaxFPS.setPosition(width-150,30);

    //on initialise une pomme avec des coordonnées random
    f.x=rand()%size;
    f.y=rand()%size;

    while (window.isOpen()){
        sf::Event event;

        //prise en compte des touches
        while (window.pollEvent(event)) {
            switch (event.type){
                case (sf::Event::KeyReleased):
                    if (event.key.code==sf::Keyboard::Escape){
                        window.close();
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

    return 0;
}

