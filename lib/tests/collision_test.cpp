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
// Ball(double initVY, double vX, double rad, double startX, double startY)
    Ball b1{-1*((double)(rand()%300)/1000) - 0.1,pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05),
    50.f,300,200};

    Ball b2{-1*((double)(rand()%300)/1000) - 0.1,pow(-1, rand()%2)*((double)(rand()%200)/1000 + 0.05),
    50.f,320,210};


    balls.push_back(b1);
    balls.push_back(b2);

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

        for(auto& ball1 : balls)
        {
            // ball1.drawing.move(0.1f,0.1f);
            for(auto& ball2 : balls)
            {
                // ball2.drawing.move(-0.1f,-0.1f);
                    resolve_collisions(ball1,ball2);
                    w.draw(ball1.getDrawing());
                    w.draw(ball2.getDrawing());
            }
        }

        w.display();
    }
}