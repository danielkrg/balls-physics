#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <cmath> 
#include <vector>
#include<random>

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
    double rad = 5.0;

    int startX = 400;
    // int startY = 600;
    int startY = 300;
    double g = 0.0981;

    // std::random_device rd;
    std::mt19937 gen(0);
    std::uniform_real_distribution<> dis(-0.1f,0.1f);

    srand(time(NULL));

    std::vector<Ball> balls;

    // for (int i = 0; i < NUM_BALLS; i++) {
        double initVelY = -0.2;
        // double velX = 0.2;
        double velX = 0.01f;
        // double rad = 5;
    //     // Ball ball(initVelY, velX, rad, startX, startY);
    //     // balls.push_back(ball);
    //     balls.push_back(Ball(initVelY, velX, rad, startX, startY));
    //     sf::sleep(sf::Time(sf::microseconds(10000)));
    // }

    int count = 0;

//     for (int i = 0; i < NUM_BALLS; i++) {
//         // float initVelY = -0.3;
//         float initVelY = -1*((double)(rand()%300)/1000) - 0.1;
//         // float velX = 0.5;
//         float velX = pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05);
//         float rad = 5;
//         Ball ball(initVelY, velX, rad, startX, startY);
//         balls.push_back(ball);
//     }

    // int count = 0;

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

        if(count <= NUM_BALLS * 10)
        {
            if(count % 10 == 0)
                balls.push_back(Ball(initVelY, dis(gen), rad, startX, startY));

        }
            // sf::sleep(sf::Time(sf::microseconds(100)));
        count++;

        window.clear();

        // for(auto& ball1 : balls) {
        //     moveBall(ball1, g, winX, winY);
        //     window.draw(ball1.drawing);
        // }

        // if(count % 10 == 0)
        {
        for(auto& ball : balls) {

            ball.move(g, winX, winY);
        }
        for (auto& ball1 : balls)
        {
            for(auto& ball2 : balls)
            {
                resolve_collisions(ball1 ,ball2);
                // window.draw(ball1.drawing);
                // window.draw(ball2.drawing);
            }
        }

        for(auto& ball : balls)
            window.draw(ball.getDrawing());


        window.display();


    }

    return 0;
}