#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

class Ball {
    public:
        sf::CircleShape C;
        Ball(int rad, int x, int y, int r, int g, int b) {
            C.setRadius(r);
            C.setPosition(x, y);
            C.setFillColor(sf::Color(r, g, b));
        }
        void move(float x, float y);
        void update();
};

int main() {
    // Ball ball(50, 100, 30, 250, 0, 0);
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Test");
    Ball b(100, 50, 50, 121, 54, 12);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Blue);
        // display code here
        window.draw(b.C);

        window.display();
    }


    return 0;
}
