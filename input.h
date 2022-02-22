//
// Created by Joseph Pouradier duteil on 22/02/2022.
//

#ifndef MYPROJECT_INPUT_H
#define MYPROJECT_INPUT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Input{

    struct Button {bool left, right, up, down,escape,cheat;};

public:
    Input();
    Button GetButton(void);
    void InputHandler (Event event, RenderWindow& window);

private:
    Button button;
};


#endif //MYPROJECT_INPUT_H
