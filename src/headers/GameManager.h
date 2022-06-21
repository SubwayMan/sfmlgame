#pragma once
#include "GameObject.h"
#include <SFML/Window/Window.hpp>
#include <set>
#include <SFML/Window.hpp>

class GameManager {
    public:
        std::set<GameObject*> colliders;
        std::set<GameObject*> objectList;
        sf::Window *window;

        GameManager(sf::Window *window);
        void addGameObject(GameObject *, bool);
};
  
