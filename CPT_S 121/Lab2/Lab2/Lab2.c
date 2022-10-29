/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: Lab 2

      * Date: February 4, 2021

      * Description: This program prompts the user for inputs to the 3 equations and evaluate them based on the inputs:
        1) The equation of the perpendicular bisector of the line segment between two points
        2) Calculating your body mass index (BMI)
        3) Calculating the Bowl Championship Series (BCS) score of a college football team

*/

#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

int main(void)
{

    // Task 1 (The equation of the perpendicular bisector of the line segment between two points)
    printf("1)\n"); //start task 1


    // Prompt the user for the coordinates of the two points
    double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
    printf("Enter the coordinates of the point A1(x1,y1) (both floating-point values): ");
    scanf("%lf%lf", &x1, &y1); //get the coordinates of A1(x1,y1) from the user

    printf("Enter the coordinates of the point A2(x2,y2) (both floating-point values): ");
    scanf("%lf%lf", &x2, &y2); //get the coordinates of A2(x2,y2) from the user


    // Compute the slope of the line between the two points
    double the_line_slope = 0.0;
    the_line_slope = (y1 - y2) / (x1 - x2);
    

    // Compute the coordinates of the midpoint A(x_mid, y_mid) of the line segment between the two points 
    double x_mid = 0.0, y_mid = 0.0;
    x_mid = (x1 + x2) / 2; y_mid = (y1 + y2) / 2; //average the two x coordinates and the two y coordinates of those points
    

    // Compute the slope of the perpendicular bisector 
    double m = 0.0; //put m = the slope of the perpendicular bisector 
    m = -1 / the_line_slope; //take the negative reciprocal of the slope of the line segment
    

    // Compute the y intercept of the perpendicular bisector
    double y_intercept = 0.0;
    /*  Because the mid point A(x_mid,y_mid) on the perpendicular bisector and the slope of the perpendicular bisector is m,
        the y intercept is y_mid - m * x_mid
    */
    y_intercept = y_mid - m * x_mid;
   

    // Display the result to the screen
    printf("\nThe original two points A1(%lf , %lf) and A2(%lf , %lf)\n", x1, y1, x2, y2);
    printf("The equation of the perpendicular bisector of the line segment between the two points: y = %lfx + %lf\n", m, y_intercept);




    // Task 2 ( Calculate your body mass index (BMI) )
    printf("\n2) "); //start task 2

    // Prompt the user for weight in pounds and height in feet
    printf("Enter the weight (in pounds) and the height (in feet) (both floating-point values): ");


    // Get the weight and height from the user through the keyboard
    double weight_in_pounds = 0.0, height_in_feet = 0.0;
    scanf("%lf%lf", &weight_in_pounds, &height_in_feet);


    // Convert the height to inches
    double height_in_inches = 0.0;
    height_in_inches = height_in_feet * 12; //since 1 foot = 12 inches


    // Compute the BMI by the formula BMI = ( (weight in pounds) / (height in inches)^2 ) * 703
    double BMI = 0.0;
    BMI = (weight_in_pounds / ((height_in_inches) * (height_in_inches))) * 703;


    // Display the BIM value to the screen
    printf("The BMI value = ( (weight in pounds) / (height in inches)^2 ) * 703 = ( (%lf) / (%lf)^2 ) * 703 = %lf\n", weight_in_pounds, height_in_inches, BMI);






    // Task 3 (Calculate the Bowl Championship Series (BCS) score of a college football team)
    printf("\n3) ");


    // Prompt the user for team's scores in the Harris Poll and the Coaches Poll, and the computer ranking
    printf("Enter the two scores of the team in the Harris Poll (an integer value between 1 and 2,850) and the Coaches Poll (an integer value between 1 and 1,475), and the computer ranking (a floating-point value between 0 and 1): ");


    // Get the two scores of the team and the computer ranking from the user through the keyboard
    int harris_poll_score = 0, coaches_poll_score = 0; double computer_ranking = 0.0;
    scanf("%d%d%lf", &harris_poll_score, &coaches_poll_score, &computer_ranking);


    // Compute the results harris_poll and coaches_poll and display them to the screen
    double harris_poll = 0.0, coaches_poll = 0.0;
    harris_poll = (double)harris_poll_score / 2850;
    coaches_poll = (double)coaches_poll_score / 1475;
    printf("The result harris_poll = harris_poll_score / 2850 = %d / 2850 = %lf\n", harris_poll_score, harris_poll);
    printf("The result coaches_poll = coaches_poll_score / 1475 = %d / 1475 = %lf\n", coaches_poll_score, coaches_poll);


    // Compute the BCS total score by the formula
    double BCS_score = 0.0;
    BCS_score = (harris_poll + coaches_poll + computer_ranking) / 3;


    // Print the BCS total score to the screen
    printf("The BCS total score = (harris_poll + coaches_poll + computer_ranking) / 3 = (%lf + %lf + %lf) / 3 = %lf\n", harris_poll, coaches_poll, computer_ranking, BCS_score);




    return 0; //the program was successful


}