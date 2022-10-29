
/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"



//All the defined functions for task 1


void charges(double number_hours, double* total_charge, double* average_cost)
{
    //Calculate the total charge
    if (number_hours <= 10) 
    {
        *total_charge = 7.99;
    }

    else
    {
        /* 
        
        Because additional hours or partial hours are charged at $1.99 each, we use the function ceil() 
        
        */
        int rounded_hours = ceil(number_hours);     

        *total_charge = 1.99 * (rounded_hours - 10) + 7.99;

    }

    //Calculate the average cost per hour of the time used
    *average_cost = *total_charge / number_hours;


}



double round_money(double number)
{
      /*  For example: We need to round 15.5662 two decimal places
                 1) We multiply by 100:  15.5662 * 100 = 1556.62
                 2) Add to 0.5:          1556.62 + 0.5 = 1557.12
                 3) Then type cast to int so value is 1557 
                 4) Divided by 100 so the value converted into 37.67
      */

    double a = (int)(number * 100 + 0.5);

    return (double)a / 100;
}






//All the defined functions for task 2


void calculate_revenues(int t, double* R)
{
    *R = 203.265 * pow(1.071, t);      //R is in millions of dollars and t is the years since 1984

}


int predict(double target_revenues)
{
    int t = 0; double R = 0.0;
    do
    {
        calculate_revenues(t, &R);
        t++;
    } while (R < target_revenues);

    t -= 1;     //The exact value of t must be subtracted by one unit because of the increment in the loop 


    return (1984 + t);      //Because the year is determined since 1984

}