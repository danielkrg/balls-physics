#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<cmath> 

#include "lib/include/ball.h"

bool checkGround(float y, int winY, float rad) {
    return (y + 2*rad >= winY);
}

bool checkWalls(float x, int winX, float rad) {
    return (x + 2*rad >= winX || x <= 0);
}

void moveBall(Ball& ball, float g, int winX, int winY) {
        ball.drawing.move(ball.velX, ball.velY);
        ball.t += 0.001;
        ball.velY = ball.initVelY + g*ball.t;
        ball.x += ball.velX;
        ball.y += ball.velY;

        if (checkGround(ball.y, winY, ball.rad)) {
            ball.initVelY = -0.80*ball.velY;
            ball.velY = ball.initVelY;
            ball.t = 0;
            ball.y = winY - ball.rad;
            ball.drawing.setPosition(ball.x, ball.y);
            ball.velX *= 0.9995;
        }

        if (checkWalls(ball.x, winX, ball.rad)) {
            ball.velX *= -1;
        }
}

int main()
{
    int NUM_BALLS = 5;

    int winX = 800;
    int winY = 700;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "balls");
    float rad = 5.0;

    int startX = 400;
    int startY = 600;
    float g = 0.0981;
    srand(time(NULL));

    Ball balls[NUM_BALLS];
    for (int i = 0; i < NUM_BALLS; i++) {
        Ball ball;
        ball.x = startX;
        ball.y = startY;
        ball.t = 0;
        ball.initVelY = -1*((double)(rand()%300)/1000) - 0.1;
        ball.velY = ball.initVelY;
        ball.velX = pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05);
        ball.rad = rand()%3 + 20; 
        sf::CircleShape shape(ball.rad);
        shape.setOrigin(shape.getRadius(),shape.getRadius());
        ball.drawing = shape;
        int r = rand()%256;
        int g = rand()%256;
        int b = rand()%256;
        ball.drawing.setFillColor(sf::Color(r, g, b));
        ball.drawing.setPosition(sf::Vector2f(startX, startY));
        balls[i] = ball;
    }

    // int count = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                window.close();
        }

        window.clear();

        // for(auto& ball1 : balls) {
        //     moveBall(ball1, g, winX, winY);
        //     window.draw(ball1.drawing);
        // }

        for(auto& ball : balls) {
            moveBall(ball, g, winX, winY);
            window.draw(ball.drawing);
        }
        // if(count % 10 == 0)
        // {
        //     for(auto& ball1 : balls)
        //     {
        //         for(auto& ball2 : balls)
        //         {
        //             // resolve_collisions(ball1,ball2);
        //         }
        //     }
        // }
        // count++;

        window.display();
    }

    return 0;
}