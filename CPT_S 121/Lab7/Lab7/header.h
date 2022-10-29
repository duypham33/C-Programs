
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h>  //necessary to use ceil() and pow()




//Function prototype





//All the function prototypes for task 1



/*
  Function:      void charges ()

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  This function calculates the total charges and average cost of each customer 

  Input parameters:   The number of hours, The pointers of the totoal charge and average cost

  Returns:  None

  Preconditions:     The number of hours, The pointers of the totoal charge and average cost

  Postconditions:   The totoal charge and average cost have been sent back indirectly
*/
void charges(double number_hours, double* total_charge, double* average_cost);





/*
  Function:    double round_money ()

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  This functions round a real number to two decimal places

  Input parameters:   A real number

  Returns:   The real number rounded to tow decimal places

  Preconditions:  The real number

  Postconditions:   The real number rounded has been returned
*/
double round_money(double number);




//All the function prototypes for task 2

/*
  Function:      void calculate_revenues ()

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:      The funciton calculates the estimated revenues by the function of time: R(t) = 203.265 X (1.071)^t, where R is in millions of dollars and t is the years since 1984

  Input parameters:   The year and the pointer of revenues

  Returns:    None

  Preconditions:  The year and the pointer of revenues

  Postconditions:  The revenues has been returned indirectly
*/
void calculate_revenues(int t, double* R);



/*
  Function:      int predict ()

  Date Created: Feb 24, 2021

  Date Last Modifiled: Feb 24, 2021

  Description:  This function predicts the year in which revenues (in millions) will first equal or exceed the value of the input parameter

  Input parameters:   The tager revenues

  Returns:    The year

  Preconditions:   The tager revenues

  Postconditions:  The year has been returned
*/
int predict(double target_revenues);





#endif

