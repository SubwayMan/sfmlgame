#include "headers/GameManager.h"
#include "headers/GameObject.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Window.hpp>

GameManager::GameManager(sf::Window *w) {
    this->window = w;
}

void GameManager::addGameObject(GameObject* g, bool isCollider) {
    this->objectList.insert(g);
    if (isCollider) 
        this->colliders.insert(g);
}


