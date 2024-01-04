#pragma once
#include<SFML/Graphics.hpp>

class Ball {
    public:
        float x;
        float y;
        float initVelY;
        float velY;
        float velX;
        float t;
        float rad;
        sf::CircleShape drawing;
};