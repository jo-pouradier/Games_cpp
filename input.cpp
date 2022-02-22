//
// Created by Joseph Pouradier duteil on 22/02/2022.
//
#include "input.h"
#include <iostream>

Input::Input() {
    button.left = button.right = button.down = button.up = button.escape =button.cheat= false;
}

Input::Button Input::GetButton(){
    return button;
}

void Input::InputHandler(Event event, RenderWindow& window) {
    if (event.type ==Event::Closed){
        window.close();
    }
    if (event.type==Event::KeyPressed){
        switch (event.key.code){
            case Keyboard::Escape:
                button.escape= true;
                break;
            case Keyboard::Right:
                button.right=true;
                break;
            case Keyboard::Left:
                button.left=true;
                break;
            case Keyboard::Up:
                button.up=true;
                break;
            case Keyboard::Down:
                button.down=true;
                break;
            case Keyboard::T:
                if (!button.cheat){
                    button.cheat= true;
                }
                else{
                    button.cheat=false;
                }

            default:
                break;
        }
    }
    if (event.type==Event::KeyReleased){
        switch (event.key.code){
            case Keyboard::Escape:
                button.escape= false;
                break;
            case Keyboard::Right:
                button.right=false;
                break;
            case Keyboard::Left:
                button.left=false;
                break;
            case Keyboard::Up:
                button.up=false;
                break;
            case Keyboard::Down:
                button.down=false;
                break;
            default:
                break;
        }
    }

}