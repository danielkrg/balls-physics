#include"include/collision.h"

void resolve_collisions(Ball& obj_1, Ball& obj_2)
{

        double x_1 = obj_1.drawing.getPosition().x;
        double x_2 = obj_2.drawing.getPosition().x;

        double y_1 = obj_1.drawing.getPosition().y;
        double y_2 = obj_2.drawing.getPosition().y;
        double x = x_1 - x_2;
        double y = y_1 - y_2;

        double overlap = std::hypot(x,y) - (obj_1.drawing.getRadius() + obj_2.drawing.getRadius());
        if(overlap < 0)
        {
            double theta = std::atan2(y,x);
            double move_x = (abs(overlap) / 2) * std::cos(theta);
            double move_y = (abs(overlap) / 2) * std::sin(theta);

            double move_x_1 = move_x;
            double move_x_2 = move_x;

            double move_y_1 = move_y;
            double move_y_2 = move_y;

            if(x_1 > x_2)
                move_x_2 *= -1;
            else if(x_1 < x_2)
                move_x_1 *= -1;
            else
            {
                move_x_1 = 0;
                move_x_2 = 0;
            }
            if(y_1 > y_2)
                move_y_1 *= -1;
            else if(y_1 < y_2)
                move_y_2 *= -1;
            else
            {
                move_y_1 = 0;
                move_y_2 = 0;
            }
            obj_1.drawing.move(move_x_1,move_y_1);
            obj_2.drawing.move(move_x_2,move_y_2);

        }

}