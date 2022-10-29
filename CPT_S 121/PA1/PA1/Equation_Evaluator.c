/*
      * Programmer: Duy Pham

      * Class: CptS 121, Spring 2021; Section 01; Lab Section 14

      * Programming Assignment: PA1 Equation Evaluator

      * Date: February 1, 2021

      * Description: This program prompts the user for inputs to the 7 equations and evaluate them based on the inputs:
        1) Newton’s Second Law of Motion
        2) Volume of a cylinder
        3) Character encoding
        4) Distance between two points
        5) Tangent
        6) Total resistance of resistors in parallel
        7) General equation

*/

#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h> //necessary to use sqrt(), sin(), and cos()

#define PI 3.141592  //define the constant PI

int main(void)
{

    // Equation 1 (Newton’s Second Law of Motion)
          printf("1) ");  //start Eq 1
          
          //Prompt the user for the mass and acceleration
          printf("Enter the mass and acceleration (both floating-point values) for use in Newton\'s Second Law of Motion: "); 

          //Get the mass and acceleration from the user through the keyboard
          double mass = 0.0; double acceleration = 0.0; 
          scanf("%lf%lf", &mass, &acceleration);

          //Compute the force by the formula
          double force = 0.0;
          force = mass * acceleration;

          //Display the result to the screen 
          printf("Newton\'s Second Law: force = mass * acceleration = %lf * %lf = %lf\n", mass, acceleration, force);





    // Equation 2 (Volume of a cylinder)
          printf("\n2) "); //start Eq 2

          //Prompt the user for the radius and height
          printf("Enter the radius and height (both floating-point values) for use in a volume of cylinder equation: ");

          //Get the radius and height from the user through the keyboard
          double radius = 0.0; double height = 0.0; 
          scanf("%lf%lf", &radius, &height);

          //Compute the volume_cylinder by the formula
          double volume_cylinder = 0.0;
          volume_cylinder = PI * (radius * radius) * height;

          //Display the result to the screen
          printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %lf\n", PI, radius, height, volume_cylinder);

          

         // scanf("%*c");   //to clean the stdin before starting equation 3


         

    // Equation 3 (Character encoding)
          printf("\n3) "); //start Eq 3

          //Prompt the user for the plaintext character and shift
          printf("Enter the plaintext_character and shift (an integer) for use in a character encoding equation: ");

          //Get the plaintext character and shift from the user through keyboard
          char plaintext_character = '\0'; int shift = 0; 
          scanf(" %c%d", &plaintext_character, &shift);

        

          //Get the encoded character by the formula
          char encoded_character = '\0';
          encoded_character = (plaintext_character - 'A') + 'a' - shift;

          //Display the result to the screen
          printf("Encoded character (determined from the equation encoded_character = (plaintext_character - 'A') + 'a' - shift): %c\n", encoded_character);


          /*
        If plaintext_character is uppercase, then the encoded_character is the plaintext_chracter in lowercase (if shift=0).
        Because (- 'A' + 'a') = 32, encoded_character = plaintext_character + 32.
        Plaintext_character is uppercase added 32 so equals lowercase

        With various shift keys can make the encoded_character equal any character in Ascii Table.

    */

          printf("\nIf plaintext_character is uppercase, then the encoded_character is the plaintext_chracter in lowercase (if shift=0).\n");
          printf("With various shift keys can make the encoded_character equal any character in Ascii Table.\n");





    // Equation 4 (Distance between two points)
          printf("\n4)\n"); //start Eq 4

          //Prompt the user for the coordinates of A1(x1,y1) and A2(x2,y2)
          double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
          printf("Enter the coordinates of the point A1(x1,y1) (both floating-point values): ");
          scanf("%lf%lf", &x1, &y1); //get the coordinates of A1(x1,y1) from the user

          printf("Enter the coordinates of the point A2(x2,y2) (both floating-point values): ");
          scanf("%lf%lf", &x2, &y2); //get the coordinates of A2(x2,y2) from the user

          //Compute the distance between those two points by the formula
          double distance = 0.0; 
          distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 

          //Display the result to the screen
          printf("The distance between the two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) = square root of ((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n", x1, x2, y1, y2, distance);




    //Equation 5 (Tangent)
          printf("\n5) "); //start Eq 5

          //Prompt the user for the theta
          printf("Enter the value of the theta (a floating-point value): ");

          //Get the theta from the user through the keyboard
          double theta = 0.0;
          scanf("%lf", &theta); 

          //Compute tan(theta) by the formula
          double tan_theta = 0.0;
          tan_theta = sin(theta) / cos(theta); 

          //Display the result to the screen
          printf("Tan(theta): tan_theta = sin (theta) / cos (theta) = sin (%lf) / cos (%lf) = %lf\n", theta, theta, tan_theta);




    //Equation 6 (Total resistance of resistors in parallel)
          printf("\n6) "); //start Eq 6

          //Prompt the user for the three resistors R1, R2, and R3 (all integers)
          printf("Enter the three resistors R1, R2, and R3 (all integers): ");

          //Get the three resistors from the user through the keyboard
          int R1 = 0, R2 = 0, R3 = 0;
          scanf("%d%d%d", &R1, &R2, &R3); 

          //Compute the total resistance by the formula
          double total_resistance = 0.0;
          total_resistance = (double)1 / ((double)1 / R1 + (double)1 / R2 + (double)1 / R3); 

          //Display the result to the screen
          printf("Total resistance of resistors: total_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d ) = %lf\n", R1, R2, R3, total_resistance);





    //Equation 7 (General equation)
          printf("\n7) "); //start Eq 7

          //Promte the user for the values of b, z, x (floating-point values) and a (an integer)
          printf("Enter the values of b, z, x (floating-point values) and a (an integer): ");

          //Get the b, z, x and a from the user through the keyboard
          double b = 0.0, z = 0.0, x = 0.0; int a = 0;
          scanf("%lf%lf%lf%d", &b, &z, &x, &a);

          //Compute the value of y by the general equation
          double y = 0.0;
          y = ((double)2 / 3) - b + z * x / (a % 2) + PI;

          //Display the result to the screen
          printf("y = (2 / 3) - b + z * x / (a %% 2) + PI = (2 / 3) - %lf + %lf * %lf / (%ld %% 2) + %lf = %lf\n", b, z, x, a, PI, y);



          return 0; //the program was successful


}