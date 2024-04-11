#pragma once
#include "ball.h"
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <cmath> 

class Renderer {
    public:
        Renderer(sf::RenderTarget& win) 
            : window{win}
        {}
        
        void render(Handler& handler) {
            sf::CircleShape circle{1.0f};
            auto& balls = handler.getBalls();
            for (auto& ball : balls) {
                circle.setPosition(ball.currentPosition);
                circle.setRadius(ball.radius);
                circle.setFillColor(ball.color);
                window.draw(circle);
            }
        }

    private:
        sf::RenderTarget& window;
};