
/*

  This is the header file that stores  standard library includes, #defined and function prototypes

*/



#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h> //necessary to use sqrt(), sin(), and cos()

#define PI 3.141592  //define the constant PI




//function prototype

/*
  Function: calculate_newtons_2nd_law ()

  Date Created: Feb 9, 2021

  Date Last Modifiled: Feb 9, 2021

  Description:  This function calculates the force by Newton’s Second Law of Motion: force = mass * acceleration

  Input parameters: The mass and the acceleration

  Returns:  The force

  Preconditions:  The mass and the acceleration

  Postconditions:  The force has been calculated
*/

double calculate_newtons_2nd_law(double mass, double acceleration);




/*
  Function:   calculate_volume_cylinder ()

  Date Created:  Feb 9, 2021

  Date Last Modifiled:  Feb 9, 2021

  Description:   This function calculates the voulume of a cylinder by the formula   volume_cylinder = PI * radius2 * height

  Input parameters:  The radius and the height 

  Returns:   The volume of the cylinder 

  Preconditions:    The radius and the height 

  Postconditions:   The volume of the cylinder has been calculated
*/

double calculate_volume_cylinder(double radius, double height);





/*
  Function:    perform_character_encoding ()

  Date Created:  Feb 9, 2021

  Date Last Modifiled:  Feb 9, 2021

  Description:    This function performs the encoded character based on the equation  encoded_character = (plaintext_character - 'A') + 'a' - shift

  Input parameters:   The plaintext character and the shift 

  Returns:    The encoded character 

  Preconditions:   The plaintext character and the shift 

  Postconditions:    The encoded character has been performed
*/

char perform_character_encoding(char plaintext_character, int shift);





/*
  Function:   calculate_distance_between_two_points

  Date Created:  Feb 9, 2021

  Date Last Modifiled:  Feb 9, 2021

  Description:    This function calculates the distance between two points by the formula  distance = square root of ((x1 - x2)^2 + (y1 - y2)^2)

  Input parameters:   The coordinates of the two points  x1, y1, x2, and y2

  Returns:   The distance

  Preconditions:    The value of  x1, y1, x2, and y2

  Postconditions:   The distance has been calculated
*/

double calculate_distance_between_two_points(double x1, double y1, double x2, double y2);






/*
  Function:       calculate_tan_theta ()

  Date Created:  Feb 9, 2021

  Date Last Modifiled:  Feb 9, 2021

  Description:   This function calculates the tangent of the theta by the formula    tan_theta = sin (theta) / cos (theta)

  Input parameters:   The theta

  Returns:  The tangent 

  Preconditions:   The theta

  Postconditions:   The tangent has been calculated
*/

double calculate_tan_theta(double theta);






/*
  Function:   calculate_total_resistance ()

  Date Created:  Feb 9, 2021

  Date Last Modifiled:   Feb 9, 2021

  Description:  This function calculates the total parallel resistance by the formula   total_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3)

  Input parameters:  The three resistors R1, R2, and R3 

  Returns:   The total parallel resistance

  Preconditions:  The value of R1, R2 and R3

  Postconditions:   The total parallel resistance has been calculated
*/

double calculate_total_resistance(int R1, int R2, int R3);





/*
  Function:     calculate_general_equation ()

  Date Created:  Feb 9, 2021

  Date Last Modifiled:  Feb 9, 2021

  Description:   This function calculates the value of y by the general equation   y = (2 / 3) - b + z * x / (a % 2) + PI

  Input parameters:   The value of b, z, x, and a

  Returns:   The value of y
  
  Preconditions:   The value of b, z, x, and a

  Postconditions:   y has been calculated 
*/

double calculate_general_equation(double b, double z, double x, int a);