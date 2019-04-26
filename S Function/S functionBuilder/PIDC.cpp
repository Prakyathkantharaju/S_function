#include "PIDC.h"
#include "math.h"

double pid (double error ,double *Kp ,double *Ki,double *Kd)
{   
    // error - input P,I,D paramters
    static double previous_error = 0;
    static double error_integral = 0.0;
    // Note: all the paramters should be double variable.
    double P_out,I_out, D_out, Out;
    P_out  = error * *Kp;
    error_integral = error + error_integral;
    I_out =  error_integral * *Ki;
    D_out = (error-previous_error) * *Kd;
    Out = P_out +  I_out + D_out;
    //update
    previous_error = error;
    return Out;
}