#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<cmath> 


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
            ball.initVelY = -0.85*ball.velY;
            ball.velY = ball.initVelY;
            ball.t = 0;
            ball.y = winY - 2*ball.rad;
            ball.drawing.setPosition(ball.x, ball.y);
        }

        if (checkWalls(ball.x, winX, ball.rad)) {
            ball.velX *= -1;
        }
}

int main()
{
    int NUM_BALLS = 1;

    int winX = 800;
    int winY = 700;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "balls");
    float rad = 5.0;

    int startX = 300;
    int startY = 300;
    float g = 0.0981;
    srand(time(NULL));

    Ball balls[NUM_BALLS];
    for (int i = 0; i < NUM_BALLS; i++) {
        Ball ball;
        ball.x = startX;
        ball.y = startY;
        ball.t = 0;
        ball.initVelY = -1*((double)(rand()%3)/10) - 0.1;
        ball.velY = ball.initVelY;
        ball.velX = pow(-1, rand()%2)*((double)(rand()%3)/10 + 0.05);
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