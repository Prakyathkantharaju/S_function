#include "PIDC.h"
#include "math.h"
double pid (double error ,double Kp ,double Ki,double Kd)
{
static double previous_error = 0;
static double error_integral = 0.0;
// error - input; P,I,D paramters
double P_out,I_out,D_out,PIDOut;
P_out = error * Kp;
error_integral = error_integral + error;
I_out = error_integral * Ki;
D_out = (error-previous_error) * Kd;
PIDOut = P_out + I_out + D_out;
previous_error = error;
return PIDOut;
}