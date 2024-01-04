#include "include/ball.h"
#include <cmath> 

void initBalls(Ball balls[], int NUM_BALLS, int startX, int startY) {
    for (int i = 0; i < NUM_BALLS; i++) {
        Ball ball;
        ball.rad = rand()%3 + 2; 
        ball.x = startX + ball.rad;
        ball.y = startY + ball.rad;
        ball.t = 0;
        ball.initVelY = -1*((double)(rand()%300)/1000) - 0.1;
        ball.velY = ball.initVelY;
        ball.velX = pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05);
        sf::CircleShape shape(ball.rad);
        ball.drawing = shape;
        int r = rand()%256;
        int g = rand()%256;
        int b = rand()%256;
        ball.drawing.setFillColor(sf::Color(r, g, b));
        ball.drawing.setPosition(sf::Vector2f(startX, startY));
        balls[i] = ball;
    }
}

bool checkGround(float y, int winY, float rad) {
    return (y + rad >= winY);
}

bool checkWalls(float x, int winX, float rad) {
    return (x + rad >= winX || x <= 0);
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
            ball.drawing.setPosition(ball.x, ball.y - ball.rad);
            ball.velX *= 0.9995;
        }

        if (checkWalls(ball.x, winX, ball.rad)) {
            ball.velX *= -1;
        }
}