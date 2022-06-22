#pragma once
#include "GameObject.h"

class Player: public GameObject {
    public:
        Player(double x, double y, double w, double h, GameManager *GM) : GameObject(x, y, w, h, GM){
            this->setTexture("assets/knuckles.png");
        };
        void loop() override;

};

