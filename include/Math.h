#ifndef MATH_H
#define MATH_H

#include "Node.h"
#include <stdio.h>
#include <math.h>

/*
* Just defining a macro for usage of sine and cosine with degrees, because the angles B12 and B2 are given in degree.
*/
#define sin_d(x) sin((x)*M_PI/180)
#define cos_d(x) cos((x)*M_PI/180)

void loesen(Naca* iterator);
void calculate_Profile(Naca* iterator, double* Profile_x,double* Profile_y);

#endif