/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: Lab 3 Task 2 and 3


      * Date: February 10, 2021

      * Description: This program prompts the user for inputs:
          -  for theta  (angle (radians) of elevation ), distance ( distance (ft) to target ) and velocity ( projectile velocity (ft/sec) ),
                then computes the duration of a projectile's flight and its height above the ground when it reaches the target
        
          - for the scores received on two exams, two labs, and two projects, then compute separate averages for the exams, labs, and projects
            and finally compute the weighted average (out of 100%) according to: Each exam is worth 30%, each lab is worth 5% and each project is worth 15%
*/



#include "header.h"


int main(void)
{

      // Task 2 

    double theta = 0.0, distance = 0.0, velocity = 0.0;

    // Prompts the user for the theta, distance, and velocity
    theta = get_theta(); distance = get_distance(); velocity = get_velocity();

    // Compute the time of the projectile's flight
    double time = 0.0;
    time = calculate_time_flight(theta, distance, velocity);

    // Compute the height above the ground when the flight reaches the target
    double height = 0.0;
    height = calculate_height_impact(theta, distance, velocity, time);

    //Display the results on the screen 
    display_time_flight(time);
    display_height_impact(height);




    printf("\n********************************************************************************\n");
    // Task 3


    //Prompt the user for the scores received on two exams, two labs, and two projects
    double exam_point1 = 0.0, exam_point2 = 0.0, lab_point1 = 0.0, lab_point2 = 0.0, project_point1 = 0.0, project_point2 = 0.0;

    exam_point1 = get_point("exam", 1);
    exam_point2 = get_point("exam", 2);
    lab_point1 = get_point("lab", 1);
    lab_point2 = get_point("lab", 2);
    project_point1 = get_point("project", 1);
    project_point2 = get_point("project", 2);



    //Compute separate averages for the exams, labs, and projects
    double exam_avg = 0.0, lab_avg = 0.0, project_avg = 0.0;

    exam_avg = compute_average(exam_point1, exam_point2);
    lab_avg = compute_average(lab_point1, lab_point2);
    project_avg = compute_average(project_point1, project_point2);


    //Compute the weight average
    double weighted_avg = 0.0;
    weighted_avg = compute_weighted_average(exam_avg, lab_avg, project_avg);



    //Display the weighted average to the screen
    display_weighted_average(weighted_avg);



    return 0;   // the program was successful
}