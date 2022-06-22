#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "headers/GameManager.h"
#include "headers/Player.h"
#include "headers/GameObject.h"

int main() {
    // Ball ball(50, 100, 30, 250, 0, 0);
    sf::Event event;

    sf::VideoMode vm = sf::VideoMode::getFullscreenModes()[0];

    sf::RenderWindow window(vm, "SFML Test");
    window.setFramerateLimit(60);


    GameManager GM(&window);
    Player knux(20, 20, 100, 100, &GM);
    Blank bl(500, 500, 100, 100, &GM);
    bl.setTexture("assets/placeholder.png");
    GM.addGameObject(&knux, true);
    GM.addGameObject(&bl, true);

    knux.scaleToSize();
    bl.scaleToSize();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        // display code here

        for (auto obj: GM.objectList) {
            obj->loop();
            window.draw(obj->sprite);
        }


        window.display();
    }


    return 0;
}
