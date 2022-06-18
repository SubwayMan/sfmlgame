#include "Player.h"
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

void Player::loop() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
        this->move(sf::Vector2f(0, -20));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
        this->move(sf::Vector2f(0, 20));
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
        this->move(sf::Vector2f(-20, 0));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
        this->move(sf::Vector2f(20, 0));
    
}
