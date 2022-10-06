#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode(1200,800),"the hello world window");
    sf::Vector2u shapePosition;
    shapePosition.x=0;
    shapePosition.y=50;

    sf::CircleShape *shape = new sf::CircleShape;
    shape->setRadius(30.f);
    shape->setPosition(shapePosition.x,shapePosition.y);

    sf::Texture background;
    if (!background.loadFromFile("/Users/jopouradierduteil/Desktop/Perso/Code/untitled_copie/sources/background_space_4.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(background);

    sf::Font font;
    if (!font.loadFromFile("/Users/jopouradierduteil/Desktop/Perso/Code/untitled_copie/sources/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    text.setPosition(600,0);

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close(); // close est le destructeur
        }
        if (shapePosition.x >= 1200)
            shape->setPosition(shape->getPosition().x + 10,shape->getPosition().y);
        else
            shape->setPosition(shape->getPosition().x,shape->getPosition().y+10);
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.draw(*shape);
        window.display();

    }
    return EXIT_SUCCESS;
}
