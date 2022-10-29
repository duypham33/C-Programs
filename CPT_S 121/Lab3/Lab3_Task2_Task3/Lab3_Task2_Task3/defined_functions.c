

/*

    This file is to establish the definitions for all programmer-defined functions, aside from main ()

*/


#include "header.h"


// All defined-functions for task 2

double get_theta(void)  //function header
{
    //function definition

    double theta = 0.0;  // angle (radians) of elevation 
    printf("Please enter the value of the theta: ");
    scanf("%lf", &theta);

    return theta;
}



double get_distance(void)   //function header
{
    //function definition
    double distance = 0.0;  // distance (ft) to target
    printf("Please enter the distance in ft: ");
    scanf("%lf", &distance);

    return distance;
}



double get_velocity(void)  //function header
{
    //function definition
    double velocity = 0.0;  // projectile velocity (ft/sec)
    printf("Please enter the velocity (ft/sec): ");
    scanf("%lf", &velocity);

    return velocity;
}



double calculate_time_flight(double theta, double distance, double velocity)   //function header
{
    //function definition
    double time = 0.0;  // time (sec) of flight
    time = (distance) / (velocity * cos(theta));  //compute the time by the formula
    return time;

}



double calculate_height_impact(double theta, double distance, double velocity, double time)   //function header
{
    //function definition
    double height = 0.0;  //  height of impact 
    height = velocity * sin(theta) * time - ((G * time * time) / 2);   //compute the height by the formula
    return height;
}


void display_time_flight(double time)   //function header
{
    //function definition
    printf("The time of the projectile's flight: time = (distance) / (velocity * cos(theta)) = %lf\n", time);

}


void display_height_impact(double height)    //function header
{
    //function definition
    printf("The height above the ground when the flight reaches the target: height = velocity * sin(theta) * time - ((G * time ^ 2) / 2) = %lf\n", height);
}





 // All defined-functions for task 3

double get_point(char work_type[10], int num)   //function header
{
    //function definition


   //Prompt the user for the point of the work type
    printf("Please enter the point of the %s%d: ", work_type, num);

    //Get the point from the user through the keyboard
    double point = 0.0;
    scanf("%lf", &point);

    return point;

}


double compute_average(double point1, double point2)
{
    //function definition
    double average = 0.0;
    //Compute the average for the two points
    average = (point1 + point2) / 2;


    return average;

}


double compute_weighted_average(double exam_avg, double lab_avg, double project_avg)
{
    // function definition

  // Compute the weighted average 
    double weighted_avg = 0.0;
    /*
           Each exam is worth 30%, each lab is worth 5% and each project is worth 15%

        weighted_avg = ( (30%)*exam_point1 + (30%)*exam_point2 + (5%)*lab_point1 + (5%)*lab_point2 + (15%)*project_point1 + (15%)*project_point2 ) / ( 30%+30%+5%+5%+15%+15% )
                     =  ( (30%)*exam_avg + (5%)*lab_avg + (15%)*project_avg ) / (30% + 5% + 15%)
    */
    weighted_avg = (0.30 * exam_avg + 0.05 * lab_avg + 0.15 * project_avg) / (0.30 + 0.05 + 0.15);


    return weighted_avg;
}



void display_weighted_average(double weighted_avg)     //function header
{
    // function definition
    printf("The weighted  average (out of 100%): %lf (out of 100%)\n", weighted_avg);

}

  