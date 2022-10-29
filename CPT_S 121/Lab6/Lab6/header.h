
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h> //necessary to use printf() and scanf()

#include<math.h>  //necessary to use sqrt()




//Function prototype





//All the function prototypes for task 1



/*
  Function:   int is_prime ( )

  Date Created: March 5, 2021

  Date Last Modifiled: March 5, 2021

  Description:   This functions determines if a number is prime

  Input parameters:  An integer number

  Returns:    0 (True) or 1 (False)

  Preconditions:   The integer number

  Postconditions:   Return 0 or 1 
*/
int is_prime(int n);




/*
  Function:    int calculate_sum_digits ( )

  Date Created: March 5, 2021

  Date Last Modifiled: March 5, 2021

  Description:  This function calculates the sum of individual digits of a integer number

  Input parameters:  An integer number

  Returns:   The sum of individual digits

  Preconditions:  The integer value

  Postconditions:   The sum has been returned
*/
int calculate_sum_digits(int n);






// The function prototype for task 2

/*
  Function:   int calculate_factorial ( )

  Date Created: March 5, 2021

  Date Last Modifiled: March 5, 2021

  Description:  This function determines the factorial of n, represented n!

  Input parameters:  An integer number

  Returns:   The factorial of the number

  Preconditions:  The integer value

  Postconditions:   The factorial has been returned
*/
int calculate_factorial(int n);





// The function prototype for task 3


/*
  Function:   int calculate_Fibonacci ( )

  Date Created: March 5, 2021

  Date Last Modifiled: March 5, 2021

  Description:  The function calculates the Fibonacci number for the nth term

  Input parameters:  An integer number
    
  Returns:   The Fubonacci number 

  Preconditions:  The integer value

  Postconditions:    The Fubonacci number has been returned
*/
int calculate_Fibonacci(int n);




#endif
