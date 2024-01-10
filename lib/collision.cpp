
#include "collision.h"
void resolve_collisions(Ball& obj_1, Ball& obj_2)
{

    if(&obj_1 == &obj_2)
        return;

        double x_1 = obj_1.getPos().x;
        double x_2 = obj_2.getPos().x;

        double y_1 = obj_1.getPos().y;
        double y_2 = obj_2.getPos().y;
        double x = x_1 - x_2;
        double y = y_1 - y_2;

        double sum_rads = obj_1.getRad() + obj_2.getRad();

/*
The line between the centres of the two circles on impact is in the direction which the collided with ball
should travel.


*/

        double overlap = std::hypot(x,y) - sum_rads;
        if(overlap <= 0.f)
        {
            double theta = (std::atan2(y,x));
            // double theta = std::asin(std::hypot(x,y) / sum_rads);
            // double move_x_1 = x_1 * std::cos(theta);// - y_1 * std::sin(theta);
            double move_x_1 = std::cos(theta);// - y_1 * std::sin(theta);
            // double move_y_1 = x_1 * std::sin(theta);// + y_1 * std::cos(theta);
            double move_y_1 = std::sin(theta);// + y_1 * std::cos(theta);

            // double move_x_2 = -1.f * move_x_1;
            // double move_x_2 = (abs(overlap) / 2) * std::sin(theta);
            // double move_y_2 = -1.f * move_y_1;
            // double move_y_2 = (abs(overlap) / 2) * std::sin(theta);
            double move_x_2 = std::cos(theta - M_PI);
            double move_y_2 = std::sin(theta - M_PI);

            double swap_x = -1.f;
            double swap_y = -1.f;

            // They shouldn't stick together after modifying this
            // if(std::fabs(obj_1.getVel().x - obj_2.getVel().x) < 1e-6)
            if((obj_1.getVel().x > 0 && obj_2.getVel().x > 0) || (obj_1.getVel().x < 0 && obj_2.getVel().x < 0))
            {
                swap_x *= -1.f;
            }
            // if(std::fabs(obj_1.getVel().x - obj_2.getVel().x) < 1e-6)
            if((obj_1.getVel().y > 0 && obj_2.getVel().y > 0) || (obj_1.getVel().y < 0 && obj_2.getVel().y < 0))
            {
                swap_y *= -1.f;
            }

            // the t of collided particles that have not touched the ground keeps increasing,
            // so they eventually shoot up high into the air.

//             obj_1.setVel(obj_1.getVel().x * swap_x, obj_1.getInitVelY());
//             obj_2.setVel(obj_2.getVel().x * swap_x, obj_2.getInitVelY());

            obj_1.moveDrawing(move_x_1,move_y_1);
            obj_2.moveDrawing(move_x_2,move_y_2);


        }


            // double theta = std::atan2(y,x);
            // double move_x = (abs(overlap) / 2) * std::cos(theta);
            // double move_y = (abs(overlap) / 2) * std::sin(theta);
            // double move_x_1 = move_x;
            // double move_x_2 = move_x;
        // double overlap = std::hypot(x,y) - sum_rads;
        // if(overlap <= 0)
        // {
        //     double theta = std::atan2(y,x);
        //     double move_x = (abs(overlap) / 2) * std::cos(theta);
        //     double move_y = (abs(overlap) / 2) * std::sin(theta);

        //     double move_x_1 = move_x;
        //     double move_x_2 = move_x;
        // }
}
            // double move_y_1 = move_y;
            // double move_y_2 = move_y;

            // if(x_1 > x_2)
            // {
            //     move_x_2 *= -1;
            //     obj_2.setVel(obj_2.getVel().x * -1.f * damping_coeff,obj_2.getVel().y);
            // }
            // else if(x_1 < x_2)
            // {
            //     move_x_1 *= -1;
            //     obj_1.setVel(obj_1.getVel().x * -1.f * damping_coeff,obj_1.getVel().y);
            // }
            // else
            // {
            //     move_x_1 = 0;
            //     move_x_2 = 0;
            // }
            // if(y_1 > y_2)
            // {
            //     move_y_1 *= -1;
            //     obj_1.setInitVelY(obj_1.getInitVelY() * -1.f * damping_coeff);
            //     obj_1.setVel(obj_1.getVel().x,obj_1.getVel().y * -1.f * damping_coeff);
            // }
            // else if(y_1 < y_2)
            // {
            //     move_y_2 *= -1;
            //     obj_2.setInitVelY(obj_2.getInitVelY() * -1.f * damping_coeff);
            //     obj_2.setVel(obj_2.getVel().x,obj_2.getVel().y * -1.f * damping_coeff);
            // }
            // else
            // {
            //     move_y_1 = 0;
            //     move_y_2 = 0;
            // }
            // obj_1.moveDrawing(move_x_1,move_y_1);
            // obj_2.moveDrawing(move_x_2,move_y_2);