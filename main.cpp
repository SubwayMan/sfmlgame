#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

class Ball {
    public:
        Ball(int rad, int x, int y, int r, int g, int b);
        sf::CircleShape C;
        void move(float x, float y);
        void update();
};

int main() {
    // Ball ball(50, 100, 30, 250, 0, 0);
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Test");

    //while (window.isOpen()) {
        //while (window.pollEvent(event))
    window.display();

    return 0;
}
