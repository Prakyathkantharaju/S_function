#include "math.h"
#include "massc.h"
void mass(double u, double K, double C,double M, double delta_t, double *y1, double *y2)
{
// u - input , K,C,t - parameters, y1 and y2 are pointers for the output.
// U - control input
// K, C are spring constant and damping
// t - euler time step
//x_dot is the velocity and acceleration
// new_x is the updated velcoty and distance
double x_dot[2];
static double new_x[2] = {0.0,0.0};
x_dot[0] = new_x[1];
x_dot[1] = (1/M) * (u - K * new_x[0] - C * new_x[1]);
new_x[0] = euler(x_dot[0],new_x[0],delta_t);
new_x[1] = euler(x_dot[1],new_x[1],delta_t);
*y1 = new_x[0];
*y2 = new_x[1];
}



double euler(double y,double x,double delta_t)
{
double z = y * delta_t + x;
return z;
}