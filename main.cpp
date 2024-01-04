#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<cmath> 

#include "lib/include/ball.h"

bool checkGround(float y, int winY, float rad) {
    return (static_cast<int>(y) + 2*rad >= winY - 1);
}

bool checkWalls(float x, int winX, float rad) {
    return (static_cast<int>(x) + 2*rad >= winX || static_cast<int>(x) <= 0);
}

void moveBall(Ball& ball, float g, int winX, int winY) {
        ball.drawing.move(ball.velX, ball.velY);
        ball.t += 0.001;
        ball.velY = ball.initVelY + g*ball.t;

        if (checkGround(ball.y, winY, ball.rad)) {
            ball.initVelY = -0.86*ball.velY;
            ball.velY = ball.initVelY;
            ball.t = 0;
        }

        if (checkWalls(ball.x, winX, ball.rad)) {
            ball.velX *= -1;
        }
}

int main()
{
    int winX = 800;
    int winY = 700;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "balls");
    float rad = 5.0;

    int startX = 300;
    int startY = 300;
    float g = 0.0981;
    srand(time(NULL));

    Ball balls[10];
    for (int i = 0; i < 10; i++) {
        Ball ball;
        ball.x = startX;
        ball.y = startY;
        ball.t = 0;
        ball.initVelY = -1*((double)(rand()%3)/10);
        ball.velY = ball.initVelY;
        ball.velX = pow(-1, rand()%2)*((double)(rand()%3)/10);
        ball.rad = rand()%3 + 2; 
        sf::CircleShape shape(ball.rad);
        ball.drawing = shape;
        ball.drawing.setFillColor(sf::Color::White);
        ball.drawing.setPosition(sf::Vector2f(startX, startY));
        balls[i] = ball;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
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