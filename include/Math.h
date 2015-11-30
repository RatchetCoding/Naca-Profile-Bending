#ifndef MATH_H
#define MATH_H

#include "Node.h"
#include <stdio.h>
#include <math.h>

#define sin_d(x) sin((x)*M_PI/180)
#define cos_d(x) cos((x)*M_PI/180)

void loesen(Naca* iterator);
void calculate_Profile(Naca* iterator, double* Profile_x,double* Profile_y);

#endif