#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int NUM_BALLS = 1;

    int winX = 800;
    int winY = 700;
    sf::RenderWindow window(sf::VideoMode(winX, winY), "balls");
    float rad = 5.0;

    int startX = 400;
    int startY = 600;
    float g = 0.0981;

    std::vector<Ball> balls;
    for (int i = 0; i < NUM_BALLS; i++) {

        float initVelY = -0.2;
        float velX = 0.2;
        float rad = 5;
        Ball ball(initVelY, velX, rad, startX, startY);
        balls.push_back(ball);

    }

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