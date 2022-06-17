#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.h"
#include "GameObject.h"

int main() {
    // Ball ball(50, 100, 30, 250, 0, 0);
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    window.setFramerateLimit(60);

    int xVel = 3;
    int yVel = 3;
    Player knux(20, 20, 100, 100, "./assets/knuckles.png");
    std::vector<GameObject*> gameObjects;
    gameObjects.push_back(&knux);

    knux.scaleToSize();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        // display code here
        window.draw(knux.sprite);

        for (auto obj: gameObjects) {
            obj->loop();
        }


        window.display();
    }


    return 0;
}
