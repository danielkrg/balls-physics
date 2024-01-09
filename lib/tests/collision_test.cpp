/*
    Two objects overlap if the distance between their centres is smaller than the
    sum of their radii.

    The value of the overlap is computed by subtracting the distance between the objects from the
    sum of their radii.

    Then, we move them along the axis defined by their centres.
    Each object is moved by half of the overlap.
*/
#include"collision.h"

int main()
{
    sf::RenderWindow w(sf::VideoMode(640,480),"collision-testing");
    w.setFramerateLimit(60);
    sf::CircleShape c1(50.f);
    c1.setOrigin(c1.getRadius(),c1.getRadius());
    c1.setPosition(300,200);
    sf::CircleShape c2(50.f);
    c2.setOrigin(c2.getRadius(),c2.getRadius());
    c2.setPosition(320,210);

    std::vector<Ball> balls;

    // Ball b1;
    //     b1.id = 1;
    //     b1.x = 300;
    //     b1.y = 200;
    //     b1.t = 0;
    //     b1.initVelY = -1*((double)(rand()%300)/1000) - 0.1;
    //     b1.velY = b1.initVelY;
    //     b1.velX = pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05);
    //     b1.drawing = c1;
    // Ball b2;
    //     b2.id = 0;
    //     b2.x = 320;
    //     b2.y = 210;
    //     b2.t = 0;
    //     b2.initVelY = -1*((double)(rand()%300)/1000) - 0.1;
    //     b2.velY = b2.initVelY;
    //     b2.velX = pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05);
    //     b2.drawing = c2;

    // balls.push_back(b1);
    // balls.push_back(b2);

    while(w.isOpen())
    {
        sf::Event event;

        while(w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();
            if(event.type == sf::Event::KeyPressed)
                w.close();
        }
        w.clear();

        // b1.drawing.move(0.1f,0.1f);
        // b2.drawing.move(-0.1f,-0.1f);

        // for(auto& ball1 : balls)
        // {
        //     // ball1.drawing.move(0.1f,0.1f);
        //     for(auto& ball2 : balls)
        //     {
        //         if(ball1.id != ball2.id)
        //         {
        //         // ball2.drawing.move(-0.1f,-0.1f);
        //             resolve_collisions(ball1,ball2);
        //             w.draw(ball1.drawing);
        //             w.draw(ball2.drawing);
        //         }
        //     }
        // }

        w.display();
    }
}