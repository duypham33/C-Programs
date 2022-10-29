
/*

  This is the header file that stores standard library includes, #defined and function prototypes

*/


#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()

#include<stdio.h>    //necessary to use printf() and scanf()

#include<string.h>  //necessary to use strcpy() and strtol()

#include <stdlib.h> // atof ()




typedef struct employee
{
	char last[50], first[50];           // employee's name - last, first
	char title;               // title 'B' or 'M'
	double hours_worked;      // total number of hours worked
	double payrate;           // pay rate per hour
	double total_payment;     // total payment for the pay period

} Employee;








//Function prototype





//All the function prototypes 



/*
  Function:      

  Date Created: April 8, 2021

  Date Last Modifiled: Apri; 8, 2021

  Description:  This function 

  Input parameters:   

  Returns:  

  Preconditions:    

  Postconditions:   
*/
char convert_string_to_char(char s[]);


/*
  Function:

  Date Created: April 8, 2021

  Date Last Modifiled: Apri; 8, 2021

  Description:  This function

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
void compute_total_payment(Employee* payroll_ptr);


/*
  Function:

  Date Created: April 8, 2021

  Date Last Modifiled: Apri; 8, 2021

  Description:  This function

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double max_payment(Employee payroll[], int num_payrolls);




/*
  Function:

  Date Created: April 8, 2021

  Date Last Modifiled: Apri; 8, 2021

  Description:  This function

  Input parameters:

  Returns:

  Preconditions:

  Postconditions:
*/
double min_payment(Employee payroll[], int num_payrolls);







































#endif
