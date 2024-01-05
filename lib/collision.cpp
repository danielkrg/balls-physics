#include"include/collision.h"
#include<random>
#include<cmath>
// #include<SFML/Graphics.hpp>

void resolve_collisions(Ball& obj_1, Ball& obj_2)
{

        sf::Vector2f pos = obj_1.drawing.getPosition()-obj_2.drawing.getPosition();
        double x = pos.x;
        double y = pos.y;

        double overlap = std::hypot(x,y) - (obj_1.drawing.getRadius() + obj_2.drawing.getRadius());
        if(overlap < 0)
        {
            double theta = std::atan2(y,x);
            double move_x = (abs(overlap) / 2) * std::cos(theta);
            double move_y = (abs(overlap) / 2) * std::sin(theta);
            obj_1.drawing.move(move_x,move_y);
            obj_2.drawing.move(-1 * move_x,-1 * move_y);

        }

}