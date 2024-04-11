
// #include "collision.h"
// #include <iostream>
// #include <cstdlib>
// #include <cmath> 

// void resolve_collisions(Ball& obj_1, Ball& obj_2)
// {

//     if(&obj_1 == &obj_2)
//         return;

//         double x_1 = obj_1.getPos().x;
//         double x_2 = obj_2.getPos().x;

//         double y_1 = obj_1.getPos().y;
//         double y_2 = obj_2.getPos().y;
//         double x = x_1 - x_2;
//         double y = y_1 - y_2;

//         double sum_rads = obj_1.getRad() + obj_2.getRad();

// /*
// The line between the centres of the two circles on impact is in the direction which the collided with ball
// should travel.


// */

//         double overlap = std::hypot(x,y) - sum_rads;
//         if(overlap <= 0.f)
//         {
//             sf::Vector2f b1_vel = obj_1.getVel();
//             sf::Vector2f b2_vel = obj_2.getVel();

//             double theta = (std::atan2(b2_vel.x + b1_vel.x, b2_vel.y + b1_vel.x));
//             double move_x_1 = std::sin(theta);
//             double move_y_1 = std::cos(theta);
//             double move_x_2 = std::sin(M_PI/2 - theta);
//             double move_y_2 = std::cos(M_PI/2 - theta);

//             b1_vel = obj_1.getVel();
//             b2_vel = obj_2.getVel();

//             double total_vel_x = abs(b1_vel.x) + abs(b2_vel.x);
//             double total_vel_y = abs(b1_vel.y) + abs(b2_vel.y);

//             double b1_x_sign = b1_vel.x/abs(b1_vel.x);
//             double b1_y_sign = b1_vel.y/abs(b1_vel.y);
//             double b2_x_sign = b2_vel.x/abs(b2_vel.x);
//             double b2_y_sign = b2_vel.y/abs(b2_vel.y);

//             sf::Vector2f b1_new_vel = sf::Vector2f(move_x_1*total_vel_x/2, move_y_1*total_vel_y/2);
//             sf::Vector2f b2_new_vel = sf::Vector2f(move_x_2*total_vel_x/2, move_y_2*total_vel_y/2);

//             if (abs(b1_new_vel.x) <= 0.0001)
//                 b1_new_vel.x = 0;

//             if (abs(b1_new_vel.y) <= 0.0001)
//                 b1_new_vel.y = 0;

//             if (abs(b2_new_vel.x) <= 0.0001)
//                 b2_new_vel.x = 0;

//             if (abs(b2_new_vel.y) <= 0.0001)
//                 b2_new_vel.y = 0;

//             obj_1.setVel(b1_new_vel.x, b1_new_vel.y);
//             obj_2.setVel(b2_new_vel.x, b2_new_vel.y);

//             obj_1.setInitVelY(b1_new_vel.y);
//             obj_2.setInitVelY(b2_new_vel.y);

//             obj_1.setT(0);
//             obj_2.setT(0);

//             obj_1.moveDrawing(move_x_1,move_y_1);
//             obj_2.moveDrawing(move_x_2,move_y_2);


//         }
// }