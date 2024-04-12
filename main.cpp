#include <string>
#include <iostream>
#include <thread> 
#include <cmath> 

#include "lib/include/ball.h"
#include "lib/include/renderer.h"
#include "lib/ball.cpp"
#include "lib/include/collision.h"

void rainbow(Ball& ball, float t) {
    float r = sin(t);
    float g = sin(t + 0.33f * 2.0f * M_PI);
    float b = sin(t + 0.66f * 2.0f * M_PI);
    r = r * r * 255.0f;
    g = g * g * 255.0f;
    b = b * b * 255.0f;
    ball.color = sf::Color(r, g, b);
}

int main()
{
    int NUM_BALLS = 1500;

    float winX = 800.0f;
    float winY = 700.0f;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "balls");
    double rad = 10.0;

    float startX = 200.0f;
    float startY = 200.0f;
    sf::Vector2f startVel = {400.0f, 100.0f};

    float spawn_delay = 0.02f;
    const int framerate = 60;
    window.setFramerateLimit(framerate);

    Handler handler(winX, winY, NUM_BALLS);
    Renderer renderer(window);

    handler.setFrameDt(framerate);
    
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                window.close();
        }

        if (handler.getNumBalls() < NUM_BALLS && clock.getElapsedTime().asSeconds() >= spawn_delay) {
            clock.restart();
            auto& newBall = handler.addNewBall({startX, startY}, rad);
            newBall.setVelocity(startVel, handler.getFrameDt());
            rainbow(newBall, handler.getTime());
        }

        handler.update();
        window.clear(sf::Color::Black);
        renderer.render(handler);     
        window.display();

    }

    return 0;
}