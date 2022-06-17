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
#include "GameObject.h"

class Ball {
    public:
        sf::CircleShape C;
        Ball(int rad, int x, int y, int r, int g, int b) {
            C.setRadius(rad);
            C.setPosition(x, y);
            C.setFillColor(sf::Color(r, g, b));
        }
        void move(float x, float y) {
            sf::Vector2f mv(x, y);
            C.setPosition(C.getPosition() + mv);
        }

        void update();
};

int main() {
    // Ball ball(50, 100, 30, 250, 0, 0);
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    window.setFramerateLimit(60);
    Ball b(30, 50, 50, 121, 54, 12);

    int xVel = 3;
    int yVel = 3;
    float brad = b.C.getRadius();
    GameObject knux(20, 20, 100, 100, "./assets/knuckles.png");

    knux.scaleToSize();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        // display code here
        window.draw(b.C);
        window.draw(knux.sprite);

        b.move(xVel, yVel);
        sf::Vector2f bpos = b.C.getPosition();
        if (bpos.x + 2*brad > 800) xVel = abs(xVel) * -1;
        if (bpos.y + 2*brad> 600) yVel = abs(yVel) * -1;
        if (bpos.x <= 0) xVel = abs(xVel);
        if (bpos.y <= 0) yVel = abs(yVel);
    

        window.display();
    }


    return 0;
}
