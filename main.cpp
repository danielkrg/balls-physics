#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath> 

#include "lib/include/ball.h"
#include "lib/ball.cpp"
#include "lib/collision.h"
#include "lib/collision.cpp"

int main()
{
    int NUM_BALLS = 100;

    int winX = 800;
    int winY = 700;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "balls");
    float rad = 5.0;

    int startX = 400;
    int startY = 600;
    float g = 0.0981;
    srand(time(NULL));

    Ball balls[NUM_BALLS];
    initBalls(balls, NUM_BALLS, startX, startY);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
        }

        window.clear();

        for(auto& ball : balls) {
            moveBall(ball, g, winX, winY);
            window.draw(ball.drawing);
        }

        window.display();
    }

    return 0;
}