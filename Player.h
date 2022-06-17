#include "GameObject.h"

class Player: public GameObject {
    using GameObject::GameObject;
    public:
        void loop() override;

};

