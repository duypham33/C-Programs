
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/



#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h> //necessary to use sin(), and cos()

#define G 32.17  //define the gravitational constant




//function prototype



  // All defined-functions for task 2

/*
  Function:  double get_theta()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function prompts the user for theta  (angle (radians) of elevation )

  Input parameters: None

  Returns:  The theta

  Preconditions:  None

  Postconditions:  The theta has been got and returned
*/

double get_theta(void);




/*
  Function:    double get_distance ()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function prompts the user for distance ( distance (ft) to target )

  Input parameters:  None 

  Returns:   The distance

  Preconditions:   None
    
  Postconditions:    The distance has been got and returned
*/

double get_distance(void);



/*
  Function:    double get_velocity ()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function prompts the user for the velocity ( projectile velocity (ft/sec) )

  Input parameters:  None

  Returns:  The velocity

  Preconditions:   None

  Postconditions:  The velocity has been got and returned
*/

double get_velocity(void);




/*
  Function:    double calculate_time_flight()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function calculates the the time of a projectile's flight by the formula  time = (distance) / (velocity * cos(theta))

  Input parameters:  The theta, distance and velocity

  Returns:  The time

  Preconditions:   The theta, distance and velocity

  Postconditions:  The time has been calculated
*/

double calculate_time_flight(double theta, double distance, double velocity);




/*
  Function:    double calculate_height_impact()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function computes the height above the ground when it reaches the target by the formula   height = velocity * sin(theta) * time - ((G * time * time) / 2)

  Input parameters:   The theta, distance, velocity and time

  Returns:  The height

  Preconditions:   The theta, distance, velocity and time

  Postconditions:   The height has been calculated
*/

double calculate_height_impact(double theta, double distance, double velocity, double time);



/*
  Function:   void display_time_flight()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function displays the time to the screen

  Input parameters:  The time

  Returns:  None

  Preconditions: The time

  Postconditions:  The result has been displayed on the screen 
*/

void display_time_flight(double time);




/*
  Function:    void display_height_impact ()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function displays the height to the screen

  Input parameters:  The height

  Returns:  None

  Preconditions:   The height

  Postconditions:  The result has been displayed on the screen 
*/

void display_height_impact(double height);






  // All defined-functions for task 3


/*
  Function:  double get_point()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function prompts the user for point

  Input parameters:  The work type and the order number of the work type

  Returns:  The point

  Preconditions:  The work type and the order number of the work type

  Postconditions:   The point has been got and returned
*/
double get_point(char work_type[10], int num);






/*
  Function:   double compute_average()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function computes the average of the two points on the same work type

  Input parameters:   The point1 and point2

  Returns:  The average

  Preconditions:  The point1 and point2

  Postconditions:  The average has been calculated
*/
double compute_average(double point1, double point2);




/*
  Function:   double compute_weighted_average()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function computes the weight average according to:  Each exam is worth 30%, each lab is worth 5% and each project is worth 15%

  Input parameters:  The three seperate averages of exams, labs and projects

  Returns:  The weighted average

  Preconditions:   The three seperate averages of exams, labs and projects

  Postconditions:  The weighted average has been calculated

*/
double compute_weighted_average(double exam_avg, double lab_avg, double project_avg);





/*
  Function:   void display_weighted_average()

  Date Created: Feb 10, 2021

  Date Last Modifiled: Feb 10, 2021

  Description:  This function displays the weighted average to the screen

  Input parameters:  The weight average

  Returns:   None

  Preconditions:   The weight average


  Postconditions:  The result has been displayed to the screen
*/

void display_weighted_average(double weighted_avg);
