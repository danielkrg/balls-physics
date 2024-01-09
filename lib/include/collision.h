/*
    Two objects overlap if the distance between their centres is smaller than the
    sum of their radii.

    The value of the overlap is computed by subtracting the distance between the objects from the
    sum of their radii.

    Then, we move them along the axis defined by their centres.
    Each object is moved by half of the overlap.
*/
#include<cmath>
#include<iostream>
#include"ball.h"

void resolve_collisions(Ball& obj_1, Ball& obj_2);