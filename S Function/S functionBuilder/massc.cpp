#include "math.h"
#include "massc.h"

double mass(double *delta_t ,double u1, double *K, double *C, double *M)
{   
    // u - input , K,C,t - parameters
    // U - control input
    // K, C are spring constant and damping
    // delta_t - euler time step
    //x_dot is the velocity and acceleration
    //new_x[0] in the distance
    double x_dot[2];
    static double new_x[2] = {0.0,0.0};
    // Note: All the paramters must be pointers, Input and state are variables(double),
    x_dot[0] = new_x[1];
    x_dot[1] = (1/ *M) * ( u1  - *K * new_x[0] - *C * new_x[1]);
    new_x[0] = euler(x_dot[0],new_x[0], *delta_t);
    new_x[1]  = euler(x_dot[1],new_x[1], *delta_t);
    return new_x[0];
}

double euler(double y,double x,double delta_t)
{
    double z = y * delta_t + x;
    return z;
}

